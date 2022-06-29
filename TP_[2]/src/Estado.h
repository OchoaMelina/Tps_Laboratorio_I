/*
 * Estado.h
 *
 *  Created on: 29 jun. 2022
 *      Author: PC
 */

#ifndef ESTADO_H_
#define ESTADO_H_

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#define ACTIVO 0
#define CANCELADO 1
#define DEMORADO 2
typedef struct{
        char flycode[10];
        int statusFlight;
        int isEmpty;
}eFlight;

void printFlight(eFlight list);

int printFlights(eFlight list[], int len);

int initFlight(eFlight array[], int len);

int eFlight_buscarLibre(eFlight list[], int len);

eFlight CargarVuelo(eFlight aux);

int addFlight(eFlight list[], int len);

int findFlightByCode(eFlight lista[], int len, char* index);

int removeFlight(eFlight lista[], int len, int code);

eFlight  eFlight_ModificarUno(eFlight copia);

int modificarFlight(eFlight lista[], int len);



#endif /* ESTADO_H_ */
