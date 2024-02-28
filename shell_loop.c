#include "shell.h"

int shellLoop(info_t *information, char **arguments)
{
    ssize_t readStatus = 0;
    int builtinReturn = 0;

    while (readStatus != -1 && builtinReturn != -2)
    {
        clearInfo(information);
        if (isInteractive(information))
            _print("$ ");
        _ePrint(BUFFER_FLUSH);
        readStatus = getInput(information);
        if (readStatus != -1)
        {
            setInfo(information, arguments);
            builtinReturn = findBuiltin(information);
            if (builtinReturn == -1)
                findCommand(information);
        }
        else if (isInteractive(information))
            _print('\n');
        freeInfo(information, 0);
    }
    writeHistory(information);
    freeInfo(information, 1);
    if (!isInteractive(information) && information->status)
        exit(information->status);
    if (builtinReturn == -2)
    {
        if (information->errNum == -1)
            exit(information->status);
        exit(information->errNum);
    }
    return (builtinReturn);
}

int findBuiltin(info_t *information)
{
    int i, builtInReturn = -1;
    builtinTable builtInTable[] = {
        {"exit", _myExit},
        {"env", _myEnv},
        {"help", _myHelp},
        {"history", _myHistory},
        {"setenv", _mySetenv},
        {"unsetenv", _myUnsetenv},
        {"cd", _myCd},
        {"alias", _myAlias},
        {NULL, NULL}};
    for (i = 0; builtInTable[i].type; i++)
    {
        if (_stringCompare(information->argv[0], builtInTable[i].type) == 0)
        {
            information->lineCount++;
            builtInReturn = builtInTable[i].func(information);
            break;
        }
    }
    return (builtInReturn);
}

void findCommand(info_t *information)
{
    char *path = NULL;
    int i, argCount;

    information->path = information->argv[0];
    if (information->lineCountFlag == 1)
    {
        information->lineCount++;
        information->lineCountFlag = 0;
    }
    for (i = 0, argCount = 0; information->arg[i]; i++)
    {
        if (!isDelimiter(information->arg[i], " \t\n"))
            argCount++;
    }
    if (!argCount)
        return;

    path = findPath(information, _getEnv(information, "PATH="), information->argv[0]);
    if (path)
    {
        information->path = path;
        forkCommand(information);
    }
    else
    {
        if ((isInteractive(information) || _getEnv(information, "PATH=") || information->argv[0][0] == '/') && isCommand(information, information->argv[0]))
            forkCommand(information);
        else if (*(information->arg) != '\n')
        {
            information->status = 127;
            printError(information, "not found\n");
        }
    }
}

void forkCommand(info_t *information)
{
    pid_t childPid;

    childPid = fork();
    if (childPid == -1)
    {
        /* TODO: PUT ERROR FUNCTION */
        perror("Error:");
        return;
    }
    if (childPid == 0)
    {
        if (execve(information->path, information->argv, getEnvironment(information)) == -1)
        {
            freeInfo(information, 1);
            if (errno == EACCES)
                exit(126);
            exit(1);
        }
        /* TODO: PUT ERROR FUNCTION */
    }
    else
    {
        wait(&(information->status));
        if (WIFEXITED(information->status))
        {
            information->status = WEXITSTATUS(information->status);
            if (information->status == 126)
                printError(information, "Permission denied\n");
        }
    }
}
