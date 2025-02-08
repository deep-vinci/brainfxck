#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <assert.h>

void brainfxck(char code[])
{
    int len = 65535;
    int pointer = 0, i = 0;
    char memoryMap[len];

    while (i <= strlen(code))
    {
        switch (code[i])
        {
        case '>':
            pointer++;
            break;

        case '<':
            pointer--;
            break;

        case '+':
            memoryMap[pointer]++;
            break;

        case '-':
            memoryMap[pointer]--;
            break;

        case '.':
            // getchar()
            putchar(memoryMap[pointer]);
            break;

        case ',':
            printf("Yay");
            break;

        case '[':
            printf("Yay");
            break;

        case ']':
            printf("Yay");
            break;

        default:
            break;
        }
        i++;
    }

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", memoryMap[i]);
        // putchar(memoryMap[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        fprintf(stderr, "%s", "error: argv[1] is NULL!\n");
        return 0;
    }

    brainfxck(argv[1]);
}