#include <iostream>
#include <stdio.h>
using namespace std;

struct datosAlumnos
{
    int numLegajo;
    string apellidoNombre;
    int notaAlumno;
}alumnos[100];

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}
void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void cargarAlumno(struct datosAlumnos datosAlumnos, int numAlumnos){
    int notaAlumno;
    string apellidoNombre;
    int numLegajo;


    for (int i = 0; i < numAlumnos; i++)
    {
        leer("Ingrese el numero de legajo del alumno", numLegajo);
        leer("Ingrese el apellido y nombre del alumno", apellidoNombre);
        leer("Ingrese la nota del alumno", notaAlumno);
        datosAlumnos.numLegajo= numLegajo;
        datosAlumnos.apellidoNombre = apellidoNombre;
        datosAlumnos.notaAlumno = notaAlumno;

        alumnos[i] = datosAlumnos;
    }
}

void mostrarAlumnos(struct datosAlumnos datosAlumnos, int numAlumnos){
    cout << "Legajo     |      ApellidoNombre     |     Nota" << endl;
    for (int i = 0; i < numAlumnos; i++)
    {
        cout << alumnos[i].numLegajo << "   |      " << alumnos[i].apellidoNombre << "       |   " << alumnos[i].notaAlumno << endl;
    }
}

void menu(){
    int numAlumnos;
    int opcion;
    struct datosAlumnos datosAlumnos;

    do
    {
        cout << "Menu" << endl;
        cout << "1- Ingresar numero de alumnos" << endl;
        cout << "2- Cargar datos de los alumnos" << endl;
        cout << "3- Mostrar alumnos" << endl;
        cout << "0- Salir" << endl;
        cin >> opcion;
    
        switch (opcion)
        {
        case 1:
            leer("Ingrese el numero de alumnos", numAlumnos);
            break;
            
        case 2:
            cargarAlumno(datosAlumnos, numAlumnos);

        case 3:
            mostrarAlumnos(datosAlumnos, numAlumnos);
            break;

        case 0:
            break;
        }
    } while (opcion > 0 && opcion <= 3);
}

int main(){

    menu();

    return 0;
}