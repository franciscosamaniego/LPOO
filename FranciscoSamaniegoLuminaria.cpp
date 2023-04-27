#include <iostream>
#include <stdlib.h>
using namespace std;

//funcion que imprime si la calle es luminosa, muy luminosa, oscura o tenebrosa
void check(int zona[5][15], int luces[5], int maxcalle[5]) {
    int lucesApagadas[5] = {0};
    int count = 0;
    for(int i = 0; i < 5; i++) {
        lucesApagadas[i] = 0;
        for(int j = 0; j < 15; j++) { //calcula la cantidad de luces apagadas por cada calle
            if(zona[i][j] == 0) lucesApagadas[i]++;
        }
    }
    for(int i = 0; i < 5; i++) {
        cout << "Calle " << i+1 << ":";
    if(lucesApagadas[i] == 15) {
        cout << "Oscura" << endl; //si todas las luces estan apagadas, la calle es tenebrosa
        count++;
    }
    else if(luces[i] == maxcalle[i] && luces[i] > lucesApagadas[i]) cout << "Muy luminosa" << endl; //si hay misma cantidad
    //de luces prendidas como de maximo de luces y las luces prendidas es mayor a las luces apagadas, es una calle muy luminosa
    else if(luces[i] == maxcalle[i] && luces[i] <= lucesApagadas[i]) cout << "Luminosa" << endl; //si hay misma cantidad
    //de luces prendidas como de maximo de luces pero las luces prendidas es menor o igual a las luces apagadas, es una calle luminosa
    else cout << "Tenebrosa" << endl; //si no pasa ninguna de estas, es una calle tenebrosa
    }
    cout << "Total de calles con todas las luces apagadas: " << count << endl;
}
//funcion que imprime las calles y sus luces prendidas
void printZona(int zona[5][15]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 15; j++) {
            cout << zona[i][j] << " ";
        }
        cout << endl;
    }
}

void prenderLuces(int zona[5][15], int maxcalle[5]) {
    int m, l;
    char choice;
    int luces[5] = {0};
    while(1) {
        cout << "Que luz quiere iluminar? Elija la fila?" <<endl;
        cin >> m;
        cout << "Que luz quiere iluminar? Elija la columna" <<endl;
        cin >> l;
        //mientras que este dentro del parametro y mientras que la cantidad de luces sea menor al maximo de luces
        //anteriormente definido, el valor de la posicion que el ususario ingresa pasa a ser uno
        if(m <= 5 && m > 0 && l <= 15 && l > 0) {
            if(luces[m-1] < maxcalle[m-1]) {
                if(zona[m-1][l-1] == 0) {
                zona[m-1][l-1] = 1;
                luces[m-1]++;
                }
                else cout << "Esa luz ya fue encendida" << endl;
                printZona(zona);
            }
            else {
                cout << "Llego al maximo de luces de esta calle" << endl;
                printZona(zona);
            } 
        } else cout << "Ingrese un numero valido" << endl;
        cout << "Desea seguir prendiendo luces? s/n" << endl;
        cin >> choice;
        if(choice == 'n' || choice == 'N') break;
    }
    check(zona,luces,maxcalle);
}


int main(void) {
    int zona[5][15] = {0};
    int maxcalle[5];
    int n;
    printZona(zona);
    //le pide al usuario ingresar el maximo de luces que puede haber prendida por calle
    for(int i = 0; i < 5; i++) {
        cout << "Cuanto es el maximo de luces que puede haber en la calle " << i+1 << "?" << endl;
        cin >> n;
        if(n > 0 && n <= 15) maxcalle[i] = n;
        else {
            cout << "Elija una opcion valida" << endl;
            i--;
        }
    }
    prenderLuces(zona,maxcalle);
    return 0;
}