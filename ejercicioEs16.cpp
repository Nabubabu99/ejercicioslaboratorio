#include <iostream>
#include <stdio.h>
using namespace std;

struct Venta
{
    int legajo;
    int idTelefono;
    int cantVendida;
    int diaVenta;
};

struct Promotor
{
    int legajo;
    string nombre;
    float porcentaje;
};

struct Telefono
{
    int idTelefono;
    string descripcion;
    int precio;
};

void obtenerComision(Promotor promotores[], int cantPromotores, Venta ventas[], int numVentas, Telefono telefonos[], int numTelefonos);
void promotoresNoVendieron(Promotor promotores[], int cantPromotores, Venta ventas[], int numVentas, Telefono telefonos[], int numTelefonos);
int buscarCantidad(Venta ventas[], int numVentas, int buscado);
void burbujeoMejorado(Venta ventas[], int numVentas);

int main(){
    int numTelefonos = 10;
    Telefono telefonos[numTelefonos] = {
        {1, "Rojo y negro", 25000},
        {2, "Con tapita", 75000},
        {3, "Blanco", 55500},
        {4, "De River(?", 28000},
        {5, "Colorao", 17000},
        {6, "Fino", 46500},
        {7, "Dorado", 125000},
        {8, "Buenardo", 15000},
        {9, "De lolsito", 37000},
        {10, "De Maicra", 75300}
    };
    int numVentas = 10;
    Venta ventas[numVentas] = {
        {1, 1, 5, 10},
        {3, 2, 2, 12},
        {4, 1, 0, 15},
        {5, 2, 3, 17},
        {2, 1, 15, 21},
        {3, 5, 0, 22},
        {4, 7, 8, 23},
        {2, 9, 15, 27},
        {5, 8, 25, 25},
        {2, 10, 7, 28}
    };
    int cantPromotores = 5;
    Promotor promotores[cantPromotores] = {
        {1, "Babu", 0.10},
        {2, "Facu", 0.20},
        {3, "Karu", 0.30},
        {4, "Ruperto", 0.40},
        {5, "Jorge", 0.50}
    };

    obtenerComision(promotores, cantPromotores, ventas, numVentas, telefonos, numTelefonos);

    return 0;
}

void obtenerComision(Promotor promotores[], int cantPromotores, Venta ventas[], int numVentas, Telefono telefonos[], int numTelefonos){
    float sumaComision = 0;
    int masVendido = 0;
    int posMasVendido = 0;
    int masVendidoTodos = 0;
    int posMasVendidoTodos = 0;
    for (int i = 0; i < cantPromotores; i++)
    {
        for (int j = 0; j < numVentas; j++)
        {
            if (promotores[i].legajo == ventas[j].legajo)
            {
                sumaComision += (telefonos[ventas[j].idTelefono - 1].precio * ventas[j].cantVendida) * promotores[i].porcentaje;
                if (ventas[j].cantVendida > masVendido)
                {
                    masVendido = ventas[j].cantVendida;
                    posMasVendido = ventas[j].idTelefono;
                }

                if (ventas[j].cantVendida > masVendidoTodos)
                {
                    masVendidoTodos = ventas[j].cantVendida;
                    posMasVendidoTodos = ventas[j].idTelefono;
                }
            }
        }

        cout << "\nLa comision de " << promotores[i].nombre << " es de $" << sumaComision << endl;
        cout << "Descripcion del mas vendido: " << telefonos[posMasVendido - 1].descripcion << endl;

        sumaComision = 0;
        masVendido = 0;
        posMasVendido = 0;
    }

    cout << "\nDescripcion del mas vendido entre todos los promotores: " << telefonos[posMasVendidoTodos - 1].descripcion << endl;
    promotoresNoVendieron(promotores, cantPromotores, ventas, numVentas, telefonos, numTelefonos);
}

void promotoresNoVendieron(Promotor promotores[], int cantPromotores, Venta ventas[], int numVentas, Telefono telefonos[], int numTelefonos){
    for (int i = 0; i < numTelefonos; i++)
    {
        cout << "Promotores que no vendieron el telefono de id-" << telefonos[i].idTelefono << endl;
        for (int j = 0; j < numVentas; j++)
        {
            if (buscarCantidad(ventas, numVentas, telefonos[i].idTelefono) == -1 || ventas[j].cantVendida == 0)
            {
                cout << promotores[ventas[j].legajo -1].nombre << endl;
            }
        }
    }
}

int buscarCantidad(Venta ventas[], int numVentas, int buscado){
    burbujeoMejorado(ventas, numVentas);
    int inicio = 0;
    int fin = numVentas-1;
    int medio = 0;

    while (inicio <= fin)
    {
        medio = inicio + (fin - inicio) / 2;

        if (ventas[medio].idTelefono == buscado)
        {
            return 1;
        }

        if (ventas[medio].idTelefono > buscado)
        {
            fin = medio - 1;
        }
        else{
            inicio = medio + 1;
        }
    }
    
    return -1;
}

void burbujeoMejorado(Venta ventas[], int numVentas){
    int i = 0;    
    Venta aux;
    bool ordenado = false;

    while (i < numVentas && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < numVentas-i-1; j++) 
        {
            if (ventas[j].idTelefono > ventas[j+1].idTelefono) 
            {
                aux = ventas[j];
                ventas[j] = ventas[j+1];
                ventas[j+1] = aux;
                ordenado = false; 
            }
        }  
        i++;
    }
    return;
}