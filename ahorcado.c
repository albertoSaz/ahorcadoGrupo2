#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
char frase[60],rep[100],temporal[100];
char pal;
int longitud=0,i,j=0,inicial=0,acertado=0,correct=0,oportunidades=5;
int repetido=0,gano=0;

printf("\tJuego del Ahorcado\n");
printf("\t\t\t__\n\t\t\t| |\n\t\t\t| 0\n\t\t\t|/|\\ \n\t\t\t|/ \\ ");
printf("\nDi una palabra para adivinar:\n");
gets(frase);

system("cls");

do {

  correct=0;

//Inicia el programa con las barrabajas correspondientes a la palabra
  if(inicial == 0) {
    for(i=0;i<strlen(frase);i++) {

      if(frase[i] == ' ') {
        temporal[i] = ' ';
        longitud++;
      }

      else {
        temporal[i] = '_';
        longitud++;
      }
    }

    inicial = 1;
    correct=1;
    temporal[longitud] = '\0';

  }
  //Compara las letras introducidas anteriormente con la actual
  for(i=0;i<strlen(rep);i++) {
    if(rep[i] == pal) {
      repetido = 1;
      break;

    }else {
      repetido = 0;
    }
  }
  //Guarda la letra introducida si no esta repetida
  if(repetido == 0 && correct==0) {
    rep[j] = pal;
    j++;

    //Recorre la palabra para encontrar coincidencias
    for(i=0;i<strlen(frase);i++) {

      if(frase[i] == pal) {
        temporal[i] = pal;
        acertado++;
        correct=1;
      }

    }
  }


    //Resta por error
    if(correct == 0) {
    oportunidades = oportunidades - 1;
    }

    system("cls");
    //Imprime la palabra con las ketras correctas introducidas anteriormente y barras para las que no
    for(i=0;i<strlen(temporal);i++) {
      printf(" %c ",temporal[i]);
    }

    printf("\n");
    //Si temporal coincide con la palabbra original sale del bucle indicando que se ha ganado el juego
    if(strcmp(frase,temporal) == 0) {
      gano = 1;
      break;
    }

    if(repetido == 1) {
      printf("\nYa se ha introducido la '%c' en esta partida. ",pal);
    }

    //Escribe nuestras estadisticas de partida a cada ronda
    printf("\n");
    printf("Letras Acertadas: %d",acertado);
    printf("\n");
    printf("Oportunidades Restantes: %d",oportunidades);
    printf("\n");


  //Recoge letras mientras aun queden oportunidades
  if (oportunidades!=0){
    printf("Introduzca una letra:");
    scanf(" %c",&pal);
  }



}while(oportunidades != 0);


if(gano) {

  printf("\n\n");
  printf("Enhorabuena, has ganado :)");

}else {
  printf("\n\n");
  printf("Has perdido.\n");
  printf("\t\t\t__\n\t\t\t| |\n\t\t\t| 0\n\t\t\t|/|\\ \n\t\t\t|/ \\ ");
  printf("R.I.P");
}

printf("\n\n");
system("PAUSE");
return 0;
}
