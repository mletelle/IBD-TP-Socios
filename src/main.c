#include <stdio.h>
#include <string.h>

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
            existe (archivo);
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
    printf("Gestion de Socios\n");
    printf("1. Alta\n");
    printf("2. Baja\n");
    printf("3. Existe\n");
    printf("4. Listado\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion:\n");
}