#include <iostream>
using namespace std;

struct Cancion {
    string artista;
    string titulo;
    int duracion;
    double size;
};

void imprimirCancion(Cancion nuevaCancion[100], int cantC) {
    char n = 164;
    for(int i = 0; i < cantC; i++) {
        cout << "Cancion numero " << i+1 << endl;
        cout << "\tArtista: " << nuevaCancion[i].artista << endl;
        cout << "\tTitulo: " << nuevaCancion[i].titulo << endl;
        cout << "\tDuracion: " << nuevaCancion[i].duracion << endl;
        cout << "\tTama" << n << "o: "<< nuevaCancion[i].size << endl;
    }
}

int ingresarCancion(Cancion nuevaCancion[100]) {
    int cont = 0;
    string musico, nombre;
    int duracion, duracionTotal;
    double size;
    char n = 164;
    cout << "Ingrese el nombre del artista" << endl;
    cin >> musico;

    cout << "Ingrese el nombre de la cancion" << endl;
    cin >> nombre;

    cout << "Ingrese la duracion de la cancion(en segundos)" << endl;
    cin >> duracion;

    duracionTotal = duracion / 60;
    cout << "Ingrese el tama"<< n << "o de la cancion(en Kb)" << endl;
    cin >> size;

    Cancion cancion = {musico,nombre,duracion,size};
    nuevaCancion[cont] = cancion;
    cont++;

    return cont;
}

void buscarcancion(Cancion nuevaCancion[100], int cantC) {
    string choice;
    int idx = -1;
    int artista = 0, titulo = 0;
    cout << "Que cancion quiere buscar?" << endl;
    cin >> choice;
    for(int i = 0; i < cantC; i++) {
        if(nuevaCancion[i].artista == choice) {
            idx = i;
            artista = 1;
            break;
        }
        else if (nuevaCancion[i].titulo == choice) {
            idx = i;
            titulo = 1;
            break;
        }
    }
    if(idx == -1) cout << "No encontramos a ese artista o cancion" << endl;
    else if(artista == 1 && idx != -1) cout << "Encontramos el siguiente artista: " << nuevaCancion[idx].artista << endl;
    else cout << "Encontramos la siguiente cancion: " << nuevaCancion[idx].titulo << endl;
}

int main(void) {
    Cancion nuevaCancion[100];
    int cantC = 0, choice;
    while(1) {
    cout << "Bienvenido a Spotify, que quiere hacer?" << endl;
    cout << "1)Ver las canciones" << endl;
    cout << "2)Agregar una cancion" << endl;
    cout << "3)Buscar una cancion" << endl;
    cout << "4)Salir" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
        imprimirCancion(nuevaCancion,cantC);
        break;
        case 2:
        cantC = ingresarCancion(nuevaCancion);
        break;
        case 3:
        buscarcancion(nuevaCancion,cantC);
        break;
        case 4:
        cout << "Chau" << endl;
        return 1;
        default:
        cout << "Elija una opcion correcta" << endl;
        break;
        }
    }
    return 0;
}