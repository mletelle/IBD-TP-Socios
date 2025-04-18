#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "socio.h"
//agrega al final, no busca lugares vacios, asi no borra el socio
void alta(FILE *archivo) {
    tSocio socio;
    printf("Ingrese el numero de socio: ");
    scanf("%d", &socio.numeroDeSocio);  
    printf("Ingrese el DNI: ");
    scanf("%d", &socio.DNI);
    printf("Ingrese el apellido: ");
    scanf("%24s", socio.apellido);
    printf("Ingrese el nombre: ");
    scanf("%24s", socio.nombre);
    printf("Ingrese el domicilio: ");
    scanf("%49s", socio.domicilio);
    printf("Ingrese la fecha de nacimiento (dd/mm/aaaa): ");
    scanf("%2d/%2d/%4d", &socio.fecNac.dia, &socio.fecNac.mes, &socio.fecNac.anio);
    printf("Ingrese la fecha de asociacion (dd/mm/aaaa): ");
    scanf("%2d/%2d/%4d", &socio.fecAsoc.dia, &socio.fecAsoc.mes, &socio.fecAsoc.anio);
    socio.estado=1; // 1 para indicar que el socio está activo
//buscamos altas solamente? o para reincorporaciones  buscamos bajas tmb?
    if (existe(archivo, socio.numeroDeSocio)){
        tSocio s; 
        rewind(archivo); 
        while (fread(&s, sizeof(tSocio), 1, archivo) == 1) {
            //revisa si hay algun lugar vacio por una baja logica
            if (s.numeroDeSocio == socio.numeroDeSocio) {
                s.estado=1; // 1 para indicar que el socio esta activo
                fseek(archivo, -(long)sizeof(tSocio), SEEK_CUR);  
                fwrite(&s, sizeof(tSocio), 1, archivo); // guardar el nuevo socio en el archivo
                fflush(archivo);
                printf("El socio ya existe, se cambio a activo\n");
            }
            }           
    }else {
        // agregar al final del archivo
        //porque si un socio se da de baja se sobreescribiria perdiendo su historia
        fseek(archivo, 0, SEEK_END); // Mover el puntero al final del archivo
        fwrite(&socio, sizeof(tSocio), 1, archivo); // Guardar el nuevo socio en el archivo
        fflush(archivo);
    }
}