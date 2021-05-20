#include <iostream>
#include <stdio.h>
using namespace std;

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

int main(){
    int valorFilas;
    int valorColumnas;
    float sumaValores = 0;
    float promedioValores = 0;
    int sumaColumnas = 0;
    int contador = 0;

    leer("Ingrese el numero de filas", valorFilas);
    leer("Ingrese el numero de columnas", valorColumnas);

    int MATRIZA[valorFilas][valorColumnas] = {0, 0};
    int VECSUMCOL[valorColumnas] = {0};
    int VECMAXFIL[valorFilas] = {0};

    for (int i = 0; i < valorFilas; i++)
    {
        for (int j = 0; j < valorColumnas; j++)
        {
            cout << "Ingrese el valor de la posicion (" << i << "," << j << ")" << endl;
            cin >> MATRIZA[i][j];

            if (MATRIZA[i][j] > VECMAXFIL[i])
            {
                VECMAXFIL[i] = MATRIZA[i][j];
            }   
        }
    }

    for (int i = 0; i < valorFilas; i++)
    {
        for (int j = 0; j < valorColumnas; j++)
        {
            cout << MATRIZA[i][j] << " | ";
            sumaValores += MATRIZA[i][j];
        }
        cout << endl;
    }

   for (int i = 0; i < valorColumnas; i++)
    {
        for (int j = 0; j < valorFilas; j++)
        {
            sumaColumnas += MATRIZA[j][i];
        }
        VECSUMCOL[i] += sumaColumnas;
        sumaColumnas = 0;
    }
    
    
    promedioValores = sumaValores / (valorFilas * valorColumnas);
    cout << "El promedio de los valores es de " << promedioValores << endl;

    for (int i = 0; i < valorColumnas; i++)
    {
        cout << VECSUMCOL[i] << " | ";
    }

    cout << endl;

    for (int i = 0; i < valorFilas; i++)
    {
        cout << "Valor maximo de la fila " << i + 1 << ": " << VECMAXFIL[i] << endl;
    }

    return 0;
}