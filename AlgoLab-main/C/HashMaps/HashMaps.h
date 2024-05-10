//
// Created by gr on 27/06/23.
//

#ifndef HASHMAPS_HASHMAPS_H
#define HASHMAPS_HASHMAPS_H

#include <stdlib.h>
#include <string.h>

typedef struct cell {

    char *val;


    struct cell *next;
} cell;


cell *createCell(char *str);

typedef struct {

    int M;

    cell **Map;

} HashMaps;


HashMaps *createHashMaps(int size);


int Hash(char *str);

void insert(HashMaps *hashMaps, char *str);

void printHash(HashMaps *hashMaps);


void growTable(HashMaps *hashMaps) {
    cell **Map = malloc(sizeof(cell *) * hashMaps->M * 2);
    for (int i = 0;i<hashMaps->M;i++){

    }

}


#endif //HASHMAPS_HASHMAPS_H
