typedef struct node {
    int value;
    struct node *next;
} Node;

Node* createNode(int);

/*
//
// Created by Alice Ni on 11/1/21.
//
#include <stdbool.h>
#ifndef PSET3_NODE_H
#define PSET3_NODE_H

typedef struct node { // should be in the header file (slides)
    int value;
    struct node* next;
} node;

node* createNode(int value); //Create a new node with a given value


#endif //PSET3_NODE_H
*/