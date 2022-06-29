/*
 * Productos.c
 *
 *  Created on: 26/04/2022
 *      Author:Melina Ochoa
 */

#include "ArrayPassenger.h"
#define MAX_PASSENGER 2000

#define PRIMERA_CLASE 10
#define ECONOMICO 9
#define EJECUTIVO 8
#define TURISTA 7


static int GenerarId(void);

static int GenerarId(void)
{
        static int contador=0;
        return contador++;
}

void printPassenger(Passenger list)
{
        printf("\n %-5d %-15s %-15s %-15.2f %-15d %-15s",list.id,list.name,list.lastName,list.price,list.typePassenger,list.FK_flycode);
}

int printPassengers(Passenger list[], int len)
{
        int i;
        int retorno=-1;
        puts("\n\tListado Pasajeros\n");
        printf("%5s %15s %15s %15s %15s %15s","ID","NOMBRE","APELLIDO","PRICE","TIPO DE PASAJERO","CODIGO");
        if(list!=NULL && len>0)
        {
                for(i=0; i<len;i++)
                {
                    if (list[i].isEmpty == 0)
                    {
                         continue;
                    }
                    else
                    {
                       printPassenger(list[i]);
                        retorno=0;
                    }
                }
                retorno=0;

        }
        return retorno;

}


int initPassengers(Passenger array[], int len)
{
    int retorno= -1;
    int i;
    if(array!=NULL && len>0)
    {
        retorno=0;
        for(i=0;i<len; i++)
        {
            array[i].isEmpty=0;
            retorno=0;
        }
    }
    return retorno;
}

int buscarLibre(Passenger list[], int len)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

Passenger CargaDatos(Passenger aux)
{
  utn_getNombre(aux.name,"\nIngrese nombre del pasajero: ","\nError reingrese: ",2, 51);
  utn_getNombre(aux.lastName,"\nIngrese apellido del pasajero: ","\nError reingrese: ",2, 51);
  getNumeroFloat(&aux.price,"\nIngrese precio: ","\nError reingrese: ",1000000,0,2);
  getNumero(&aux.typePassenger,"\n10.Pimera Clase \n9.Economico \n8.Ejecutivo \n7.Turista "
            "\nIngrese tipo de pasajero: ", "\nError reingrese: ",10,7,2);
  return aux;
}

int addPassengers(Passenger list[], int MAX_PASSANGER, eFlight array[], int TAM_VUELOS)
{
    int retorno=-1;
    int indexLibre;
    Passenger aux;
    char indexCode[10];
    if(list!=NULL && MAX_PASSANGER>0)
    {
    	indexLibre=buscarLibre(list, MAX_PASSANGER);
    	if(indexLibre==-1)
    	{
    	  printf("No hay lugares libres");
    	}
    	else{
    		aux=CargaDatos(aux);
    		aux.id=GenerarId();
    		aux.isEmpty=1;
    		if(array!=NULL && TAM_VUELOS)
    		{
    			addFlight(array,TAM_VUELOS);
    			findFlightByCode(array,TAM_VUELOS,indexCode);
    			if(indexCode!=NULL)
    			{
    				strcpy(aux.FK_flycode,indexCode);
    			}
    	    }
    	    list[indexLibre]=aux;
    	    retorno=0;
    	}
    }

    return retorno;
}





int findPassengerById(Passenger lista[], int len)
{
        int ret=0;
        int i;
        int flag=0;
        int buscarId;
        if(lista!=NULL && len>0)
        {
                getNumero(&buscarId,"\nIngrese id: ","\nError ",2000,0,2);
                for(i=0;i<len;i++)
                {
                        if(lista[i].isEmpty==1)
                        {
                                if(lista[i].id==buscarId)
                                {
                                        flag=1;
                                        ret=i;
                                        break;
                                }
                        }
                }

        }
        else
        {
                if(flag==0)
                {
                   puts("\nError ID no encontrado");
                   ret=-1;
                }
        }
        return ret;
}

int removePassenger(Passenger lista[], int len, int id)
{
        int ret=0;
        int indexBaja;
        if(lista!=NULL && len>0)
        {
                indexBaja=findPassengerById(lista, len);
                if(indexBaja<0)
                {
                        ret=-1;
                        puts("\nId no encontrado");
                }
                else{
                        if(indexBaja==id)
                          {
                            printPassenger(lista[indexBaja]);
                            puts("\nDesea eliminar pasajero?\n");
                            if(utn_getCaracterSN()==0)
                              {
                                lista[indexBaja].isEmpty=-1;
                              }

                          }

                }
        }
        return ret;
}

Passenger ModificarUno(Passenger copia)
{
        int opcion;
        getNumero(&opcion,"\nIngrese una opcion a modificar "
                        "\n1.Nombre \n2.Apellido \n3.Precio \n4.Tipo de Pasajero \n5.Codigo de vuelo","Error",6,1,2);
        switch(opcion)
               {
                case 1:
                         utn_getString(copia.name,"\nIngrese nombre:","Error",2);
                         break;
                case 2:
                        utn_getString(copia.lastName,"\nIngrese descripcion:","Error",2);
                        break;
                case 3:
                        getNumeroFloat(&copia.price,"\nIngrese precio: ","\nError",1000,0,2);
                        break;
                case 4:
                        getNumero(&copia.typePassenger,"\nIngreese tipo de pasajero: ","\nError reingrese: ",10,7,2);
                        break;

                }
        return copia;
}

int modificarPassenger(Passenger lista[], int len)
{
        int ret=0;
        int indexModificacion;
        Passenger auxiliarPasajero;
        if(lista!=NULL && len>0)
        {
                indexModificacion=findPassengerById(lista, len);
                if(indexModificacion==0)
                {
                    auxiliarPasajero=lista[indexModificacion];
                    auxiliarPasajero=ModificarUno(auxiliarPasajero);
                    lista[indexModificacion]=auxiliarPasajero;
                }
                else{
                    puts("Id no encontrado");
                     ret=-1;

                }
        }
        return ret;
}

void menu(int* opcion)
{
  int aux;
  printf("\t\t Bienvenido\n");
      printf("\n1.Alta\n2.Modificar\n3.Baja\n4.Informar\n5.Salir");
      if(getNumero(&aux,"\nIngrese opcion: ","\nError reingrese: ",5,1,2)==0)
      {
         *opcion=aux;
      }
}

void subMenu(int* resp)
{
  printf("\n INFORMAR: ");
  printf("\n1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero"
            "\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio"
            "\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
            "\n4. Alta forzada\n5. Salir");
  getNumero(resp,"\nIngrese a la opcion que desea","\nError reingrese",5,1,2);
}
