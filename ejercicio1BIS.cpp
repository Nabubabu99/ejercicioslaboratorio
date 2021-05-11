#include <stdio.h>
#include <iostream>
using namespace std;

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

bool tiempoLlegadaSemana(int tiempoLlegadaSemanal[], int cantDias, int alumnosMinimosAbrir, int alumnosTotal){
    bool arraySeAbreSemana[cantDias];

    for (int i = 0; i < cantDias; i++)
    {
        arraySeAbreSemana[i] = seAbreCurso(tiempoLlegadaSemanal[i], alumnosTotal, alumnosMinimosAbrir);
    }
    
    return arraySeAbreSemana;
}

bool seAbreCurso(int tiempoLlegadaSemanal[], int cantidadTotal, int alumnosMinimosAbrir){
    int cantAlumnosHorario = 0;

    for (int i = 0; i < cantidadTotal; i++)
    {
        if(tiempoLlegadaSemanal[i] <= 0){
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

    leer("Ingrese el minumo para abrir el curso ", alumnosMinimosAbrir);

    int tiempoLlegadaSemanal[cantDias][alumnosTotal];

    for (size_t i = 0; i < cantDias; i++)
    {
        for (int j = 0; j < alumnosTotal; j++)
        {
            cout << "Ingrese el tiempo que llego el alumno en el dia " << diasSemana[i] << endl;
            cin >> tiempoLlegadaSemanal[i][j];
        }
    }
    
    for (int i = 0; i < cantDias; i++)
    {
        if(tiempoLlegadaSemana(tiempoLlegadaSemanal, cantDias, alumnosMinimosAbrir, alumnosTotal)){
            cout << "El dia " << diasSemana[i] << " se abrio el curso" << endl;
        }
        else{
            cout << "El dia " << diasSemana[i] << " no se abrio el curso" << endl;
        }
    }

    return 0;
}