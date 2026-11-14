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
```
## Instrucciones de Compilación y Ejecución
Abra el **Símbolo del sistema (CMD)** en la carpeta raíz del repositorio y ejecute los siguientes comandos:

### 1. Compilación con MinGW (Makefile)
```cmd
mingw32-make
Ejecucion: .\artemis_sim.exe
```
## Uso de Inteligencia Artificial como Herramienta de Apoyo
En cumplimiento con las pautas de transparencia de la cátedra, se detallan las consultas puntuales realizadas a herramientas de IA durante el desarrollo, utilizadas exclusivamente como soporte teórico y de depuración:

| Integrante | Herramienta | Consulta / Apoyo Puntual | Validación y Trabajo Propio |
| :--- | :--- | :--- | :--- |
| **Gomez, Agustin Ivan** | ChatGPT / Gemini | Verificación de convenciones de tipos `double` y formato exponencial (`%e`) en C para constantes astronómicas. | Desarrollo integral del modelo físico, despeje de ecuaciones de conservación de energía y pruebas de telemetría por tramos. |
| **Lopez, Andres Maximiliano** | Gemini | Consulta sobre el comportamiento del búfer `stdin` tras fallos de lectura con `scanf` y buenas prácticas en cabeceras `.h`. | Diseño e implementación de las funciones de validación de tipos/rangos y ejecución de pruebas de estrés con entradas inválidas. |
| **Fernandez, Lautaro Alejandro** | ChatGPT / Gemini | Resolución de errores de sintaxis en reglas de compilación modular (`Makefile`) y enlaces con `-lm`. | Diseño del menú principal, estructuración de `MisionTranslunar`, integración de los módulos y control de versiones en GitHub. |