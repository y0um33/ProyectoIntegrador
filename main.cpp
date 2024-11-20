#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype> 
#include "shop.h"
#include "employee.h"

using namespace std;

int main(int argc, char *argv[]){
    Emplist<string> d1;
    int opcion = 22;
    int answer = 33;
    int respo = 44;
    int index;
    int int_cal = 0;
    string temp_nombre;
    string temp_cal;
    string temp_ori;
    string nomb;
    bool verifDato = true;

    Shop tienda;
    tienda.crea_dulce("dulces.csv");

    d1.insertion("Juan");
    d1.insertion("David");
    d1.insertion("Leticia");

    while (opcion != 0){

        cout << "BIENVENIDOS A NUESTRA DULCERÍA" << endl;
        cout << "Si eres cliente ingresa número 1" << endl;
        cout << "Si eres nuestro staff ingresa número 2" << endl;
        cout << "Si quieres salir ingresa número 0" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1){

            cout << "Gracias por visitar nuestra dulcería." << endl;
            cout << "Estos son los dulces disponibles: " << endl;
            tienda.muestra_dulce();
            cout << "Si quieres ordenar pos caloría (menor a mayor) ->" << endl;
            cin >> answer;
            if(answer == 1){
                tienda.mergeSort();
                cout << "Ordenado por caloría: " << endl;
                cout << endl;
                tienda.muestra_dulce();
            }

        } else if (opcion == 2){

            cout << "Bienvenido, ¿Cuál servicio quieres realizar?" << endl;
            cout << "Agregar productos -> 1" << endl;
            cout << "Agregar empleados -> 2" << endl;
            cout << "Eliminar empleados -> 3" << endl;
            cin >> respo;

            if (respo == 1){

                while (verifDato){

                    cout << "Nombre de dulce (INGRESA SÓLO EL NOMBRE DEL DULCE): ";
                    cin >> temp_nombre;

                    cout << "Orgien de dulce (INGRESA SÓLO EL PÁIS (Si es Estados Unidos, escribir como -EstadosUnidos- (juntos, sin espacio))): ";
                    cin >> temp_ori;

                    if(temp_nombre.empty() || temp_ori.empty()){
                        cout << "Porfavor ingresa un nombre/origen adecuado para el dulce" << endl;
                        continue;
                    } 
                    
                    cout << "Caloría (INGRESA SÓLO NÚMEROS ENTEROS): ";
                    cin >> temp_cal;
                    if (temp_cal.empty()){
                        cout << "Por favor ingresa una caloría adecuada para el dulce" << endl;
                        continue;
                    } else if(!all_of(temp_cal.begin(), temp_cal.end(), [](char c){return isdigit(c);})){
                        cout << "Por favor ingresa un NÚMERO, LEE LAS INSTRUCCIONES" << endl;
                        continue;
                    } else{
                        int_cal = atoi(temp_cal.c_str());
                    }

                    verifDato = false;
                }

                if (verifDato == false){
                    tienda.agrega_dulce(int_cal, temp_nombre, temp_ori);
                    cout << endl;
                    cout << "Lista de dulces modificada: " << endl;
                    tienda.muestra_dulce();
                    verifDato = true;
                }

            } 

            else if (respo == 2){

                cout << "Ingresa el nombre del empleado que quieres agregar (SOLO EL NOMBRE): " << endl;
                cin >> nomb;
                d1.insertion(nomb);
                cout << "Ya se agregó" << endl;
                cout << d1.toString() << endl;

            } 
            
            else if (respo == 3){
                cout << "Lista de empleados: " << endl;
                cout << d1.toString(); 
                cout << endl;
                cout << "Ingresa el número del empleado que quieres eliminar (EL ORDEN QUE ESTÁ REGISTRADO EL EMPLEADO): " << endl;
                cin >> index; // El índice del objeto dentro de la lista
                if (index >= 0 && index < d1.getSize()){

                    d1.deleteAt(index);
                    cout << "Ya se eliminó" << endl;
                    cout << "Lista de empleados actualizada: " << endl;
                    cout << d1.toString();
                    cout << endl;

                } else if (cin.fail()){

                    cout << "Ingresa un índice válido, NÚMERO" << endl;

                }

            } 

            else if (cin.fail()){
                cout << "Porfavor ingresa un valor adecuado como indica en las instrucciones" << endl;

            } 

            else {
                
                cout << "Opción inválido" << endl;
            }

        } 
        
        else if (opcion == 0){
            cout << "Gracias por su visita :)" << endl;
        } 

        else if(cin.fail()){
            cout << "UH-OH opción inválida" << endl;
        } 
        
        else{
            cout << "No existe esa opción" << endl;
        }
    }
}
