#include <iostream>
using namespace std;
#define CANT_MAX_FILAS 1
#define CANT_MAX_COLUMNAS 1
#define CANT_MAX_FIL_COL 1

//Función leer: imprime mensaje y toma dato por referencia según tipo de dato que se especifique.
//En el caso del ejemplo, recibe cadena para mensaje y devuelve valor ingresado (de tipo cadena) por referencia (string &valor).

void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;  
}

void leer(string mensaje, char &valor){
    cout << mensaje << endl;
    cin >> valor;    
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

// Calcular promedio
float calcularPromedio(float numerador, float denominador){        
    return numerador/denominador;
}

// Calcular porcentaje
float calcularPorcentaje(float numerador, float denominador){
    return numerador/denominador * 100;
}

// Función formarFecha8Digitos: recibe día, mes y año por separado, convierte esos 3 valores en un único valor de 8 dígitos
// que corresponde a una fecha en formato AAAAMMDD y devuelve ese valor.

int formarFecha8Digitos(int dia, int mes, int anio){    
    return ((anio*10000)+(mes*100)+(dia));
}

// Funcion partirFecha8Digitos: recibe valor entero de 8 dígitos que corresponde a una fecha en formato AAAAMMDD y 
// asigna los valores correspondientes al día, mes y año por referencia a los parámetros que le pasamos.
void partirFecha8Digitos(int fechaCompleta, int &dia, int &mes, int&anio){
    int restoFecha = 0;
    restoFecha = fechaCompleta % 10000;
    anio = (fechaCompleta - restoFecha) / 10000;
    mes = (restoFecha - dia) / 100;
    dia = fechaCompleta % 100;    
}

// Función esCapicuaTres: recibe valor de 3 dígitos y evalúa si es capicúa. Devuelve True si lo es o False si no lo es.
bool esCapicuaTres(int numero){
    int primerNumero = 0;
    int ultimoNumero = 0;

    primerNumero = numero / 100;
    ultimoNumero = numero % 10;

    if(primerNumero == ultimoNumero)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Función esCapicuaCuatro: recibe valor de 4 dígitos y evalúa si es capicúa. Devuelve True si lo es o False si no lo es.
bool esCapicuaCuatro(int numero){
    int primerNumero = 0;
    int segundoNumero = 0;
    int tercerNumero = 0;
    int ultimoNumero = 0;

    ultimoNumero = numero % 10;
    primerNumero = numero / 1000;
    tercerNumero = ((numero - ultimoNumero) / 10) % 10;
    segundoNumero = (numero % 1000 - numero % 100) / 100;

    if(primerNumero == ultimoNumero && segundoNumero == tercerNumero)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Funcion esCapicuaCinco: recibe valor de 5 dígitos y evalúa si es capicúa. Devuelve True si lo es o False si no lo es.
bool esCapicuaCinco(int numero){
    int primerNumero = 0;
    int segundoNumero = 0;
    int cuartoNumero = 0;
    int ultimoNumero = 0;

    ultimoNumero = numero % 10;
    primerNumero = numero / 10000;
    cuartoNumero = ((numero - ultimoNumero) / 10) % 10;
    segundoNumero = (numero % 10000 - numero % 1000) / 1000;

    if(primerNumero == ultimoNumero && segundoNumero == cuartoNumero)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Función esTriangulo: recibe 3 lados y determina si forman un triángulo o no.
bool esTriangulo(float lado1, float lado2, float lado3){

    if((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1))
    {
        return true;
    }
    else
    {
        return false;
    }
}


// Función tipoDeTriangulo: recibe 3 lados y determina qué tipo de triángulo forman. Retorna cadena que informa el tipo de triángulo.
string tipoDeTriangulo(float lado1, float lado2, float lado3){
    
    if(lado1 == lado2 && lado2 == lado3)
    {
        return "Es equilatero.";
    }
    else if(lado1 != lado2 && lado1 != lado3 && lado2 != lado3)
    {
        return "Es escaleno.";
    }
    else
    {
        return "Es isosceles.";
    }
}

// Función esTrianguloRectangulo con funcion potencia asociada: recibe 3 lados, determina la hipotenusa y catetos . 
// Retorna true si lo es o false si no lo es. Requiere definir función potencia.
bool esTrianguloRectangulo(float lado1, float lado2, float lado3)
{
    float cateto1 = 0;
    float cateto2 = 0;
    float hipotenusa = 0;

    if(lado1 > lado2 && lado1 > lado3)
    {
        hipotenusa = lado1;
        cateto1 = lado2;
        cateto2 = lado3;
    }
    else if(lado2 > lado1 && lado2 > lado3)
    {
        hipotenusa = lado2;
        cateto1 = lado1;
        cateto2 = lado3;
    }
    else if(lado3 > lado1 && lado3 > lado2)
    {
        hipotenusa = lado3;
        cateto1 = lado1;
        cateto2 = lado2;
    }

    if(potencia(cateto1,2) + potencia(cateto2,2) == potencia(hipotenusa,2))
    {
        cout << "Es triangulo rectangulo" << endl;
        return true;
    }
    else
    {
        cout << "No es triangulo rectangulo" << endl;
        return false;
    }
}

// Función esTrianguloRectangulo: recibe 3 lados, determina la hipotenusa y catetos. 
// Retorna true si lo es o false si no lo es. No requiere función potencia.
bool esTrianguloRectangulo(float lado1, float lado2, float lado3)
{
    float cateto1 = 0;
    float cateto2 = 0;
    float hipotenusa = 0;

    if(lado1 > lado2 && lado1 > lado3)
    {
        hipotenusa = lado1;
        cateto1 = lado2;
        cateto2 = lado3;
    }
    else if(lado2 > lado1 && lado2 > lado3)
    {
        hipotenusa = lado2;
        cateto1 = lado1;
        cateto2 = lado3;
    }
    else if(lado3 > lado1 && lado3 > lado2)
    {
        hipotenusa = lado3;
        cateto1 = lado1;
        cateto2 = lado2;
    }

    if((cateto1*cateto1) + (cateto2*cateto2) == (hipotenusa*hipotenusa))
    {
        cout << "Es triangulo rectangulo" << endl;
        return true;
    }
    else
    {
        cout << "No es triangulo rectangulo" << endl;
        return false;
    }
}

// Función potencia: recibe base y exponente y retorna el resultado de la potencia.
int potencia(int base, int pot)
{
    int resultado = 1;
    
    for(int i = 0; i < pot; i++)
    {
        resultado = resultado * base;
    }

 return resultado;
}

// Función calcularDiasDelMes: recibe mes y anio. Retorna cadena que informa cuandos días tiene el mes correspondiente.
string calcularDiasDelMes(int mes, int anio){

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
       return "El mes tiene 31 dias.";
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
       return "El mes tiene 30 dias.";
    }
    else if (mes == 2 && anio % 4 == 0 && (anio % 100 != 0 ) || (anio % 400 == 0))
    {
       return "El mes tiene 29 dias.";
    }    
    else if (mes == 2)
    {
       return "El mes tiene 28 dias.";
    }
}

// Función esPrimo : se le pasa por parámetro un numero entero para evaluar si es primo o no, si es primo devuelve true,
// si no devuelve false
bool esPrimo(int num){
    int cantDiv = 0;

    for (int i = 1; i <= num; i++)
    {
        if(num % i == 0){
            cantDiv++;
        }
    }

    if(cantDiv > 2){
        return false;
    }

    return true;
}

// Calcular el factorial de un número.
int calcularFactorial(int valor){  
    
    int factorial = 1;

    for(int i = 1; i <= valor; i++)
    {
        factorial = factorial * i;        
    }

    return factorial;

}

// Cargar vector por medio de un for.
void cargarVector(int cantidadValores, int valores[]){

    int valor = 0;

    for (int i = 0; i < cantidadValores; i++)
    {
        leer("Ingrese un valor: ", valor);

        valores[i] = valor;
    }    

    return;
}

// Algoritmo de busqueda secuencial
int busquedaSecuencial(int array[], int n, int valor) {
    for(int i = 0; i < n; i++) 
    {
        if (array[i] == valor)
        {
        return i;
        }
    }    
    return -1;
}

// Algoritmo de busqueda binaria
int busquedaBinaria(int array[], int n, int x) {
    
    int inicio = 0;
    int fin = n -1;
    while (fin >= inicio) 
    {
        int mitad = inicio + (fin - inicio) / 2;
        
        if (array[mitad] == x)
        {
            return mitad ;
        }        
        else if (array[mitad] > x) 
        {
            fin = mitad - 1;
        } 
        else 
        {
            inicio = mitad + 1;
        }
    }    
    return -1;
}

// Algoritmo insertion sort

void insertionSort(int array[], int n){
    int aux = 0;
    int j = 0;

    for (int i = 1; i < n; i++)
    {
        aux = array[i];
        j = i - 1;
       
        while (j >= 0 && array[j] > aux)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = aux;
    }
    return;
}

// Algoritmo burbujeo
void burbujeo(int array[], int n){
    int aux = 0;
    
    for(int i = 0; i < n-1; i++) 
    {    
        for(int j = 0; j < n-i-1; j++) 
        {
            if (array[j] > array[j+1]) 
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }            
        }        
    }
    return;
}

// Algoritmo burbujeo mejorado
void burbujeoMejorado(int array[], int n){

    int i = 0;    
    int aux = 0;
    bool ordenado = false;

    while (i < n && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < n-i-1; j++) 
        {
            if (array[j] > array[j+1]) 
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                ordenado = false; 
            }
        }              
        i++;
    }
    return;
}

