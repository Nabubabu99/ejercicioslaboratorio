#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_ANIOS 10
#define MAX_DISCOS 1000
#define MAX_BANDAS 100
#define CANT_BANDAS 5

struct Venta
{
    string idDisco;
    int cantDiscos;
};

struct Disco
{
    string idDisco;
    string nombreDisco;
    int idBanda;
    string nombreBanda;
};

struct VentasXBanda
{
    string nombre;
    int ventas;
};


int buscarBin(Disco discos[], int numDiscos, string idDisco);
void ordenarXNombre(VentasXBanda ventasBandas[], int cant);
void imprimir(VentasXBanda ventaBandas[], int cant);

int main(){
    Venta ventasAnio[MAX_ANIOS][MAX_DISCOS] = {
        {
            {"PORTA01", 1000},
            {"LYTOS01", 1500},
            {"DANTE01", 1250},
            {"PORTA02", 1750}
        },
        {
            {"BLAKE01", 1300},
            {"BABI01", 1800},
            {"DANTE02", 1250},
            {"LYTOS02", 1950}
        },
        {
            {"PORTA01", 1000},
            {"LYTOS02", 1500},
            {"BLAKE01", 1250},
            {"BABI02", 1750}
        },
        {
            {"BABI01", 1000},
            {"LYTOS01", 1500},
            {"BLAKE02", 1250},
            {"PORTA02", 1750}
        }
    };
    Disco discos[MAX_DISCOS];
    VentasXBanda ventasBandas[CANT_BANDAS] = {0};
    int numDiscos = 10;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Venta venta = ventasAnio[i][j];
            int pos = buscarBin(discos, numDiscos, venta.idDisco);
            Disco disco = discos[pos];
            ventasBandas[disco.idBanda - 1].ventas += venta.cantDiscos;
            ventasBandas[disco.idBanda].nombre = disco.nombreBanda;
        }
    }

    ordenarXNombre(ventasBandas, CANT_BANDAS);
    imprimir(ventasBandas, CANT_BANDAS);

    return 0;
}

int buscarBin(Disco discos[], int numDiscos, string idDisco){
    int inicio = 0;
    int fin = numDiscos-1;
    int medio = 0;

    while (inicio <= fin)
    {
        medio = inicio + (fin - inicio) / 2;

        if (discos[medio].idDisco == idDisco)
        {
            return discos[medio].idBanda;
        }

        if (discos[medio].idDisco > idDisco)
        {
            fin = medio - 1;
        }
        else{
            inicio = medio + 1;
        }
    }
}

void ordenarXNombre(VentasXBanda ventasBandas[], int cant){
    int i = 0;    
    VentasXBanda aux;
    bool ordenado = false;

    while (i < cant && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cant-i-1; j++) 
        {
            if (ventasBandas[j].nombre > ventasBandas[j+1].nombre) 
            {
                aux = ventasBandas[j];
                ventasBandas[j] = ventasBandas[j+1];
                ventasBandas[j+1] = aux;
                ordenado = false; 
            }
        }     
        i++;
    }
}

void imprimir(VentasXBanda ventaBandas[], int cant){

    cout << "Banda\t\tVentas" << endl;
    for (int i = 0; i < cant; i++)
    {
        cout << ventaBandas[i].nombre << "\t\t" << ventaBandas[i].ventas << endl;
    }
}