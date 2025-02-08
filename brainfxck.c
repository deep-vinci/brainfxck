#include <stdio.h>
#include <stdlib.h>
// #include <assert.h>

void brainfxck(char code[])
{
    int len = 65535;
    int pointer = 0, i = 0;
    int memoryMap[len];

    while (i <= strlen(code))
    {
        printf("%c", code[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
        fprintf(stderr, "%s", "error: argv[1] is NULL!\n");

    brainfxck(argv[1]);
}