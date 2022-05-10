/*
 * input.c
 *
 *  Created on: 11/04/2022
 *      Author: melys
 */

#include "input.h"

//Validaciones

int myGets(char* cadena, int longitud)
{
  int retorno=-1;
  if(cadena!=NULL && longitud>0 && fgets(cadena,longitud,stdin)==cadena)
    {
      __fpurge(stdin);
      if(cadena[strlen(cadena)-1]=='\n')
        {
          cadena[strlen(cadena)-1]='\0';
          retorno=0;
        }
    }
  return retorno;
}

int esNumerica(char* cadena)
{
  int i=0;
  int retorno=-1;
  if(cadena!=NULL && strlen(cadena)>0)
    {
      while(cadena[i]!='\0')
        {
          if(cadena[i]<'0' || cadena[i]>'0')
            {
              retorno=0;
              break;
            }
          i++;
        }
    }
  return retorno;
}

int getInt(int* pResultado)
{
  int retorno=-1;
  char buffer[64];
  if(pResultado!=NULL)
    {
      if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
        {
          *pResultado=atoi(buffer);
          retorno=0;
        }
    }
  return retorno;
}

int esNumeroDecimal(char* cadena)
{
  int i=0;
  int retorno=-1;
  if(cadena!=NULL && strlen(cadena)>0)
    {
      for(i=0; i<longitud && cadena[i]!='\0'; i++)
        {
          if(cadena[i]<'0'||cadena[i]>'9')
           {
              if(cadena[i]=='.' && contadorPunto==0)
               {
                   contadorPunto++;
               }
               else
               {
                 retorno=0;
                 break;
               }
           }
        }
         
        
    }
  return retorno;
}

int getFloat(int* pResultado)
{
  int retorno=-1;
  char buffer[64];
  if(pResultado!=NULL)
    {
      if(myGets(buffer,sizeof(buffer))==0 && esNumeroDecimal(buffer))
        {
          *pResultado=atof(buffer);
          retorno=0;
        }
    }
  return retorno;
}


//Ingresos de Datos

int getNumero(int* pResultado,char mensaje[],char mensajeError[],int maximo,int minimo,int reintentos)
{
	int retorno=-1;
	int bufferInt;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos!=0)
	{
	    while(reintentos>0)
	      {
		 reintentos--;
		 printf("%s",mensaje);
		 if(getInt(&bufferInt)==0)
		 {
		   if(bufferInt>=minimo && bufferInt<=maximo)
		     {
		       *pResultado=bufferInt;
		       retorno=0;
		       break;
		     }
		 }
		 printf("%s", mensajeError);
	      }
	}

	return retorno;
}


float getNumeroFloat(float* pResultado,char mensaje[],char mensajeError[],int maximo,int minimo,int reintentos)
{
	int retorno=-1;
	float bufferInt;
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos!=0)
	{
	    while(reintentos>0)
	        {
	           reintentos--;
	           printf("%s",mensaje);
	           if(getFloat(&bufferInt)==0)
	             {
	               if(bufferInt>=minimo && bufferInt<=maximo)
	                {
	                   *pResultado=bufferInt;
	                   retorno=0;
	                   break;
	                }
	             }
	             printf("%s", mensajeError);
	        }
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
