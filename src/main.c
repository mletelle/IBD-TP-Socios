#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "socio.h"

void mostrar_menu();

int main() {
    FILE *archivo=  fopen("data/socios.dat", "rb+");
    if (!archivo){
        archivo = fopen("data/socios.dat", "wb+");
        if (!archivo) {
            printf("Error al abrir el archivo\n");
        }
    }
    int opcion;
    do
    {
		int buscar;
        mostrar_menu();
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            alta(archivo);
            break;
        case 2:
            baja(archivo);
            break;
        case 3:
			printf("Ingrese numero a buscar: ");
			scanf("%d", &buscar);
            if (existe (archivo, buscar)){
                printf("El socio existe\n");
            } else {
                printf("El socio no existe\n");
            }
            break;
        case 4:
            listado(archivo);
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        default:
            break;
        }
    } while (opcion != 0);
    fclose(archivo);
    return 0;
}

void mostrar_menu() {
        printf("|-------------------------------|\n");
        printf("|--------Gestion de Socios------|\n");
        printf("|1-Alta-------------------------|\n");
        printf("|2-Baja-------------------------|\n");
        printf("|3-Existe-----------------------|\n");
        printf("|4-Listado----------------------|\n");
        printf("|0-Salir------------------------|\n");
        printf("|-------------------------------|\n");
        printf("|Seleccione una opcion:");
    }
