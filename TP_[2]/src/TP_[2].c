/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Melina Ochoa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include"ArrayPassenger.h"
#include"Informes.h"
#define MAX_PASSENGER 2000
#define TAM_VUELOS 2000
#define ASCENDENTE 1
#define DESCENDENTE 0

int main(void) {
	setbuf(stdout,NULL);
      int flagAlta=-1;
      int opcion;
      int resp;
      Passenger pasajeros[MAX_PASSENGER];
      eFlight vuelos[TAM_VUELOS];
      int id;
      float promedio;
      int auxInt;
      initPassengers(pasajeros,MAX_PASSENGER);
      do{

           menu(&opcion);
           switch(opcion)
           {
             case 1:

                     flagAlta=addPassengers(pasajeros,MAX_PASSENGER,vuelos,TAM_VUELOS);
                     if(flagAlta==0){
                         puts("\nCARGA EXITOSA");
                     }
                     else{
                           puts("\nERROR");
                     }
                     break;
             case 2:
                     if(flagAlta==0)
                     {
                        modificarPassenger(pasajeros,MAX_PASSENGER);
                     }
                     else{
                           puts("\nPRIMERO INGRESE PASAJEROS");
                       }
                     break;
             case 3:
                     if(flagAlta==0)
                     {
                         id=get_Int("\nIngrese Id: ","\nError");
                         removePassenger(pasajeros,MAX_PASSENGER,id);
                     }
                     else
                     {
                         puts("\nPRIMERO DEBE INGRESAR PASAJEROS");
                     }
                     break;
             case 4:
                     if(flagAlta==0)
                     {
                       do{
                           subMenu(&resp);
                           switch(resp)
                           {
                             case 1:
                            	 	printf("Ingrese criterio ascendente 1 o descendente 0");
                            	 	scanf("%d", &auxInt);
                            	 	sortPassengers(pasajeros,MAX_PASSENGER,auxInt);
                                    printPassengers(pasajeros,MAX_PASSENGER);
                                    break;
                             case 2:
                            	    PromMaxPrecio(&promedio,pasajeros,MAX_PASSENGER);
                                    break;
                             case 3:
                                    sortPassengersByCode(pasajeros,MAX_PASSENGER,ASCENDENTE);
                                    printPassengers(pasajeros,MAX_PASSENGER);
                                    break;
                             case 4:
                            	 cargaForzada(pasajeros,MAX_PASSENGER, vuelos,TAM_VUELOS);
                            	 break;
                           }
                       }while(resp!=4);
                     }
                     break;

           }
      }while(opcion!=5);
      return EXIT_SUCCESS;
}
