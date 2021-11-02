#include "node.h"
#include <stdbool.h>
#include <stdlib.h>

Node *head = NULL; // this is the list

bool addNode(Node *);
void printList(void);
Node* findNode(int value);
bool deleteNode(Node* node);
void deleteLargest(void);
void bubbleSort(void);
int sizeofList(void);

