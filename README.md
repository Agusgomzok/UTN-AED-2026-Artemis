# UTN-AED-2026-Artemis
## Trabajo Final Integrador - Simulador de Misiones Artemis

**Materia:** Algoritmos y Estructuras de Datos | UTN - Facultad Regional Resistencia  
**Escenario 3:** Inyección Translunar (TLI) e Inercia en Trayectoria Libre (1.ª Ley de Newton y Energía).

## Integrantes del grupo (Comisión 4)
* ** Gomez, Agustin Ivan - Legajo: [28913] *(Módulo Físico y Cálculos - `simulador`)*
* ** Lopez, Andres Maximiliano - Legajo: [28848] *(Módulo Validaciones e Interfaz - `validaciones`)*
* ** Fernandez, Lautaro Alejandro - Legajo: [29237] *(Módulo Principal, Menú y Compilación - `main`)*

## Descripción del Proyecto
Este simulador interactivo por consola, desarrollado en lenguaje C, modela el comportamiento físico y energético de la nave Orion tras apagar sus motores principales y ejecutar la maniobra de Inyección Translunar (TLI). El sistema evalúa la trayectoria libre en 10 tramos hasta el punto de equilibrio gravitatorio Tierra-Luna, calcula la energía cinética inicial ($K_i$), determina el trabajo específico mínimo requerido ($W_{\text{ext}}/m$) y expone los fundamentos teóricos de la 1.ª Ley de Newton y la asimetría energética ida/vuelta.

## Arquitectura del Sistema
El proyecto está estructurado de forma modular separando interfaces (`.h`) de implementaciones (`.c`):

```text
📁 Proyecto
├── 📁 include/
│   ├── simulador.h    (Constantes, struct MisionTranslunar, prototipos)
│   └── validaciones.h (Prototipos de lectura segura)
├── 📁 src/
│   ├── main.c         (Menú do-while/switch, inicialización)
│   ├── simulador.c    (Ecuaciones físicas y reporte)
│   └── validaciones.c (Filtrado de input, limpieza de buffer)
└── Makefile           (Script de compilación)

## Instrucciones de Compilación y Ejecución
Desde la carpeta raíz del repositorio:

```bash
# Opción 1: Utilizando Makefile (Linux/Mac) o mingw32-make (Windows)
make
./artemis_sim

# Opción 2: Compilación directa con GCC
gcc -Wall -Wextra -Iinclude src/main.c src/simulador.c src/validaciones.c -lm -o artemis_sim
./artemis_sim