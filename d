// Copyright 2023 Sajjad Arghavani
/*
* This file is for displaying Hanoi towers in C language
* Author: Sajjad Arghavani <sajjad.arghavani@gmail.com>
*/
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


#define DELAY 190000
#define MAXRINGS 6
#define SPACER 6


int a[MAXRINGS], b[MAXRINGS], c[MAXRINGS];
int moves = 0;


void
ascending(int *arr, int length) {
    int i, j, temp;
    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int getcell(int *t, int i) {
    if (i >= 1 && i <= MAXRINGS) {
        return t[i - 1];
    }

    return 0;
}


void
printtowers() {
    int j;
    int i = MAXRINGS;
    int tempa[MAXRINGS], tempb[MAXRINGS], tempc[MAXRINGS];

    moves++;
    printf("\033[%dAMove: %d\n", MAXRINGS + 7, moves);
        for (int k = 0; k < MAXRINGS; k++) {
        tempa[k] = a[k];
        tempb[k] = b[k];
        tempc[k] = c[k];
    }
    ascending(tempa, MAXRINGS);
    ascending(tempb, MAXRINGS);
    ascending(tempc, MAXRINGS);
    while (i > 0) {
        int cella = getcell(tempa, i);
        int cellb = getcell(tempb, i);
        int cellc = getcell(tempc, i);

        printf("%*d%*d%*d\n", SPACER, cella, SPACER, cellb, SPACER, cellc);
        i--;
    }

    for (j = 0; j < SPACER * 2 + 3 * MAXRINGS; j++) {
        printf("-");
    }

    printf("\n");
    printf("%*c%*c%*c\n\n", SPACER, 'A', SPACER, 'B', SPACER, 'C');
}


void
move(int n, int *ta, int *tb, int *tc) {
    int nextindex = (MAXRINGS - n) + 1;
    int length = sizeof(ta) / sizeof(ta[0]);

    usleep(DELAY);
    if (n == 1) {
        tb[MAXRINGS - n] = ta[MAXRINGS - n];
        ta[MAXRINGS - n] = 0;
        printtowers();
        return;
    }

    move(n - 1, ta, tc, tb); 
    tb[MAXRINGS - n] = ta[MAXRINGS - n];
    ta[MAXRINGS - n] = 0;
    printtowers();
    move(n - 1, tc, tb, ta);
}


int
main() {
    int length = sizeof(a) / sizeof(a[0]);
    
    for (int i = 0; i < MAXRINGS; i++) {
        a[i] = MAXRINGS - i;
        b[i] = 0;
        c[i] = 0;
    }

    printf("\033c");
    move(MAXRINGS, a, c, b);
    printtowers();

    return 0;
}
