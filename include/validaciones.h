#ifndef VALIDACIONES_H
#define VALIDACIONES_H

void limpiar_buffer(void);
void pausar_consola(void);


int leer_entero(const char *mensaje, int min, int max);
double leer_double(const char *mensaje, double min, double max);

#endif