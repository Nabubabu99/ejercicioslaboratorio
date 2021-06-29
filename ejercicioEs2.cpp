/* struct FechaNacimiento{
    int dia;
    int mes;
    int anio;
};

void convertirFecha(int fecha, FechaNacimiento fechaNacimiento){
    fechaNacimiento.dia = fecha % 100;
    fechaNacimiento.mes = (fecha % 10000) - fechaNacimiento.dia;
    fechaNacimiento.anio = fecha / 10000;
} */
/* Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un
Nombre = “FIN”, informar el nombre de la persona de mayor edad. */

#include <iostream>
#include <stdio.h>
using namespace std;

struct Persona{
    string nombre;
    int fechaNacimiento;
};

void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void mostrarMayor(string nombre, int fechaNacimiento){
    cout << "Nombre     |       Fecha" << endl;
    cout << nombre << "    |   " << fechaNacimiento << endl;
}

int main(){
    Persona persona;
    string nombreMay = "";
    int fechaNacimientoMayEdad = 99990000;

    do{
        leer("Ingrese el nombre de la persona(FIN para terminar)", persona.nombre);
        if(persona.nombre != "FIN"){

            leer("Ingrese la fecha de nacimiento en formato AAAAMMDD", persona.fechaNacimiento);
            if(persona.fechaNacimiento < fechaNacimientoMayEdad){
                fechaNacimientoMayEdad = persona.fechaNacimiento;
                nombreMay = persona.nombre;
            }   
        }
    }while(persona.nombre != "FIN");

    mostrarMayor(nombreMay, fechaNacimientoMayEdad);

    return 0;
}