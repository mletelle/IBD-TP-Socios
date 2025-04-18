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
- Fecha de nacimiento: "dd/mm/yyyy"
- Fecha de asociación: "dd/mm/yyyy"

---

## 🧩 Módulos del sistema

1. **alta.c**  
   Da de alta un nuevo socio, controlando que no exista previamente el número de socio.

2. **baja.c**  
   Elimina un socio del archivo, verificando su existencia.

3. **existe.c**  
   Comprueba si un número de socio ya está presente en el archivo.

4. **listado.c**  
   Muestra en pantalla todos los socios almacenados.

5. **socio.h**  
   Header de la estrucutra de socio y demas modulos del sistema.

6. **main.c**  
   Menú principal del sistema, que muestra el menu y permite acceder a todas las funcionalidades anteriores.
---

## 🏗️ Implementacion / Compilación

