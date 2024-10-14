#include <iostream>
#include <sstream>
#include "shop.h"

using namespace std;

int main(int argc, char *argv[]) {
    int opcion = 22;
    int answer = 33;
    int respo = 44;
    Shop tienda; // Asegúrate de especificar que es un vector de punteros a Candy
    tienda.crea_dulce();

    while (opcion != 0) {
        cout << "BIENVENIDOS A NUESTRA DULCERÍA" << endl;
        cout << "Si eres cliente ingresa número 1" << endl;
        cout << "Si eres nuestro staff ingresa número 2" << endl;
        cout << "Si quieres salir ingresa número 0" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Gracias por visitar nuestra dulcería." << endl;
            cout << "Estos son los dulces disponibles: " << endl;
            tienda.muestra_dulce();
            cout << "Si quieres ordenar por caloría (menor a mayor) -> 1" << endl;
            cin >> answer;
            if (answer == 1) {
                tienda.mergeSort();
                cout << "Ordenado por caloría: " << endl;
                tienda.muestra_dulce();
            }
        }

        if (opcion == 2) { // Sección para el staff
            cout << "Bienvenido, ¿Cuál servicio quieres realizar?" << endl;
            cout << "Agregar productos -> 1" << endl;
            cout << "Agregar empleados -> 2" << endl;
            cout << "Eliminar empleados -> 3" << endl;
            cin >> respo;
            if (respo == 1) {
                cout << "Función para agregar productos no implementada." << endl; 
            }
            else if (respo == 2) {
                cout << "Función para agregar empleados no implementada." << endl; 
            }
            else if (respo == 3) {
                cout << "Función para eliminar empleados no implementada." << endl; 
            }
        }
    }

    if (opcion == 0) {
        cout << "Gracias por su visita :)" << endl;
    }

    return 0; 
}
