#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TEMP 491 // Tope del vector

void llenarVectorManual(float Placas[], int tamaño) { // Funcion para llenar el vector y verificar los datos que ingresa el usuario.
    printf("Ingrese las %d temperaturas en º C de las placas madres:\n", tamaño);
    for (int i = 0; i < tamaño; i++) {
        printf("Elemento %d: ", i + 1001);
        char entrada[100]; // Leer la entrada del usuario como una cadena
        scanf("%s", entrada);
        char *endptr; // Convertir la cadena a float
        float valor = strtof(entrada, &endptr);

        if (*endptr != '\0') { // Verificar si la conversión fue exitosa y si el usuario ingresó caracteres adicionales.
            printf("Error: Por favor ingrese un número válido.\n");
            // Solicitar al usuario que vuelva a ingresar el valor.
            i--; // Hace que el valor del vector no quede vacio ya que vuelve uno atras.
            continue;
        }
        Placas[i] = valor; // Almacenar el valor en el vector
    }
}

void MaxTemperatura(float Placas[]) {
    system("clear"); // Para limpiar la terminal y que se vea mejor el resultado.
    int TempMax;
    TempMax = 0;
    for(int i = 0; i < MAX_TEMP;i++){ // Ciclo para recorrer los valores del vector Placas.
        if(TempMax<Placas[i]){
            TempMax = Placas[i]; // En TempMax va a quedar guardado la mayor temperatura.
        }
    }
    for(int i = 0; i < MAX_TEMP;i++){
        if(TempMax == Placas[i]){ // Se compara para ver si hay varios valores mayores.
            printf("El valor maximo es: %d º C y esta en la posicion: %d\n",TempMax,(i + 1001)); // El (i + 1001) es para ver en que valor de placa esta.
        }
    }
}

void ElPromedio(float Placas[]){
    system("clear"); // Para limpiar la terminal y que se vea mejor el resultado.
    float Contador = 0;
    for(int i = 0; i <= MAX_TEMP;i++){ // Ciclo para recorrer los valores del vector Placas.
        Contador += Placas[i]; // Se suman todos los valores del vector Placas.
    }
    printf("El promedio de todas las placas es: %.2f º C.\n",(Contador/MAX_TEMP)); // Se divide por MAX_TEMP para tener el promedio.
}

void SuperanElPromedio(float Placas[]){
    system("clear"); // Para limpiar la terminal y que se vea mejor el resultado.
    float Contador = 0,Promedio;
    // En vez de hacer el siguiente FOR se podria llamar a la funcion anterior, pero tendira que tener un return con el Promedio y etc.
    for(int i = 0; i <= MAX_TEMP;i++){ // Ciclo para recorrer los valores del vector Placas.
        Contador += Placas[i];
    }
    Promedio = (Contador/MAX_TEMP);
    printf("El promedio de todas las placas es: %.2f.\n",Promedio);
     for(int i = 0; i <= MAX_TEMP;i++){ // Ciclo para recorrer los valores del vector Placas.
        if(Placas[i] >= Promedio){ // Ve los valores Superan el promedio.
            printf("La placa %d supera el promedio y su temperatura es de: %.2f º C.\n",(i + 1001), Placas[i]);
        }
    }
}

void PlacasDefectuosas(float Placas[]){
    system("clear"); // Para limpiar la terminal y que se vea mejor el resultado.
    for(int i = 0; i <= MAX_TEMP;i++){ // Ciclo para recorrer los valores del vector Placas.
        if(Placas[i] < 30){ // Ve los valores que no superan el valor de 30.
            printf("La placa %d esta defectuosa y su temperatura es de: %.2f º C.\n",(i + 1001), Placas[i]);
        }
    }
}

void TemperaturaOptima(float Placas[]){
    system("clear"); // Para limpiar la terminal y que se vea mejor el resultado.
    int Perfecto = 0;
    for(int i = 0; i <= MAX_TEMP;i++){ // Ciclo para recorrer los valores del vector Placas.
        if( (Placas[i] >= 50) && (Placas[i] <= 70) ){ // Evaluan los valores que se encuentran entre 50 y 70.
            printf("La placa %d esta en estado optimo y su temperatura es de: %.2f º C.\n",(i + 1001), Placas[i]);
            Perfecto++;
        }
    }
    if(Perfecto == 0){ // Por si no hay ninguna que cumpla la condicon del if anterior se deja este mensaje.
        printf("No hay ni una sola placa en estado optimo.\n");
    }
}

