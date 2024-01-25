#include "mrowka.h"
#include "plik.h"
int main(int argc, char *argv[]) {
    // 1-dlugosc X 2- dlugos Y 3- liczba iteracji 4-
    ant mrowka;

    srand(time(NULL)); // 4- przedrostek 5- procent zapelnienia(int)6-poczatkowy zwrot
    // 1-gora2-prawo3-dol4-lewo
    // 6-zwrot
    int x = 5;
    int y = 5;
    char nazwaPliku[60];
    int *pola;
	int procent;
    char przedrostek[50] = "";
    int iteracje = 5;
    /* for(int i = 0; i < y; i++){
                for(int j = 0; j < x; j++){
                    pola[j][i].kolor=1;*/
    int opt, percentFlag = 0, fileFlag = 0;
    while ((opt = getopt(argc, argv, "x:y:i:z:n:p:")) != -1) {
        switch (opt) {
            case 'x':
                if (atoi(optarg) > 2 && atoi(optarg) < 80) {
                    x = atoi(optarg);
                } else {
                    printf("Zostaly wpisane zle wymiary planszy, przyjeto szerokosc 5\n");
                }
                break;

            case 'y':
                if (atoi(optarg) > 2 && atoi(optarg) < 80) {
                    y = atoi(optarg);
                } else {
                    printf("Zostaly wpisane zle wymiary planszy, przyjeto wysokosc 5\n");
                }
                break;
            case 'i':
		if(atoi(optarg) > 0 && atoi(optarg) < 500){
                	iteracje = atoi(optarg);}
		else{printf("Zostala wpisana zla liczba iteracji, przyjeto liczbe 5\n");}
                break;
            case 'z':
                if (atoi(optarg) == 1 || atoi(optarg) == 2 || atoi(optarg) == 3 || atoi(optarg) == 4) {
                    mrowka.zwrot = atoi(optarg);

                } else {
                    printf("Wprowadź prawidłowy zwrot - 1-góra, 2-prawo, 3-dół lub 4-lewo. Został wpisany zły zwrot,przyjęto początkowy zwrot w górę\n");
                }
                break;
            case 'n':
                if (strlen(optarg) < 1 || strlen(optarg) > 50) {
                    printf("Podano zły przedrostek nazwy pliku - iteracje zostaną zapisane na standardowe wyjście\n");
                    break;
                }
                strcpy(przedrostek, optarg);
                fileFlag = 1;
                break;
            case 'p':
                if (atoi(optarg) < 101 && atoi(optarg) > -1) {
                    percentFlag = 1;
                    procent = atoi(optarg);

                } else {
                    printf("Podano zły procent - wszystkie pola na początku będą białe");
                }
                break;
        }
    }

    pola = (int *)calloc(x * y, sizeof(int));
    mrowka.currentX = x / 2;
    mrowka.currentY = y / 2;
	mrowka.zwrot = 1;
    int dotychczasoweIteracje = 0;
    int exitFlag = 0;
    char mapa[3000];
    if(percentFlag == 1){
	 for(int q = 0; q < x*y;q++){
    		if(rand() % 100 < procent){
			pola[q] = 1;	
	}else{pola[q]=0;}
	 }
	 
    }
    else{
    	for(int q = 0; q < x*y;q++){
		pola[q]=0;
	}
    }
    while (dotychczasoweIteracje < iteracje && exitFlag == 0) {

        createMap(mapa, x, y, mrowka, pola);
	if(fileFlag == 1){
		saveToFile(przedrostek,mapa,dotychczasoweIteracje+1);
	}
	else{
        printf("%s", mapa);}

        if (pola[mrowka.currentX + mrowka.currentY * x] == 0) { // bialy - obrot w prawo

            switch (mrowka.zwrot) {
                case 1:
                    mrowka.zwrot = 4;
                    if (mrowka.currentX > 0) {
                        mrowka.currentX--;
                    } else {
                        exitFlag = -1;
                    }
                    break;
                case 2:
                    mrowka.zwrot = 1;
                    if (mrowka.currentY > 0) {
                        mrowka.currentY--;
                    } else {
                        exitFlag = -1;
                    }
                    break;
                case 3:
                    mrowka.zwrot = 2;
                    if (mrowka.currentX < x - 1) {
                        mrowka.currentX++;
                    } else {
                        exitFlag = -1;
                    }
                    break;
                case 4:
                    mrowka.zwrot = 3;
                    if (mrowka.currentY < y - 1) {
                        mrowka.currentY++;
                    } else {
                        exitFlag = -1;
                    }
                    break;
            }
        } else { // czarny - obrot w lewo            	
		 switch (mrowka.zwrot) {
                case 1:
                    mrowka.zwrot = 2;
                    if (mrowka.currentX < x - 1) {
                        mrowka.currentX++;
                    } else {
                        exitFlag = -1;
                    }
                    break;
                case 2:
                    mrowka.zwrot = 3;
                    if (mrowka.currentY < y - 1) {
                        mrowka.currentY++;
                    } else {
                        exitFlag = -1;
                    }
                    break;
                case 3:
                    mrowka.zwrot = 4;
                    if (mrowka.currentX > 0) {
                        mrowka.currentX--;
                    } else {
                        exitFlag = -1;
                    }
                    break;
                case 4:
                    mrowka.zwrot = 1;
                    if (mrowka.currentY > 0) {
                        mrowka.currentY--;
                    } else {
                        exitFlag = -1;
                    }
                    break;
            }
        }
	switch(mrowka.zwrot){
		case 1:
			 pola[mrowka.currentX + (mrowka.currentY+1) * x] = 1 - pola[mrowka.currentX + (mrowka.currentY+1) * x];
			 break;
		case 2:
			  pola[mrowka.currentX - 1 + mrowka.currentY * x] = 1 - pola[mrowka.currentX - 1 + mrowka.currentY * x];
			  break;
		case 3:
			   pola[mrowka.currentX + (mrowka.currentY-1) * x] = 1 - pola[mrowka.currentX + (mrowka.currentY - 1) * x];
			   break;
		case 4:
			    pola[mrowka.currentX + 1 + mrowka.currentY * x] = 1 - pola[mrowka.currentX + 1 + mrowka.currentY * x];
			    break;
	
	}
        
        
        dotychczasoweIteracje++;
    }
    free(pola);
    return 0;
}

