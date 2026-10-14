#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	float fdr; /*frecuencia de radio*/
	float d; 	/*distancia*/
	char nombre[50];
}avion;


void menu(){
	
	printf("\n================================\n");
	printf("1. ingresar cantidad de vuelos\n");
	printf("2. ingresar un nuevo vuelo\n");
	printf("3. mostrar frecuencias cercanas\n");
	printf("4. cerrar sala de comandos");
	printf("\n================================\n");
}

	//funcion para seleccionar la cantidad de vuelos y asignarle la memoria dinamica correspondiente
	
void cantidadv(avion **vuelos, int *cantidad, int *capacidad) {  //de parametros de entrada recibe punteros para modificar y actualizar los valores en la funcion main
		printf("Ingrese la cantidad de vuelos iniciales: ");
		scanf("%d", cantidad); 
		
		*capacidad = *cantidad;
		*vuelos = (avion *)malloc((*capacidad) * sizeof(avion));  //asignacion de memoria
		
		if (*vuelos == NULL) {
			printf("Error de asignacion de memoria.\n"); //verificamos si se asigno la memoria
			return;
		}
		
		for (int i = 0; i < *cantidad; i++) { //utilizamos un for para repetir el bucle hasta ingresar la cantidad de vuelos especificada
			printf("\nComplete los datos del vuelo %d:\n", i + 1);
			printf("Ingrese la frecuencia de radio: ");
			scanf("%f", &((*vuelos)[i].fdr)); 
			
			printf("Ingrese la distancia: ");
			scanf("%f", &((*vuelos)[i].d));   
			
			printf("Ingrese el nombre del vuelo %d: ", i + 1);
			scanf("%s", (*vuelos)[i].nombre); 
		}
	}

//funcion para ingresar un vuelo en todo momento


void ingresarvuelo(avion **vuelos, int *cantidad, int *capacidad) { //vuelve a recibir punteros de parametros de entrada
	if (*capacidad == 0) {
		*capacidad = 1;
		*vuelos = (avion *)malloc((*capacidad) * sizeof(avion)); //le asignamos memoria
	} else {
		(*capacidad)++;
		avion *temp = (avion *)realloc(*vuelos, (*capacidad) * sizeof(avion));
		if (temp == NULL) {
			printf("Error al reasignar memoria.\n");
			return;
		}
		*vuelos = temp;
	}
	
	int i = *cantidad; 
	printf("\ncomplete los datos del nuevo vuelo %d:\n", i + 1); //ingresamos los datos del vuelo
	printf("ingrese la frecuencia de radio: ");
	scanf("%f", &((*vuelos)[i].fdr));
	
	printf("ingrese la distancia: ");
	scanf("%f", &((*vuelos)[i].d));
	
	printf("ingrese el nombre del vuelo %d: ", i + 1);
	scanf("%s", (*vuelos)[i].nombre);
	
	(*cantidad)++; 
	printf("Vuelo agregado correctamente\n");
}

//funcion para mostrar los vuelos ingresados en pantalla

void mostraraviones(avion *vuelos, int cantidad) {  //recibe puntero a la struct del avion y un entero q indica los elementos a recorrer
	if (cantidad == 0) {
		printf("\nno hay vuelos registrados para mostrar\n");
		return;
	}
	
	printf("\n== aviones registrados ==\n");
	for (int i = 0; i < cantidad; i++) { //bucle que recorre el arreglo y muestra los datos de los vuelos ingresados
		printf("  Avion %d:\n", i + 1);
		printf("  Nombre: %s\n", vuelos[i].nombre);
		printf("  Frecuencia de Radio: %.2f MHz\n", vuelos[i].fdr);
		printf("  Distancia: %.2f km\n", vuelos[i].d);
	}
}
void freq_cercanas(avion *vuelos, int cantidad) {  //recibe un puntero al arreglo de estructura y un entero que es el limite sup del arreglo
	if (cantidad == 0) {  //comprobamos que hayan vuelos a buscar
		printf("\nno hay vuelos registrados aun\n");
		return;
	}
	
	float freq_buscada, porcentaje;
	printf("\nIngrese la frecuencia de radio objetivo (MHz): ");
	scanf("%f", &freq_buscada);
	printf("Ingrese el porcentaje de tolerancia permitido: ");
	scanf("%f", &porcentaje);
	
	float margen = freq_buscada * (porcentaje / 100.0); // Calculamo el margen inferior y superior según el porcentaje
	float limite_inf = freq_buscada - margen;  //definimos los limites de nuestro entorno
	float limite_sup = freq_buscada + margen;
	
	printf("\n== Resultados: Vuelos con frecuencia entre %.2f y %.2f MHz ==\n", limite_inf, limite_sup);
	int encontrados = 0;
	
	for (int i = 0; i < cantidad; i++) {
		
		if (vuelos[i].fdr >= limite_inf && vuelos[i].fdr <= limite_sup) { // verificamos si la frecuencia del vuelo cae dentro del rango de tolerancia
			printf("  Coincidencia: Vuelo '%s' | Frecuencia: %.2f MHz | Distancia: %.2f km\n", 
				   vuelos[i].nombre, vuelos[i].fdr, vuelos[i].d); 
			encontrados++;
		} //llave del if
	}
	
	if (encontrados == 0) {
		printf("No se encontraron vuelos dentro del porcentaje de tolerancia buiscado\n");
	}
}

int main() {  //funcion principal
	int opcion;
	avion *vuelos = NULL; // Puntero para la memoria dinamica de los aviones
	int cantidad = 0;     // Cantidad actual de vuelos registrados
	int capacidad = 0;    // Capacidad total reservada en memoria
	
	do {
		menu();          
		printf("Opcion: ");
		scanf("%d", &opcion);   
		
		switch(opcion) {   //en cada caso llamamos a la funcion responsable de hacer lo que el usuario haya elegido
		case 1: 
			cantidadv(&vuelos, &cantidad, &capacidad); 
			break;
		case 2: 
			ingresarvuelo(&vuelos, &cantidad, &capacidad); 
			break;
		case 3: 
			mostraraviones(vuelos, cantidad); 
			break;
		case 4: 
			freq_cercanas(vuelos, cantidad);
			break;
		case 5: 
			printf("Hasta pronto!\n");
			break;
		default:
			printf("Opcion invalida\n");
		}
	} while (opcion != 5); 
	
	if (vuelos != NULL) {
		free(vuelos);
	}
	
	return 0;
}
