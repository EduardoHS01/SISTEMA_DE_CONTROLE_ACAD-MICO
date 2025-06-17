#include <stdio.h>
#include <ctype.h>
#include "funcoesauxiliares.h"

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n') {}
}

void converteMaiusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((char)str[i]);
    }
}
