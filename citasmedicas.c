#include <stdio.h>
void MostrarMenu();
    int main(){
        int opcion;
        do{
            MostrarMenu();
            scanf("%d", &opcion);
            switch (opcion){
                case 1:
                printf("\nRegistrar cita\n");
                break;
                case 2:
                printf("\nListar cita\n");
                break;
                case 3:
                printf("\nBuscar cita\n");
                break;
                case 4:
                printf("\nActualizar cita\n");
                break;
                case 5:
                printf("\n Eliminar cita\n");
                break;
                case 6:
                printf("\n Guardar cambios de la cita\n");
                break;
                case 7:
                printf("\nSalida\n");
                break;


            }
            
            
        }while(opcion !=7);
        return 0;
    }
void MostrarMenu(){
            printf("\n==========================================\n");
            printf("/ BIENVENIDO AL SISTEMA DE CITAS MEDICAS /\n");
            printf("==========================================\n");
            printf("1. Registrar cita\n");
            printf("2.Listar cita\n");
            printf("3.Buscar cita\n");
            printf("4.Actualizar cita\n");
            printf("5.Eliminar cita\n");
            printf("6. Guardar cambios de la cita\n");
            printf("7. Salir\n");
            printf("Seleccione una opción: ");
}
typedef struct {
    char codigo_cita[16];
    char nombre_paciente[50];
    char especialidad[30];
    char fecha[11];
    char hora[6];
    char medico[50];
} Cita;
