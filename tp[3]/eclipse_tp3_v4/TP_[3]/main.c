
#include "Controller.h"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
	int option;
	int flag=0;
	int flag2=0;
	LinkedList* listaPasajeros = ll_newLinkedList();
	printf("**************** BIENVENIDO ***************\n");
		    do{
		    	if(getNumero(&option,"******* Elija una opcion **********\n"
		    			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
		    			"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)\n"
		    			"3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n7. Ordenar pasajeros\n"
		    			"8. Guardar los datos de los pasajeros en archivo tipo .csv (modo texto)\n"
		    			"9. Guardar los datos de los pasajeros en archivo tipo .bin (modo binario)\n10. Salir",
		    					"******* Error ingrese ******* \n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
		    			"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)\n"
		    			"3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n7. Ordenar pasajeros\n"
		    			"8. Guardar los datos de los pasajeros en archivo tipo .csv (modo texto)\n"
		    			"9. Guardar los datos de los pasajeros en archivo tipo .bin (modo binario)\n10. Salir\n", 10, 1, 2)==0){
					switch(option)
					{
						case 1:
							if(flag==0)
							{
								getNumero(&flag, "Desea abrir: \n1. data.csv \n2. Chequeo.csv", "Error, opcion incorrecta", 2, 1, 1);
								switch(flag)
								{
								case 1:
									controller_loadFromText("data.csv",listaPasajeros);
									break;
								case 2:
									controller_loadFromText("Chequeo.csv",listaPasajeros);
									break;
								}
							}
							else
							{
								printf("El archivo ya fue cargado");
							}
							break;
						case 2:
							if(flag==0)
							{
								getNumero(&flag, "Desea abrir: \n1. data.bin \n2.Chequeo.bin", "Error, opcion incorrecta", 2, 1, 1);
								switch(flag)
								{
								case 1:
									controller_loadFromBinary("data.bin",listaPasajeros);
									break;
								case 2:
									controller_loadFromBinary("Chequeo.bin",listaPasajeros);
									break;
								}
							}
							else
							{
								printf("El archivo ya fue cargado\n");
							}

							break;
						case 3:
							controller_addPassenger(listaPasajeros);
							break;
						case 4:
							controller_editPassenger(listaPasajeros);
							break;
						case 5:
							controller_removePassenger(listaPasajeros);
							break;
						case 6:
							controller_ListPassenger(listaPasajeros);
							break;
						case 7:
							controller_sortPassenger(listaPasajeros);
							printf("Desea imprimir lista ordenada. ");
							if(utn_getCaracterSN()==0)
							{
								controller_ListPassenger(listaPasajeros);
							}
							break;
						case 8:
							getNumero(&flag2, "Desea guardar en: \n1. data.csv \n2. Chequeo.csv", "Error, opcion incorrecta", 2, 1, 1);
							switch(flag2)
							{
							case 1:
								controller_saveAsText("data.csv",listaPasajeros);
								break;
							case 2:
								controller_saveAsText("Chequeo.csv",listaPasajeros);
								break;
							}
							break;
						case 9:
							getNumero(&flag2, "Desea guardar en: \n1. data.bin \n2. Chequeo.bin", "Error, opcion incorrecta", 2, 1, 1);
							switch(flag2)
							{
							case 1:
								controller_saveAsBinary("data.bin",listaPasajeros);
								break;
							case 2:
								controller_saveAsBinary("Chequeo.bin",listaPasajeros);
								break;
							}
							break;
						case 10:
							if(ll_isEmpty(listaPasajeros)==0 && flag2==0)
							{
								printf("Se encuentra una lista con datos en ejecucion, desea salir sin guardar? ");
								if(utn_getCaracterSN()==0)
								{
									controller_deleteLinkedList(listaPasajeros);
								}
								else
								{
									option=11;
								}
							}
							else
							{
								controller_deleteLinkedList(listaPasajeros);
							}
							break;
					}
		    	}
		    }while(option != 10);
		return 0;
}

