/*
 * input.c
 *
 *  Created on: 11/04/2022
 *      Author: Melina Ochoa
 */

#include "input.h"

//Validaciones

static int myGets(char* cadena, int longitud);
static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int getString(char pLetrasTomadas[]);

static int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[5000];
	if(cadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString))<=longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

static int getInt(int* pResultado)
{
  int retorno=-1;
  char buffer[64];
  if(pResultado!=NULL)
    {
      if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer,sizeof(buffer))==1)
        {
          *pResultado=atoi(buffer);
          retorno=0;
        }
    }
  return retorno;
}

int esNumerica(char* cadena, int longitud)
{
	int retorno= 1;
		int i;
		if(cadena!=NULL)
		{

			for(i=0; i<longitud && cadena[i]!='\0'; i++)
			{
				if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
				{
					continue;
				}
				if(cadena[i]<'0'||cadena[i]>'9')
				{
					retorno=0;
					break;
				}
			}
		}
		return retorno;
	}



int esNumeroDecimal(char* cadena)
{
  int i=0;
  int retorno=-1;
  int contadorPunto=0;
  if(cadena!=NULL && strlen(cadena)>0)
    {
      for(i=0;cadena[i]!='\0'; i++)
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

static int getFloat(float* pResultado)
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

int soloLetra(char* pResultado)
{
        int retorno=-1;
        int i;
        if(pResultado!=NULL && strlen(pResultado)>0)
        {
                for(i=0;i<strlen(pResultado);i++)
                {
                        if(isalpha(pResultado[i])==0)
                        {
                                retorno=0;
                                break;
                        }
                }
        }
        return retorno;
}

int esConEspacio(char *pResultado)
{
        int retorno = 1;
        int i;

        if (pResultado!=NULL && strlen(pResultado)>0)
        {
                for(i = 0; i < strlen(pResultado); i++)
                {
                        if (isalpha(pResultado[i])==0)
                        {
                                if (isspace(pResultado[i])==0)
                                {
                                        retorno=0;
                                        break;
                                }
                        }
                }
        }
        else
        {
                retorno=0;
        }
        return retorno;
}

static int getString(char pLetrasTomadas[])
{
        int retorno=-1;
        char auxiliar[200];
        if(myGets(auxiliar,sizeof(auxiliar))==0
                        && soloLetra(auxiliar)==0)
        {
                 strcpy(pLetrasTomadas,auxiliar);
                retorno=0;


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

int utn_getString(char letras[],char mensaje[],char mensajeError[],int reintentos)
{
        int retorno=-1;
        char bufferString[40];
        if(letras!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos!=0)
        {
                do
                        {
                                printf("%s", mensaje);
                                if(myGets(bufferString,40)==0 || getString(bufferString)==0)
                                {
                                        strcpy(letras, bufferString);
                                        retorno=0;
                                        break;
                                }
                                else
                                {
                                        printf("%s", mensajeError);
                                        reintentos--;
                                }
                        }while(reintentos>=0);
        }
        return retorno;
}

int get_Int(char mensaje[], char mensajeError[])
{
        int numero;
        int ret=-1;
        if(mensaje!=NULL && mensajeError!=NULL)
        {
                printf("%s",mensaje);
                if(scanf("%d",&numero)==0)
                {
                        ret=numero;
                }
                else
                {
                        printf("%s",mensajeError);
                }
        }
        return ret;
}

int getChar(char* letra,char mensaje[],char mensajeError[],int reintentos)
{
        int retorno=-1;
        char bufferChar;

        if(letra!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos!=0)
        {
                do
                        {
                                printf("%s", mensaje);
                                fflush(stdin);
                                if(scanf("%c",&bufferChar)==0)
                                {
                                       *letra=bufferChar;
                                       retorno=0;
                                }
                                else
                                {
                                        printf("%s", mensajeError);
                                        reintentos--;
                                }
                        }while(reintentos>=0);
        }
        return retorno;
}

int utn_getCaracterSN(void)
{
        int retorno = -1;
        char c;

        printf("\nIngrese 's' Si o 'n' No");
        fflush(stdin);
        scanf("%c",&c);

        while(c!='s' && c!='n')
        {
            printf("\nError. Ingrese 's' Si o 'n' No");
            fflush(stdin);
            scanf("%c",&c);

        }
                if(c=='s')
                {
                        retorno = 0;
                }
        return retorno;
}
int esNombre(char* cadena,int longitud)
{
	int retorno = 1;

	if(cadena!=NULL && longitud>0)
	{
		for(int i=0; i<=longitud && cadena[i] != '\0';i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') && cadena[i] != '.')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int getNombre(char* pResultado, int longitud)
{
	int retorno=-1;
	char buffer[5000];
	if(pResultado!=NULL && longitud>0)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esNombre(buffer, sizeof(buffer))!=0 && strnlen(buffer, sizeof(buffer))<=longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno=0;
		}
	}
	return retorno;
}

void formaNombre(char *pResultado)
{
	if(pResultado!=NULL && strlen(pResultado)>0)
	{
		strlwr(pResultado);
		for(int i = 0; i < strlen(pResultado); i++)
		{
			if (i == 0 && isspace(pResultado[i]) == 0)
			{
				pResultado[0] = toupper(pResultado[0]);

			}
			else
			{
				if(pResultado[i]=='.' && (i<strlen(pResultado)- 1))
				{
					pResultado[i + 1] = toupper(pResultado[i + 1]);
				}
			}
		}
	}
}

int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError,int reintentos, int longitud)
{
	char bufferString[1000];
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && longitud > 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getNombre(bufferString, 1000)==0)
			{
				formaNombre(bufferString);
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
