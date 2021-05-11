#include <stdio.h>
#include <iostream>
using namespace std;

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

bool seAbreCursoSemanal(int tiempoLlegada[], int alumnosTotal, int alumnosMinimosAbrir){
    int cantAlumnosHorario = 0;

    for (int i = 0; i < alumnosTotal; i++)
    {
        if(tiempoLlegada[i] <= 0){
            cantAlumnosHorario++;
        }
    }
    
    return cantAlumnosHorario >= alumnosMinimosAbrir;
}

int main()
{
    int cantDias = 5;
    int alumnosTotal = 4;
    int alumnosMinimosAbrir = 0;
    string diasSemana[5] = {"lunes", "martes", "miercoles", "jueves", "viernes"};

    leer("Ingrese el minumo para abrir el curso", alumnosMinimosAbrir);

    int tiempoLlegada[alumnosTotal];
    bool tiempoLlegadaSemanal[cantDias];

    for (size_t i = 0; i < cantDias; i++)
    {
        for (int j = 0; j < alumnosTotal; j++)
        {
            cout << "Ingrese el tiempo que llego el alumno en el dia " << diasSemana[i] << endl;
            cin >> tiempoLlegada[j];
        }
        
        tiempoLlegadaSemanal[i] = seAbreCursoSemanal(tiempoLlegada, alumnosTotal, alumnosMinimosAbrir);
    }
    
    for (int i = 0; i < cantDias; i++)
    {
        if(tiempoLlegadaSemanal[i]){
            cout << "El dia " << diasSemana[i] << " se abrio el curso" << endl;
        }
        else{
            cout << "El dia " << diasSemana[i] << " no se abrio el curso" << endl;
        }
    }

    return 0;
}