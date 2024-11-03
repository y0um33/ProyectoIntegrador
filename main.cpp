#include <iostream>
#include <sstream>
#include <fstream>
#include "shop.h"
#include "employee.h"

using namespace std;

int main(int argc, char *argv[]) {
    Emplist<string> d1;
    int opcion = 22;
    int answer = 33;
    int respo = 44;
    int index;
    string temp_nombre;
    int temp_cal;
    string temp_ori;
    string nomb;

    Shop tienda;
    tienda.crea_dulce("dulces.csv");

    //Agregar en la lista los empleados
    d1.insertion("Juan");
    d1.insertion("David");
    d1.insertion("Leticia");

    while (opcion != 0) {
        cout << "BIENVENIDOS A NUESTRA DULCERÍA" << endl;
        cout << "Si eres cliente ingresa número 1" << endl;
        cout << "Si eres nuestro staff ingresa número 2" << endl;
        cout << "Si quieres salir ingresa número 0" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) { // Sección para el cliente
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
        } else if (opcion == 2) { // Sección para el staff
            cout << "Bienvenido, ¿Cuál servicio quieres realizar?" << endl;
            cout << "Agregar productos -> 1" << endl;
            cout << "Agregar empleados -> 2" << endl;
            cout << "Eliminar empleados -> 3" << endl;
            cin >> respo;

            if (respo == 1) { // Agregar en el archivo dulces.csv
                cout << "Nombre de dulce: " << ' ';
                cin >> temp_nombre;
                cout << "Caloría: " << ' ';
                cin >> temp_cal;
                cout << "Origen: " << ' ';
                cin >> temp_ori;
                tienda.agrega_dulce(temp_cal, temp_nombre, temp_ori);
                cout << endl;
                cout << "Lista de dulces modificada: " << endl;
                tienda.muestra_dulce();
            } else if (respo == 2) { // Insertar en la lista
                cout << "Ingresa el nombre del empleado que quieres agregar (SOLO EL NOMBRE): " << endl;
                cin >> nomb;
                d1.insertion(nomb);
                cout << "Ya se agregó" << endl;
                cout << d1.toString() << endl; 
            } else if (respo == 3) { // Eliminar en la lista
                cout << "Lista de empleados: " << endl;
                cout << d1.toString(); 
                cout << endl;
                cout << "Ingresa el número del empleado que quieres eliminar (EL ORDEN QUE ESTÁ REGISTRADO EL EMPLEADO): " << endl;
                cin >> index; //El índice del objeto dentro de la lista

                if (index >= 0 && index < d1.getSize()) {
                    d1.deleteAt(index);
                    cout << "Ya se eliminó" << endl;
                    cout << "Lista de empleados actualizada: " << endl;
                    cout << d1.toString();
                    cout << endl;
                } else {
                    cout << "Índice inválido." << endl;
                }
            } else {
                cout << "Oops no sé qué quieres hacer :(" << endl;
            }
        } else if(cin.fail()){
                cout << "UH-OH opción inválida" << endl;
        }
    }

    if (opcion == 0) {
        cout << "Gracias por su visita :)" << endl;
    } 

    return 0; 
}
