//
// Created by gr on 27/06/23.
//

#include <printf.h>
#include "HashMaps.h"

HashMaps *createHashMaps(int size) {
    HashMaps *new = malloc(sizeof(HashMaps));
    new->M = size;
    new->Map = malloc(sizeof(cell *) * size);
    return new;
}

int Hash(char *str) {
    int len = strlen(str);

    int hash = 0;

    for (int i = 0; i < len; i++) {
        hash += str[i];
    }
    return hash;
}

void insert(HashMaps *hashMaps, char *str) {
    int hash_value = Hash(str);
    hash_value = hash_value % hashMaps->M;
    cell *new_cell = createCell(str);

    cell *current_cell = hashMaps->Map[hash_value];

    if (current_cell == NULL) {
        hashMaps->Map[hash_value] = new_cell;
    } else {
        new_cell->next = hashMaps->Map[hash_value];
        hashMaps->Map[hash_value] = new_cell;
    }

}

cell *createCell(char *str) {
    cell *new = malloc(sizeof(cell));
    new->val = str;
    new->next = NULL;
    return new;

}


void printHash(HashMaps *hashMaps) {
    for (int i = 0; i < hashMaps->M; i++) {
        cell *curr = hashMaps->Map[i];

        if (curr == NULL) printf("---------");
        else {
            while (curr != NULL) {
                printf("%s->", curr->val);
                curr = curr->next;
            }
        }


        printf("\n");


    }
}
