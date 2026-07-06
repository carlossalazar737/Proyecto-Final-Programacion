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
void BuscarCodigo();
void BuscarNombre();
void ActualizarCita();
void EliminarCita();
void GuardarCambios();
void CargarArchivo();
int main(){
    CargarArchivo();
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
                ActualizarCita();
                break;
                case 5:
                EliminarCita();
                break;
                case 6:
                GuardarCambios();
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
    printf("Seleccione la manera de búsqueda:\n");
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
void ActualizarCita(){
    char codigo[16];
    int opcion;
    printf("Ingrese el codigo de la cita a actualizar: ");
    scanf("%s", codigo);
    for (int i=0; i<totalCitas; i++){
        Cita *cita = &citas[i];
        if (strcmp(citas[i].codigo_cita, codigo) == 0){
            printf("=====Cita Actualizable=====\n");
            printf("Codigo: %s\n", cita->codigo_cita);
            printf("Nombre del paciente: %s\n", cita->nombre_paciente);
            printf("Especialidad: %s\n", cita->especialidad);
            printf("Fecha: %s\n", cita->fecha);
            printf("Hora: %s\n", cita->hora);
            printf("Medico: %s\n", cita->medico);
            do {
                printf("Seleccione el campo a actualizar:\n");
                printf("1. Nombre del paciente\n");
                printf("2. Especialidad\n");
                printf("3. Fecha\n");
                printf("4. Hora\n");
                printf("5. Medico\n");
                printf("6. Regresar al Menú Principal\n");
                printf("Ingrese su opción: ");
                scanf("%d", &opcion);
                switch (opcion) {
                    case 1:
                    printf("Ingrese el nuevo nombre del paciente: ");
                    scanf(" %[^\n]", cita->nombre_paciente);
                    break;
                    case 2:
                    printf("Ingrese la nueva especialidad: ");
                    scanf(" %[^\n]", cita->especialidad);
                    break;
                    case 3:
                    printf("Ingrese la nueva fecha (dd/mm/aaaa): ");
                    scanf("%s", cita->fecha);
                    break;
                    case 4:
                    printf("Ingrese la nueva hora (hh:mm): ");
                    scanf("%s", cita->hora);
                    break;
                    case 5:
                    printf("Ingrese el nuevo medico: ");
                    scanf(" %[^\n]", cita->medico);
                    break;
                    case 6:
                    printf("Regresando al Menú Principal\n");
                    break;
                    default:
                    printf("Opción inválida. Intente nuevamente.\n");
                }
            } while (opcion !=6);
         printf("Cita actualizada exitosamente.\n");
            return;
        }
    }
    printf("Cita no encontrada.\n");   
}
void EliminarCita(){
    char codigo[16];
    printf("\n=====Eliminar cita=====\n");
    printf("Ingrese el codigo de la cita a eliminar: ");
    scanf("%s", codigo);
    for (int i=0; i<totalCitas; i++){
        if (strcmp(citas[i].codigo_cita, codigo) == 0){
            printf("=====Cita eliminable=====\n");
            printf("Codigo: %s\n", citas[i].codigo_cita);
            printf("Nombre del paciente: %s\n", citas[i].nombre_paciente);
            printf("Especialidad: %s\n", citas[i].especialidad);
            printf("Fecha: %s\n", citas[i].fecha);
            printf("Hora: %s\n", citas[i].hora);
            printf("Medico: %s\n", citas[i].medico);
            printf("Desea eliminar esta cita? (S/N): ");
            char respuesta;
            scanf(" %c", &respuesta);
            if (respuesta == 'S' || respuesta == 's'){
                for (int j=i; j<totalCitas-1; j++){
                citas[j] = citas[j+1];
            }
            totalCitas--;
            
            printf("=====Cita eliminada exitosamente=====\n");
            }
            else{
                printf("Eliminación cancelada.\n");
            }
            return;
        }
    }
    printf("Cita no encontrada\n");
}
void GuardarCambios(){
    FILE *archivo;
    archivo = fopen("citas.csv", "a");
    if (archivo == NULL){
        printf("Error al abrir el archivo.\n");
        return;
    }
    for (int i=0; i<totalCitas; i++){
        fprintf(archivo, "%s,%s,%s,%s,%s,%s\n", 
            citas[i].codigo_cita, 
            citas[i].nombre_paciente, 
            citas[i].especialidad, 
            citas[i].fecha, 
            citas[i].hora, 
            citas[i].medico);
    }
    fclose(archivo);
    printf("=====Cambios guardados exitosamente en citas.csv=====\n");
}
void CargarArchivo(){
    FILE *archivo;
    archivo = fopen("citas.csv", "r");
    if (archivo == NULL){
        printf("No se pudo abrir el archivo citas.csv. Se creará uno nuevo al guardar cambios.\n");
        return;
    }
    while (fscanf(archivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", 
        citas[totalCitas].codigo_cita, 
        citas[totalCitas].nombre_paciente, 
        citas[totalCitas].especialidad, 
        citas[totalCitas].fecha, 
        citas[totalCitas].hora, 
        citas[totalCitas].medico) == 6){
            totalCitas++;
    }
    fclose(archivo);
}
