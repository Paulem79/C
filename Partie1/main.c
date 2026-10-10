// Ah bah on sent que c'est pas linux (et flemme de mettre sur WSL)
typedef void* HANDLE;
typedef unsigned long DWORD;
typedef int BOOL;

#define NULL 0
#define STD_OUTPUT_HANDLE ((DWORD)-11)
#define INVALID_HANDLE_VALUE ((HANDLE)(long long)-1)

__declspec(dllimport) HANDLE __stdcall GetStdHandle(DWORD nStdHandle);
__declspec(dllimport) BOOL __stdcall WriteFile(
    HANDLE hFile,
    const void* lpBuffer,
    DWORD nNumberOfBytesToWrite,
    DWORD* lpNumberOfBytesWritten,
    void* lpOverlapped
);

int my_putchar(const char c[]) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) {
        return 0;
    }

    // Calcul de la taille sans sizeof
    DWORD octetsAecrire = 0;
    while (c[octetsAecrire] != '\0') {
        octetsAecrire++;
    }

    DWORD octetsEcrits = 0;
    BOOL succes = WriteFile(
        hStdOut,
        c,
        octetsAecrire,
        &octetsEcrits,
        NULL
    );

    return succes ? (int) octetsEcrits : -1;
}

int main(void) {
    char nom[30];
    signed int age;

    my_putchar("Quel est ton nom ? \n");
    //scanf("%29s", nom);
    my_putchar("Quel est ton age ? \n");
    //scanf("%d", &age);
    //my_putchar("Tu t'appelles %s et tu auras %d ans l'an prochain\n", nom, age + 1);

    if (age < 18) {
        my_putchar("TU ES MINEUR !!!");
    } else {
        my_putchar("Tu es majeur");
    }

    return 0;
}