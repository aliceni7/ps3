#include <stdio.h>
#include "list.h"

int main(void) {
    int arr[] = {89, 39, 18, 96, 71, 25, 2, 55, 60, -8, 9, 42, 69, 96, 24};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        addNode(createNode(arr[i]));
    }
    printf("Linked List: ");
    printList();
    deleteLargest();
    printList();
    printf("Length of list: %d", sizeofList());
    bubbleSort();
    printList();
}
