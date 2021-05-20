#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int filas = 5;
    int columnas = 4;
    int contador = 1;
    int matriz[filas][columnas] = {0, 0};
    int array[20];

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = contador;
            cout << matriz[i][j] << " | ";

            array[contador-1] = matriz[i][j];

            contador++;
        }
        cout << endl;
    }

    for (int i = 0; i < contador-1; i++)
    {
        cout << array[i] << " | ";
    }
    
    return 0;
}
/* #include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int filas = 5;
    int columnas = 4;
    int contador = 1;
    int matriz[filas][columnas] = {0, 0};
    int arrayDe20[20];

    for (int i = 0; i < filas; i++)
    {
        contador = 1 + i;
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = contador;
            contador = contador + 5;
            cout << matriz[i][j] << " | ";
        }
        cout << endl;
    }
    
    return 0;
} */