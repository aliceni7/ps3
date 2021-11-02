#include <stdbool.h>
#include <stdio.h>
#include "list.h"

bool addNode(Node *node) {
    if (!head) {
        head = node;
        return true;
    } else {
        Node *walker = head;
        while (walker->next) { walker = walker->next; }
        walker->next = node;
        walker = NULL;
        return true;
    }
}

void printList(void) {
    Node *walker = head;
    if (!head) {
        puts("There is no list");
        return;
    }
    while (walker) {
        printf("%d ", walker->value);
        walker = walker->next;
    }
    puts("");
}

Node* findNode(int value) {
    if (!head) {
        puts("List is empty, unable to locate node");
        return NULL;
    } else {
        Node *walker = head; //start at the top
        while (walker) { // traverse through the linked list
            if (walker->value == value) { // if the current node is the node you're searching for
                return walker;
            } else {
                walker = walker->next;
            }
        }
        return NULL;
    }
}

bool deleteNode(Node* node) {
    if (!head) {
        puts("List is empty");
        return false;
    } else {
        Node* upstream = head; //this will be pointing at the previous node when traversing
        Node* walker = head; //start at the top of the list
        if (walker->value == node->value) { // checking if the first node is the one to delete
            upstream = upstream->next; // now there is no longer this node bye bye
            free(walker); // walker is pointing at the deleted node so we must free it
            walker = NULL; // grounding the pointer, jic we want to use it for other reasons
            head = upstream;
            return true;
        } else {
            walker = walker->next; // setting walker to the next one, keeping upstream at HEAD
        }
        while (walker) {
            if (walker->value == node->value) {
                // code for deleting
                upstream->next = walker->next;
                free(walker);
                walker = NULL;
                return true;
            } else {
                walker = walker->next;
                upstream = upstream->next;
            }
        }
        return false;
    }
}

void deleteLargest(void) {
    // traversing the list to find the largest value(s)
    Node* walker = head;
    Node* largest = createNode(head->value);
    while (walker) {
        if (walker->value > largest->value) {
            largest->value = walker->value;
        }
        walker = walker->next;
    }
    while (findNode(largest->value)) { // while there are multiple values of the largest value
        deleteNode(createNode(largest->value)); //sdljflskdjf no way this actually works hmmmm sussy
    }
}

int sizeofList(void) { // rename to count?
    int ans = 0;
    if (!head) {
        puts("List is empty");
        return ans;
    } else {
        Node* walker = head;
        while (walker) {
            ans++;
            walker = walker->next;
        }
        return ans;
    }
}

void bubbleSort(void) {
    if (!head) {
        puts("List is empty");
        return;
    } else {
        Node *walker = head;
        bool swaps = true; // boolean to keep track of if there are swaps in the list
        while (swaps) {
            swaps = false; // in the next loop swaps will be set to true if a swap occurs
            while (walker->next) { // since it compares the next node too
                //printf("%d\n", walker->value);
                //printf("%d\n\n", walker->next->value);
                if (walker->value > walker->next->value) {
                    // do i need to account for if this is the head?
                    swaps = true; // this code won't be reached once the list is fully sorted so it can break out of the while loop
                    int temp = walker->value; // temp to hold current node's value
                    walker->value = walker->next->value; // set current value to next (smaller) value
                    walker->next->value = temp; // set next value to original current value
                }
                walker = walker->next; // move to the next node
            }
            walker = head; // after one full traversal through the list, set the walker to head to traverse again
        }
    }
}

