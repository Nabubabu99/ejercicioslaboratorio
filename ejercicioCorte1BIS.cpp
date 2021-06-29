#include<iostream>
using namespace std;

void leer(string msg,char &valor){
    cout << msg;
    cin >> valor;
    return;
}
void leer(string msg,float &valor){
    cout << msg;
    cin >> valor;
    return;
}
void leer(string msg,int &valor){
    cout << msg;
    cin >> valor;
    return;
}

struct Facturacion{
    char tipo;
    float monto = 0;
    int tipoProveedor;
};

void guardalaSiEsBuena(Facturacion factura, Facturacion facturasMejores[]){
    Facturacion aux;
    Facturacion aux2;
    bool cambio = false;

    for (int i = 2; i >= 0; i--)
    {
        if (factura.monto > facturasMejores[i].monto)
        {
            if (i == 2 && cambio == false)
            {
                aux = facturasMejores[i];
                aux2 = facturasMejores[i-1];
                facturasMejores[i] = factura;
                facturasMejores[i-1] = aux;
                facturasMejores[i-2] = aux2;
                cambio = true;
            }
            else if (i == 1 && cambio == false)
            {
                aux = facturasMejores[i];
                facturasMejores[i] = factura;
                facturasMejores[i-1] = aux;
                cambio = true;
            }
            else if(cambio == false){
                facturasMejores[i] = factura;
                cambio = true;
            }
        }
    }
}

void acumuladorDeFacturas(Facturacion facturas) {
    float sumadorTipo = 0, sumadorProveedor = 0;
    int contadorTodas = 0;
    char tipoFactMax = 0;
    float facturaMax = 0;
    float totalFacturacion = 0;
    Facturacion facturasMejores[3] = {0};

    leer("Ingrese el tipo de la factura: ", facturas.tipo);

    while(facturas.tipo != '0') {
        char keyTipo = facturas.tipo;
        //Inicializo variables de sublote
        contadorTodas = 0;
        sumadorTipo = 0;
        leer("Ingrese el tipo de proveedor: ", facturas.tipoProveedor);

        while(facturas.tipo != '0' && keyTipo == facturas.tipo) {

            int keyProveedor = facturas.tipoProveedor;
            sumadorProveedor = 0;
            while(facturas.tipo != '0' && keyTipo == facturas.tipo && keyProveedor == facturas.tipoProveedor){
                leer("Ingrese el monto de la factura: ",facturas.monto);

                guardalaSiEsBuena(facturas, facturasMejores);

                if(facturaMax < facturas.monto) {
                    facturaMax = facturas.monto;
                    tipoFactMax = keyTipo;
                }

                sumadorProveedor += facturas.monto;
                sumadorTipo += facturas.monto;
                contadorTodas++;

                leer("Ingrese el tipo de la factura: ",facturas.tipo);
                leer("Ingrese el tipo de proveedor: ", facturas.tipoProveedor);
            }
            // Mostrar total proveedor
            cout << "Monto total del proveedor " << keyProveedor << " es " << sumadorProveedor << endl;
        }
        totalFacturacion += sumadorTipo;
        cout << "Se ingreso " << contadorTodas << " facturas, del tipo: " << keyTipo << endl;
        cout << "Con un Monto total de: " << sumadorTipo << endl;
    }
    cout << "El total de Facturacion es: " << totalFacturacion << endl << "La Factura de Mayor monto es $"<< facturaMax << ", la cual pertenece al Tipo " << tipoFactMax << endl;

    cout << "Las 3 mejores facturas tuvieron un monto de:" << endl;
    for (int i = 2; i >= 0; i--)
    {
        cout << "$" << facturasMejores[i].monto << endl;
    }
    
}

int main()
{
    Facturacion facturas;

    system ("cls");

    acumuladorDeFacturas(facturas);

    system("pause");
    return 0;
}
