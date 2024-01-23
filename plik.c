#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "plik.h"

//zapisywanie do pliku
//przedrostek,string,icbz a iteracji
//
//
void saveToFile(char przedrostek[], char mapa[], int nrIteracji){
	char nazwaPliku[100];
	strcpy(nazwaPliku,przedrostek);
	char strLiczba[10];
	sprintf(strLiczba, "%d", nrIteracji);	
	strcat(nazwaPliku,"_");
	strcat(nazwaPliku,strLiczba);
	FILE *fp;
	fp = fopen(nazwaPliku,"w");
	if(fp == NULL){
		fprintf(stderr,"Blad otwierania pliku\n");
		
	}
	else{
	fprintf(fp,"%s",mapa);}
	fclose(fp);


}
