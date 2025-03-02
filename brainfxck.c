#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void brainfxck(char code[])
{
    int len = 65535;
    int pointer = 0, i = 0;
    char memoryMap[len];
    memset(memoryMap, 0, len); // Initialize memory with zeros

    while (i < strlen(code))
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
            putchar(memoryMap[pointer]);
            break;

        case ',':
            memoryMap[pointer] = getchar();
            break;

        case '[':
            if (memoryMap[pointer] == 0)
            {
                int loop = 1;
                while (loop > 0)
                {
                    i++;
                    if (code[i] == '[')
                        loop++;
                    else if (code[i] == ']')
                        loop--;
                }
            }
            break;

        case ']':
            if (memoryMap[pointer] != 0)
            {
                int loop = 1;
                while (loop > 0)
                {
                    i--;
                    if (code[i] == ']')
                        loop++;
                    else if (code[i] == '[')
                        loop--;
                }
            }
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

    printf("\n");
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