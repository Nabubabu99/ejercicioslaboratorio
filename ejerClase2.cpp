#include <iostream>
#include <stdio.h>
using namespace std;

struct ST_CURSO{
    string nombre;
    int cantidadDeHoras;
    int carrera;
};

void leer(string mensaje, int &valor);
void leer(string mensaje, string &valor);
void ingresarCursos();
void ordenarCursos(ST_CURSO cursosTec[], ST_CURSO cursosGuar[], int cantCursosTec, int cantCursosGuar);
void unirCursos(ST_CURSO cursosTec[], ST_CURSO cursosGuar[], int cantCursosTec, int cantCursosGuar);
void mostrarCursos(ST_CURSO cursosTodos[], int cantCursosTotal);

int main(){
    ingresarCursos();

    return 0;
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void ingresarCursos(){
    int cantCursosTec;
    int cantCursosGuar;
    ST_CURSO curso;

    leer("Ingrese la cantidad de cursos de la carrera Tecnicatura en sistemas", cantCursosTec);
    ST_CURSO cursosTec[cantCursosTec];

    for (int i = 0; i < cantCursosTec; i++)
    {
        leer("Ingrese el nombre del curso", curso.nombre);
        leer("Ingrese la cantidad de horas", curso.cantidadDeHoras);
        leer("Ingrese el codigo de carrera", curso.carrera);
        cursosTec[i] = curso;
    }

    leer("Ingrese la cantidad de cursos de la carrera Guardavidas", cantCursosGuar);
    ST_CURSO cursosGuar[cantCursosGuar];

    for (int i = 0; i < cantCursosGuar; i++)
    {
        leer("Ingrese el nombre del curso", curso.nombre);
        leer("Ingrese la cantidad de horas", curso.cantidadDeHoras);
        leer("Ingrese el codigo de carrera", curso.carrera);
        cursosGuar[i] = curso;
    }

    ordenarCursos(cursosTec, cursosGuar, cantCursosTec, cantCursosGuar);
}

void ordenarCursos(ST_CURSO cursosTec[], ST_CURSO cursosGuar[], int cantCursosTec, int cantCursosGuar){
    int aux;
    for (int i = 0; i < cantCursosTec-1; i++)
    {
        for (int j = i+1; j < cantCursosTec; j++)
        {
            if(cursosTec[i].cantidadDeHoras > cursosTec[j].cantidadDeHoras)
            {
                aux = cursosTec[i].cantidadDeHoras;
                cursosTec[i].cantidadDeHoras = cursosTec[j].cantidadDeHoras;
                cursosTec[j].cantidadDeHoras = aux;
            }
        }
    }

    for (int i = 0; i < cantCursosGuar-1; i++)
    {
        for (int j = i+1; j < cantCursosGuar; j++)
        {
            if(cursosGuar[i].cantidadDeHoras > cursosGuar[j].cantidadDeHoras)
            {
                aux = cursosGuar[i].cantidadDeHoras;
                cursosGuar[i].cantidadDeHoras = cursosGuar[j].cantidadDeHoras;
                cursosGuar[j].cantidadDeHoras = aux;
            }
        }
    }

    unirCursos(cursosTec, cursosGuar, cantCursosTec, cantCursosGuar);
}

void unirCursos(ST_CURSO cursosTec[], ST_CURSO cursosGuar[], int cantCursosTec, int cantCursosGuar){
    int cantCursosTotal = cantCursosTec + cantCursosGuar;
    ST_CURSO cursosTodos[cantCursosTotal];
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < cantCursosTec && j < cantCursosGuar)
    {
        if(cursosTec[i].cantidadDeHoras < cursosGuar[j].cantidadDeHoras){
            cursosTodos[k] = cursosTec[i];
            i++;
        }
        else{
            cursosTodos[k] = cursosGuar[j];
            j++;
        }
        k++;
    }

    while (i < cantCursosTec)
    {
        cursosTodos[k] = cursosTec[i];
        i++;
        k++;
    }
    
    while (j < cantCursosGuar)
    {
        cursosTodos[k] = cursosGuar[j];
        j++;
        k++;
    }

    mostrarCursos(cursosTodos, cantCursosTotal);
}

void mostrarCursos(ST_CURSO cursosTodos[], int cantCursosTotal){
    for (int i = 0; i < cantCursosTotal; i++)
    {
        cout << cursosTodos[i].cantidadDeHoras << " | " << cursosTodos[i].nombre << endl;
    }
}