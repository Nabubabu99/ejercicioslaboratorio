#include <iostream>
#include <stdio.h>
using namespace std;

void leer(string mensaje, int &valor);

int main(){
    int numCamion;
    int kilosCamion;
    int importeMercaderia;
    int cantKilos = 0;
    int cantImporte = 0;
    int cantPedidos = 0;
    float cantTotalPedidos = 0;
    int cantTotalEnvios = 0;
    int cantTotalImporte = 0;
    int cantTotalKilos = 0;
    float promTotalImporte = 0;
    float promTotalKilos = 0;

    leer("Ingrese el numero del camion", numCamion);

    while (numCamion != 0)
    {
        int key = numCamion;
        cantKilos = 0;
        cantImporte = 0;
        cantPedidos = 0;
        while (numCamion != 0 && numCamion == key)
        {
            leer("Ingrese los kilos del pedido", kilosCamion);
            leer("Ingrese el importe del pedido", importeMercaderia);
            cantKilos += kilosCamion;
            cantImporte += importeMercaderia;
            cantPedidos++;

            leer("Ingrese el numero del camion", numCamion);
        }

        cantTotalPedidos += cantPedidos;
        cantTotalEnvios++;
        cantTotalImporte += cantImporte;
        cantTotalKilos += cantKilos;

        cout << "El camion numero " << key << " lleva " << cantKilos << "kg con un importe de " << cantImporte << " y un total de " << cantPedidos << " pedidos" << endl;
    }

    promTotalImporte = cantTotalImporte / cantTotalPedidos;
    promTotalKilos = cantTotalKilos / cantTotalPedidos;

    cout << "Se hicieron " << cantTotalEnvios << " envios con un importe de " << cantTotalImporte << " (importe promedio " << promTotalImporte << " de los pedidos) y con un peso promedio de " << promTotalKilos << "kg" << endl;

    return 0;
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}