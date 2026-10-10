#include <stdio.h>

int main(void) {
    char nom[30];
    signed int age;
    printf("Quel est ton nom ? \n");
    scanf("%29s", nom);
    printf("Quel est ton age ? \n");
    scanf("%d", &age);
    printf("Tu t'appelles %s et tu as %d ans", nom, age);

    return 0;
}
