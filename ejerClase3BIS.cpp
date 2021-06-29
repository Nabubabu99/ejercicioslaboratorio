#include <iostream>
#include <stdio.h>
using namespace std;

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

struct Vendedor
{
    int codVendedor;
    int importeVenta;
};

int main(){
    Vendedor vendedor;
    int totalVenta = 0;
    int codMayorVendedor = -1;
    int mayorVenta = -1;
    int keyCod;

    leer("Ingrese el codigo del vendedor", vendedor.codVendedor);

    while (vendedor.codVendedor != 0)
    {
        // Nuevo codigo vendedor
        keyCod = vendedor.codVendedor;
        totalVenta = 0;

        while (vendedor.codVendedor != 0 && keyCod == vendedor.codVendedor)
        {   
            leer("Ingrese el importe de la venta", vendedor.importeVenta);
            totalVenta += vendedor.importeVenta;

            leer("Ingrese el codigo del vendedor", vendedor.codVendedor);
        }
        
        if (totalVenta > mayorVenta)
        {
            mayorVenta = totalVenta;
            codMayorVendedor = keyCod;
        }

        cout << "Las ventas del vendedor " << keyCod << " tuvieron un total de " << totalVenta << endl;
        // Cambio codigo de vendedor | codigo 0
    }

    cout << "El vendedor que mas vendio fue el " << codMayorVendedor << " y su venta total fue de " << mayorVenta << endl;

    return 0;
}