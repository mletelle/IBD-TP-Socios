#ifndef SOCIOS_H
#define SOCIOS_H

#include <stdio.h>

#define N 25
#define D 50
#define FECHA_LEN 11

typedef struct FecNac {
    int dia;
    int mes;
    int anio;
} tFecNac;

typedef struct Socio {
    int numeroDeSocio;
    int DNI;
    char apellido[N];
    char nombre[N];
    char domicilio[D];
    tFecNac fecNac;
    tFecNac fecAsoc;
    int estado; // 1 para activo, 0 para inactivo
} tSocio;

/* Prototipos */
int existe(FILE *archivo, int nro_buscar);
void alta(FILE *archivo);
void baja(FILE *archivo);
void listado(FILE *archivo);

#endif /* SOCIOS_H */
