#include "shell.h"

size_t findListLength(const list_t *list) {
    size_t length = 0;

    while (list) {
        list = list->next;
        length++;
    }
    return length;
}

char **convertListToStrings(list_t *head) {
    list_t *currentNode = head;
    size_t listLength = findListLength(head);
    char **stringsArray;
    char *string;

    if (!head || !listLength)
        return NULL;
    stringsArray = malloc(sizeof(char *) * (listLength + 1));
    if (!stringsArray)
        return NULL;
    for (size_t i = 0; currentNode; currentNode = currentNode->next, i++) {
        string = malloc(strlen(currentNode->str) + 1);
        if (!string) {
            for (size_t j = 0; j < i; j++)
                free(stringsArray[j]);
            free(stringsArray);
            return NULL;
        }

        string = copyString(string, currentNode->str);
        stringsArray[i] = string;
    }
    stringsArray[listLength] = NULL;
    return stringsArray;
}

size_t printList(const list_t *list) {
    size_t length = 0;

    while (list) {
        printString(convertNumber(list->num, 10, 0));
        printChar(':');
        printChar(' ');
        printString(list->str ? list->str : "(nil)");
        printChar('\n');
        list = list->next;
        length++;
    }
    return length;
}

list_t *findNodeStartsWith(list_t *node, char *prefix, char c) {
    char *p = NULL;

    while (node) {
        p = findPrefix(node->str, prefix);
        if (p && ((c == -1) || (*p == c)))
            return node;
        node = node->next;
    }
    return NULL;
}

ssize_t getNodeIndex(list_t *head, list_t *node) {
    size_t index = 0;

    while (head) {
        if (head == node)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

