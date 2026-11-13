#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "simulador.h"

void mostrar_menu() {
    printf("\n======================================================\n");
    printf("   SIMULADOR ARTEMIS - ESCENARIO 3: TLI E INERCIA\n");
    printf("======================================================\n");
    printf("1. Ejecutar simulacion con valores oficiales (Orion)\n");
    printf("2. Ejecutar simulacion personalizada\n");
    printf("3. Calcular Trabajo Especifico Minimo (Punto de Equilibrio)\n");
    printf("4. Consultar Fundamentos Teoricos (1ra Ley de Newton y Combustible)\n");
    printf("5. Salir del simulador\n");
    printf("======================================================\n");
}

int main() {
    int opcion;
    double trabajo_calculado;
    
    // Inicializacion con valores oficiales del TFI
    MisionTranslunar mision_actual = {
        .masa_nave = 26000.0, 
        .v_tli = 10900.0, 
        .altitud_leo = 192000.0
    };

    do {
        mostrar_menu();
        opcion = leer_entero("Seleccione una opcion (1-5): ", 1, 5);

        switch (opcion) {
            case 1:
                printf("\n--- EJECUTANDO SIMULACION OFICIAL ---\n");
                ejecutar_simulacion_escenario3(&mision_actual);
                pausar_consola();
                break;
                
            case 2:
                printf("\n--- CONFIGURACION PERSONALIZADA ---\n");
                mision_actual.masa_nave = leer_double("Ingrese la masa de la nave (kg) [1000 - 100000]: ", 1000.0, 100000.0);
                mision_actual.v_tli = leer_double("Ingrese la velocidad de inyeccion TLI (m/s) [5000 - 20000]: ", 5000.0, 20000.0);
                mision_actual.altitud_leo = leer_double("Ingrese la altitud LEO inicial (m) [100000 - 500000]: ", 100000.0, 500000.0);
                
                printf("\nValores actualizados correctamente. Ejecutando...\n");
                ejecutar_simulacion_escenario3(&mision_actual);
                pausar_consola();
                break;
                
            case 3:
                printf("\n--- CALCULO DE TRABAJO ESPECIFICO ---\n");
                trabajo_calculado = calcular_trabajo_especifico_equilibrio(mision_actual.altitud_leo);
                printf("El trabajo adicional minimo requerido por unidad de masa es: %.2f J/kg\n", trabajo_calculado);
                pausar_consola();
                break;
                
            case 4:
                printf("\n--- FUNDAMENTOS TEORICOS ---\n");
                explicar_ley_inercia();
                printf("\n");
                explicar_diferencia_combustible();
                pausar_consola();
                break;
                
            case 5:
                printf("\nSaliendo del simulador. ¡Mision abortada con exito!\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}