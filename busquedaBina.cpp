#include <iostream>
#include <stdio.h>
using namespace std;

// Acordate de arrays ordenados -.-

int main(){
    int inicio = 0;
    int fin = 9;
    int medio = 0;
    int miArray[10];
    int numBuscado;

    for (int i = 0; i < 10; i++)
    {
        miArray[i] = i + 1;
    }

    cout << "Indique el numero a buscar" << endl;
    cin >> numBuscado;

    while (inicio <= fin)
    {
        medio = inicio + (fin - inicio) / 2;

        if (miArray[medio] == numBuscado)
        {
            cout << "El numero buscado esta en la posicion " << medio << endl;
        }

        if (miArray[medio] > numBuscado)
        {
            fin = medio - 1;
        }
        else{
            inicio = medio + 1;
        }
    }
    
    return 0;
}