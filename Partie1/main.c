#include <stdio.h>

int main(void) {
    char nom[30];
    printf("Quel est ton nom ? \n");
    scanf("%s", &nom);
    printf("Tu t'appelles %s", nom);


    return 0;
}
