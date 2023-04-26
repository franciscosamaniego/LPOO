#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i = 0;
int j = 0;
//funcion que imprime la tabla para que el usuario se pueda guiar
void printM(int m[10][10]) {
    for(int i = 0; i < 10; i++) {
        printf("%d  ", i);
        for(int j = 0; j < 10; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("   ");
    for(int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");
}
//la tabla empieza valiendo todos uno
void defineM(int m[10][10]) {
      for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            m[i][j] = 1;
        }
    }
//luego de definir la tabla, tres posiciones aleatorias pasan a valer cero, haciendo referencia a los pozos
//y estos no pueden ser ni el inicio ni el final
    for(int i = 0; i < 3; i++) {
        m[rand() % 10][rand() % 10] = 0;
        m[0][0] = 2;
        if(m[0][0] == 0 || m[9][9] == 0) {
            i--;
            m[0][0] == 2;
            m[9][9] == 1;
        }
    }
}
//en estas funcion comprueba si el usuario se salio del tablero y en el caso de que si el programa le avisa
int checki(int i, int m[10][10]) {
    if(i > 9) {
        printf("No se salga del tablero\n");
        return 1;
    }
    else if(i < 0) {
        printf("No se salga del tablero\n");
        return 1;
    }
    return 0;
}
//tambien revisa que el usuario no se salio del tablero
int checkj(int j, int m[10][10]) {
    if(j > 9) {
        printf("No se salga del tablero\n");
        return 1;
    }
    else if(j < 0) {
        printf("No se salga del tablero\n");
        return 1;
    }
    return 0;
}

int main(void) {
    srand(time(NULL));
    int m[10][10];
    int choice;
    int perder = 0;
    defineM(m);
    printf("Bienvenido al juego. Empezaras en el punto 0,0 y te tendras que mover horizontal o verticalmente\n");
    printM(m);
    while(1) {
        printf("Su posicion: %d,%d\n", i, j);
        printf("En que sentido se quiere mover? Para arriba(1), para abajo(2), para la izquierda(3) o para la derecha(4)?\n");
        scanf("%d", &choice);
        //en cualquier decicion que elija se mueve por el tablero
        switch(choice) {
            case 1:
                if(m[i-1][j] != 0) {
                if (checki(i-1,m) == 0) {
                m[i-1][j] = 2; //esto esta para que aparezca la posicion en el tablero
                m[i][j] = 1;
                i--;
                }
            }
            else perder = 1;
            printM(m);
            break;
            case 2:
                if(m[i+1][j] != 0) {
                    if (checki(i+1,m) == 0) {
                        m[i+1][j] = 2; //esto esta para que aparezca la posicion en el tablero
                        m[i][j] = 1; 
                        i++;
                    }
            }
            else perder = 1;
            printM(m);
            break;
            case 3:
                if(m[i][j-1] != 0) {
                    if (checkj(j-1,m) == 0) {
                        m[i][j-1] = 2; //esto esta para que aparezca la posicion en el tablero
                        m[i][j] = 1;
                        j--;
                    }
                }
                else perder = 1;
                printM(m);
            break;
            case 4:
                if(m[i][j+1] != 0) {
                    if (checkj(j+1,m) == 0) {
                        m[i][j+1] = 2; //esto esta para que aparezca la posicion en el tablero
                        m[i][j] = 1;
                        j++;
                    }
            }
            else perder = 1; // si no se cumple la condicion, entonces el usuario esta encima de un pozo, por lo
            //que perdio
            printM(m);
            break;
            default: 
                printf("Elija una opcion valida\n");
                continue;
        }
        getchar();
        if(perder) {
            printf("Perdiste, si quiere intentelo de nuevo\n");
            break;
        }
        else if (i == 9 && j == 9){
            printf("Ganaste, Felicidades!!!\n");
            break;
        }
    }
    return 0;
}