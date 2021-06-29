#include <iostream>
#include <stdio.h>
using namespace std;

struct LibroLocal
{
    int codLibro;
    string autor;
    int stock;
    string tituloLibro;
    string editorial;
    string genero;
};

struct LibroDeposito
{
    int codLibro;
    int stock;
};

void ordenarMostrarLibros(LibroLocal stockEnLocal[], int cantLibros, LibroDeposito stockEnDeposito[]){
    int i = 0;    
    LibroLocal aux;
    LibroDeposito aux2;
    bool ordenado = false;
    int cantLibrosEnFalta = 0;

    while (i < cantLibros && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantLibros-i-1; j++) 
        {
            if (stockEnLocal[j].codLibro > stockEnLocal[j+1].codLibro) 
            {
                aux = stockEnLocal[j];
                stockEnLocal[j] = stockEnLocal[j+1];
                stockEnLocal[j+1] = aux;
                ordenado = false; 
            }
        }      
        i++;
    }

    i = 0;
    ordenado = false;

    while (i < cantLibros && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantLibros-i-1; j++) 
        {
            if (stockEnDeposito[j].codLibro > stockEnDeposito[j+1].codLibro) 
            {
                aux2 = stockEnDeposito[j];
                stockEnDeposito[j] = stockEnDeposito[j+1];
                stockEnDeposito[j+1] = aux2;
                ordenado = false; 
            }
        }      
        i++;
    }

    cout << "     Libros Faltantes" << endl;
    cout << "Codigo     |      Observacion" << endl;

    for (int i = 0; i < cantLibros; i++)
    {
        if (stockEnLocal[i].stock == 0 && stockEnDeposito[i].stock == 0)
        {
            cout << stockEnLocal[i].codLibro << "        Falta en local y deposito" << endl;
        }
        else if (stockEnLocal[i].stock == 0)
        {
            cout << stockEnLocal[i].codLibro << "        Falta en local" << endl;
        }
        else if (stockEnDeposito[i].stock == 0)
        {
            cout << stockEnDeposito[i].codLibro << "        Falta en deposito" << endl;
        }
    }
    
}

int main(){
    int cantLibros = 4;
    LibroLocal libroLocal;
    LibroLocal stockEnLocal[cantLibros] = {
        {1540, "Jorge", 5, "Obras Ocultas", "Alta Edicion", "Misterio"},
        {1122, "Jose", 0, "La Pepa Pog", "Alta Edicion", "Infantiles"},
        {940, "Ruperto", 0, "Lola la niña", "Alta Edicion", "Terror"},
        {1840, "Tolito", 2, "Cosas pa cocinar", "Alta Edicion", "Cocina"}
    };
    LibroDeposito libroDeposito;
    LibroDeposito stockEnDeposito[cantLibros] = {
        {1540, 15},
        {1122, 0},
        {940, 155},
        {1840, 0}
    };

    ordenarMostrarLibros(stockEnLocal, cantLibros, stockEnDeposito);

    return 0;
}