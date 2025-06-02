#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "socio.h"
void baja(FILE *archivo){
    tSocio socio;
    int nro_baja;
    printf("Ingrese el numero de socio a dar de baja: ");
    scanf("%d", &nro_baja);
    if(existe(archivo, nro_baja)){
        fseek(archivo, 0, SEEK_SET); //rewind
        int encontrado=0;
        while ((fread(&socio, sizeof(tSocio), 1, archivo) == 1)&&(encontrado==0)) {
            if (socio.numeroDeSocio == nro_baja) {
                socio.estado=0; // 0 para indicar que el socio esta inactivo
                fseek(archivo, -(long)sizeof(tSocio), SEEK_CUR);  //posiciona el puntero donde correspondia el socio
                fwrite(&socio, sizeof(tSocio), 1, archivo); // guardar el nuevo socio en el archivo
                printf("El socio fue dado de baja\n");
                encontrado=1;
            }
        }
    }else {
        printf("El socio no existe\n");
    }
}

