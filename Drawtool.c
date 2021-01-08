//Alexander Rollison 1001681800

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Drawtool.h"

void DrawMap(char MyStringPtr[][MAX_SIZE], char *Token, int *Token1, int *Token2, int *Token3, char *Token4)
{
    int i;
    int j;
	int k;
	char TokenR = *Token;
	int Token1R = *Token1;
	int Token2R = *Token2;
	int Token3R = *Token3;
	char Token4R = *Token4;
    if(TokenR == 'P' || TokenR == 'p')
    {
        *(*(MyStringPtr + Token2R) + Token1R) = Token4R;
    }
    else if(TokenR == 'V' || TokenR == 'v')
    {
        for(i = 1; i <= Token2R; i++)
        {
            for(j = 1; j <= Token1R; j++)
            {
                if(i == Token2R && j == Token1R)
                {
					for(k = 1; k <= Token3R; k++,i++)
					{
						*(*(MyStringPtr + i) +j) = Token4R;
					}
                }
            }
        }
    }
    else if(TokenR == 'H' || TokenR == 'h')
    {
		for(i = 1; i <= Token2R; i++)
		{
            for(j = 1; j <= Token1R; j++)
            {
                if(i == Token2R && j == Token1R)
                {
					for(k = 1; k <= Token3R; k++,j++)
					{
						*(*(MyStringPtr + i) +j) = Token4R;
					}
                }
            }
		}  
    }

}
void PrintMap(char MyStringPtr[][MAX_SIZE], int *MySize)
{
	printf("\n");
    int i;
    int j;
    for(i = 0; i < *MySize; i++)
    {
        for(j = 0; j < *MySize; j++)
        {
            printf(" %c",*(*(MyStringPtr + i)+j));
        }
        printf("\n");
    }
}
void PrintMain()
{
    printf("Draw commands start with\n\n\tP for a single point\n\tH for a horizontal line\n\tV for a vertical line\n\n");
    printf("After the P/V/H, enter a row,col coordinate and the number of spots to mark enclosed in () and separated by commas and then the character for the mark. 'X' will be used if a mark is not entered. For example,\n\n");
    printf("\tP(2,3,1)*\tstart at point 2,3 in the array and mark one spot\n\t\t\twith an *. For P, the 3rd parameter is ignored.\n");
    printf("\tV(1,2,3)$\tstart at point 1,2 in the array and mark the next\n\t\t\t3 spots down from the current position with $\n");
    printf("\tH(4,6,7)#\tstart at point 4,6 in the array and mark the next\n\t\t\t7 spots to the right with #\n\n");
    printf("Coordinates out of range and lines drawn past the borders are not allowed.\n\n");
}
void InitMap(char MyStringPtr[][MAX_SIZE], int *MySize)
{
    char MyChar = '*';
    int x = 1;
    int i;
    int j;
    while(x == 1)
    {
        printf("\nHow big is the array? (Enter a value between 1 and 20) ");
        scanf("%d", MySize);
		getchar();
        if(*MySize <= MAX_SIZE && *MySize > 0)
        {
			printf("\n\nWhat is the background character? ");
            scanf(" %c", &MyChar);
			getchar();
            for(i = 0; i < *MySize; i++)
            {
                for(j = 0; j < *MySize; j++)
                {
                    *(*(MyStringPtr + i) + j) = MyChar;
                }
            }
            x++;
        }
		else
        {
            printf("\nEnter Another Value\n");
        }
    }
}
