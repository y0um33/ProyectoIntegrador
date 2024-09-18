#include <iostream>
#include <sstream>
#include "shop.h"

using namespace std;

int main(int argc, char * argv[]) {
    int opcion = 22;
    int answer = 33;
    Shop tienda;
    tienda.crea_dulce();

    while(opcion != 0){
        cout << "BIENVENIDOS A NUESTRA DULCERÍA" << endl;
        cout << "Si eres cliente ingresa número 1" << endl;
        cout << "Si eres nuestro staff ingresa número 2" << endl;
        cout << "Si quieres salir ingresa nújmero 0" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1){
            cout << "Gracias por visitar a nuestra dulcería." << endl;
            cout << "Estos son los dulces disponibles: " << endl;
            tienda.muestra_dulce();
            cout << "Ordenar por caloría(menor a mayor) -> 1" << endl;
            cout << "Ordenar por origen(Alfabéticamente A->Z) -> 2" << endl;
            cin >> answer;
            if(answer == 1){
                tienda.sort_calorie();
                cout << "Ordenado por caloría: " << endl;
                tienda.muestra_dulce();
            }
            else if (answer == 2){
                tienda.sort_origin();
                cout << "Ordenado por país: " << endl;
                tienda.muestra_dulce();
            }
        }
        if (opcion == 2){ //no he terminado
            
        }
    }

    if (opcion == 0){
            cout << "Gracias por su visita :)" << endl;
    }

};