int main(){
    system("clear"); // Para limpiar la terminal y que se vea mejor el resultado.
    int opcion;
    char Automatico;
    float Placas[MAX_TEMP];
    bool seguir = true ;
    
    printf("¡Bienvenido al sistema Placas electrónicas “SuperLogics”!\n");
    printf("Presione el ENTER del teclado para poder llenar las temperaturas...\n");
    getchar(); // Espera a que el usuario presione Enter y muestra la funcion para rellenar el vector Placas.

    llenarVectorManual(Placas,MAX_TEMP); // Llama a la funcion para poder llenarla manualmente.

    // Esta parte es para que se pueda ver bien el menu, ya que una buena comunicacion con el usuario es importante.
    printf("Para una visualización óptima del programa, se recomienda una resolución de la terminal de al menos 120x35 o superior.\n");
    printf("¡Gracias por tu atención!\n");

    while (seguir){ // El while es para la recursividad del menu.
        // Los ( - ) y los ( | ) son para remarcar el menu en la terminal, puede confundir un poco en el cogido ( no se que tan buena idea sea dejarlo ).
        printf("|---------------------------------------------------------------------------------------------------------------------|\n");
        printf("| Por favor, elija una opción del menú:                                                                               |\n");
        printf("|---------------------------------------------------------------------------------------------------------------------|\n");
        printf("| (1) -> Buscando la temperatura máxima y el número de orden de las placas que la alcanzaron                          |\n");
        printf("|---------------------------------------------------------------------------------------------------------------------|\n");
        printf("| (2) -> Calculando la temperatura promedio de todo el lote de dispositivos...                                        |\n");
        printf("|---------------------------------------------------------------------------------------------------------------------|\n");
        printf("| (3) -> Generando un resumen con los números de orden de las placas que superaron el promedio                        |\n");
        printf("|---------------------------------------------------------------------------------------------------------------------|\n");
        printf("| (4) -> Contando e informando cuántas placas poseen temperaturas menores a 30 º C                                    |\n");
        printf("|---------------------------------------------------------------------------------------------------------------------|\n");
        printf("| (5) -> Mostrando el número de orden y la temperatura de las placas que alcanzaron temperaturaturas entre 50 y 70 º C|\n");
        printf("|---------------------------------------------------------------------------------------------------------------------|\n");
        printf("| (6) -> Finalizar el programa...                                                                                     |\n");
        printf("|---------------------------------------------------------------------------------------------------------------------|\n");
        
        if (scanf("%d", &opcion) != 1) {
            system("clear"); // Para limpiar la terminal y que se vea mejor el resultado.
            printf("¡Error! Debes ingresar un número.\n");
            while (getchar() != '\n'); // Limpia el buffer de entrada.
            continue;
        }

        switch(opcion) {
            case 1:
                MaxTemperatura(Placas);
                break;
            case 2:
                ElPromedio(Placas);
                break;
            case 3:
                SuperanElPromedio(Placas);
                break;
            case 4:
                PlacasDefectuosas(Placas);
                break;
            case 5:
                TemperaturaOptima(Placas);
                break;
            case 6:
                system("clear");// Para limpiar la terminal y que se vea mejor el resultado.
                printf("CERRANDO EL PROGRAMA...\n");
                seguir = false;
                break;
            default:
                system("clear");// Para limpiar la terminal y que se vea mejor el resultado.
                printf("!!! SOLO VALIDOS VALORES DEL 1 AL 6 ¡¡¡\n");
                break;
        }
    }
    return 0;
}
// ERRORES --> 
// Aveces el vector de la nada se le agrega un valor que no deberia estar, por lo que da algunos valores raros. 
// Ej MAX_TEMP = 10 y de la nada el vector tiene 11 valores (Solo pasa algunas veces, la mayoria de veces funciona bien).