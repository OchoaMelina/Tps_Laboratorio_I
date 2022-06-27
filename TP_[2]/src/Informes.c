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
                               if(strcmp(list[i].lastName,list[i+1].lastName)==0 && list[i].typePassenger  > list[i+1].typePassenger )
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
                           if(strcmp(list[i].flycode,list[i+1].flycode)>0)
                             {
                                 aux=list[i];
                                  list[i]=list[i+1];
                                 list[i+1]=aux;
                                 flagNoOrdenado=1;
                             }
                             else
                             {
                                 if(strcmp(list[i].flycode,list[i+1].flycode)==0 && list[i].flycode > list[i+1].flycode)
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
                                if(strcmp(list[i+1].flycode,list[i].flycode)>0)
                                 {
                                      aux=list[i];
                                      list[i]=list[i+1];
                                      list[i+1]=aux;
                                      flagNoOrdenado=1;
                                 }
                                 else
                                 {
                                    if(strcmp(list[i].flycode,list[i+1].flycode)==0 && list[i+1].flycode> list[i].flycode)
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

int promPrecio(float* promedioResultado, Passenger list[], int len)
{
        int retorno = -1;
        int i;
        int acumulador=0;
        int contador=0;

        if(promedioResultado != NULL && list!=NULL && len>0)
        {
                for(i=0; i<len; i++)
                {
                        if(list[i].isEmpty==0)
                        {
                                acumulador=acumulador+list[i].price;
                                contador++;
                        }
                }
                *promedioResultado = (float)acumulador/contador;
                printf("El Total de los paasajes es: %d\n", acumulador);
                printf("El salario promedio es: %.2f\n", *promedioResultado);
                retorno = 0;
        }
        return retorno;
}
