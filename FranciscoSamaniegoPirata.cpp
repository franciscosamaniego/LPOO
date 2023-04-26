#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//2 = agua, 1 = tierra, 3 = puentes, 4 = pirata, 5 = tesoro

//funcion que imprime el mapa con la posicion actual del pirata, en caso de que un casillero sea el tesoro,
//imprime 1 en vez de 5
void definirMapa(int n, int **mapa) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mapa[i][j] == 5) {
                cout << "1 ";
                j++;
            }
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}
//funcion que le permite al usuario buscar el tesoro por todo el mapa, teniendo 50 intentos
int buscarTesoro(int n, int **mapa, int Tx, int Ty) {
    int perder = 0;
    int count = 0;
    int ganar = 0;
    int Px;
    int Py;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mapa[i][j] == 4) {
                Px = i;
                Py = j;
            }
        }
    }
    while(count != 50) {
        char choice;
        cout << "Para que lado quiere moverse segun la estrella? Norte(N), Sur(S), Este(E), Oeste(O)" << endl;
        cin >> &choice;
        //por cada caso, si no es ni agua o el tesoro, se va moviendo el pirata por el mapa
        if(choice == 'N' || choice == 'n') {
            if(mapa[Px-1][Py] != 2 && mapa[Px-1][Py] != 5) {
            mapa[Px][Py] = 1;
            mapa[Px-1][Py] = 4; //para arriba
            count++;
            definirMapa(n,mapa);
            Px--;
            }
            else if(mapa[Px-1][Py] == 2) perder = 1;
            else ganar = 1;
        }
        else if(choice == 'S' || choice == 's') {
            if(mapa[Px+1][Py] != 2 && mapa[Px+1][Py] != 5) {
            mapa[Px][Py] = 1;
            mapa[Px+1][Py] = 4; //para abajo
            count++;
            definirMapa(n,mapa);
            Px++;
            }
            else if(mapa[Px+1][Py] == 2) perder = 1;
            else ganar = 1;
        }
        else if(choice == 'E' || choice == 'e') {
            if(mapa[Px][Py+1] != 2 && mapa[Px][Py+1] != 5) {
            mapa[Px][Py] = 1;
            mapa[Px][Py+1] = 4; //para la derecha
            count++;
            definirMapa(n,mapa);
            Py++;
            }
            else if(mapa[Px][Py+1] == 2) perder = 1;
            else ganar = 1;
        }
        else if(choice == 'O' || choice == 'o') {
            if(mapa[Px][Py-1] != 2 && mapa[Px][Py-1] != 5) {
            mapa[Px][Py] = 1;
            mapa[Px][Py-1] = 4; //para la izquierda
            count++;
            definirMapa(n,mapa);
            Py--;
            }
            else if(mapa[Px][Py-1] == 2) perder = 1; //en este caso si la posicion actual del pirata es agua, pierde
            else ganar = 1; //sino, gana
        }
        else {
            cout << "Elija una opcion correcta" << endl;
            continue;
        }
        if(perder) {
            cout << "Te caiste al agua, perdiste" << endl;
            break;
        }
        else if(ganar) {
            cout << "Felicidades, encontraste el tesoro" << endl;
            break;
        }
    }
    if(count == 50) cout << "Llegaste al maximo de intentos, lo siento"; //si llega a 50 intentos pierde
}



void incializarMapa(int n, int **mapa, int Tx, int Ty) {
for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) { //declara los bordes del mapa, o sea el agua y los puentes
            mapa[i][j] = 1;
            if(i == 0 || j == 0 || i == n-1 || j == n-1) {
                mapa[i][j] = 2;
            }
        }
    } 
    int esquina1 = rand() % 4;
    int esquina2 = rand() % 4; //en esta parte declara los dos puentes en alguna de las 4 esquinas del mapa
    while(esquina1 == esquina2) esquina2 = rand() % 4;
    if (esquina1 == 0) {
        mapa[0][0] = 3;
    } else if (esquina1 == 1) {
        mapa[0][n-1] = 3;
    } else if (esquina1 == 2) {
        mapa[n-1][0] = 3;
    } else {
        mapa[n-1][n-1] = 3;
    }

    if (esquina2 == 0) {
        mapa[0][0] = 3;
    } else if (esquina2 == 1) {
        mapa[0][n-1] = 3;
    } else if (esquina2 == 2) {
        mapa[n-1][0] = 3;
    } else {
        mapa[n-1][n-1] = 3;
    }
    Tx = rand() % (n-2) + 1;
    Ty = rand() % (n-2) + 1;
    while(1) {
       int Px = rand() % (n-2) + 1;
       int Py = rand() % (n-2) + 1; //declara la posicion del pirata y del tesoro, sin que sean la misma
        if(Tx != Px || Ty != Py) {
            mapa[Px][Py] = 4;
            mapa[Tx][Ty] = 5;
            break;
        }
    }
}

int main(void) {
    int n;
    int tesoroX;
    int tesoroY;
    srand(time(NULL));
    cout << "De cuanto quiere que sea la matriz?" << endl; //le pide al usuario que ingrese la longitud del mapa
    cin >> n;
    
    int** mapa = new int*[n];
    for(int i = 0; i < n; i++) {
        mapa[i] = new int[n];
    }
    incializarMapa(n,mapa,tesoroX,tesoroY);
    definirMapa(n,mapa);
    buscarTesoro(n,mapa,tesoroX,tesoroY);
}       
       
        