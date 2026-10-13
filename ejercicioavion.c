#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	float fdr; /*frecuencia de radio*/
	float d; 	/*distancia*/
	char nombre[50];
}avion;


void menu(){
	
	printf("\n=========================");
	printf("1. ingresar cantidad de vuelos\n");
	printf("2. ingresar un nuevo vuelo\n");
	printf("3. mostrar frecuencias cercanas\n");
	printf("4. cerrar sala de comandos");
	printf("\n=========================");
}

	//funcion para seleccionar la cantidad de vuelos y asignarle la memoria dinamica correspondiente
	
void cantidad(avion **vuelos, int *cantidad, int *capacidad) {  //de parametros de entrada recibe punteros para modificar y actualizar los valores en la funcion main
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
void cercanas{
	float k
	for(i=1;i<=v;i++){
		k = identificacion[i+1].fdr - Identificacion[i].fdr;
	}
	if(k<10){
		puts("barcos cercanos menores a una fdr de 10m:%s y tiene una distancia de %f ", Identificacion[i],&k):
	}
	}
	
}


int main() {
	int opcion;
	do {
		menu();                                  
		printf("Opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: cantidad;
			break;
			case 2: ingresarnuevovuelo;
			break;
			case 3: mostraraviones;
			break;
			case 4: cercanas; 
			break;
			case 5: printf("hasta pronto");
 		}
	} while (opcion!=5);	
	return 0;
}



