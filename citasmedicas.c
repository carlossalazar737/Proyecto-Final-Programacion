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
void BuscarCita();
void MostrarminiMenu();
void BuscarCodigo();
void BuscarNombre();
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
                BuscarCita();
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
void BuscarCita(){
    int opcion;
    printf("\n=====Buscar cita=====\n");
    printf("Seleccione el criterio de búsqueda:\n");
    printf("1. Buscar por código\n");
    printf("2. Buscar por nombre del paciente\n");
    printf("3. Regresar al Menú Principal\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
        BuscarCodigo();
        break;
        case 2:
        BuscarNombre();
        break;
        case 3:
        printf("Regresar al Menú Principal\n");
        break;
    }
}
void BuscarCodigo(){
    char codigo[16];
    printf("Ingrese el codigo de la cita: ");
    scanf("%s", codigo);
    for (int i=0; i<totalCitas; i++){
        if (strcmp(citas[i].codigo_cita, codigo) == 0){
            printf("=====Cita encontrada=====\n");
            printf("Codigo: %s\n", citas[i].codigo_cita);
            printf("Nombre del paciente: %s\n", citas[i].nombre_paciente);
            printf("Especialidad: %s\n", citas[i].especialidad);
            printf("Fecha: %s\n", citas[i].fecha);
            printf("Hora: %s\n", citas[i].hora);
            printf("Medico: %s\n", citas[i].medico);
            return;
        }
    }
    
    printf("Cita no encontrada.\n");
}
void BuscarNombre(){
    char nombre[50];
    printf("ingrese el nombre del paciente: ");
    scanf(" %[^\n]", nombre);
    for (int i=0; i<totalCitas; i++){
        if (strcmp(citas[i].nombre_paciente, nombre) == 0){
            printf("=====Cita encontrada=====\n");
            printf("Codigo: %s\n", citas[i].codigo_cita);
            printf("Nombre del paciente: %s\n", citas[i].nombre_paciente);
            printf("Especialidad: %s\n", citas[i].especialidad);
            printf("Fecha: %s\n", citas[i].fecha);
            printf("Hora: %s\n", citas[i].hora);
            printf("Medico: %s\n", citas[i].medico);
            return;
        }
    }
    printf("Cita no encontrada.\n");
}
