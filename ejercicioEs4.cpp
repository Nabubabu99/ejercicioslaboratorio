#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno{
    int numLegajo;
    int codMateria;
    int diaExamen;
    int mesExamen;
    int anioExamen;
    string apellido;
};

void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void mostrarDatos(Alumno conjuntoAlumno[], int contAlumnos){
    cout << "Legajo   |   Apellido    |      Fecha      |    Codigo de Materia" << endl;
    for(int i = 0; i < contAlumnos; i++){
        cout << conjuntoAlumno[i].numLegajo << "      " << conjuntoAlumno[i].apellido << "       " << conjuntoAlumno[i].diaExamen << "/" << conjuntoAlumno[i].mesExamen << "/" << conjuntoAlumno[i].anioExamen << "            " << conjuntoAlumno[i].codMateria << endl;
    }
}

int main(){
    Alumno conjuntoAlumno[100];
    Alumno alumno;
    int contAlumnos = 0;

    do{
        leer("Ingrese el numero de legajo", alumno.numLegajo);
        if(alumno.numLegajo != 0){
            leer("Ingrese el apellido", alumno.apellido);
            leer("Ingrese el codigo de la materia", alumno.codMateria);
            leer("Ingrese el dia del examen", alumno.diaExamen);
            leer("Ingrese el mes del examen", alumno.mesExamen);
            leer("Ingrese el anio del examen", alumno.anioExamen);
            conjuntoAlumno[contAlumnos] = alumno;
            contAlumnos++;
        }
    }while(alumno.numLegajo != 0);

    mostrarDatos(conjuntoAlumno, contAlumnos);

    return 0;
}