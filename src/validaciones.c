#include <stdio.h>
#include "validaciones.h"

void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void pausar_consola(void) {
    printf("\nPresione ENTER para continuar...");
    limpiar_buffer();
}

int leer_entero(const char *mensaje, int min, int max) {
    int valor;
    int lectura;
    int valido = 0;

    do {
        printf("%s", mensaje);
        lectura = scanf("%d", &valor);

        if (lectura != 1) {
            printf("Error: debe ingresar un numero entero.\n");
            limpiar_buffer();
        } else if (valor < min || valor > max) {
            printf("Error: el valor debe estar entre %d y %d.\n", min, max);
            limpiar_buffer();
        } else {
            limpiar_buffer();
            valido = 1;
        }
    } while (!valido);

    return valor;
}

double leer_double(const char *mensaje, double min, double max) {
    double valor;
    int lectura;
    int valido = 0;

    do {
        printf("%s", mensaje);
        lectura = scanf("%lf", &valor);

        if (lectura != 1) {
            printf("Error: debe ingresar un valor numerico.\n");
            limpiar_buffer();
        } else if (valor < min || valor > max) {
            printf("Error: el valor debe estar entre %.2f y %.2f.\n", min, max);
            limpiar_buffer();
        } else {
            limpiar_buffer();
            valido = 1;
        }
    } while (!valido);

    return valor;
}