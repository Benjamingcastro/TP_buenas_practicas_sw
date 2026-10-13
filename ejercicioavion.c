#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct identificacion{
	float fdr; /*frecuencia de radio*/
	float d; 	/*distancia*/
	char nombre[30];
}Identificacion[];
void menu(){
	
	printf("\n=========================");
	printf("1. ingresar cantidad de vuelos\n");
	printf("2. ingresar un nuevo vuelo\n");
	printf("3. mostrar frecuencias cercanas\n");
	printf("4. cerrar sala de comandos");
	printf("\n=========================");
}
 cantidadv(int c){
	struct identificacion vuelos;
	int v,i;
	float t,l,*pid,*temp;
	printf("ingrese la cantidad de vuelos: ");
	scanf("%d", &v);
	printf("usted ingresara %d vuelos",&v);
	for(i=1;i<=v;i++){
		printf("complete los datos del vuelo %d\n",i);
		printf("ingrese la frecuencia de radio: ");
		scanf("%f"&t);
		temp = &t;
		(*temp)= Identificacion.fdr;
		printf("\ningrese la distancia: ");
		scanf("%f",&l);
		temp=&l;
		(*temp)= identificacion.d;
		printf("\ningrese el nombre del vuelo %d: ",i);
		gets(identification.nombre[i]);
		free(temp);
	}
	return c;
}

void ingresarvuelo{
	identificacion[v+1];
	rintf("complete los datos del vuelo %d\n",i+1);
	printf("ingrese la frecuencia de radio: ");
	scanf("%f"&t);
	temp = &t;
	(*temp)= Identificacion.fdr;
	printf("\ningrese la distancia: ");
	scanf("%f",&l);
	temp=&l;
	(*temp)= Identificacion.d;
	printf("\ningrese el nombre del vuelo %d: ",i);
	gets(identification.nombre[i+1]);
	free(temp);
}
void mostraraviones(Identificacion[], int i,int,int) {
	for (i = 0; i <= v; i++){ 
	printf("avion %d ", i);
	puts(Identificacion[i]);
	}
}
void cercanas{
	float k
	for(i=1;i<=v;i++){
		k = identificacion[i+1].fdr - Identificacion[i].fdr;
	}
	if(k<10){
		puts("barcos cercacnos menores a una fdr de 10m:%s y tiene una distancia de %f ", Identificacion[i],&k):
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
			case 1: cantidadv;
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



