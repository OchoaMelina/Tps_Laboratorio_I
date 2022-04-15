/*
 * Calculos.c
 *
 *  Created on: 11/04/2022
 *      Author: melys
 */

#include "Calculos.h"

int Debito(float precio, float* pResultado)
{
	int aux;
	int ret=-1;
	if(pResultado!=NULL && precio!=0)
	{
		aux=precio-((precio*10)/100);
		ret=0;
	}

	*pResultado=aux;
	return ret;
}

int Credito(float precio, float* pResultado)
{
    int ret=-1;
    float aux;
    if(pResultado!=NULL && precio!=0)
      {
        aux=precio+((precio*25)/100);
        ret=0;
      }

    *pResultado=aux;
    return ret;

}

int Bitcoin(float precio, float* pResultado)
{
    int ret=-1;
    float bit;
    float aux;
    bit=4495568.71;
    if(pResultado!=NULL && precio!=0)
     {
	aux=precio/bit;
	ret=0;
     }

    *pResultado=aux;
    return ret;
}

int Unitario(float precio, int km, float* pResultado)
{
    float aux;
    int ret=-1;
    if(pResultado!=NULL && precio!=0 && km!=0)
     {
	aux=precio/km;
	ret=0;
     }

    *pResultado=aux;
    return ret;

}

int Diferencia(float precio1, float precio2, float* pResultado)
{
   int ret=-1;
   float aux;
   if(precio1!=0 && precio2!=0 && pResultado!=NULL)
    {
	aux=precio1-precio2;
	ret=0;
    }

   *pResultado=aux;
   return ret;
}

void MostrarResultadosA(float precioA, int km, float aA, float bA, float cA, float dA)
{
	printf("\nKMs Ingresados: %d km"
			"\n\nPrecio Aerolineas: $%f"
			"\na)Precio con tarjeta de Debito: $%f"
			"\nb)Precio con tarjeta de Credito: $%f"
			"\nc)Precio con bitcoin: $%f"
			"\nd)Mostrar precio unitario: $%f",km,precioA,aA,bA,cA,dA);
}

void MostrarResultadosL(float precioL, float aL, float bL, float cL, float dL, float difPrecio)
{
	printf("\n\nPrecio Latam: $%f"
			"\na)Precio con tarjeta de Debito: $%f"
			"\nb)Precio con tarjeta de Credito: $%f"
			"\nc)Precio con bitcoin: $%f"
			"\nd)Mostrar precio unitario: $%f"
			"\n\nLa diferencia de precio es: $%f", precioL,aL,bL,cL,dL,difPrecio);
}

void CargaForzada(float precioA, float precioL, int km, float aA, float aL, float bA, float bL, float cA, float cL, float dA, float dL, float difPrecio)
{
	printf("\nKMs Ingresados: %d km"
				"\n\nPrecio Aerolineas: $%f"
				"\na)Precio con tarjeta de Debito: $%f"
				"\nb)Precio con tarjeta de Credito: $%f"
				"\nc)Precio con bitcoin: $%f"
				"\nd)Mostrar precio unitario: $%f",km,precioA,aA,bA,cA,dA);
	printf("\n\nPrecio Latam: $%f"
				"\na)Precio con tarjeta de Debito: $%f"
				"\nb)Precio con tarjeta de Credito: $%f"
				"\nc)Precio con bitcoin: $%f"
				"\nd)Mostrar precio unitario: $%f"
				"\n\nLa diferencia de precio es: $%f", precioL,aL,bL,cL,dL,difPrecio);

}
