#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void brainfxck(char code[])
{
    int len = 65535;
    int pointer = 0, i = 0;
    char memoryMap[len];
    memset(memoryMap, 0, len);

    while (i < strlen(code))
    {
        switch (code[i])
        {
        case '>':
            if (pointer < len - 1)
                pointer++;
            break;

        case '<':
            if (pointer > 0)
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
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        fprintf(stderr, "error: no Brainfuck code provided as argument!\n");
        return 1;
    }

    size_t code_length = strlen(argv[1]);
    if (code_length >= 65535)
    {
        fprintf(stderr, "error: input code too long (max %d characters)!\n", 65534);
        return 1;
    }

    brainfxck(argv[1]);
    return 0;
}