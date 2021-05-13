#include <iostream>
#include <stdio.h>
using namespace std;

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

int main(){
    int valorIngresado;
    
    leer("Ingrese un valor", valorIngresado);

    int conjuntoA[valorIngresado] = {0};
    int conjuntoB[valorIngresado] = {0};
    int conjuntoC[valorIngresado] = {0};

    for (int i = 0; i < valorIngresado; i++)
    {
        cout << "Ingrese un valor para la posicion " << i << " del conjunto A" << endl;
        cin >> conjuntoA[i];
    }
    for (int i = 0; i < valorIngresado; i++)
    {
        cout << "Ingrese un valor para la posicion " << i << " del conjunto B" << endl;
        cin >> conjuntoB[i];
    }
    
    for (int i = 0; i < valorIngresado; i++)
    {
        conjuntoC[i] = conjuntoA[i] + conjuntoB[valorIngresado - 1 - i];
    }
    
    for (int i = 0; i < valorIngresado; i++)
    {
        cout << "Posicion " << i << "= " << conjuntoC[i] << endl;
    }

    return 0;
}