
#include <iostream>
using namespace std;

void imprimirVector(int array[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return;
}

void insertionSort(int array[], int n){
    int aux, j = 0;

    for (int i = 1; i < n; i++)
    {
        aux = array[i];
        j = i - 1;
       
        while (j >= 0 && array[j] > aux)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = aux;
        cout << "Resultado de la iteracion: ";
        imprimirVector(array, n);
    }
    return;
}

int main () {
    
    int notas[8] = {4,3,2,10,12,1,5,6};    
    int n = 8;

    cout << "Vector desordenado: ";
    imprimirVector(notas, n);

    insertionSort(notas, n);

    cout << "Vector ordenado: ";
    imprimirVector(notas, n);

 return 0;
}