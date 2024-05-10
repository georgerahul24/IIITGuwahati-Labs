//
// Created by gr on 29/04/23.
//

#include "Infix_to_Postfix.h"

int convert_infix_to_postfix(const char *input, int maxsize) {
    stack *s1 = createStack(maxsize);
    int index = 0;
    load_symbols_data();
    while (index < strlen(input)) {
        break;
    }
}


node *load_symbols_data() {
    node *head = NULL;
    FILE *f = fopen("/Users/gr/Desktop/C/Stack/symbols.data", "r");
    char string[5];
    int prece;
    while (1) {


        fscanf(f, "%s %d ", &string, &prece);
        if (!strcmp("END", string)) {
            break;
        }

        add_at_beginning(string, prece, &head);

    }
    node *curr = head;
    while (curr != NULL) {

        printf("\n%s %d", curr->s, curr->precedence);
        curr = curr->next;
    }
    return head;

}

void add_at_beginning(const char* c, int precedence, node **head) {
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->s,c);
    new_node->precedence = precedence;
    new_node->next = *head;
    *head = new_node;
}

int is_symbol(const char *s, node *head) {
    node *curr = head;
    while (curr != NULL) {
        if (strcmp(s, curr->s)) return 1;
        curr = curr->next;

    }

    return -1;

}
