#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_CONSOLAS 100

struct Consola
{
    string consola;
    int cantJuegos;
};

struct Juego{
    int codJuego;
    int stockLocal;
    string tituloJuego;
    string consola;
};

void completarVectorConsola(Juego juegos[], Consola juegosPorConsola[], int cantJuegos, int &cantConsolas);
void mostrarConsolas(Consola juegosPorConsola[], int cantConsolas);
void ordenarJuegos(Juego juegos[], int cantJuegos);

int main(){
    int cantJuegos = 6;
    Juego juegos[cantJuegos] = {
        {14, 10, "Budokai Tekainchi 3", "Ps2"},
        {17, 2, "NARC", "Ps2"},
        {35, 4, "Call Of Duty", "Ps5"},
        {48, 15, "Beyond Two Souls", "Ps3"},
        {55, 7, "Minecraft", "Xbox"},
        {99, 5, "League of Legends", "Ps5"}
    };
    int cantConsolas = 0;
    Consola juegosPorConsola[MAX_CONSOLAS];

    completarVectorConsola(juegos, juegosPorConsola, cantJuegos, cantConsolas);
    mostrarConsolas(juegosPorConsola, cantConsolas);

    return 0;
}

void completarVectorConsola(Juego juegos[], Consola juegosPorConsola[], int cantJuegos, int &cantConsolas){
    ordenarJuegos(juegos, cantJuegos);
    int i = 0;
    int totalJuegos = 0;
    string keyConsola;

    while (i < cantJuegos)
    {

        totalJuegos = 0;
        keyConsola = juegos[i].consola;

        while (i < cantJuegos && keyConsola == juegos[i].consola)
        {
            totalJuegos += juegos[i].stockLocal;
            i++;
        }

        juegosPorConsola[cantConsolas].consola = keyConsola;
        juegosPorConsola[cantConsolas].cantJuegos = totalJuegos;
        cantConsolas++;
    }
}

void mostrarConsolas(Consola juegosPorConsola[], int cantConsolas){
    for (int i = 0; i < cantConsolas; i++)
    {
        cout << juegosPorConsola[i].consola << " con " << juegosPorConsola[i].cantJuegos << " juegos" << endl;
    }
}

void ordenarJuegos(Juego juegos[], int cantJuegos){
    int i = 0;    
    Juego aux;
    bool ordenado = false;

    while (i < cantJuegos && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantJuegos-i-1; j++) 
        {
            if (juegos[j].consola > juegos[j+1].consola) 
            {
                aux = juegos[j];
                juegos[j] = juegos[j+1];
                juegos[j+1] = aux;
                ordenado = false; 
            }
        }     
        i++;
    }
}