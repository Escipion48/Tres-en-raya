#include <stdio.h>
#include <stdlib.h>



char** crearMatriz(){
    int i, j;
    char** matriz = (char**) malloc (4*sizeof (char*));
    for(i=0;i<4;i++){
        matriz[i] = (char*) malloc (4*sizeof (char));
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(j==3){
                matriz[i][j]='\0';
            }
            else{
                matriz[i][j]='_';
            }
        }
    }
    return matriz;
}
void mostrarMatriz(char** matriz){

    int i,j;

    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
            printf("%c ", matriz[i][j]);
        }
    }
}
void destructor(char** matriz){
    int i;
    for(i=0;i<4;i++){
        free(matriz[i]);
    }
    free(matriz);
}
void insertarEnMatriz(char** matriz, int x, int y, char simbolo[2]){
    matriz[3-y][x-1]=simbolo[0];
}
void alternarSimbolo(char* simbolo){
    if(simbolo[0]=='x'){
        simbolo[0]='o';
    }
    else simbolo[0]='x';
}
int comprobarGanador(char** matriz);
int main(void) {
    int fin=0, anchura, altura;
    printf("Hola, bienvenido al juego de tres en raya\n"
            "a continuacion tendra que escribir dos numeros\n"
            "seguidos para colocar una marca en el juego\n"
            "el primero es la anchura y el segundo la altura\n");
    char** matriz = crearMatriz();
    char* simbolo = (char*) malloc (2*sizeof (char));
    simbolo[0]='x';
    simbolo[1]='\n';
    for(int i=0 ; i<9 && fin==0 ; i++){
        printf("Introduce la anchura y la altura del 1 al 3 y con espacios:\n");
        scanf("%d %d", &anchura, &altura);
        insertarEnMatriz(matriz, anchura, altura, simbolo);
        alternarSimbolo(simbolo);
    }
    destructor(matriz);
    free(simbolo);
    printf("\n\nGracias por participar\n");

    return 0;
}
