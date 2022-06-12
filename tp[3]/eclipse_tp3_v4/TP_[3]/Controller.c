#include "Controller.h"
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
		if(path!=NULL && pArrayListPassenger!=NULL)
		{
			retorno=0;
			if(ll_isEmpty(pArrayListPassenger)==1)
			{
				FILE *pFile=fopen(path,"r");
				if(parser_PassengerFromText(pFile,pArrayListPassenger)!=0)
				{
					puts("No se pudo leer el archivo\n");
				}
				else
				{
					puts("Archivo bien leido. Cerrado correctamente\n");
				}
				fclose(pFile);
			}
			else
			{
				printf("\t************************************************************************************************************\n");
				printf("\t*\t Cuidado! Se encontraron datos en su LinkedList                                                   *\n");
				printf("\t*\t Si hace la apertura del archivo se borraran los datos actuales cargados en memoria        *\n");
				printf("\t*\t Desea continuar y borrar los archivos guardados en memoria presione SI                           *\n");
				printf("\t*\t Desea continuar usando la LinkedList actual presione NO                                          *\n");
				printf("\t************************************************************************************************************\n");
				if(utn_getCaracterSN()==0 && ll_clear(pArrayListPassenger)==0)
				{
					FILE *pFile=fopen(path,"r");
					if(parser_PassengerFromText(pFile,pArrayListPassenger)!=0)
					{
						puts("No se pudo leer el archivo\n");
					}
					else
					{
						puts("Archivo bien leido. Cerrado correctamente\n");
					}
					fclose(pFile);
				}
			}
		}
		return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		retorno=0;
		if(ll_isEmpty(pArrayListPassenger)==1)
		{
			FILE *pFile=fopen(path,"rb");
			if(pFile!=NULL)
			{
				if(parser_PassengerFromBinary(pFile,pArrayListPassenger)!=0)
				{
					printf("No se pudo leer el archivo\n");
				}
				else
				{
					printf("Archivo bien leido. Cerrado correctamente\n");
				}
			}
			fclose(pFile);
		}
		else
		{
			printf("\t***********************************************************************************************************\n");
			printf("\t*\t Cuidado! Se encontraron datos en su LinkedList                                                   *\n");
			printf("\t*\t Si hace la apertura del archivo se borraran los datos actuales cargados en memoria        *\n");
			printf("\t*\t Desea continuar y borrar los archivos guardados en memoria presione SI                           *\n");
			printf("\t*\t Desea continuar usando la LinkedList actual presione NO                                          *\n");
			printf("\t************************************************************************************************************\n");
			if(utn_getCaracterSN()==0 && ll_clear(pArrayListPassenger)==0)
			{
				FILE *pFile=fopen(path,"rb");
				if(pFile!=NULL)
				{
					if(parser_PassengerFromBinary(pFile,pArrayListPassenger)!=0)
					{
						printf("No se pudo leer el archivo\n");
					}
					else
					{
						printf("Archivo bien leido. Cerrado correctamente\n");
					}
				}
				fclose(pFile);
			}
		}
	}
	return retorno;
}


