/*
Yumee Chung
A01712059

shop.h es para guardar los métodos para crear dulce, agregar dulce, mostrar dulce
ordenar la caloría y ordenar el origen de los dulces. 
*/
#ifndef SHOP_H_
#define SHOP_H_

#include <string>
#include <iostream>
#include <sstream>
#include "candy.h"

using namespace std;

const int MAX = 1000;

class Shop {
private:
    Candy* can[MAX];
    int ven;

public:
    Shop() : ven(0) {}

    void crea_dulce();
    void muestra_dulce();
    void agrega_dulce(int calorie, string name, string origin);
    void sort_calorie();
    void sort_origin();
};

void Shop::crea_dulce() {
    can[ven] = new Candy(50, "Sour Patch", "Canadá");
    ven++;
    can[ven] = new Candy(98, "Carlos V", "México");
    ven++;
    can[ven] = new Candy(46, "Chupa Chups", "España");
    ven++;
    can[ven] = new Candy(100, "HARIBO Goldbears", "Alemania");
    ven++;
}

void Shop::muestra_dulce() {
    for (int i = 0; i < ven; i++)
        cout << can[i]->to_string() << endl;
}

void Shop::agrega_dulce(int calorie, string name, string origin) {
    can[ven] = new Candy(calorie, name, origin);
    ven++;
}

//Ordena la caloría en orden ascendente
//Bubble Sort
void Shop::sort_calorie() {
    for (int i = 0; i < ven - 1; i++) {  //ciclo externo: recorre hasta el tamaño-1 del arreglo
        for (int j = 0; j < ven - i - 1; j++) { //ciclo interno: compara el valor con todos los valores y busca el lugar correspondiente
            if (can[j]->get_cal() > can[j + 1]->get_cal()) { //si la caloría es menor que el siguiente caloría
                Candy* temp = can[j]; //realiza este intercambio guardando el valor [j] en variable temp
                can[j] = can[j + 1]; //igualamos j con el siguiente j+1
                can[j + 1] = temp;  //guarda j+1 en el variable temp
            }
        }
    }
}

//Ordena el país del origen en orden alfabético ascendente
//Bubble Sort
void Shop::sort_origin() {
    for (int i = 0; i < ven - 1; i++) { //ciclo externo: recorre hasta el tamaño-1 del arreglo
        for (int j = 0; j < ven - i - 1; j++) { //ciclo interno: compara el valor con todos los valores y busca el lugar correspondiente
            if (can[j]->get_origin() > can[j + 1]->get_origin()) { //si el alfabeto origen es menor que el siguiente alfabeto origen
                Candy* temp = can[j]; //realiza este intercambio guardando el valor [j] en variable temp
                can[j] = can[j + 1]; //igualamos j con el siguiente j+1
                can[j + 1] = temp; //guarda j+1 en el variable temp
            }
        }
    }
}

#endif
