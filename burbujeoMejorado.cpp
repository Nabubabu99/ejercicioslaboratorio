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

void burbujeoMejorado(int array[], int n){

    int i = 0;    
    int aux = 0;
    bool ordenado = false;

    while (i < n && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < n-i-1; j++) 
        {
            if (array[j] > array[j+1]) 
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                ordenado = false; 
            }
        }
        cout << "Resultado de la iteracion: ";
        imprimirVector(array, n);        
        i++;
    }
    return;
}

int main () {   
   
    int n = 5;
    int array[5] = {14,33,27,35,10};

    cout << "Vector desordenado: ";
    imprimirVector(array, n);

    burbujeoMejorado(array, n);

    cout << "Vector ordenado: ";
    imprimirVector(array, n);

 return 0;
}