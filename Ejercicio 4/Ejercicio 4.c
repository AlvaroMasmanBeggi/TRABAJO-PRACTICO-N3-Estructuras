#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//declaro las nuevas variables tipo struct//

struct BaseDePuntos
{
	float X;
	float Y;
}Puntos[101];


struct FuncionLineal
{
	float X;
	float Y;
}Puntos_Recta[101];


//declaro las funciones a usar//

void CargarXCuadrado(struct BaseDePuntos *,float);
void ImprimirBaseDePuntos(struct BaseDePuntos *);
void GenerarRecta(struct FuncionLineal *,float,float,float);
void ImprimirFuncionLineal(struct FuncionLineal *);
void Interseccion(void);

//programa principal//

int main(int argc, char *argv[]) 
{
	//algunas variables auxiliares//
	
	int i;
	float x,m,b;
	
	//cargo la funcion cudratica en el sistema//
	
	x=-5;
	for(i=0;i<101;i++)
	{
		CargarXCuadrado(&Puntos[i],x);
		x=x+0.1;
	}
	
		
	//pido los parametros de la recta al usuario//
	
	printf("\nLa funcion cargada en el sistema es -> y=x^2 -> La cortaremos con una funcion afin o lineal, de caracteristicas ingresadas por el usuario\n");
	printf("\nLa recta tiene la forma y=mx+b, donde:\n\nm=pendiente\nb=ordenada al origen\n");
	printf("\nIngrese la pendiente m= ");
	scanf("%f",&m);
	printf("\nIngrese la ordenada al origen b= ");
	scanf("%f",&b);
	
	//genero los puntos de la recta//
	
	x=-5;
	for(i=0;i<101;i++)
	{
		GenerarRecta(&Puntos_Recta[i],m,b,x);
		x=x+0.1;
	}
	
	//chequeo las intersecciones entre las dos funciones//
	
	Interseccion();
	
	return 0;
}





//código de las funciones utilizadas//

void CargarXCuadrado(struct BaseDePuntos *A,float x)
{
	A->X=x;
	A->Y=pow(x,2);
}


void ImprimirBaseDePuntos(struct BaseDePuntos *A)
{
	printf("\nF(%f)= %f",A->X,A->Y);
}


void GenerarRecta(struct FuncionLineal *A,float M,float B,float x)
{
	A->X=x;
	A->Y=(M*x)+B;
}

void ImprimirFuncionLineal(struct FuncionLineal *A)
{
	printf("\nF(%f)= %f",A->X,A->Y);
}

void Interseccion(void)
{
	int i,bandera=0;
	
	for(i=0;i<101;i++)
	{
		if(Puntos[i].Y == Puntos_Recta[i].Y)
		{
			bandera=1;
			printf("\nLa recta corta a la función cuadratica en X=%f --> Y=%f",Puntos_Recta[i].X,Puntos_Recta[i].Y);
		}
		else
		{
			if((Puntos[i].Y < Puntos_Recta[i].Y) && (Puntos[i+1].Y > Puntos_Recta[i+1].Y))
			{
				bandera=1;
				printf("\nCorta a la funcion entre los siguientes puntos:");
				printf("\nEje X: %.2f  Eje Y: %.2f",Puntos[i].X,Puntos[i].Y);
				printf("\nEje X: %.2f  Eje Y: %.2f",Puntos[i+1].X,Puntos[i+1].Y);
			}
			if((Puntos[i].Y > Puntos_Recta[i].Y) && (Puntos[i+1].Y < Puntos_Recta[i+1].Y))
			{
				bandera=1;
				printf("\nCorta a la funcion entre los siguientes puntos:");
				printf("\nEje X: %.2f  Eje Y: %.2f",Puntos[i].X,Puntos[i].Y);
				printf("\nEje X: %.2f  Eje Y: %.2f",Puntos[i+1].X,Puntos[i+1].Y);
			}
		}
	}
	if(bandera==0)
	{
		printf("\nLa funcion lineal no corta a la funcion cuadratica entre x=-5 y x=5");
	}
}

