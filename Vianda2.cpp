#include <iostream>

using namespace std;

void initialize(int precios[4], char vianda[4][20]) {
    for(int i = 0; i < 4; i++) {
        cout << "Cuanto sale la vianda de " << vianda[i] << "?" << endl;
        cin >> precios[i];
    }
}

int main(void) {
    int operadores[7] = {1,2,3,4,5,6,7};
    char vianda[4][20] = {"Carne", "Verduras", "Pescado", "Fruta"};
    int precios[4];
    int cantC = 0, cantV = 0, cantP = 0, cantF = 0;
    int totalC = 0, totalV = 0, totalP = 0, totalF = 0;
    int ventas = 0;
    int cantVenta[7] = {0};
    int cantVop[7] = {0};
    int comision[7] = {0};
    initialize(precios,vianda);
    while(1) {
        int id, cant;
        char viandas;
        int total = 0;
        cout << "Que operario sos? (del 1 al 6 o eleji 0 para finalizar)" << endl;
        cin >> id;
        if(id > 0 && id < 7) {
            cout << "Que vianda fabrico? Carne(c), Verdura(v), Pescado(p) o Fruta(f)" << endl;
            cin >> viandas;
            cout << "Cuantos produjo?" << endl;
            cin >> cant;
            if(cant >= 4) {ventas++; cantVop[id-1]++;}
            if(viandas == 'c' || viandas == 'C') {
                cantVenta[id-1]++;
                cantC += cant;
                total += cant * precios[0];
                totalC += cant * precios[0];   
            }
            else if(viandas == 'v' || viandas == 'V') {
                cantVenta[id-1]++;
                cantV += cant;
                total += cant * precios[1];
                totalV += cant * precios[1];
            }
            else if(viandas == 'p' || viandas == 'P') {
                cantVenta[id-1]++;
                cantP += cant;
                total += cant * precios[2];
                totalP += cant * precios[2];
            }
            else if(viandas == 'f' || viandas == 'F') {
                cantVenta[id-1]++;
                cantF += cant;
                total += cant * precios[3];
                totalF += cant * precios[3];
            }
            if(cantVop > 0) comision[id-1] = total * 0.1 + total * 0.03;
            else comision[id-1] = total * 0.1;
            char choice;
        }
        else if(id == 0) break;
        else cout << "Elija una opcion correcta" << endl;
    }
    for(int i = 0; i < 7; i++) {
        cout << "Operario " << i+1 <<endl;
        cout << "Cantidad de ventas: " << cantVenta[i] << endl;
        cout << "Comisiones: " << comision[i];
        cout << endl;
    }
    cout << "Ganancias generadas con las viandas de carne: " << totalC << endl;
    cout << "Ganancias generadas con las viandas de verduras: " << totalV << endl;
    cout << "Ganancias generadas con las viandas de pescado: " << totalP << endl;
    cout << "Ganancias generadas con las viandas de fruta: " << totalF << endl;
    cout << "Cantidad de ventas con mas de cuatro viandas: " << ventas << endl;
    return 0;
}