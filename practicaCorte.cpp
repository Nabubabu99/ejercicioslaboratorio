#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_GRUPOS 10

struct Grupo
{
    string nombre;
    int cantidad;
};

void cargarGrupos(Grupo grupos[], int &cantGrupos);
void leer(string mensaje, string &valor);
void leer(string mensaje, int &valor);
void mostrarGrupos(Grupo grupos[], int cantGrupos);
void ordenarGrupos(Grupo grupos[], int cantGrupos);

int main(){
    int cantGrupos = 0;
    Grupo grupos[MAX_GRUPOS];

    cargarGrupos(grupos, cantGrupos);
    mostrarGrupos(grupos, cantGrupos);

    return 0;
}

void cargarGrupos(Grupo grupos[], int &cantGrupos){

    leer("\nIngrese el nombre del grupo", grupos[cantGrupos].nombre);

    while (grupos[cantGrupos].nombre != "F")
    {
        leer("Ingrese la cantidad de beneficiarios", grupos[cantGrupos].cantidad);
        cout << "\nCargue otro grupo o ingrese F para salir" << endl;
        cantGrupos++;
        leer("\nIngrese el nombre del grupo", grupos[cantGrupos].nombre);
    }   
}

void mostrarGrupos(Grupo grupos[], int cantGrupos){
    ordenarGrupos(grupos, cantGrupos);
    cout << "Grupo\t\tBeneficiarios" << endl;
    for (int i = 0; i < cantGrupos; i++)
    {
        cout << grupos[i].nombre << "\t\t" << grupos[i].cantidad << endl;
    }
    
}

void ordenarGrupos(Grupo grupos[], int cantGrupos){
    int i = 0;    
    Grupo aux;
    bool ordenado = false;

    while (i < cantGrupos && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantGrupos-i-1; j++) 
        {
            if (grupos[j].cantidad > grupos[j+1].cantidad) 
            {
                aux = grupos[j];
                grupos[j] = grupos[j+1];
                grupos[j+1] = aux;
                ordenado = false; 
            }
        }       
        i++;
    }
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;
}