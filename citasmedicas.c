#include <stdio.h>

typedef struct {
    char codigo_cita[16];
    char nombre_paciente[50];
    char especialidad[30];
    char fecha[11];
    char hora[6];
    char medico[50];
} Cita;