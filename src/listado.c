#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "socio.h"
void listado(FILE *archivo){
    tSocio socio;
    fseek(archivo, 0, SEEK_SET); // Mover el puntero al inicio del archivo
    printf("|----------------------------------------------------------------------------------------|\n");//imprime como una tabla
    printf("|------------------------------------Listado de Socios-----------------------------------|\n");
    printf("+---------+-----------+-----------------+-----------------+------------------------------+\n");
    printf("| Numero  |    DNI    |     Nombre      |     Apellido    |          Domicilio           |\n");
    printf("+---------+-----------+-----------------+-----------------+------------------------------+\n");
    
    while (fread(&socio, sizeof(tSocio), 1, archivo) == 1) {
        if (socio.estado == 1) {
            printf("|%7d|%9d|%15s|%15s|%28s|\n",
                    socio.numeroDeSocio,
                    socio.DNI,
                    socio.nombre,
                    socio.apellido,
                    socio.domicilio);
        }
    }
    
    printf("+---------+-----------+-----------------+-----------------+------------------------------+\n");
    
}
