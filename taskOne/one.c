#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseFile(FILE* f)
{
    char* txtNumbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char line[4096];
    int sum = 0;
    while (fgets(line, sizeof(line), f) != NULL)
    {
        int iRev = -1;
        char foundNum[3] = "00";
        short foundFirst = 0;
        short foundLast = 0;
        for (int i = 0, iRev = strlen(line)-1; ; i++)
        {
            if ((line[i] >= '0' && line[i] <= '9') && !foundFirst)
            {
                printf("%c ", line[i]);
                foundNum[0] = line[i];
                foundFirst = 1;
            }
            if ((line[iRev] >= '0' && line[iRev] <= '9') && !foundLast)
            {
                printf("%c ", line[iRev]);
                foundNum[1] = line[iRev];
                foundLast = 1;
            } 
            iRev--;
            if (foundFirst && foundLast)
                break;
        }
        sum += atoi(foundNum);
        printf("\n");
    }
    printf("\nSUM : %d\n", sum);
}
    
int main(int argc, char** argv) 
{
    FILE* f = fopen(argv[1], "r");
    if (f == NULL) 
    {
        printf("Failed to open the file.\n");
        return 1;
    }
    parseFile(f);
    fclose(f);
    return 0;
}