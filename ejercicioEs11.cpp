#include <iostream>
#include <stdio.h>
using namespace std;

struct Episodio
{
    int idSerie;
    string tituloEp;
    int numTemp;
    int numEp;
    long cantDescargas;
    int fechaUltimaDescarga;
};

void partirFecha8Digitos(int fechaCompleta, int &dia, int &mes, int&anio){
    int restoFecha = 0;
    restoFecha = fechaCompleta % 10000;
    anio = (fechaCompleta - restoFecha) / 10000;
    mes = (restoFecha - dia) / 100;
    dia = fechaCompleta % 100;    
}

void mostrarDatos(Episodio episodios[], int cantEpisodios){
    int i = 0;
    int key;
    int keyTemp;
    int sumaEp = 0;
    int sumaDescargas = 0;
    int cantSeries = 0;
    int dia = 0;
    int mes = 0;
    int anio = 0;

    while (i < cantEpisodios)
    {
        sumaEp = 0;
        sumaDescargas = 0;
        key = episodios[i].idSerie;
        while (i < cantEpisodios && key == episodios[i].idSerie)
        {
            keyTemp = episodios[i].numTemp;
            cout << endl;
            cout << "       Listado de Descargas de Series" << endl;
            cout << "Serie: " << episodios[i].idSerie << endl;
            cout << "   Temporada: " << episodios[i].numTemp << endl;

            cantSeries++;

            cout << "N. de Episodio | Titulo del Episodio | Cant. descargas | Fecha de la ultima descarga" << endl;
            while (i < cantEpisodios && key == episodios[i].idSerie && keyTemp == episodios[i].numTemp)
            {
                partirFecha8Digitos(episodios[i].fechaUltimaDescarga, dia, mes, anio);
                cout << "             " << episodios[i].numEp << " | " << episodios[i].tituloEp << " |                 " << episodios[i].cantDescargas << " |     " << dia << "/" << mes << "/" << anio << endl;
                sumaEp += 1;
                sumaDescargas += episodios[i].cantDescargas;
                i++;
            }
        }
        
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        cout << "Cant. Total de Episodios de la temporada: " << sumaEp << endl;
        cout << "Total descargas de la temporada: " << sumaDescargas << endl;
    }

    cout << endl;
    cout << "#######################################################################################################" << endl;
    cout << "Total General de series: " << cantSeries << endl;
}

int main(){
    Episodio episodios[5] = {
        {121514488, "En busca del pibe", 1, 1, 15, 20211021},
        {121514488, "Cosas del barrio", 1, 2, 17, 20211122},
        {121514488, "Vamos a la plaza?", 2, 1, 5, 20201021},
        {121513115, "El Marginal", 5, 1, 50, 20211205},
        {121513000, "De la plaza al escenario", 3, 10, 3, 20201021}
    };
    int cantEpisodios = 5;

    mostrarDatos(episodios, cantEpisodios);

    return 0;
}