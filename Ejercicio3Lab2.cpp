#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno
{
    int legajo;
    string nombre;
    string carrera;
};

void buscarAlumno(Alumno alumnos[], int legajoBuscado, int cantAlumnosTotal);
void leer(string mensaje, int &valor);
void leer(string mensaje, string &valor);
void cargarAlumnos(Alumno alumnos[], int cantAlumnos, string carrera);
void unirAlumnosCarreras(Alumno alumnosTecSis[], Alumno alumnosGuardavidas[], Alumno alumnosTodos[], int cantAlumnosTecSis, int cantAlumnosGuardavidas, int cantAlumnosTotal);
void mostrarAlumnos(Alumno alumnosTodos[], int cantAlumnosTotal);
void buscarAlumno(Alumno alumnos[], int legajoBuscado, int cantAlumnosTotal);
void ordenarAlumnos(Alumno alumnosTodos[], int cantAlumnosTotal);

int main(){
    int cantAlumnosTecSis;
    int cantAlumnosGuardavidas;
    int legajoBuscado;

    leer("Ingrese la cantidad de alumnos de la carrera Tecnicatura en Sistemas", cantAlumnosTecSis);
    leer("Ingrese la cantidad de alumnos de la carrera Guardavidas", cantAlumnosGuardavidas);

    Alumno alumnosTecSis[cantAlumnosTecSis];
    Alumno alumnosGuardavidas[cantAlumnosGuardavidas];

    cout << "Ingresar los alumnos de la carrera de Tecnicatura en Sistemas" << endl;
    cargarAlumnos(alumnosTecSis, cantAlumnosTecSis, "Tecnicatura en Sistemas");

    cout << "Ingresar los alumnos de la carrera de Guardavidas" << endl;
    cargarAlumnos(alumnosGuardavidas, cantAlumnosGuardavidas, "Guardavidas");
    
    int cantAlumnosTotal = cantAlumnosTecSis + cantAlumnosGuardavidas;
    Alumno alumnosTodos[cantAlumnosTotal];
    unirAlumnosCarreras(alumnosTecSis, alumnosGuardavidas, alumnosTodos, cantAlumnosTecSis, cantAlumnosGuardavidas, cantAlumnosTotal);

    leer("Ingrese el legajo que desea buscar", legajoBuscado);
    buscarAlumno(alumnosTodos, legajoBuscado, cantAlumnosTotal);
        
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

void cargarAlumnos(Alumno alumnos[], int cantAlumnos, string carrera){
    for (int i = 0; i < cantAlumnos; i++)
    {
        leer("Ingrese el numero de legajo", alumnos[i].legajo);
        leer("Ingrese el nombre del alumno", alumnos[i].nombre);
        alumnos[i].carrera = carrera;
    }
}

void unirAlumnosCarreras(Alumno alumnosTecSis[], Alumno alumnosGuardavidas[], Alumno alumnosTodos[], int cantAlumnosTecSis, int cantAlumnosGuardavidas, int cantAlumnosTotal){
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < cantAlumnosTecSis && j < cantAlumnosGuardavidas)
    {
        if(alumnosTecSis[i].legajo < alumnosGuardavidas[j].legajo){
            alumnosTodos[k] = alumnosTecSis[i];
            i++;
        }
        else{
            alumnosTodos[k] = alumnosGuardavidas[j];
            j++;
        }
        k++;
    }

    while (i < cantAlumnosTecSis)
    {
        alumnosTodos[k] = alumnosTecSis[i];
        i++;
        k++;
    }
    
    while (j < cantAlumnosGuardavidas)
    {
        alumnosTodos[k] = alumnosGuardavidas[j];
        j++;
        k++;
    }

    ordenarAlumnos(alumnosTodos, cantAlumnosTotal);
    mostrarAlumnos(alumnosTodos, cantAlumnosTotal);
}

void ordenarAlumnos(Alumno alumnosTodos[], int cantAlumnosTotal){
    int i = 0;    
    Alumno aux;
    bool ordenado = false;

    while (i < cantAlumnosTotal && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantAlumnosTotal-i-1; j++) 
        {
            if (alumnosTodos[j].legajo > alumnosTodos[j+1].legajo) 
            {
                aux = alumnosTodos[j];
                alumnosTodos[j] = alumnosTodos[j+1];
                alumnosTodos[j+1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}


void mostrarAlumnos(Alumno alumnosTodos[], int cantAlumnosTotal){
    cout << "Legajo\t\tNombre" << endl;
    for (int i = 0; i < cantAlumnosTotal; i++)
    {
        cout << alumnosTodos[i].legajo << "\t\t" << alumnosTodos[i].nombre << endl;
    }
}

void buscarAlumno(Alumno alumnos[], int legajoBuscado, int cantAlumnosTotal){
    int inicio = 0;
    int fin = cantAlumnosTotal-1;
    int medio = 0;

    while (inicio <= fin)
    {
        medio = inicio + (fin - inicio) / 2;

        if (alumnos[medio].legajo == legajoBuscado)
        {
            cout << "El nombre del alumno es " << alumnos[medio].nombre << " y esta en la carrera de " << alumnos[medio].carrera << endl;
        }

        if (alumnos[medio].legajo > legajoBuscado)
        {
            fin = medio - 1;
        }
        else{
            inicio = medio + 1;
        }
    }
}