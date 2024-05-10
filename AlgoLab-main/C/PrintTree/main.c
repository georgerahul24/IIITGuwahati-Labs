#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PrintTree.h"

node *createNode(int data) {
    node *new = malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node **createBST(node **head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
        return head;
    }

    if (data <= (*head)->data) createBST(&(*head)->left, data);
    else createBST(&(*head)->right, data);
}


int main() {
    node *head = NULL;

    char choice[5];
    do {
        printf("Enter the number to add, type 'n' in order to exit: ");
        scanf("%s", &choice);

        if (!strcmp(choice, "n")) {
            break;
        } else {
            int data = atoi(choice);
            createBST(&head, data);

        }


    } while (1);

    printTree(head);


    return 0;


}
