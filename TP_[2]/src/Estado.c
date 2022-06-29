/*
 * Estado.c
 *
 *  Created on: 29 jun. 2022
 *      Author: PC
 */
#include "Estado.h"

void printFlight(eFlight list)
{
        printf("\n %-5s %-15d",list.flycode,list.statusFlight);
}
int printFlights(eFlight list[], int len)
{
        int i;
        int retorno=-1;
        puts("\n\tListado Pasajeros\n");
        printf("%5s %15s","CODIGO","STATUS");
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
                       printFlight(list[i]);
                        retorno=0;
                    }
                }
                retorno=0;

        }
        return retorno;

}


int initFlight(eFlight array[], int len)
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

int eFlight_buscarLibre(eFlight list[], int len)
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

eFlight CargarVuelo(eFlight aux)
{
	utn_getString(aux.flycode,"\nIngrese el codigo de vuelo: ","\nError reingrese: ",2);
	getNumero(&aux.statusFlight,"\n0.ACTIVO\t1.CANCELADO\t2.DEMORADO\nIngrese el estado del vuelo: ","\nError reingrese:",2,0,2);
	return aux;
}

int addFlight(eFlight list[], int len)
{
    int retorno=-1;
    int indexLibre;
    eFlight auxFly;

    indexLibre=eFlight_buscarLibre(list, len);
    if(list==NULL && indexLibre==-1)
    {
        printf("No hay lugares libres");
    }
    else{
              auxFly=CargarVuelo(auxFly);
              auxFly.isEmpty=1;
              list[indexLibre]=auxFly;
              retorno=0;

            }

    return retorno;
}

int findFlightByCode(eFlight lista[], int len, char* index)
{
		int ret=-1;
        int i;
        int flag=0;
        char buscarCode[10];
        if(lista!=NULL && len>0)
        {
                utn_getString(buscarCode,"\nIngrese Codigo: ","\nError ",2);
                for(i=0;i<len;i++)
                {
                        if(lista[i].isEmpty==1)
                        {
                                if(lista[i].flycode==buscarCode)
                                {
                                        flag=1;
                                        strcpy(index,buscarCode);
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
                   puts("\nError codigo no encontrado");
                }
        }
        return ret;
}
int removeFlight(eFlight lista[], int len, int code)
{
        int ret=0;
        int indexBaja;
        char codigo[10];
        if(lista!=NULL && len>0)
        {
                indexBaja=findFlightByCode(lista, len,codigo);
                if(indexBaja<0)
                {
                        ret=-1;
                        puts("\nCodigo no encontrado");
                }
                else{
                        if(indexBaja==code)
                          {
                            printFlight(lista[indexBaja]);
                            puts("\nDesea eliminar vuelo?\n");
                            if(utn_getCaracterSN()==0)
                              {
                                lista[indexBaja].isEmpty=-1;
                              }

                          }

                }
        }
        return ret;
}

eFlight eFlight_ModificarUno(eFlight copia)
{
        int opcion;
        getNumero(&opcion,"\nIngrese una opcion a modificar "
                        "\n1.Codigo \n2.Estado \n","Error",2,1,2);
        switch(opcion)
               {
                case 1:
                         utn_getString(copia.flycode,"\nIngrese codigo:","Error",2);
                         break;
                case 2:
                        getNumero(&copia.statusFlight,"\nIngrese estado de vuelo:","Error",2,0,2);
                        break;

                }
        return copia;
}

int modificarFlight(eFlight lista[], int len)
{
        int ret=0;
        int indexModificacion;
        eFlight auxiliarVuelo;
        char code[10];
        if(lista!=NULL && len>0)
        {
               indexModificacion=findFlightByCode(lista, len,code);
                if(indexModificacion!=-1)
                {
                    auxiliarVuelo=lista[indexModificacion];
                    auxiliarVuelo=eFlight_ModificarUno(auxiliarVuelo);
                    lista[indexModificacion]=auxiliarVuelo;
                }
                else{
                    puts("Codigo no encontrado");
                     ret=-1;

                }
        }
        return ret;
}
