//Alexander Rollison

#ifndef _Drawtool_H
#define _Drawtool_H
#define MAX_SIZE 20

void PrintMain();
void InitMap(char MyStringPtr[][MAX_SIZE], int *MySize);
void PrintMap(char MyStringPtr[][MAX_SIZE], int *MySize);
void DrawMap(char MyStringPtr[][MAX_SIZE], char *Token, int *Token1, int *Token2, int *Token3, char *Token4);

#endif

