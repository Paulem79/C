#include <stdio.h>

int main(void) {
    char nom[30];
    signed int age;

    printf("Quel est ton nom ? \n");
    scanf("%29s", nom);
    printf("Quel est ton age ? \n");
    scanf("%d", &age);
    printf("Tu t'appelles %s et tu auras %d ans l'an prochain\n", nom, age + 1);

    if (age < 18) {
        printf("TU ES MINEUR !!!");
    } else {
        printf("Tu es majeur");
    }

    return 0;
}
