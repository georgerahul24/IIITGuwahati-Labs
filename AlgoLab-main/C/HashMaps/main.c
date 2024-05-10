#include <stdio.h>
#include "HashMaps.h"

int main() {

    HashMaps * new = createHashMaps(10);
    insert(new,"Hello");
    insert(new,"Hello");
    insert(new,"Hi");
    insert(new,"Bye");
    insert(new,"George");
    insert(new,"Rahul");
    insert(new,"My");
    insert(new,"Name");
    printHash(new);




    return 0;
}
