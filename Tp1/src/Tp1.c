/*
 ============================================================================
 Name        : Tp1.c
 Author      : Melina Ochoa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "input.h"

int main() {
	setbuf(stdout,NULL);
	int km=0;
	float latam=0;
	float aerolineas=0;
	int opcion;
	float aA, bA, cA, dA;
	float aL, bL, cL, dL;
	float difPrecio;
	do{
		menu(&opcion,km,aerolineas,latam);

		switch(opcion)
		{
		case 1:
		{
			getInt(&km,"\nIngrese kilometros:","\nError reingrese: ",30000,0,2);
			break;
		}
		case 2:
		{
			if(km!=0)
			{
				getFloat(&aerolineas,"\nIngrese precio de Aerolineas:","\nError reingrese: ",1000000,0,2);
				getFloat(&latam,"\nIngrese precio de Latam:","\nError reingrese: ",1000000,0,2);
			}
			else
			{
				printf("\n Error primero debe ingresar los kilometros");
			}
			break;
		}
		case 3:
		{
			if(km!=0 && aerolineas!=0 && latam!=0)
			{

				Debito(aerolineas,&aA);
				Credito(aerolineas,&bA);
				Bitcoin(aerolineas,&cA);
				Unitario(aerolineas,km,&dA);

				Debito(latam,&aL);
				Credito(latam,&bL);
				Bitcoin(latam,&cL);
				Unitario(latam,km,&dL);
				Diferencia(aerolineas, latam, &difPrecio);
			}
			else{
				printf("\nError debe ingresar a las opciones anteriores");
			}
			break;

		}
		case 4:
		{
			if(km!=0 && aerolineas!=0 && latam!=0)
			{
				MostrarResultadosA(aerolineas,km,aA,bA,cA,dA);
				MostrarResultadosL(latam,aL,bL,cL,dL,difPrecio);
			}
			else{
				printf("\nError debe ingresar a las opciones anteriores");
			}
			break;
		}
		case 5:
		{
			km=7090;
			aerolineas=162965;
			latam=159339;
			Debito(aerolineas,&aA);
			Debito(latam,&aL);
			Credito(aerolineas,&bA);
			Credito(latam,&bL);
			Bitcoin(aerolineas,&cA);
			Bitcoin(latam,&cL);
			Unitario(aerolineas,km,&dA);
			Unitario(latam,km,&dL);
			Diferencia(aerolineas,latam,&difPrecio);
			CargaForzada(aerolineas,latam,km,aA,aL,bA,bL,cA,cL,dA,dL,difPrecio);
		}
		break;
		}

	}while(opcion!=6);

	return 0;

}

