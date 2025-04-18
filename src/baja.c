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
        fseek(archivo, -sizeof(tSocio), SEEK_CUR); 
        if(socio.estado == 0){
            printf("El socio ya se encuentra dado de baja\n");
        }else{
            socio.estado = 0;
            printf("El socio con numero %d ha sido dado de baja\n", nro_baja);
            fwrite(&socio, sizeof(tSocio), 1, archivo);
        }
    }else{
        printf("El socio con numero %d no existe\n", nro_baja);
    }
}
