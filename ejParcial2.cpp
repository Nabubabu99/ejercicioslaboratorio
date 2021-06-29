#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int largo;
    int aux;
    int sumatoria = 0;
    int sumatoriaDiag = 0;
    int sumatoriaDiagInv = 0;
    bool esMagico = false;

    cout << "Ingrese el largo de la matriz: " << endl;
    cin >> largo;

    int constMagica = (largo * (largo * largo + 1 )) / 2;
    int cuboMagico[largo][largo] = {0};

    // Cargar cubo
    for (int i = 0; i < largo; i++)
    {
        for (int j = 0; j < largo; j++)
        {
            cout << "Ingrese el valor de [" << i << "]-[" << j << "]" << endl;
            cin >> cuboMagico[i][j];
        }
    }

    for (int i = 0; i < largo; i++)
    {
        sumatoria = 0;
        for (int j = 0; j < largo; j++)
        {
            sumatoria += cuboMagico[i][j];
            if (i == j)
            {
                sumatoriaDiag += cuboMagico[i][j];
            }

            if (j == largo-i)
            {
                sumatoriaDiagInv += cuboMagico[i][j];
            } 
        }
        if (sumatoria == constMagica)
        {
            esMagico = true;
        }
    }

    if (sumatoriaDiag == constMagica)
    {
        esMagico = true;
    }

    if (sumatoriaDiagInv == constMagica)
    {
        esMagico = true;
    }

    for (int i = 0; i < largo; i++)
    {
        for (int j = 0; j < largo; j++)
        {
            cout << "\t|" << cuboMagico[i][j] << "|";
        }
        cout << endl;
    }

    if (esMagico == true)
    {
        cout << "Es magico y su constante es " << constMagica << endl;
    }
    else{
        cout << "No es magico" << endl;
    }
    
    return 0;
}