int controller_getMaxId(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int cantLinkedList;
	int id;
	Passenger* pPassenger=NULL;
	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)==0)
	{
		cantLinkedList=ll_len(pArrayListPassenger);
		for(int i=0; i<cantLinkedList ; i++)
		{
			pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_getId(pPassenger, &id);
			if(id>retorno)
			{
				retorno=id;
			}
		}
	}
	return retorno;
}
/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* pPassenger=NULL;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	char auxCodigoVuelo[4];
	float auxPrecio;
	int auxTipoPasajero;
	int respuesta;
	if(pArrayListPassenger!=NULL)
	{
		if(ll_isEmpty(pArrayListPassenger)==1)
		{
			puts("\t***************************************************************************************\n");
			puts("\t*\t Atencion! Se cargaran datos en una nueva LinkedList                       *\n");
			puts("\t*\t Recuerde guardar estos datos en un archivo                     *\n");
			puts("\t*\t Desea continuar e inicializar un Id o generar un Id propio presione SI        *\n");
			puts("\t*\t Desea salir y abrir volver al menu para abrir un archivo presione NO          *\n");
			puts("\t*****************************************************************************************\n");
			if(utn_getCaracterSN()==0)
			{
				getNumero(&respuesta, "Desea\n1. Crear una nueva lista inicializando el ID en 1\n2. Inicializar el ID en otro numero\n",
							                   "Error, opcion no valida", 2, 1, 1);
				switch(respuesta)
				{
					case 1:
							auxId=1;
							break;
					case 2:
							getNumero(&auxId, "En que numero quiere inicializar el ID?\n", "Error, ingrese valor numerico\n", 100000000,1, 2);
							break;
				}
				pPassenger=Passenger_new();
				if(pPassenger!=NULL)
				{
					if(utn_getString(auxNombre, "Ingrese nombre del pasajero", "Error ingrese nombre valido\n", 2)==0 &&
							   utn_getString(auxApellido, "Ingrese apellido del pasajero", "Error ingrese apellido valido\n",2)==0 &&
							   utn_getString(auxCodigoVuelo, "Ingrese codigo del vuelo", "Error ingrese codigo valido\n",2)==0 &&
							   getNumero(&auxTipoPasajero,"Ingrese el tipo de pasajero:\n","Error ingrese un tipo valido 10.PRIMERA CLASE, 9.ECONOMICO"
									   "8.EJECUTIVO, 7.TURISTA\n",10,7,2)==0 &&
								getNumeroFloat(&auxPrecio,"Ingrese el precio:\n","Error ingrese un precio valido\n",100000000,1,2)==0)

					{
						if(Passenger_setId(pPassenger, auxId)==0 &&
						  Passenger_setNombre(pPassenger, auxNombre)==0 &&
						  Passenger_setCodigoVuelo(pPassenger, auxCodigoVuelo)==0 &&
						  Passenger_setTipoPasajero(pPassenger, auxTipoPasajero)==0 &&
						  Passenger_setPrecio(pPassenger, auxPrecio)==0)
						{
							ll_add(pArrayListPassenger, pPassenger);
									Passenger_Print(pPassenger);
									puts("Carga exitosa\n");
									retorno=0;
								}
								else
								{
									printf("Error al cargar pasajero\n");
								}
							}
						}
					}
			}
			else
			{
				auxId=controller_getMaxId(pArrayListPassenger);
				pPassenger=Passenger_new();
				if(pPassenger!=NULL)
				{
					if(utn_getString(auxNombre, "Ingrese nombre del pasajero", "Error, ingrese nombre valido\n", 2)==0 &&
					   utn_getString(auxApellido, "Ingrese apellido del pasajero", "Error, ingrese apellido valido\n", 2)==0 &&
					   utn_getString(auxCodigoVuelo, "Ingrese el codigo de vuelo", "Error, ingrese codigo valido\n", 2)==0 &&
					   getNumero(&auxTipoPasajero, "Ingrese tipo de pasajeros", "Error ingrese tipo de pasajeros\n", 10,7,2)==0 &&
					   getNumeroFloat(&auxPrecio,"Ingrese el precio:\n","Error ingrese un precio valido\n",100000000,1,2)==0)
					{
						if(Passenger_setId(pPassenger, (auxId+1))==0 &&
						   Passenger_setNombre(pPassenger, auxNombre)==0 &&
						   Passenger_setApellido(pPassenger, auxApellido)==0 &&
						   Passenger_setCodigoVuelo(pPassenger, auxCodigoVuelo)==0 &&
						   Passenger_setTipoPasajero(pPassenger, auxTipoPasajero)==0 &&
						   Passenger_setPrecio(pPassenger, auxPrecio)==0)
						{
							ll_add(pArrayListPassenger, pPassenger);
							Passenger_Print(pPassenger);
							puts("Carga exitosa\n");
							retorno=0;
						}
						else
						{
							puts("Error al cargar empleado\n");
						}
					}
				}
			}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* pPassenger=NULL;
	int cantLinkedList;
	int auxId, auxTipoPasajero, id, auxInt;
	float auxPrecio;
	int numMax=0;
	char auxNombre[50], auxApellido[50], auxCodigo[4];

	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)==0)
	{
		cantLinkedList=ll_len(pArrayListPassenger);
		for(int i=0; i<cantLinkedList ; i++)
		{
			pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_getId(pPassenger, &auxId);
			if(auxId>numMax)
			{
				numMax=auxId;
			}
		}
		getNumero(&id, "Ingrese Id del pasajero a modificar\n", "Error, ingrese valor numerico\n", auxId, 0, 2);
		for(int i=0; i<cantLinkedList ; i++)
		{
			pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_getId(pPassenger, &auxId);
			if(auxId==id)
			{
				printf("Desea modificar este empleado?\n");
				Passenger_Print(pPassenger);
				if(utn_getCaracterSN()==0)
				{
					getNumero(&auxInt, "------Modificar-------\n1. Nombre \n2. Apellido \n3. Codigo de vuelo"
							"\n4. Tipo de pasajero \n5. Precio", "Error, opcion incorrecta\n", 5, 1, 2);
					switch(auxInt)
					{
						case 1:
							if((utn_getString(auxNombre, "Ingrese nombre del Pasajero", "Error, ingrese nombre valido\n", 2)==0) &&
								  (Passenger_setNombre(pPassenger, auxNombre)==0))
								{
									puts("Datos modificados correctamente\n");
									Passenger_Print(pPassenger);
								}
								break;
						case 2:
							if((utn_getString(auxApellido, "Ingrese apellido del pasajero", "Error ingrese apellido valido\n",2)==0) &&
								   (Passenger_setApellido(pPassenger, auxApellido)==0))
								{
									puts("Datos modificados correctamente\n");
									Passenger_Print(pPassenger);
								}
								break;
						case 3:
							if((utn_getString(auxCodigo, "Ingrese codigo", "Error\n", 2)==0) &&
								   (Passenger_setCodigoVuelo(pPassenger, auxCodigo)==0))
								{
									puts("Datos modificados correctamente\n");
									Passenger_Print(pPassenger);
								}
								break;
						case 4:
							if((getNumero(&auxTipoPasajero,"Ingrese tipo de pasajero:\n","Error reingrese:\n",10,7,2)==0)&&
									(Passenger_setTipoPasajero(pPassenger,auxTipoPasajero)==0))
							  {
								puts("Datos modificados correctamente\n");
								Passenger_Print(pPassenger);
							  }
							  break;
						case 5:
							if((getNumeroFloat(&auxPrecio,"Ingrese el precio:\n","Error reingrese:\n",100000000,1,2)==0)&&
									(Passenger_setPrecio(pPassenger,auxPrecio)==0))
							{
								puts("Datos modificados correctamente\n");
								Passenger_Print(pPassenger);
							}
							break;
						}
						retorno=0;
					}
				}
			 }
			}
		return retorno;
}


