/*
Yumee Chung
A01712059

candy.h es para definir el objetivo tipo Candy
*/
#ifndef CANDY_H_
#define CANDY_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Candy{

    protected: //variables de instancia
        int calorie;
        string name;
        string origin;
    
    public: //Métodos
        Candy(): calorie(0), name(""), origin("") {}; //constructor por default
        Candy(int cal, string na, string ori):calorie(cal),name(na),origin(ori) {};

    //Getters
    int get_cal(){
        return calorie;
    }

    string get_name(){
        return name;
    }

    string get_origin(){
        return origin;
    }

    string to_string(); 
};

/*
to_string convierte atributos a string.

Juntan todos los valores de los atritubos en un string e imprime.

@param
@return string con los valores y textos concatenado
*/

string Candy::to_string(){
    stringstream aux;
    aux << "Producto: " << name << endl <<
    "Origen: " << origin << endl << "Caloría: " << calorie << endl;
    return aux.str();
}

#endif