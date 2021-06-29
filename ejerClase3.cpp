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
    int keyImporte;

    leer("Ingrese el codigo del vendedor", vendedor.codVendedor);

    while (vendedor.codVendedor != 0)
    {
        keyCod = vendedor.codVendedor;
        while (vendedor.codVendedor != 0 && keyCod == vendedor.codVendedor)
        {   
            leer("Ingrese el importe de la venta", vendedor.importeVenta);
            keyImporte = vendedor.importeVenta;
            while (vendedor.codVendedor != 0 && keyCod == vendedor.codVendedor && keyImporte != 0)
            {
                totalVenta += vendedor.importeVenta;
                leer("Ingrese el importe de la venta", vendedor.importeVenta);
                keyImporte = vendedor.importeVenta;
            }
            
            cout << "Las ventas del vendedor " << vendedor.codVendedor << " tuvieron un total de " << totalVenta << endl;

            if (totalVenta > mayorVenta)
            {
                mayorVenta = totalVenta;
                codMayorVendedor = vendedor.codVendedor;
            }
            
            totalVenta = 0;
            leer("Ingrese el codigo del vendedor", vendedor.codVendedor);
        }
    }

    cout << "El vendedor que mas vendio fue el " << codMayorVendedor << " y su venta total fue de " << mayorVenta << endl;

    return 0;
}