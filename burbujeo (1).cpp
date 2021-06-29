#include <iostream>
using namespace std;

void imprimirVector(int array[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
    return;
}

void burbujeo(int array[], int n){
    int aux = 0;
    
    for(int i = 0; i < n-1; i++) 
    {    
        for(int j = 0; j < n-i-1; j++) 
        {
            if (array[j] > array[j+1]) 
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }            
        }
        cout << "Resultado de la iteracion: ";
        imprimirVector(array, n);
    }
    return;
}

int main () {
  
    int aux = 0;
    int n = 5;
    int array[5] = {14,33,27,35,10};

    cout << "Vector desordenado: ";
    imprimirVector(array, n);

    burbujeo(array, n);

    cout << "Vector ordenado: ";
    imprimirVector(array, n);
    
 return 0;
}