/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* pPassenger=NULL;
	int cantLinkedList;
	int auxId, id, i;
	int numMax;

	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)==0)
		{
			numMax=controller_getMaxId(pArrayListPassenger);
			cantLinkedList=ll_len(pArrayListPassenger);
			getNumero(&id, "Ingrese Id de persona a borrar", "Error, ingrese valor numerico\n", numMax, 0, 2);
			for(i=0; i<cantLinkedList ; i++)
			{
				pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(pPassenger, &auxId);
				if(auxId==id)
				{
					printf("Desea borrar este pasajero?\n");
					Passenger_Print(pPassenger);
					if(utn_getCaracterSN()==0)
					{
						if(ll_remove(pArrayListPassenger, i)==0)
						{
							printf("Pasajero eliminado exitosamente\n");
							retorno=0;
							break;
						}
					}
				}
			}
			if(retorno==-1)
			{
				printf("Pasajero no encontrado\n");
			}
		}
	    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxId, auxTipoPasajero;
	float auxPrecio;
	char auxNombre[50], auxApellido[50], auxCodigo[4];
	Passenger* pPassenger=NULL;
	int cantLinkedList;
	if(pArrayListPassenger != NULL)
		{
			if(ll_isEmpty(pArrayListPassenger)==0)
			{
				cantLinkedList=ll_len(pArrayListPassenger);
				printf("********************************************************************************\n");
				printf("ID		NOMBRE		  APELLIDO 	       CODIGO		TIPO PASAJERO		PRECIO\n");
				printf("***********************************************************************************\n");
				for(int i=0; i<cantLinkedList ; i++)
				{
					pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
					if(Passenger_getId(pPassenger, &auxId)!=0 ||
					   Passenger_getNombre(pPassenger, auxNombre)!=0 ||
					   Passenger_getApellido(pPassenger, auxApellido)!=0 ||
					   Passenger_getCodigoVuelo(pPassenger, auxCodigo)!=0 ||
					   Passenger_getTipoPasajero(pPassenger, &auxTipoPasajero)==0 ||
					   Passenger_getPrecio(pPassenger, &auxPrecio)==0)
					{
						retorno=-1;
						printf("Error, al imprimir lista");
						break;
					}
					else
					{
						printf("%-5d		%-15s		%-15s			%-15s		%-15d		%-15f\n",auxId, auxNombre, auxApellido, auxCodigo, auxTipoPasajero, auxPrecio);
					}
				}
				retorno = 0;
			}
			else
			{
				printf("No hay lista para imprimir\n");
			}
		}
		return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int opcion;
	int(*pOrden)(void*,void*);

	if(pArrayListPassenger!=NULL)
	{
		getNumero(&opcion, "-----ORDENAMIENTO POR-----\n1. Nombre \n2. Apellido \n3. Codigo de vuelo \n4. Tipo de pasajero"
				"\n5. Precio\n6. ID", "Error, opcion incorrecta\n", 6, 1, 2);
			switch(opcion)
			{
				case 1:
					pOrden=Passenger_sortNombre;
					break;
				case 2:
					pOrden=Passenger_sortApellido;
					break;
				case 3:
					pOrden=Passenger_sortCodigo;
					break;
				case 4:
					pOrden=Passenger_sortTipo;
					break;
				case 5:
					pOrden=Passenger_sortPrecio;
					break;
				case 6:
					pOrden=Passenger_sortId;
					break;
			}
			getNumero(&opcion, "-----CRITERIO-----\n1. Ascendente(A-Z)\n0. Descendente(Z-A)\n", "Error, opcion incorrecta\n", 1, 0, 2);
			ll_sort(pArrayListPassenger, pOrden, opcion);
		}
	    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxCantLink, auxId, auxTipo;
	float auxPrecio;
	char auxNombre[50], auxApellido[50], auxCodigo[4];
	FILE* pFile;
	Passenger* pPassenger=NULL;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		if((pFile=fopen(path,"w"))==NULL)
		{
			printf("No se pudo escribir el archivo\n");
		}
		else
		{
			auxCantLink=ll_len(pArrayListPassenger);
			fprintf(pFile,"id,nombre,apellido,codigo,tipo,precio\n");
				for(int i=0; i<auxCantLink; i++)
				{
					pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
					if(Passenger_getId(pPassenger, &auxId)==0 &&
					   Passenger_getNombre(pPassenger, auxNombre)==0 &&
					   Passenger_getApellido(pPassenger,auxApellido)==0 &&
					   Passenger_getCodigoVuelo(pPassenger,auxCodigo)==0 &&
					   Passenger_getTipoPasajero(pPassenger, &auxTipo)==0 &&
					   Passenger_getPrecio(pPassenger, &auxPrecio)==0)
					{
					   fprintf(pFile,"%d,%s,%s,%s,%d,%f\n",auxId, auxNombre, auxApellido, auxCodigo, auxTipo, auxPrecio);
					   retorno=0;
					}
				}
				printf("Archivo bien escrito. Guardado correctamente\n");
			}
			fclose(pFile);
		}
		return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxCantLink, auxId, auxTipo;
	float auxPrecio;
	char auxNombre[50], auxApellido[50], auxCodigo[4];
	FILE* pFile;
	Passenger* pPassenger=NULL;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		if((pFile=fopen(path,"w"))==NULL)
		{
			printf("No se pudo escribir el archivo\n");
		}
		else
		{
			auxCantLink=ll_len(pArrayListPassenger);
			fprintf(pFile,"id,nombre,apellido,codigo,tipo,precio\n");
			for(int i=0; i<auxCantLink; i++)
			{
				pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				if(Passenger_getId(pPassenger, &auxId)==0 &&
				   Passenger_getNombre(pPassenger, auxNombre)==0 &&
				   Passenger_getApellido(pPassenger, auxApellido)==0 &&
				   Passenger_getCodigoVuelo(pPassenger, auxCodigo)==0 &&
				   Passenger_getTipoPasajero(pPassenger, &auxTipo)==0 &&
				   Passenger_getPrecio(pPassenger, &auxPrecio)==0)
					{
					   fprintf(pFile,"%d,%s,%s,%s,,%d,%f\n",auxId, auxNombre, auxApellido, auxCodigo, auxTipo, auxPrecio);
					   retorno=0;
					}
				}
				printf("Archivo bien escrito. Guardado correctamente\n");
			}
			fclose(pFile);
		}
		return retorno;
}

/** \brief Borra la LinkedList
 *
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_deleteLinkedList(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	if(pArrayListPassenger!=NULL)
	{
		if(ll_deleteLinkedList(pArrayListPassenger)==0)
		{
			printf("************************************************");
			printf("/ PROGRAMA FINALIZADO, HASTA PRONTO /");
			printf("*************************************************");
			retorno=0;
		}
	}
	return retorno;

}
