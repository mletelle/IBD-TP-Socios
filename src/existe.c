#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "socio.h"
int existe(FILE *archivo, int nro_buscar){
    tSocio socio;
    int encontrado = 0;
    fseek(archivo, 0, SEEK_SET); // Mover el puntero al inicio del archivo
    while ((fread(&socio, sizeof(tSocio), 1, archivo) == 1) && (!encontrado)) {
        if (socio.numeroDeSocio == nro_buscar) {
            encontrado = 1;
        }
    }
    fseek(archivo, -(long)sizeof(tSocio), SEEK_CUR); 
    return encontrado;
}
