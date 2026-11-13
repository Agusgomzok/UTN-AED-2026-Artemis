#ifndef SIMULADOR_H
#define SIMULADOR_H

// Constantes Fisicas 
#define G_UNIVERSAL 6.674e-11        // N*m^2/kg^2
#define MASA_TIERRA 5.972e24         // kg
#define MASA_LUNA 7.342e22           // kg
#define RADIO_TIERRA 6371000.0       // m
#define DISTANCIA_TIERRA_LUNA 384000000.0 // m

// Estrategia de Representacion de Entidades Espaciales
typedef struct {
    double masa_nave;           // kg
    double v_tli;                   // m/s
    double altitud_leo;             // m
} MisionTranslunar;

//funciones de simulacion y calculo 
double calcular_energia_cinetica(double masa, double velocidad);
double calcular_trabajo_especifico_equilibrio(double altitud_leo);
void explicar_ley_inercia(void);
void explicar_diferencia_combustible(void);
void ejecutar_simulacion_escenario3(const MisionTranslunar* mision);

#endif // SIMULADOR_H