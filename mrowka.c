
#include"mrowka.h"

int main(int argc, char *argv[]){//1-dlugosc X 2- dlugos Y 3- liczba iteracji 4-
ant mrowka;
srand(time(NULL));                     //4- przedrostek 5- procent zapelnienia(int)6-poczatkowy zwrot
                                            //1-gora2-prawo3-dol4-lewo
                                            //6-zwrot
int x = 5;
int y = 5;
printf("▶ \n");

    char *c = "▶";
    printf("%s %d \n", c, strlen(c));

    // setlocale(LC_ALL, "");
    setlocale(LC_ALL, "C.UTF-8");
    wchar_t *wc = L"▶";
    printf("%ls %d \n", wc, wcslen(wc));
pole pola[x][y];
char przedrostek[50] = "file";
int iteracje = 5;
 for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                pola[j][i].kolor=1;
int opt;
    while ((opt = getopt(argc, argv, "x:y:i:z:n:p:")) != -1) {
        switch (opt) {
            case 'x':
                x = atoi(optarg);
                break;
            case 'y':
                y = atoi(optarg);
                break;
            case 'i':
                iteracje = atoi(optarg);
                break;  
            case 'z':
                if (atoi(optarg) == 1 || atoi(optarg) == 2 || atoi(optarg) == 3 || atoi(optarg) == 4){
                    mrowka.zwrot = atoi(optarg);
                
                }
                else{fprintf(stderr, "Wprowadź prawidłowy zwrot - 1-góra, 2-prawo, 3-dół lub 4-lewo\n");
                exit(EXIT_FAILURE);}
                break;
            case 'n':
		strcpy(przedrostek,optarg); 
            case 'p':
		int procent = atoi(optarg);
		    for(int i = 0; i < y; i++){
        		for(int j = 0; j < x; j++){
            			if (rand() % 100 < procent){
               	 			pola[j][i].kolor = 1;
           	 }
            	else{
                	pola[j][i].kolor = 0;
            	}
        }
        }
            case '?':
                fprintf(stderr, "Wpisz argumenty wywolania");
                exit(EXIT_FAILURE);
        }
    }

    }

}
printStart(x); 
int dotychczasoweIteracje = 0;
while(dotychczasoweIteracje < iteracje){


}

return 0;
}

