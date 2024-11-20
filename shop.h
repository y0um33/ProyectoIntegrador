/*
Yumee Chung
A01712059

shop.h es para guardar los métoddos del ordenamiento 
*/
#ifndef SHOP_H_
#define SHOP_H_

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "candy.h"

using namespace std;

class Shop {
protected:
    vector<Candy*> can;
    int ven;

    void copyArray(vector<Candy*>&, vector<Candy*>&, int, int);
    void mergeSplit(vector<Candy*>&, vector<Candy*>&, int, int);
    void mergeArray(vector<Candy*>&, vector<Candy*>&, int, int, int);

public:
    Shop() : ven(0) {}

    void crea_dulce(const string& datasheet);
    void muestra_dulce() const;
    void agrega_dulce(int calorie, string name, string origin);
    void sort_calorie();
    void mergeSort();
};

void Shop::crea_dulce(const string& datasheet) {
    ifstream archivo(datasheet);
    string linea;

    if(archivo.is_open()){
        while(getline(archivo, linea)){
            istringstream ss(linea);
            string name, origin, calStr;
            int calorie;

            if (getline(ss, calStr, ',')){
                calorie = atoi(calStr.c_str());
            }

            if(getline(ss, name, ',') && getline(ss, origin)){
                can.push_back(new Candy(calorie, name, origin));
                ven++;
            }
        }
        archivo.close();
    } else{
        cout << "Unable to open file" << endl;
    }
}

void Shop::muestra_dulce() const {
    for (const auto& candy : can)
        cout << candy->to_string() << endl;
}

void Shop::agrega_dulce(int calorie, string name, string origin) {

    can.push_back(new Candy(calorie, name, origin));
    ven++;

    std::ofstream file("dulces.csv", std::ios::app);
    if (file.is_open()) {
        file << calorie << "," << name << "," << origin << "\n";
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void Shop::copyArray(vector<Candy*> &A, vector<Candy*> &B, int low, int high){
    for(int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void Shop::mergeArray(vector<Candy*> &A, vector<Candy*> &B, int low, int mid, int high){
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high){
        if(A[i]->get_cal() < A[j]->get_cal()){
            B[k] = A[i];
            i++;
        } else{
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        for(; j <= high; j++){
            B[k++] = A[j];
        }
    } else{
        for(; i <= mid; i++){
            B[k++] = A[i];
        }
    }
}

void Shop::mergeSplit(vector<Candy*> &A, vector<Candy*> &B, int low, int high){
    int mid;

    if( (high - low) < 1){
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

/*
El ordenamiento Merge tiene un peor caso de la complejidad en el tiempo O(n log(n))
y el peor caso de la complejidad espacial O(n).
*/
void Shop::mergeSort(){
    vector<Candy*> tmp(can.size());

    mergeSplit(can, tmp, 0, can.size() - 1);
}

#endif
