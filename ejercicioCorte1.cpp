#include <iostream>
#include <stdio.h>
using namespace std;

void leer(string mensaje, char &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

struct Factura
{
    int monto;
    char tipo;
    int codigoDeProveedor;
};

int main(){
    int sumaMontos = 0;
    int sumaMontosTotal = 0;
    int contador = 0;
    char tipoMayorMonto;
    int montoMayor = 0;
    Factura factura;

    leer("Ingrese el codigo del proveedor", factura.codigoDeProveedor);
    leer("Ingrese el tipo de factura", factura.tipo);

    while (factura.tipo != '0')
    {
        int codigo = factura.codigoDeProveedor;

        while (factura.tipo != '0' && codigo == factura.codigoDeProveedor)
        {
            char key = factura.tipo;

            while (factura.tipo == key && factura.tipo != '0' && codigo == factura.codigoDeProveedor)
            {
                leer("Ingrese el monto de la factura", factura.monto);
                if (montoMayor < factura.monto)
                {
                    montoMayor = factura.monto;
                    tipoMayorMonto = factura.tipo;
                }
                contador++;
                sumaMontos += factura.monto;

                leer("Ingrese el codigo del proveedor", factura.codigoDeProveedor);
                if (factura.codigoDeProveedor != codigo)
                {
                    cout << "Se ingresaron " << contador << " facturas del proveedor " << codigo << " con un monto de $" << sumaMontos << endl;
                    sumaMontos = 0;
                    contador = 0;
                }
                
                leer("Ingrese el tipo de factura", factura.tipo);
            }
            sumaMontosTotal += sumaMontos;
        }
    }
    
    cout << endl;
    cout << "El monto total de todas las facturas es de $" << sumaMontosTotal << endl;
    cout << "La factura " << tipoMayorMonto << " fue la de mayor monto con un total de $" << montoMayor << endl;

    return 0;
}