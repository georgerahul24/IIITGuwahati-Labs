#include <stdio.h>

#define chToFill '.'
#define chForSpace ' '

void printLine(int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", chToFill);
    }
    printf("\n");


}

void printStart(int n) {
    printf("%c\n", chToFill);
}

void printEnd(int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%c", chForSpace);
    }
    printf("%c\n", chToFill);
}


int main() {

    int n, arg;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of arg: ");
    scanf("%d", &arg);

    int lineNo = 0;
    int status = 0;


    while (lineNo < n) {
        printLine(n);
        lineNo++;
        int argLineNo = 0;

        while (lineNo < n && argLineNo < arg) {
            lineNo++;
            argLineNo++;
            if (status % 2 == 0) {
                printEnd(n);
            } else printStart(n);

        }
        status++;

    }


    return 0;
}
