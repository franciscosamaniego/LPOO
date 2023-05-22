#include <iostream>
using namespace std;

struct Cancion {
    string artista;
    string titulo;
    int duracion;
    double size;
};

int main(void) {
    string musico;
    string nombre;
    int duracion, duracionTotal;
    double size;

    cout << "Ingrese el nombre del artista" << endl;
    cin >> musico;

    cout << "Ingrese el nombre de la cancion" << endl;
    cin >> nombre;

    cout << "Ingrese la duracion de la cancion(en segundos)" << endl;
    cin >> duracion;

    cout << "Ingrese el tamano de la cancion(en Kb)" << endl;
    cin >> size;

    Cancion cancion = {musico,nombre,duracion,size};

    cout << cancion.artista << endl << cancion.titulo << endl << cancion.duracion << endl << cancion.size << endl;
    return 0;
}