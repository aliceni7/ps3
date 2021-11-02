#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *createNode(int value) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        puts("Not enough memory");
        exit(-1);
    } else {
        new_node->value = value;
        new_node->next = NULL;
    }
    return new_node;
}


