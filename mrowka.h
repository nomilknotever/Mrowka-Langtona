#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
// LINE_VERTICAL:â”‚
// LINE_HORIZONTAL:â”€
// LINE_DOWN_RIGHT:â”Ś
// LINE_DOWN_LEFT:â”
// LINE_UP_RIGHT:â””
// LINE_UP_LEFT:â”
// SQUARE_WHITE:
// SQUARE_BLACK:â–
// ARROW_NORTH_WHITE:â–ł
// ARROW_NORTH_BLACK:â–˛
// ARROW_EAST_WHITE:â–·
// ARROW_EAST_BLACK:â–¶
// ARROW_SOUTH_WHITE:â–˝
// ARROW_SOUTH_BLACK:â–Ľ
// ARROW_WEST_WHITE:â—
// ARROW_WEST_BLACK:â—€

typedef struct{
int zwrot;
int currentX;
int currentY;


}ant;

typedef struct{
int kolor;//1-czarny 0-bialy

}pole;
void printStart(int size){
		printf(LINE_DOWN_RIGHT);
		for(int k; k < size-2; k++){
			printf(LINE_HORIZONTAL);
			}	
		printf(LINE_DOWN_LEFT);
	}
	


