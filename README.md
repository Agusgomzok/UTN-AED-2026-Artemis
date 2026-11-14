# UTN-AED-2026-Artemis
Integrantes del Grupo * Fernandez, Lautaro Alejandro * Gomez, Agustin Ivan * Lopez Andres Maximiliano
# Trabajo Final Integrador - Simulador de Misiones Artemis

Algoritmos y Estructuras de Datos | UTN  
Escenario 3 - Inyección Translunar (TLI) e Inercia en Trayectoria Libre (1.ª Ley de Newton y Energía).

## Integrantes del grupo (Comisión 4)
*   Integrante 1: - Legajo: [] *(Módulo Físico y Cálculos)*
*   Integrante 2: - Legajo: [] *(Módulo Validaciones e Interfaz)*
*   Integrante 3: - Legajo: [] *(Módulo Principal, Menú y Arquitectura)*

## Descripción del Proyecto
Este simulador por consola, desarrollado en lenguaje C, modela el comportamiento físico y energético de la nave Orion tras apagar sus motores principales y ejecutar la maniobra de Inyección Translunar (TLI). El sistema evalúa el comportamiento inercial, el cálculo de energía cinética inicial y el trabajo específico requerido para alcanzar el punto de equilibrio gravitatorio Tierra-Luna.

## Arquitectura del Sistema
El software fue diseñado bajo un paradigma modular para garantizar escalabilidad y responsabilidades únicas:

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