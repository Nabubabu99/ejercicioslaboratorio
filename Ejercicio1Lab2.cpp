#include <iostream>
#include <stdio.h>
using namespace std;

void leer(string mensaje, int &valor);
void burbujeo(int numUsuario[], int cantNumIngresar, int &cantIterBurbu);
void burbujeoMejorado(int numUsuarioMejor[], int cantNumIngresar, int &cantIterBurbuMejor);

int main(){
    int cantNumIngresar = 5;
    int numUsuario[cantNumIngresar] = {0};
    int numUsuarioMejor[cantNumIngresar] = {0};
    int cantIterBurbu = 0;
    int cantIterBurbuMejor = 0;
    
    for (int i = 0; i < cantNumIngresar; i++)
    {  
        cout << i+1 << "- ";
        leer("Ingrese un numero", numUsuario[i]);
        numUsuarioMejor[i] = numUsuario[i];
    }

    burbujeo(numUsuario, cantNumIngresar, cantIterBurbu);
    burbujeoMejorado(numUsuarioMejor, cantNumIngresar, cantIterBurbuMejor);

    cout << "Elementos ordenados" << endl;

    for (int i = 0; i < cantNumIngresar; i++)
    {
        cout << numUsuario[i] << endl;
    }
    
    cout << "Se usaron " << cantIterBurbu << " iteraciones para el burbujeo y " << cantIterBurbuMejor << " iteraciones para el burbujeo mejorado" << endl;
    
    return 0;
}

void burbujeo(int numUsuario[], int cantNumIngresar, int &cantIterBurbu){
    int aux = 0;
    
    for(int i = 0; i < cantNumIngresar-1; i++) 
    {    
        for(int j = 0; j < cantNumIngresar-i-1; j++) 
        {
            if (numUsuario[j] > numUsuario[j+1]) 
            {
                aux = numUsuario[j];
                numUsuario[j] = numUsuario[j+1];
                numUsuario[j+1] = aux;
            }            
        }
        cantIterBurbu++;
    }
}

void burbujeoMejorado(int numUsuarioMejor[], int cantNumIngresar, int &cantIterBurbuMejor){
    int i = 0;    
    int aux = 0;
    bool ordenado = false;

    while (i < cantNumIngresar && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantNumIngresar-i-1; j++) 
        {
            if (numUsuarioMejor[j] > numUsuarioMejor[j+1]) 
            {
                aux = numUsuarioMejor[j];
                numUsuarioMejor[j] = numUsuarioMejor[j+1];
                numUsuarioMejor[j+1] = aux;
                ordenado = false;
            }
        }    
        cantIterBurbuMejor++;
        i++;
    }
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}