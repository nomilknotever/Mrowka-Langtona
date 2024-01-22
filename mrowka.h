#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <math.h>
#define LINE_VERTICAL "│"
#define LINE_HORIZONTAL "─"
#define LINE_DOWN_RIGHT "┌"
#define LINE_DOWN_LEFT "┐"
#define LINE_UP_RIGHT "└"
#define LINE_UP_LEFT "┘"
#define SQUARE_WHITE " "
#define SQUARE_BLACK "█"
#define ARROW_NORTH_WHITE "△"
#define ARROW_NORTH_BLACK "▲"
#define ARROW_EAST_WHITE "▷"
#define ARROW_EAST_BLACK "▶"
#define ARROW_SOUTH_WHITE "▽"
#define ARROW_SOUTH_BLACK "▼"
#define ARROW_WEST_WHITE "◁"
#define ARROW_WEST_BLACK "◀"

typedef struct{
int zwrot;
int currentX;
int currentY;


}ant;



void printStart(int size){
		printf(LINE_DOWN_RIGHT);
		for(int k=0; k < size-2; k++){
			printf(LINE_HORIZONTAL);
			}	
		printf(LINE_DOWN_LEFT);
	}
	
void createMap(char* string,int x, int y, ant mrowka, int pola[]){
	memset(string,0,1600);
	strcat(string,LINE_DOWN_RIGHT);
                for(int k=0; k < x; k++){
                        strcat(string,LINE_HORIZONTAL);
                        }
                strcat(string, LINE_DOWN_LEFT);
		strcat(string,"\n");
		for(int a = 0; a < y; a++){
			strcat(string,LINE_VERTICAL);
			for(int b = 0; b < x; b++){
				
				if(a == mrowka.currentY && b == mrowka.currentX){
					switch(mrowka.zwrot){
						case 1:
							strcat(string,ARROW_NORTH_BLACK);
							break;
						 case 2:
                                                        strcat(string,ARROW_EAST_BLACK);
                                                        break;
						 case 3:
                                                        strcat(string,ARROW_SOUTH_BLACK);
                                                        break;
						 case 4:
                                                        strcat(string,ARROW_WEST_BLACK);
                                                        break;
						default:
							strcat(string,"XDD");
							break;
					}
				} 
				else if(pola[a*x+b] == 1)
					strcat(string,SQUARE_BLACK);
				else{
					strcat(string,SQUARE_WHITE);
				}
			}
			strcat(string,LINE_VERTICAL);
			strcat(string,"\n");
		}
		 strcat(string,LINE_UP_RIGHT);
                for(int k=0; k < x; k++){
                        strcat(string,LINE_HORIZONTAL);
                        }
                strcat(string, LINE_UP_LEFT);
		strcat(string, "\n\n");


}



