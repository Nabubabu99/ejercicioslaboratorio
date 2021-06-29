#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_LIBROS 100

struct Libro
{
    int ISBN;
    string nombre;
    int categoria;
    int codAutor;
    int anioPublicacion;
};

struct Categoria{
    int codCate;
    string nombre;
};

struct Autor
{
    int codAutor;
    string nombre;
    int fechaNacimiento;
};

void mostrarLibros(Categoria categorias[], Autor autores[], Libro libros[], int cantAutores, int cantLibros);
void cargarLibros(Autor autores[], Libro libros[], int &cantLibros, int cantAutores);
int buscarAutor(string nombreAutor, Autor autores[], int cantAutores);
string buscarCategoria(Categoria categorias[], int pos);
void ordenarLibrosCod(Libro libros[], int cantLibros);
void ordenarAutoresNombres(Autor autores[], int cantAutores);
void ordenarAutoresCod(Autor autores[], int cantAutores);
void leer(string mensaje, int &valor);
void leer(string mensaje, string &valor);

int main(){
    int opcion = 1;
    int cantLibros = 0;
    int cantAutores = 3;
    int cantCategorias = 3;
    Libro libros[MAX_LIBROS];
    Autor autores[cantAutores] = {
        {3, "Jorge", 19851112},
        {2, "Maria", 19990212},
        {1, "Ruperto", 19601020}
    };
    Categoria categorias[cantCategorias] = {
        {20, "Terror"},
        {21, "Romantico"},
        {22, "Policial"}
    };

    while (opcion != 0)
    {
        cout << "Menu biblioteca" << endl;
        cout << "1. Cargar libros" << endl;
        cout << "2. Mostrar listado de libros" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cargarLibros(autores, libros, cantLibros, cantAutores);
            break;

        case 2:
            mostrarLibros(categorias, autores, libros, cantAutores, cantLibros);
            break;

        default:
            break;
        }
    }

    return 0;
}

void cargarLibros(Autor autores[], Libro libros[], int &cantLibros, int cantAutores){
    ordenarAutoresNombres(autores, cantAutores);
    ordenarLibrosCod(libros, cantLibros);
    string nombreAutor;
    int ISBN;
    cout << "Menu de carga de libros" << endl;
    cout << endl;
    leer("Ingrese el ISBN", ISBN);

    while (ISBN != 0)
    {
        libros[cantLibros].ISBN = ISBN;
        leer("Ingrese el nombre del libro", libros[cantLibros].nombre);
        leer("Ingrese la categoria", libros[cantLibros].categoria);
        leer("Ingrese el nombre del autor", nombreAutor);
        libros[cantLibros].codAutor = buscarAutor(nombreAutor, autores, cantAutores);
        leer("Ingrese el anio de publicacion", libros[cantLibros].anioPublicacion);
        cantLibros++;
        leer("Ingrese el ISBN", ISBN);
    }
    
}

void mostrarLibros(Categoria categorias[], Autor autores[], Libro libros[], int cantAutores, int cantLibros){
    ordenarAutoresCod(autores, cantAutores);
    int key;
    int i = 0;
    int j = 0;
    int cantObras = 0;
    while (i < cantAutores)
    {
        key = autores[i].codAutor;
        cantObras = 0;
        cout << endl;
        cout << "Autor: " << "<" << key << ">-<" << autores[i].nombre << ">" << endl;
        cout << "\t" << "Nombre Libro - Categoria - Anio publicacion" << endl;
        while (key == libros[j].codAutor)
        {
            cout << "\t" << libros[j].nombre << " - " <<
            buscarCategoria(categorias, libros[j].categoria) <<
            " - " << libros[j].anioPublicacion << endl;
            cantObras++;
            j++;
        }
        cout << "Cantidad de obras del autor: " << cantObras << endl;
        i++;
    }
    
}

string buscarCategoria(Categoria categorias[], int pos){
    return categorias[pos-20].nombre;
}

int buscarAutor(string nombreAutor, Autor autores[], int cantAutores){
    int inicio = 0;
    int fin = cantAutores;
    int medio = 0;

    while (inicio <= fin)
    {
        medio = inicio + (fin - inicio) / 2;

        if (autores[medio].nombre == nombreAutor)
        {
            return autores[medio].codAutor;
        }

        if (autores[medio].nombre > nombreAutor)
        {
            fin = medio - 1;
        }
        else{
            inicio = medio + 1;
        }
    }
    
    return 0;
}

void ordenarAutoresNombres(Autor autores[], int cantAutores){
    int i = 0;    
    Autor aux;
    bool ordenado = false;

    while (i < cantAutores && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantAutores-i-1; j++) 
        {
            if (autores[j].nombre > autores[j+1].nombre) 
            {
                aux = autores[j];
                autores[j] = autores[j+1];
                autores[j+1] = aux;
                ordenado = false; 
            }
        }
      
        i++;
    }
}

void ordenarAutoresCod(Autor autores[], int cantAutores){
    int i = 0;    
    Autor aux;
    bool ordenado = false;

    while (i < cantAutores && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantAutores-i-1; j++) 
        {
            if (autores[j].codAutor > autores[j+1].codAutor) 
            {
                aux = autores[j];
                autores[j] = autores[j+1];
                autores[j+1] = aux;
                ordenado = false; 
            }
        }
      
        i++;
    }
}

void ordenarLibrosCod(Libro libros[], int cantLibros){
    int i = 0;    
    Libro aux;
    bool ordenado = false;

    while (i < cantLibros && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantLibros-i-1; j++) 
        {
            if (libros[j].nombre > libros[j+1].nombre) 
            {
                aux = libros[j];
                libros[j] = libros[j+1];
                libros[j+1] = aux;
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