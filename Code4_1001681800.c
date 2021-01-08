//Alexander Rollison 1001681800

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Drawtool.h"

int main()
{
    PrintMain();

    char MyString[MAX_SIZE][MAX_SIZE];
    int MySize;
	
    InitMap(MyString, &MySize);
    PrintMap(MyString, &MySize);

    char MyDraw[20-1]; // I put 20-1 because if you changed MAX_SIZE to 8, P(1,1,1)# is more than 8 spaces. it is 10 "\0" included
    char *Token;
    char *Token1;
    char *Token2;
    char *Token3;
    char *Token4;

	printf("Enter draw command (enter Q to quit) ");
	fgets(MyDraw, 20-1, stdin); // I put 20-1 because if you changed MAX_SIZE to 8, P(1,1,1)# is more than 8 spaces. it is 10 "\0" included
	MyDraw[strlen(MyDraw)-1] = '\0';
	Token = strtok(MyDraw, "(,)\0");
	
	while((*Token != 'Q' && *Token != 'q'))
	{
		if(*Token == 'P' || *Token == 'p' || *Token =='h'|| *Token =='H'|| *Token =='v'|| *Token =='V')
		{
			Token1 = strtok(NULL, ",");
			Token2 = strtok(NULL, ",");
			Token3 = strtok(NULL, ")");
			Token4 =strtok(NULL, "\0");
			char TokenPtr = *Token;
			int Token1Ptr = atoi(Token1);
			int Token2Ptr = atoi(Token2);
			int Token3Ptr = atoi(Token3);
			char Token4Ptr = *Token4;
			
			if(Token1Ptr < MySize && Token2Ptr < MySize && Token1Ptr >= 0 && Token2Ptr >= 0)
			{
				DrawMap(MyString, &TokenPtr, &Token1Ptr, &Token2Ptr, &Token3Ptr, &Token4Ptr);
				PrintMap(MyString, &MySize);
			}
			else
			{
				printf("\nThat draw command is out of range\n");
			}
		}
		else
		{
			printf("Invalid draw command");
		}
		printf("Enter draw command (enter Q to quit) ");
		fgets(MyDraw, 20-1, stdin); // I put 20-1 because if you changed MAX_SIZE to 8, P(1,1,1)# is more than 8 spaces. it is 10 "\0" included
		MyDraw[strlen(MyDraw)-1] = '\0';
		Token = strtok(MyDraw, "(,)\0");
	}
    return 0;
}
