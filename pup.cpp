#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    float ventas[31];
    int dia;
    float venta;
    cout << “Ingrese las ventas del mes” << endl;

    for(int i = 0; i < 31; i++) {
        cout << “Día: “;
        cin >> dia;
        cout << “Venta: ”;
        cin >> venta;
        ventas[dia - 1] = ventas[dia - 1] + venta; // Acumulo la venta leida
    }
}

// posicion = clave - valor_inicio_rango