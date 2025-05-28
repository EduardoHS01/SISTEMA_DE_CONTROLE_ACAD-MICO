#include <stdio.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n') {}
}
