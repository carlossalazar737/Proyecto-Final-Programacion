#include <stdio.h>
#include <string.h>
typedef struct {
    char codigo_cita[16];
    char nombre_paciente[50];
    char especialidad[30];
    char fecha[11];
    char hora[6];
    char medico[50];
} Cita;
Cita citas[100];
int totalCitas = 0;
void MostrarMenu();
void RegistrarCita();
void ListarCitas();
    int main(){
        int opcion;
        do{
            MostrarMenu();
            scanf("%d", &opcion);
            switch (opcion){
                case 1:
                RegistrarCita();
                break;
                case 2:
                ListarCitas();
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
void RegistrarCita(){
    printf("\n=====Registro de cita=====\n");
    sprintf(citas[totalCitas].codigo_cita, "CITA%03d", totalCitas + 1);
    printf("Codigo de cita generado: %s\n", citas[totalCitas].codigo_cita);
    printf("Nombre del paciente: ");
    scanf(" %[^\n]",citas[totalCitas].nombre_paciente);
    printf("Especialidad: ");
    scanf(" %[^\n]",citas[totalCitas].especialidad);
    printf("Fecha (dd/mm/aaaa): ");
    scanf("%s", citas[totalCitas].fecha);
    printf("Hora (hh:mm): ");
    scanf("%s", citas[totalCitas].hora);
    printf("Medico: ");
    scanf(" %[^\n]", citas[totalCitas].medico);
    totalCitas++;
    printf("Cita registrada exitosamente.\n");
}
void ListarCitas(){
    printf("\n=====Listado de citas=====\n");
    if (totalCitas == 0) {
        printf("No hay citas registradas.\n");
        return;
    }
    for (int i=0; i<totalCitas; i++){
        printf("%s,%s, %s, %s, %s, %s\n", 
            citas[i].codigo_cita, 
            citas[i].nombre_paciente, 
            citas[i].especialidad, 
            citas[i].fecha, 
            citas[i].hora, 
            citas[i].medico);
    }
}
