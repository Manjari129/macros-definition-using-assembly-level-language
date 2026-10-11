
#include <stdio.h>
#include <string.h>

int main()
{
    char code[20][100];
    int n, i, macro = 0;

    printf("Enter number of lines: ");
    scanf("%d", &n);
    getchar();

    printf("Enter assembly language code:\n");

    for (i = 0; i < n; i++)
    {
        fgets(code[i], sizeof(code[i]), stdin);
        code[i][strcspn(code[i], "\n")] = '\0';
    }

    printf("\nMacro Definitions:\n");

    for (i = 0; i < n; i++)
    {
        if (strstr(code[i], "MACRO") != NULL)
        {
            macro = 1;
            printf("%s\n", code[i]);
        }
        else if (strstr(code[i], "MEND") != NULL)
        {
            printf("%s\n", code[i]);
            macro = 0;
        }
        else if (macro == 1)
        {
            printf("%s\n", code[i]);
        }
    }

    return 0;
}
