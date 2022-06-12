/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


#include "Passenger.h"

void  Passenger_delete (Passenger* this)
{
	free(this);
}

Passenger* Passenger_new()
{
	return(Passenger*)malloc(sizeof(Passenger));
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* codigoVueloStr,char* precioStr,char* tipoStr)
{
	Passenger* pPassenger = Passenger_new();
		if(pPassenger!=NULL && idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && codigoVueloStr!=NULL && precioStr!=NULL && tipoStr !=NULL)
		{
			if((Passenger_setId(pPassenger,atoi(idStr))!=0) ||
			(Passenger_setNombre(pPassenger,nombreStr)!=0) ||
			(Passenger_setApellido(pPassenger,apellidoStr)!=0) ||
			(Passenger_setCodigoVuelo(pPassenger,codigoVueloStr)!=0)||
			(Passenger_setPrecio(pPassenger,atoi(precioStr))!=0)||
			(Passenger_setTipoPasajero(pPassenger,atoi(tipoStr))!=0))
			{
				free(pPassenger);
				pPassenger=NULL;
			}
		}
		return pPassenger;
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno=- 1 ;
	if(this != NULL && id> 0 )
	{
		this-> id =id;
		retorno= 0 ;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}


int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno=-1;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido,apellido);
		retorno=0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=-1;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,this->apellido);
		retorno=0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno=0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno=0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno=- 1 ;
	if(this != NULL && tipoPasajero> 0 )
	{
		this-> tipoPasajero =tipoPasajero;
		retorno= 0 ;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno=-1;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero=this->tipoPasajero;
		retorno=0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=- 1 ;
	if(this != NULL && precio> 0 )
	{
		this-> precio =precio;
		retorno= 0 ;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno=-1;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		retorno=0;
	}
	return retorno;
}

void Passenger_Print(Passenger* this)
{
	int auxId, auxTipoPasajero;
	float auxPrecio;
	char auxNombre[50], auxApellido[50], auxCodigoVuelo[4];
	if (Passenger_getId(this,&auxId)== 0 && Passenger_getNombre(this,auxNombre)== 0 &&
		Passenger_getApellido(this,auxApellido)== 0 &&
		Passenger_getCodigoVuelo(this,auxCodigoVuelo)== 0 &&
		Passenger_getTipoPasajero(this,&auxTipoPasajero)==0 &&
		Passenger_getPrecio(this,&auxPrecio)==0)
	{
		printf ( " Id: %d - Nombre: %s - Apellido: %s - Codigo de Vuelo: %s - Tipo de Pasajero: %d - Precio: %f\n " ,auxId, auxNombre,
				auxApellido,auxCodigoVuelo,auxTipoPasajero,auxPrecio);
	}
}

int Passenger_sortId(void* this1, void* this2)
{
	int retorno=0;
	int auxId1, auxId2;

	if(this1!=NULL && this2!=NULL)
	{
		if(Passenger_getId((Passenger*)this1, &auxId1)==0 && Passenger_getId((Passenger*)this2, &auxId2)==0)
		{
			if(auxId1 > auxId2)
			{
				retorno=1;
			}
			if( auxId1 < auxId2 )
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortNombre(void* this1, void* this2)
{
	int retorno=0;
	char auxNombre1[50],auxNombre2[50];
	if(this1!=NULL && this2!=NULL)
	{
		if(Passenger_getNombre((Passenger*)this1, auxNombre1)==0 && Passenger_getNombre((Passenger*)this2, auxNombre2)==0)
		{
			if(strcmp(auxNombre1,auxNombre2)>0)
			{
				retorno=1;
			}
			if(strcmp(auxNombre1,auxNombre2)<0)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortApellido(void* this1, void* this2)
{
	int retorno=0;
	char auxApellido1[50],auxApellido2[50];
	if(this1!=NULL && this2!=NULL)
	{
		if(Passenger_getApellido((Passenger*)this1, auxApellido1)==0 && Passenger_getApellido((Passenger*)this2, auxApellido2)==0)
		{
			if(strcmp(auxApellido1,auxApellido2)>0)
			{
				retorno=1;
			}
			if(strcmp(auxApellido1,auxApellido2)<0)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortCodigo(void* this1, void* this2)
{
	int retorno=0;
	char auxCodigo1[4],auxCodigo2[4];
	if(this1!=NULL && this2!=NULL)
	{
		if(Passenger_getCodigoVuelo((Passenger*)this1, auxCodigo1)==0 && Passenger_getCodigoVuelo((Passenger*)this2, auxCodigo2)==0)
		{
			if(strcmp(auxCodigo1,auxCodigo2)>0)
			{
				retorno=1;
			}
			if(strcmp(auxCodigo1,auxCodigo2)<0)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortTipo(void* this1, void* this2)
{
	int retorno=0;
	int auxTipo1, auxTipo2;

	if(this1!=NULL && this2!=NULL)
	{
		if(Passenger_getTipoPasajero((Passenger*)this1, &auxTipo1)==0 && Passenger_getTipoPasajero((Passenger*)this2, &auxTipo2)==0)
		{
			if(auxTipo1 > auxTipo2)
			{
				retorno=1;
			}
			if( auxTipo1 < auxTipo2 )
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortPrecio(void* this1, void* this2)
{
	int retorno=0;
	float auxPrecio1, auxPrecio2;

	if(this1!=NULL && this2!=NULL)
	{
		if(Passenger_getPrecio((Passenger*)this1, &auxPrecio1)==0 && Passenger_getPrecio((Passenger*)this2, &auxPrecio2)==0)
		{
			if(auxPrecio1 > auxPrecio2)
			{
				retorno=1;
			}
			if( auxPrecio1 < auxPrecio2 )
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}
