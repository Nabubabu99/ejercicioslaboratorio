#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int valorIngresado;
    int sumaDiagPrin = 0;
    int sumaDiagSecu = 0;
    int sumaCuarto1 = 0;
    int sumaCuarto2 = 0;
    int sumaCuarto3 = 0;
    int sumaCuarto4 = 0;
    int sumaTrianSup = 0;
    int sumaTrianInf = 0;

    cout << "Ingrese un valor" << endl;
    cin >> valorIngresado;

    int CUADRADA[valorIngresado][valorIngresado] = {0};

    for (int i = 0; i < valorIngresado; i++)
    {
        for (int j = 0; j < valorIngresado; j++)
        {
            cout << "Ingrese el valor de la posicion (" << i << ", " << j << ")" << endl;
            cin >> CUADRADA[i][j];
        }
    }

    // a)
    for (int i = 0; i < valorIngresado; i++)
    {
        for (int j = 0; j < valorIngresado; j++)
        {
            cout << CUADRADA[i][j] << " | ";
        }
        cout << endl;
    }

    for (int i = 0; i < valorIngresado; i++)
    {
        for (int j = 0; j < valorIngresado; j++)
        {
            if (i == j)
            {
                sumaDiagPrin += CUADRADA[i][j];
            }
            if (i + j == valorIngresado-1){
                sumaDiagSecu += CUADRADA[i][j];
            }
        }
    }

    if (sumaDiagPrin > sumaDiagSecu)
    {
        for (int i = 0; i < valorIngresado; i++)
        {
            for (int j = 0; j < valorIngresado; j++)
            {
                if (i == j)
                {
                    cout << "Elemento de la diagonal principal " << CUADRADA[i][j] << endl;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < valorIngresado; i++)
        {
            for (int j = 0; j < valorIngresado; j++)
            {
                if (i + j == valorIngresado-1){
                    cout << "Elemento de la diagonal secundaria " << CUADRADA[i][j] << endl;
                }
            }
        }
    }

    // b)
    for (int i = 0; i < valorIngresado; i++)
    {
        for (int j = 0; j < valorIngresado; j++)
        {
            if (i <= valorIngresado/2 && j <= valorIngresado/2)
            {
                sumaCuarto1 += CUADRADA[i][j];
            }
            else if (i <= valorIngresado/2 && j >= valorIngresado/2)
            {
                sumaCuarto2 += CUADRADA[i][j];
            }
            else if (i >= valorIngresado/2 && j <= valorIngresado/2)
            {
                sumaCuarto3 += CUADRADA[i][j];
            }
            else
            {
                sumaCuarto4 += CUADRADA[i][j];
            }
        }
    }

    for (int i = 0; i < valorIngresado; i++)
        {
            for (int j = 0; j < valorIngresado; j++)
        {
            if(sumaCuarto1 > sumaCuarto2 && sumaCuarto1 > sumaCuarto3 && sumaCuarto1 > sumaCuarto4){
                if (i < valorIngresado/2 && j < valorIngresado/2)
                {
                    cout << "Elementos del cuarto mayor " << CUADRADA[i][j] << endl;
                }
            }
            else if (sumaCuarto2 > sumaCuarto1 && sumaCuarto2 > sumaCuarto3 && sumaCuarto2 > sumaCuarto4)
            {
                if (i < valorIngresado/2 && j >= valorIngresado/2)
                {
                    cout << "Elementos del cuarto mayor " << CUADRADA[i][j] << endl;
                }
            }
            else if (sumaCuarto3 > sumaCuarto1 && sumaCuarto3 > sumaCuarto2 && sumaCuarto3 > sumaCuarto4)
            {
                if (i >= valorIngresado/2 && j < valorIngresado/2)
                {
                    cout << "Elementos del cuarto mayor " << CUADRADA[i][j] << endl;
                }
            }
            else if (sumaCuarto4 > sumaCuarto1 && sumaCuarto4 > sumaCuarto3 && sumaCuarto4 > sumaCuarto2)
            {
                if (i >= valorIngresado/2 && j >= valorIngresado/2)
                {
                    cout << "Elementos del cuarto mayor " << CUADRADA[i][j] << endl;
                }
            }
        }
    }

    // c)
    for (int i = 0; i < valorIngresado; i++)
    {
        for (int j = 0; j < valorIngresado; j++)
        {
            if (i < j)
            {
                sumaTrianSup += CUADRADA[i][j];
            }
            else if(j < i)
            {
                sumaTrianInf += CUADRADA[i][j];
            }
        }
    }

    for (int i = 0; i < valorIngresado; i++)
    {
        for (int j = 0; j < valorIngresado; j++)
        {
            if (sumaTrianSup > sumaTrianInf)
            {
                cout << "Elementos de la triangular superior " << CUADRADA[i][j] << endl;
            }
            else if(j < i)
            {
                cout << "Elementos de la triangular inferior " << CUADRADA[i][j] << endl;
            }
        }
    }

    return 0;
}