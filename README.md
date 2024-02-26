# ALX Software Engineering Program - Simple Shell Collaborative Project

Welcome to the ALX Software Engineering Program's Simple Shell Collaborative Project repository! This project is part of the SE Foundations curriculum, with a focus on developing a UNIX command interpreter.

## Collaborators
- **Faith Jackson**
- **Anieyie Edem**

## Project Description
This project involves developing a simple UNIX command interpreter, also known as a shell. The shell should be able to display a prompt, wait for user input, execute commands, handle errors, and more.

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
- Write a README with the description of your project
- You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

## Usage
To compile the shell, use the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
To run the shell in interactive mode:
```bash
./hsh
```
To run the shell in non-interactive mode:
```bash
echo "command" | ./hsh
```

## Project Tasks
The project consists of several tasks, each building upon the previous one to add more functionality to the shell. These tasks include handling command lines with arguments, implementing built-in commands like `exit` and `env`, handling logical operators like `&&` and `||`, and more.

## Testing
Testing the shell involves both interactive and non-interactive modes to ensure proper functionality, error handling, and adherence to specifications.

## Contributions
All contributors to this project are listed in the `AUTHORS` file at the root of the repository.

