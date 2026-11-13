#include <stdio.h>
#include <math.h>
#include "simulador.h"

double calcular_energia_cinetica(double masa, double velocidad) {
    return 0.5 * masa * velocidad * velocidad;
}

double calcular_trabajo_especifico_equilibrio(double altitud_leo) {
    double r0 = RADIO_TIERRA + altitud_leo;
    // r_eq = D / (1 + sqrt(ML/MT))
    double r_eq = DISTANCIA_TIERRA_LUNA / (1.0 + sqrt(MASA_LUNA / MASA_TIERRA));
    // Trabajo especifico (W/m) = G * MT * (1/r0 - 1/req)
    return G_UNIVERSAL * MASA_TIERRA * ((1.0 / r0) - (1.0 / r_eq));
}

void explicar_ley_inercia(void) {
    printf("\n--- Fundamento Teorico: 1.a Ley de Newton ---\n");
    printf("Tras apagar los motores (TLI), la nave viaja por inercia.\n");
    printf("La velocidad disminuye paulatinamente debido a la continua desaceleracion gravitatoria terrestre.\n");
}

void explicar_diferencia_combustible(void) {
    printf("\n--- Asimetria de Combustible ---\n");
    printf("Ida: Requiere vencer el profundo pozo gravitatorio de la Tierra (gran Delta-v).\n");
    printf("Vuelta: La Luna tiene menor masa y un pozo gravitatorio debil, exigiendo menos combustible.\n");
}

void ejecutar_simulacion_escenario3(MisionTranslunar* mision) {
    double r0 = RADIO_TIERRA + mision->altitud_leo;
    double r_eq = DISTANCIA_TIERRA_LUNA / (1.0 + sqrt(MASA_LUNA / MASA_TIERRA));
    double delta_r = (r_eq - r0) / 10.0;
    
    double v0 = mision->v_tli;
    double r_actual, radicando;
    int i; 

    printf("\n--- TELEMETRIA: SIMULACION TRANSLUNAR (10 TRAMOS) ---\n");
    printf("Energia cinetica inicial: %.2e J\n", calcular_energia_cinetica(mision->masa_nave, v0));
    printf("Trabajo especifico min. requerido: %.2e J/kg\n\n", calcular_trabajo_especifico_equilibrio(mision->altitud_leo));

    printf("| Tramo | Distancia al centro T. (m) | Velocidad (m/s) | Estado    |\n");
    printf("|-------|----------------------------|-----------------|-----------|\n");

    for (i = 0; i < 10; i++) {
        r_actual = r0 + (i + 1) * delta_r;
        mision->distancias_tramos[i] = r_actual;

        // Ecuacion despejada: v(r) = sqrt( v0^2 + 2GMT(1/r - 1/r0) )
        radicando = (v0 * v0) + 2.0 * G_UNIVERSAL * MASA_TIERRA * ((1.0 / r_actual) - (1.0 / r0));

        if (radicando <= 0.0) {
            mision->velocidades_tramos[i] = 0.0;
            printf("| %-5d | %-26.2e | %-15.2f | CAIDA     |\n", i + 1, r_actual, 0.0);
            printf("\n[FALLO] La nave agoto su energia cinetica antes de r_eq y cae hacia la Tierra.\n");
            break;
        } else {
            mision->velocidades_tramos[i] = sqrt(radicando);
            printf("| %-5d | %-26.2e | %-15.2f | EN VUELO  |\n", i + 1, r_actual, mision->velocidades_tramos[i]);
        }
    }
}