# 🧾 Trabajo Práctico - Archivo de Socios de un Club

**Materia:** Introducción a las Bases de Datos  
**Carrera:** Licenciatura en Sistemas - UNRN  
**Año:** 2025  
**Integrantes del grupo:**  
- Bravo Naim
- Letelle Mauro
- Perisse Lautaro  

---

## 📌 Descripción

Este programa, desarrollado en lenguaje C, tiene como objetivo realizar operaciones de mantenimiento sobre un archivo binario que contiene información de socios de un club. 

---

## 📋 Estructura del Registro

Cada socio está representado por los siguientes campos:

- Número de socio (int)
- DNI (int)
- Apellido y Nombres (char[50])
- Domicilio (char[50])
- Fecha de nacimiento: estructura de tipo "dd/mm/yyyy"
- Fecha de asociación: estructura de tipo "dd/mm/yyyy"
- Estado (int 1/0)

---

## 🧩 Módulos del sistema

1. **alta.c**  
   Da de alta un nuevo socio, controlando que no exista previamente el número de socio.
   Si existe, cambia su estado a activo con los datos previamente cargados.
   No sobreescribe históricos de bajas
   Muestra mensaje al usuario

3. **baja.c**  
   Elimina un socio del archivo, verificando su existencia.
   Verifica existencia del socio antes de intentar bajarlo
   Busca al socio en el archivo y hace la baja lógica (estado = 0).
   Muestra mensaje al usuario

5. **existe.c**  
   Comprueba si un número de socio ya está presente en el archivo.
   Devuelve 1 si el socio existe (sin importar si está activo o no).

7. **listado.c**  
   Muestra en pantalla todos los socios almacenados.
   Muestra solo los socios activos (estado == 1).

9. **socio.h**  
   Header de la estrucutra de socio y demas modulos del sistema.
   Usa estructura para el registro de longitud fija.

11. **main.c**  
   Menú principal del sistema, que muestra el menu y permite acceder a todas las funcionalidades anteriores.
   Usa fopen con rb+ o crea el archivo con wb+ si no existe.
   Pasa el puntero FILE *archivo a cada función.

---

## 🏗️ Implementacion / Compilación

