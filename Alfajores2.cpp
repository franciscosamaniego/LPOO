#include <iostream>

using namespace std;

void initialize(int precios[4], char alfa[4][20]) {
    for(int i = 0; i < 4; i++) {
        cout << "Cuanto sale la caja de alfajores de " << alfa[i] << "?" << endl;
        cin >> precios[i];
    }
}

int main(void) {
    int operadores[6] = {1,2,3,4,5,6};
    char alfa[4][20] = {"Chocolate", "Dulce de leche", "Fruta", "Mixto"};
    int precios[4];
    int cantE = 0, cajasC = 0, cajasD = 0, cajasF = 0, cajasM = 0;
    int choco[6] = {0}, dulce[6] = {0}, fruta[6] = {0}, mixto[6] = {0};
    int fueraProd[6] = {0};
    initialize(precios,alfa);
    while(1) {
        int id, cant;
        char alfajor;
        cout << "Que operario sos? (del 1 al 6)" << endl;
        cin >> id;
        cout << "Cuantos produjo?" << endl;
        cin >> cant;
        if(id > 0 && id < 7) {
            cout << "Que alfajores fabrico? Chocolate(c), Dulce de leche(d), Fruta(f) o Mixto(m)" << endl;
            cin >> alfajor;
            if(alfajor == 'c' || alfajor == 'C') {
                choco[id-1] += cant;
                cajasC += cant / 6;
            }
            else if(alfajor == 'd' || alfajor == 'D') {
                choco[id-1] += cant;
                cajasD += cant / 6;
            }
            else if(alfajor == 'f' || alfajor == 'F') {
                choco[id-1] += cant;
                cajasF += cant / 6;
            }
            else if(alfajor == 'm' || alfajor == 'M') {
                choco[id-1] += cant;
                cajasM += cant / 6;
            }
            if(cant % 6 != 0) {
                fueraProd[id-1] += cant % 6;
                cantE++;
            }
        }
        else cout << "Elija una opcion existente" << endl;
        char choice;
        cout << "Hubo mas producciones? s/n";
        cin >> choice;
        if(choice == 'n' || choice == 'N') break;
    }
    for(int i = 0; i < 6; i++) {
        cout << "Operario " << i+1 << endl;
        cout << "Cantidad de alfajores de chocolate: " << choco[i] << endl;
        cout << "Cantidad de alfajores de dulce de leche: " << dulce[i] << endl;
        cout << "Cantidad de alfajores de fruta: " << fruta[i] << endl;
        cout << "Cantidad de alfajores mixtos: " << mixto[i] << endl;
        cout << "Alfajores fuera de produccion: " << fueraProd[i] << endl;
        cout << endl;
    }
    cout << "Ganancias generadas con los alfajores de chocolate: " << cajasC * precios[0] << endl;
    cout << "Ganancias generadas con los alfajores de dulce de leche: " << cajasD * precios[1] << endl;
    cout << "Ganancias generadas con los alfajores de fruta: " << cajasF * precios[2] << endl;
    cout << "Ganancias generadas con los alfajores mixtos: " << cajasM * precios[3] << endl;
    cout << "Cantidad de errores generados: " << cantE << endl;
    return 0;
}