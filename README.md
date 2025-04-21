# Trabajo Práctico - Archivo de Socios de un Club

---

## Descripción

Este programa, desarrollado en lenguaje C, tiene como objetivo realizar operaciones de mantenimiento sobre un archivo binario que contiene información de socios de un club. 

---

## Estructura del Registro

Cada socio está representado por los siguientes campos:

- Número de socio (int)
- DNI (int)
- Apellido y Nombres (char[50])
- Domicilio (char[50])
- Fecha de nacimiento: estructura de enteros representada como "dd/mm/yyyy"
- Fecha de asociación: estructura de enteros representada como "dd/mm/yyyy"
- Estado (int 1/0)

---

## Implementacion de los módulos del sistema

1. **alta.c**  
   Da de alta un nuevo socio, controlando que no exista previamente el número de socio.
   Si existe, cambia su estado a activo con los datos previamente cargados.
   No sobreescribe históricos de bajas.
   Muestra mensaje de éxito al usuario.

2. **baja.c**  
   Elimina lógicamente un socio del archivo.
   Verifica existencia del socio antes de intentar bajarlo.
   Busca al socio en el archivo y hace la baja lógica (estado = 0).
   Muestra mensaje al usuario:
   - Si existe, informa que ha sido dado de baja.
   - Si no existe, informa que no se ha encontrado socio con ese numero. 

3. **existe.c**  
   Comprueba si un número de socio ya está presente en el archivo.
   Devuelve 1 si el socio existe (sin importar si está activo o no).

4. **listado.c**  
   Muestra en pantalla los socios activos almacenados.
   Los socios activos son aquellos cuyo `estado == 1`.

5. **socio.h**  
   Header de la estrucutra de socio y demas modulos del sistema.
   Usa estructura para el registro de longitud fija.

6. **main.c**  
   Contiene el programa principal que administra la ejecución del sistema:
   - abre (o crea si no existe) el archivo binario de socios
   - muestra el menú de opciones al usuario
   - llama a las funciones correspondientes (alta, baja, existe, listado)
   - pasa el puntero al archivo como argumento para operar directamente sobre él.

---

## Flujo del sistema
````mermaid
flowchart TD
    Start(["Inicio"]) --> Menu{"Mostrar menu"}
    Menu -- 1 --> Alta["Alta"]
    Menu -- 2 --> Baja["Baja"]
    Menu -- 3 --> Existe["Existe"]
    Menu -- 4 --> Listado["Listado"]
    Menu -- 0 --> End(["Salir"])
    Alta --> Check1["existe nroSocio"]
    Check1 -- true --> Reactivar["Reactivar socio"]
    Check1 -- false --> Append["Añadir socio al final del archivo"]
    Reactivar --> Menu
    Append --> Menu
    Baja --> Check2["existe nroSocio"]
    Check2 -- true --> Inactivate["Marcar socio como inactivo"]
    Check2 -- false --> NoExist1["Mensaje: “no existe”"]
    Inactivate --> Menu
    NoExist1 --> Menu
    Existe --> LoopEx["Recorrer archivo con fread"]
    LoopEx --> FoundEx{"nroSocio == buscado?"}
    FoundEx -- si --> ReturnTrue["return true"]
    FoundEx -- no --> LoopEx
    ReturnTrue --> Menu
    LoopEx -- fin archivo --> ReturnFalse["return false"]
    ReturnFalse --> Menu
    Listado --> LoopList["Recorrer archivo con fread"]
    LoopList --> CheckAct{"estado == 1?"}
    CheckAct -- si --> PrintRec["Imprimir registro"]
    CheckAct -- no --> LoopList
    PrintRec --> LoopList
    LoopList -- fin archivo --> Menu

    Check1@{ shape: diam}
    Check2@{ shape: diam}
````
---
## Requisitos y Compilación
Se emplea el comando `gcc -Wall -std=c99 -g -o main.exe src\main.c src\alta.c src\baja.c src\existe.c src\listado.c` para generar el `.exe`.

Requisitos:
- Sistema operativo:
   - Windows: para ejecutar el `.exe` o GCC instalado para compilar 
   - Linux: GCC instalado para compilar 
- Compilador: GCC (MinGW)
- Editor: Visual Studio Code con extensión C/C++
