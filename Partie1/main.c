#include <stdio.h>

int main(void) {
    char nom[30];
    printf("Quel est ton nom ? \n");
    scanf("%29s", nom);
    printf("Tu t'appelles %s", nom);


    return 0;
}