// Apareo de vectores (Anexión)
void apareoVectores(int vectorA[], int n, int vectorB[], int m, int vectorC[], int &k) {
    
    int i = 0, j = 0;
    
    k = 0;
    
    while (i < n && j < m)
    { 
        
        if (vectorA[i] < vectorB[j])
        { 
            vectorC[k] = vectorA[i];
        
            i++;
        }        
        else 
        {
            vectorC[k] = vectorB[j];
            j++;
        }
    
        k++;
    }
    
    while(i < n)
    {
        vectorC[k] = vectorA[i];
        i++;
        k++;
    }
    
    while(j < m)
    {
        vectorC[k] = vectorB[j];
        j++;
        k++;
    }
    
    return;
}

// Cargar matriz
void cargarMatriz(int matriz[CANT_MAX_FILAS][CANT_MAX_COLUMNAS], int filas, int columnas){
        
    for(int i = 0; i < filas; i++)
    {   
        cout << "Ingrese los valores de la fila " << i + 1 << ": " << endl;
        for (int j = 0; j < columnas; j++)
        {
            cin >> matriz[i][j];
        }        
    }    
}

// Suma valores de las diagonales principal y secundaria de una matriz.
void sumarValoresDeDiagonales(int matriz[][CANT_MAX_FIL_COL], int filasColumnas, int &sumaDiagonalPrincipal, int &sumaDiagonalSecundaria){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j)
            {
                sumaDiagonalPrincipal += matriz[i][j];
            }

            if(i + j == filasColumnas - 1)
            {
                sumaDiagonalSecundaria += matriz[i][j];
            }
        }        
    }
    return;
}

