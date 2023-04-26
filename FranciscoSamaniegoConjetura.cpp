#include <stdio.h>

int main(void) {
    int n;
    printf("Ingrese su numero\n");
    scanf("%d", &n);
    if(n == 1) { //si el numero es uno lo imprime y termina el programa
        printf("%d\n", n);
        return 0;
    }
    else if((n % 2) == 0) {
        while(n != 1) { //si empieza siendo par, se lo divide por dos y si queda impar, se lo multiplica por
        //3 y se le suma 1 y lo va imprimiendo
            if(n % 2 == 0) {
                printf("%d ", n / 2);
                n /= 2;
            }
            else {
                printf("%d ", n * 3 + 1);
                n = n * 3 + 1;
            }
        }
    }
    else {
        while(n != 1) {
            if(n % 2 == 0) { //si empieza siendo impar, primero multiplica por 3 y le suma 1 y luego si es par
            //lo divide por 2 y lo va imprimendo
                printf("%d ", n / 2);
                n /= 2;
            }
            else {
                printf("%d ", n * 3 + 1);
                n = n * 3 + 1;
            }
        }
    }
    return 0;
}