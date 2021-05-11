#include <stdio.h>
#include <iostream>
using namespace std;

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

bool seAbreCurso(int tiempoLlegada[], int cantidadTotal, int alumnosMinimosAbrir){
    int cantAlumnosHorario = 0;

    for (int i = 0; i < cantidadTotal; i++)
    {
        if(tiempoLlegada[i] <= 0){
            cantAlumnosHorario++;
        }
    }
    
    return cantAlumnosHorario >= alumnosMinimosAbrir;
}

int main()
{
    int cantidadTotal = 0;
    int alumnosMinimosAbrir = 0;

    leer("Ingrese la cantidad de alumnos", cantidadTotal);
    leer("Ingrese el minumo para abrir el curso", alumnosMinimosAbrir);

    int tiempoLlegada[cantidadTotal];

    for (int i = 0; i < cantidadTotal; i++)
    {
        leer("Ingrese el tiempo que llego el alumno", tiempoLlegada[i]);
    }
    
    if(seAbreCurso(tiempoLlegada, cantidadTotal, alumnosMinimosAbrir)){
        cout << "Se abre el curso";
    }
    else{
        cout << "No se abre el curso";
    }

    return 0;
}