// Imprimir elementos de la diagonal principal de una matriz.
void imprimirDiagonalPrincipal(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j)
            {
                cout << matriz[i][j] << " ";
            }            
        }                   
    }
    return;        
}

// Imprimir elementos de la diagonal secundaria de una matriz.
void imprimirDiagonalSecundaria(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i + j == filasColumnas - 1)
            {
                cout << matriz[i][j] << " ";
            }
        }                   
    }       
}

// Sumatoria de cada cuadrante de una matriz.
void sumarCuadrantes(int matriz[][CANT_MAX_FIL_COL], int filasColumnas, int &sumatoriaCuadrante1, int &sumatoriaCuadrante2, int &sumatoriaCuadrante3, int &sumatoriaCuadrante4){
    for(int i = 0; i < filasColumnas; i++)
    {
        for(int j = 0; j < filasColumnas; j++)
        {            
            if(i < filasColumnas/2 && j < filasColumnas/2)
            {
                sumatoriaCuadrante1 += matriz[i][j];
            }            
            else if(i < filasColumnas/2 && j >= filasColumnas/2)
            {
                sumatoriaCuadrante2 += matriz[i][j];
            }
            else if(i >= filasColumnas/2 && j < filasColumnas/2)
            {
                sumatoriaCuadrante3 += matriz[i][j];
            }
            else
            {
                sumatoriaCuadrante4 += matriz[i][j];
            }
        }
    }
    return;
}

// Imprimir primer cuadrante de una matriz (arriba a la izquierda).
void imprimirCuadrante1(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i < filasColumnas/2 && j < filasColumnas/2)
            {
                cout << matriz[i][j] << " ";
            }
        }             
    }
    return;        
}

// Imprimir segundo cuadrante de una matriz (arriba a la derecha).
void imprimirCuadrante2(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i < filasColumnas/2 && j >= filasColumnas/2)
            {
                cout << matriz[i][j] << " ";
            }
        }             
    }
    return;
}

// Imprimir tercer cuadrante de una matriz (abajo a la izquierda).
void imprimirCuadrante3(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i >= filasColumnas/2 && j < filasColumnas/2)
            {
                cout << matriz[i][j] << " ";
            }
        }             
    }
    return;        
}

// Imprimir cuarto cuadrante de una matriz (abajo a la derecha).
void imprimirCuadrante4(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i >= filasColumnas/2 && j >= filasColumnas/2)
            {
                cout << matriz[i][j] << " ";
            }
        }             
    }
    return;        
}

// Sumar elementos de la triangular superior de una matriz.
void sumarTriangularSuperior(int matriz[][CANT_MAX_FIL_COL], int filasColumnas, int &sumatoriaTriangularSuperior){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j || i <= j)
            {
                sumatoriaTriangularSuperior += matriz[i][j];
            }
        }        
    }
    return;
}

// Sumar elementos de la triangular inferior de una matriz.
void sumarTriangularInferior(int matriz[][CANT_MAX_FIL_COL], int filasColumnas, int &sumatoriaTriangularInferior){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j || i >= j)
            {
                sumatoriaTriangularInferior += matriz[i][j];
            }
        }        
    }
    return;
}

// Imprimir elementos de la triangular superior de una matriz.
void imprimirTriangularSuperior(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j || i <= j)
            {
                cout << matriz[i][j] << " ";
            }            
        }            
    }
    return;
}

// Imprimir elementos de la triangular inferior de una matriz.
void imprimirTriangularInferior(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j || i >= j)
            {
                cout << matriz[i][j] << " ";
            }
        }              
    }
    return;
}

//

int main () {
 
 return 0;
}