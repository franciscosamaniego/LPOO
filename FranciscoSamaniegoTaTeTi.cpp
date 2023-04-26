#include <stdio.h>
#include <stdlib.h>

//imprime la tabla con los resultados que se van ingresando
void print(char m[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("'%c' ", m[i][j]);
        }
        printf("\n");
    }
}

//revisa si hay un ganador o si hay empate, si no pasa ninguno, el juego sigue
int ganador(char m[3][3]) {
    for(int i = 0; i < 3; i++) {
    if (m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][0] != ' ') { //en esta parte revisa si toda una linea horizontal
    //es igual sin ser un espacio en blanco, en el caso de que si pregunta si pertenece a la x o al 0 para declarar
    //el ganador
        if(m[i][0] == 'X' || m[i][0] == 'x') return 1;
        else return 2;
        }
    }
    //en esta parte revisa si toda una linea vertical es igual sin ser un espacio en blanco, en el caso 
    //de que si pregunta si pertenece a la x o al 0 para declarar el ganador
    for(int j = 0; j < 3; j++) {
        if (m[0][j] == m[1][j] && m[1][j] == m[2][j] && m[0][j] != ' ') {
        if(m[0][j] == 'X' || m[0][j] == 'x') return 1;
        else if(m[0][j] == '0') return 2;
        }
    }
    //en esta parte revisa si toda una linea diagonal es igual sin ser un espacio en blanco, en el caso 
    //de que si pregunta si pertenece a la x o al 0 para declarar el ganador
    if (m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[0][0] != ' ') {
        if (m[0][0] == 'X') {
            return 1; 
        } else {
            return 2; 
        }
    }
    //en esta parte revisa si toda una linea diagonal inversa es igual sin ser un espacio en blanco, en el caso 
    //de que si pregunta si pertenece a la x o al 0 para declarar el ganador
    if (m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[0][2] != ' ') {
        if (m[0][2] == 'X') {
            return 1; 
        } else {
            return 2; 
        }
    }
    //si no pasa niguno de los anterios casos y hay espacios en blanco, el juego sigue
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(m[i][j] == ' ') return 0;
        }
    }
    //si no pasa nada de lo anterior, entonces es un empate
    return 3;
}

int main(void) {
    char m[3][3] = {{' ', ' ', ' '}, 
                    {' ', ' ', ' '}, 
                    {' ', ' ', ' '}
                   };
    char choice;
    int i;
    int j;
    while(1) {
        print(m);
        //le consulta al usuario en donde quiere colocar el simbolo y cual
        printf("\nEn que posicion quiere ingresarlo?\n");
        printf("Posicion i (0,1,2): ");
        scanf("%d", &i);
        printf("Posicion j (0,1,2): ");
        scanf("%d", &j);
        if(m[i][j] == ' ') {
            printf("Que quiere poner? X/0\n");
            scanf(" %c", &choice);
            if(choice == 'x') choice -= 32;
            if(choice == 'X' || choice == '0') m[i][j] = choice;
            else printf("Ingrese una opcion valida\n");
        }
        else {
            printf("Esa posicion ya fue utilizada o no es una posicion existente\n");
            continue;
        }
        getchar();
        //segun la funcion del ganador imprime lo que corresponde
        if(ganador(m) == 1) {
            print(m);
            printf("Gano la X\n");
            break;
        }
        else if(ganador(m) == 2) {
            print(m);
            printf("Gano el 0\n");
            break;
        }
        else if(ganador(m) == 3) {
            print(m);
            printf("Empate\n");
            break;
        }
    }
    return 0;
}
