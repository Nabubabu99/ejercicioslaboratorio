#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_SURCUSAL 4

struct Articulo
{
    int codArticulo;
    int codSurcusal;
    char tipoMov;
    int cantidad;
};

int main(){
    int cantArticulos = 9;
    int cantArticulosXSurcusal = 3;
    int articuloxSurcusal[cantArticulos][3] = {
        {3500, 0},
        {220, 0},
        {300, 0},
        {700, 1},
        {1500, 1},
        {5500, 1},
        {500, 2},
        {0, 2},
        {100, 2},
        {300, 3},
        {0, 3},
        {150, 3}
    };
    Articulo articulos[cantArticulosXSurcusal] = {
        {0,0, 'E', 500},
        {1,0, 'E', 150},
        {2,0, 'S', 750},
        {0,1, 'S', 1000},
        {1,1, 'E', 740},
        {2,1, 'E', 800},
        {0,2, 'E', 350},
        {1,2, 'S', 150},
        {2,2, 'S', 630},
        {0,3, 'E', 1000},
        {1,3, 'E', 640},
        {2,3, 'S', 780}
    }

    return 0;
}

void informeArticulosXSurcusal(){
    
}