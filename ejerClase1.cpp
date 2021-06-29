#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

struct Curso{
    string nombre;
    int cantidadDeHoras;
};

struct Alumno{
    int dni;
    string nombre;
    int edad;
    string email;
    string telefono;
    int curso;
};

void leer(string mensaje, int &valor);
void leer(string mensaje, string &valor);
void ingresarCursos(int cantCursos, Curso cursos[], Curso curso);
void mostrarAlumno(int dniAlumno, Alumno alumnos[], Curso cursos[], int cantAlumnos);
void ordenarPorDni(Alumno alumnos[], int cantAlumnos);
void registrarAlumnos(int cantAlumnos, Alumno alumnos[], Alumno alumno);
void menu();

int main(){
    menu();

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

void ingresarCursos(int cantCursos, Curso cursos[], Curso curso){
    for(int i = 0; i < cantCursos; i++){
        leer("Ingrese el nombre del curso", curso.nombre);
        leer("Ingrese la cantidad de horas", curso.cantidadDeHoras);
        cursos[i] = curso;
    }
    menu();
}

void mostrarAlumno(int dniAlumno, Alumno alumnos[], Curso cursos[], int cantAlumnos){
    int mitad = 0;
    int inicio = 0;
    int fin = cantAlumnos - 1;

    while (inicio <= fin)
    {
        mitad = inicio + (fin - inicio) / 2;

        if (alumnos[mitad].dni == dniAlumno)
        {
            cout << "DNI: " << alumnos[mitad].dni << endl;
            cout << "Nombre: " << alumnos[mitad].nombre << endl;
            cout << "Edad: " << alumnos[mitad].edad << endl;
            cout << "Email: " << alumnos[mitad].email << endl;
            cout << "Telefono: " << alumnos[mitad].telefono << endl;
            cout << "curso: " << alumnos[mitad].curso << endl;
        }
        
        if(alumnos[mitad].dni > dniAlumno){
            fin = mitad - 1;
        }
        else{
            inicio = mitad + 1;
        }
    }
    menu();
}

void ordenarPorDni(Alumno alumnos[], int cantAlumnos){
    Alumno aux;
    int i = 0;
    bool ordenado = false;
    while (i < cantAlumnos && !ordenado)
    {
        ordenado = true;
        for (int j = 0; j < cantAlumnos - i - 1; j++)
        {
            if (alumnos[j].dni > alumnos[j+1].dni)
            {
                aux = alumnos[j];
                alumnos[j] = alumnos[j+1];
                alumnos[j+1] = aux;
                ordenado = false;
            }
        }
    }
}

void registrarAlumnos(int cantAlumnos, Alumno alumnos[], Alumno alumno){
    for (int i = 0; i < cantAlumnos; i++)
    {
        leer("Ingrese el dni del alumno", alumno.dni);
        leer("Ingrese el nombre del alumno", alumno.nombre);
        leer("Ingrese la edad del alumno", alumno.edad);
        leer("Ingrese el email del alumno", alumno.email);
        leer("Ingrese el telefono del alumno", alumno.telefono);
        leer("Ingrese el curso del alumno", alumno.curso);

        alumnos[i] = alumno;
    }

    ordenarPorDni(alumnos, cantAlumnos);
    menu();
}

void menu(){
    int cantCursos;
    int opcion;
    int cantAlumnos;
    Curso curso;
    Curso cursos[1];
    Alumno alumno;
    Alumno alumnos[1];
    int dniAlumno;

    do
    {
        cout << "Menu" << endl;
        cout << "1- Ingresar la cantidad de cursos" << endl;
        cout << "2- Ingresar cursos" << endl;
        cout << "3- Registrar cantidad de alumnos" << endl;
        cout << "4- Registrar Alumnos" << endl;
        cout << "5- Buscar alumno" << endl;
        cout << "0- Salir" << endl;
        cin >> opcion;
    
        switch (opcion)
        {
        case 1:
            leer("Ingrese la cantidad de cursos", cantCursos);
            break;
            
        case 2:
            cursos[cantCursos];
            ingresarCursos(cantCursos, cursos, curso);
            break;

        case 3:
            leer("Ingrese la cantidad de alumnos", cantAlumnos);
            alumnos[cantAlumnos];
            break;

        case 4:
            registrarAlumnos(cantAlumnos, alumnos, alumno);
            break;
        case 5:
            leer("Ingrese el dni del alumno a buscar", dniAlumno);
            mostrarAlumno(dniAlumno, alumnos, cursos, cantAlumnos);
        }
    } while (opcion > 0 && opcion <= 5);
}
