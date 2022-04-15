/*
 * input.c
 *
 *  Created on: 11/04/2022
 *      Author: melys
 */

#include "input.h"

int getInt(int* pResultado,char mensaje[],char mensajeError[],int maximo,int minimo,int reintentos)
{
	int retorno=-1;
	int auxInt;
	int retornoScan;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos!=0)
	{
		printf("%s",mensaje);
		retornoScan=scanf("%d",&auxInt);
		do
		{
			if(auxInt>maximo || auxInt<minimo)
			{
				printf("%s",mensajeError);
				retornoScan=scanf("%d",&auxInt);
				reintentos--;
			}
			else
			{
				*pResultado=auxInt;
				retorno=0;
			}


		}while(retornoScan==0);
	}

	return retorno;
}


float getFloat(float* pResultado,char mensaje[],char mensajeError[],int maximo,int minimo,int reintentos)
{
	int retorno=-1;
	float aux;
	int retornoScan;
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos!=0)
	{
		printf("%s",mensaje);
		retornoScan=scanf("%f",&aux);
		do
		{
			if(aux>maximo || aux<minimo)
			{
				printf("%s",mensajeError);
				retornoScan=scanf("%f",&aux);
				reintentos--;
			}
			else
			{
				*pResultado=aux;
				retorno=0;
			}


		}while(retornoScan==0);
	}

	return retorno;
}

void menu(int* opcion, int km, float aerolineas, float latam)
{
	int aux;
	printf("\n\t   Bienvenidos     "
			"\n 1.Ingresar Kilometros km=%d"
			"\n 2.Ingresar Precios  Aerolineas=%f  Latam=%f"
			"\n 3.Calcular todos los costos"
			"\n 4.Informar resultados"
			"\n 5.Carga forzada de datos"
			"\n 6.Salir \n"
			"\nElija una opcion: ", km, aerolineas, latam);
	scanf("%d", &aux);
	*opcion=aux;
}
