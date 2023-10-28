#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50


//declaro el tipo de dato struct a usar//

struct DatosDePersona
{
	char Apellido[MAX];
	char Nombre[MAX];
	int Edad;
	float Altura;
}Personas[10];

//declaro las funciones que voy a usar//


void CargarDatosUsuario(struct DatosDePersona *);
void ImprimirDatos(struct DatosDePersona *);
void CargarDatosPorReferencia(struct DatosDePersona *);
void CargarDatosPorValor(struct DatosDePersona A[]);

//programa principal//

int main(int argc, char *argv[]) 
{
	int cantidad_personas,i,selector=1;
	
	while(selector!=0)
	{
	printf("\n¿Que desea hacer?\n\n1-Ingresar datos por valor\n2-Ingresar datos por referencia\n3-Pedirle datos al usuario\n4-Imprimir todo\n5-Salir\n");
	scanf("%d",&selector);
	
	switch(selector)
	{
	case 1: CargarDatosPorValor(Personas); //cargo de la estructura 3 a la 5 //
			printf("\nSe ingresaron por valor desde la estructura 3 a la 5\n");
			break;
		
	case 2: CargarDatosPorReferencia(&Personas[0]); //en esta funcion cargo las 3 (0 a 2) primeras estructuras del arreglo con información//
			printf("\nSe ingresaron por referencia desde la estructura 0 a la 2\n");
			break;
		
	case 3: do
			{
				printf("\n¿Que cantidad de personas va a ingresar al sistema?\nRecuerde que solo quedan disponibles para cargar 5 estructuras mas: ");
				scanf("%d",&cantidad_personas);
				
			}while(cantidad_personas>5);
	
			for(i=6;i<6+cantidad_personas;i++)
			{
				printf("\n DATOS DE PERSONA %d",i+1);
				CargarDatosUsuario(&Personas[i]);
			}
			break;
			
	case 4: for(i=0;i<10;i++)
			{
				printf("\nPERSONA %d",i+1);
				ImprimirDatos(&Personas[i]);
			}
			break;
	case 5: selector=1;
			break;
	default: break;
	}
	}
	return 0;
}

//codigo de las funciones//

void CargarDatosUsuario(struct DatosDePersona *A)
{
	fflush(stdin);
	printf("\nIngrese el nombre de la persona: ");
	gets(A->Nombre);
	fflush(stdin);
	printf("\nIngrese el apellido de la persona: ");
	gets(A->Apellido);
	fflush(stdin);
	printf("\nIngrese la edad de la persona: ");
	scanf("%d",&A->Edad);
	fflush(stdin);
	printf("\nIngrese la altura de la persona: ");
	scanf("%f",&A->Altura);
	fflush(stdin);
}

void ImprimirDatos(struct DatosDePersona *A)
{
	puts("\n-----------------------------\n");
	
	printf("\nNombre de la persona: ");
	puts(A->Nombre);
	
	printf("\nApellido de la persona: ");
	puts(A->Apellido);
	
	printf("\n Edad de la persona: ");
	printf("%d",A->Edad);
	
	printf("\nAltura de la persona: ");
	printf("%.2f",A->Altura);
	
	puts("\n-----------------------------\n");
}

void CargarDatosPorReferencia(struct DatosDePersona *A)
{
	strcpy(A->Nombre,"Alvaro");
	strcpy(A->Apellido,"Masman");
	A->Edad=23;
	A->Altura=1.76;
	
	A++;
	
	strcpy(A->Nombre,"Matias");
	strcpy(A->Apellido,"Lopez");
	A->Edad=25;
	A->Altura=1.80;
	
	A++;
	
	strcpy(A->Nombre,"Daniel");
	strcpy(A->Apellido,"salas");
	A->Edad=24;
	A->Altura=1.85;
}

void CargarDatosPorValor(struct DatosDePersona A[])
{

	strcpy(A[3].Nombre,"Enrique");
	strcpy(A[3].Apellido,"Masman");
	A[3].Edad=60;
	A[3].Altura=1.78;
	
	strcpy(A[4].Nombre,"Gonzalo");
	strcpy(A[4].Apellido,"Franchini");
	A[4].Edad=25;
	A[4].Altura=1.80;
	
	
	strcpy(A[5].Nombre,"Laura");
	strcpy(A[5].Apellido,"Heras");
	A[5].Edad=24;
	A[5].Altura=1.85;
	
}
