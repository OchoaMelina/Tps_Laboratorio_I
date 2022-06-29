/*
 * Informes.c
 *
 *  Created on: 10/05/2022
 *      Author: melys
 */
#include"Informes.h"
#define MAX 2000
int sortPassengers(Passenger* list, int len, int order)
{
      int i;
      int flagNoOrdenado=1;
      Passenger aux;
      int retorno=-1;

      if(list!=NULL && len>0)
       {
          do {
               flagNoOrdenado=0;
               for (i = 0; i < len-1; i++)
                  {
                    if(order == 1)
                      {
                         if(strcmp(list[i].lastName,list[i+1].lastName)>0)
                           {
                               aux=list[i];
                               list[i]=list[i+1];
                               list[i+1]=aux;
                               flagNoOrdenado=1;
                           }
                           else
                           {
                               if(strcmp(list[i].lastName,list[i+1].lastName)==0 && list[i].typePassenger>list[i+1].typePassenger )
                                   {
                                        aux=list[i];
                                        list[i]=list[i+1];
                                        list[i+1]=aux;
                                        flagNoOrdenado=1;
                                   }
                           }
                       }
                       else
                       {
                           if(order == 0)
                            {
                              if(strcmp(list[i+1].lastName,list[i].lastName)==0)
                               {
                                    aux=list[i];
                                    list[i]=list[i+1];
                                    list[i+1]=aux;
                                    flagNoOrdenado=1;
                               }
                               else
                               {
                                  if(strcmp(list[i].lastName,list[i+1].lastName)==0 && list[i+1].typePassenger > list[i].typePassenger)
                                    {
                                         aux=list[i];
                                         list[i]=list[i+1];
                                         list[i+1]=aux;
                                         flagNoOrdenado=1;
                                     }
                                }
                            }
                        }
                  }
             } while (flagNoOrdenado==1);
               retorno=0;
       }
       return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
  int i;
        int flagNoOrdenado=1;
        Passenger aux;
        int retorno=-1;

        if(list!=NULL && len>0)
         {
            do {
                 flagNoOrdenado=0;
                 for (i = 0; i < len-1; i++)
                    {
                      if(order == 1)
                        {
                           if(strcmp(list[i].FK_flycode,list[i+1].FK_flycode)>0)
                             {
                                 aux=list[i];
                                  list[i]=list[i+1];
                                 list[i+1]=aux;
                                 flagNoOrdenado=1;
                             }
                             else
                             {
                                 if(strcmp(list[i].FK_flycode,list[i+1].FK_flycode)==0 && list[i].FK_flycode > list[i+1].FK_flycode)
                                     {
                                          aux=list[i];
                                          list[i]=list[i+1];
                                          list[i+1]=aux;
                                          flagNoOrdenado=1;
                                     }
                             }
                         }
                         else
                         {
                             if(order == 0)
                              {
                                if(strcmp(list[i+1].FK_flycode,list[i].FK_flycode)>0)
                                 {
                                      aux=list[i];
                                      list[i]=list[i+1];
                                      list[i+1]=aux;
                                      flagNoOrdenado=1;
                                 }
                                 else
                                 {
                                    if(strcmp(list[i].FK_flycode,list[i+1].FK_flycode)==0 && list[i+1].FK_flycode> list[i].FK_flycode)
                                      {
                                           aux=list[i];
                                           list[i]=list[i+1];
                                           list[i+1]=aux;
                                           flagNoOrdenado=1;
                                       }
                                  }
                              }
                          }
                    }
               } while (flagNoOrdenado==1);
                 retorno=0;
         }
         return retorno;
}

int PromMaxPrecio(float* pPromedioResultado, Passenger array[], int len)
{
	int retorno = -1;
	int i;
	int acumulador=0;
	int contador=0;
	int contMax=0;

	if(pPromedioResultado != NULL && array!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(array[i].isEmpty==1)
			{
				acumulador=acumulador+array[i].price;
				contador++;
			}
		}
		*pPromedioResultado = (float)acumulador/contador;
		for(i=0; i<len; i++)
		{
			if(array[i].isEmpty==1)
			{
				if(*pPromedioResultado < array[i].price)
				{
					contMax++;
				}
			}
		}
		printf("El Total de precios es: %d\n", acumulador);
		printf("El precio promedio es: %.2f\n", *pPromedioResultado);
		printf("La cantidad de empleados que superan la cantidad promedio es: %d", contMax);
		retorno = 0;
	}
	return retorno;
}

void cargaForzada(Passenger array[], int len, eFlight arrayVuelo[], int len2)
{
	strcpy(array[1].name,"Melina");
	strcpy(array[1].lastName,"Ochoa");
	array[1].price=6600;
	array[1].typePassenger=8;
	strcpy(array[1].FK_flycode,"9y6u");
	array[1].isEmpty=1;
	strcpy(arrayVuelo[1].flycode,"9y6u");
	arrayVuelo[1].statusFlight=0;
	arrayVuelo[1].isEmpty=1;
	strcpy(array[2].name,"Alejandro");
	strcpy(array[2].lastName,"Maidana");
	array[2].price=7600;
	array[2].typePassenger=9;
	strcpy(array[2].FK_flycode,"8oy6i");
	array[2].isEmpty=1;
	strcpy(arrayVuelo[2].flycode,"8oy6i");
	arrayVuelo[2].statusFlight=2;
	arrayVuelo[2].isEmpty=1;
	strcpy(array[3].name,"Nilda");
	strcpy(array[3].lastName,"Romero");
	array[3].price=80600;
	array[3].typePassenger=10;
	strcpy(array[3].FK_flycode,"8iuyy8");
	array[3].isEmpty=1;
	arrayVuelo[3].isEmpty=1;
	strcpy(arrayVuelo[3].flycode,"8iuyy8");
	arrayVuelo[3].statusFlight=0;
	printPassengers(array,len);

}
