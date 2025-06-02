#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "socio.h"

void mostrar_menu();
void limpiar_pantalla();

int main() {
    FILE *archivo=  fopen("data/socios", "rb+");// no se lee nombre de archivo
    if (!archivo){
        archivo = fopen("data/socios", "wb+");// si no existe, lo crea
        if (!archivo) {
            printf("Error al abrir el archivo\n");
        }
    }
    int opcion;
    do//siempre queremos que el menu se muestre al menos una vez
    {
		int buscar;
        mostrar_menu();
        scanf("%d", &opcion);
        limpiar_pantalla();// limpia la pantalla para que el menu se vea mejor
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
            printf("Opcion no valida, intente nuevamente\n");
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

void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls");//windows
    #else
        system("clear");//linux o mac
    #endif
    }
    