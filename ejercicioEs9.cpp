/* Se dispone un vector de inscripción de alumnos a exámenes finales MAESTROFINALES y otro con
las inscripciones del día de hoy DIAFINALES, ambos ordenados ascendente por código de materia y con el
siguiente diseño:
Nro de legajo (8 dígitos) Código de materia (6 dígitos) ApellidoNombre(cadena)
Se pide desarrollar un procedimiento que complete un nuevo vector de inscripciones a finales
FINALESACT resultante del apareo de los dos vectores anteriores, con el mismo orden y diseño. */

#include <iostream>
#include <stdio.h>
using namespace std;

struct Final
{
    int numLegajo;
    int codMateria;
    string apellidoNombre;
};

void ordenarAsc(Final alumnos[], int cantInscriptos);
void ingresarDatos(Final alumno, Final alumnos[], string mensaje, int cantidad);
void leer(string mensaje, int &valor);
void leer(string mensaje, string &valor);
void apareo(Final finales[], Final finalesDia[], Final finalesTotal[], int canAlumnosFinal, int cantAlumnosFinalHoy, int &cantTotal);
void mostrarDatos(Final alumnos[], int cantidad);
void menu();

int main(){
    menu();

    return 0;
}

void menu(){
    int cantAlumnosFinal;
    int cantAlumnosFinalHoy;
    int cantTotal = 0;
    Final alumno;
    Final MAESTROFINALES[0];
    Final DIAFINALES[0];
    Final FINALESACT[0];
    int opcion = 0;

    do
    {
        cout << "Menu" << endl;
        cout << "1- Ingresar la cantidad de alumnos que hicieron el final" << endl;
        cout << "2- Ingresar la cantidad de alumnos en el final de hoy" << endl;
        cout << "3- Registrar alumnos que hicieron el final" << endl;
        cout << "4- Registrar Alumnos en el final de hoy" << endl;
        cout << "5- Realizar apareo" << endl;
        cout << "0- Salir" << endl;
        cin >> opcion;
    
        switch (opcion)
        {
        case 1:
            leer("Ingrese la cantidad de alumnos que tuvieron final", cantAlumnosFinal);
            MAESTROFINALES[cantAlumnosFinal];
            break;
            
        case 2:
            leer("Ingrese la cantidad de alumnos que haran el final hoy", cantAlumnosFinalHoy);
            DIAFINALES[cantAlumnosFinalHoy];
            cantTotal = cantAlumnosFinalHoy + cantAlumnosFinal;
            FINALESACT[cantTotal];
            break;

        case 3:
            ingresarDatos(alumno, MAESTROFINALES, "Datos de los alumnos que tuvieron el final", cantAlumnosFinal);
            break;

        case 4:
            ingresarDatos(alumno, DIAFINALES, "Datos de los alumnos en el final de hoy", cantAlumnosFinalHoy);
            break;

        case 5:
            apareo(MAESTROFINALES, DIAFINALES, FINALESACT, cantAlumnosFinal, cantAlumnosFinalHoy, cantTotal);
            break;

        case 6:
            mostrarDatos(FINALESACT, cantTotal);
            break;

        }
    } while (opcion > 0 && opcion <= 6);
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void ingresarDatos(Final alumno, Final alumnos[], string mensaje, int cantidad){
    cout << mensaje << endl;

    for (size_t i = 0; i < cantidad; i++)
    {
        leer("Ingrese el numero de legajo", alumno.numLegajo);
        leer("Ingrese el codigo de materia", alumno.codMateria);
        leer("Ingrese el nombre del alumno", alumno.apellidoNombre);

        alumnos[i] = alumno;
    }

    ordenarAsc(alumnos, cantidad);
}

void ordenarAsc(Final alumnos[], int cantInscriptos){
    Final aux;

    for (int i = 0; i < cantInscriptos; i++)
    {
        for (int j = i+1; j < cantInscriptos; i++)
        {
            if (alumnos[j].codMateria < alumnos[i].codMateria)
            {
                aux = alumnos[i];
                alumnos[i] = alumnos[j];
                alumnos[j] = alumnos[i];
            }
        }
    }
}

void apareo(Final finales[], Final finalesDia[], Final finalesTotal[], int cantAlumnosFinal, int cantAlumnosFinalHoy, int &cantTotal){
    int i = 0;
    int j = 0;
    cantTotal = 0;

    while (i < cantAlumnosFinal && j < cantAlumnosFinalHoy)
    {
        if (finales[i].codMateria < finalesDia[j].codMateria)
        {
            finalesTotal[cantTotal] = finales[i];
            i++;
        }
        else{
            finalesTotal[cantTotal] = finales[j];
            j++;
        }
        cantTotal++;
    }
    
    while (i < cantAlumnosFinal)
    {
        finalesTotal[cantTotal] = finales[i];
        cantTotal++;
    }
    while (j < cantAlumnosFinalHoy)
    {
        finalesTotal[cantTotal] = finales[j];
        cantTotal++;
    }
}

void mostrarDatos(Final alumnos[], int cantidad){
    int i = 0;
    int cantAlumnos = 0;
    int cantMaterias = 0;
    int cantFinales = 0;
    int key;
    
    while(i < cantidad) {
        
        key = alumnos[i].codMateria;
        cantMaterias++;
        cantAlumnos = 0;
        
        cout << "Codigo de materia: " << key << endl;
        cout << "Legajo      |      Nombre" << endl;
        while(i < cantidad && key == alumnos[i].codMateria) {
            cout << alumnos[i].numLegajo << "      |       " << alumnos[i].apellidoNombre;
            cantAlumnos++;
            cantFinales++;
            i++;
        }

        cout << "Cantidad de alumnos: " << cantAlumnos << endl;
    }

    cout << "Cantidad de materias: " << cantMaterias << endl;
    cout << "Cantidad de finales: " << cantFinales << endl;
}