#include <stdio.h>

int main(){
    int v1[2];
    int v2[2];

    v1[0] = 2, v1[1] = 4, v2[0] = 6, v2[1] = 2;

    printf("A: (%d,%d)", v2[0]-v1[0], v2[1]-v1[1]);

    

    return -1;
}
