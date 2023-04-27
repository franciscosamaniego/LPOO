#include <stdio.h>

int main(void) {
    int n;
    printf("Ingrese su numero\n");
    scanf("%d", &n);
    if(n == 1) { //si el numero es uno lo imprime y termina el programa
        printf("%d\n", n);
        return 0;
    }
        while(n != 1) { //si empieza siendo par, se lo divide por dos y si queda impar, se lo multiplica por
        //3 y se le suma 1 y lo va imprimiendo
            if(n % 2 == 0) {
                printf("%d ", n);
                n /= 2;
            }
            else {
                printf("%d ", n);
                n = n * 3 + 1;
            }
        }
    return 0;
}
