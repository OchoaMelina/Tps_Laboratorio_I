/*
 * Productos.h
 *
 *  Created on: 26/04/2022
 *      Author: Melina Ochoa
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#define ACTIVO 0
#define CANCELADO -1
#define DEMORADO 1
#define PRIMERA_CLASE 10
#define ECONOMICO 9
#define EJECUTIVO 8
#define TURISTA 7

typedef struct{
        int id;
        char name[51];
        char lastName[51];
        float price;
        int isEmpty;
        int typePassenger;
        char flycode[10];
}Passenger;

typedef struct{
        int flycode[10];
        int statusFlight;
}eFlight;

void printPassenger(Passenger pasajeros);

int printPassengers(Passenger array[], int len);

int productoVacio(Passenger productos);

/** \brief To indicate that all position in the array are empty,
*
this function put the flag (isEmpty) in TRUE in all
*
position of the array
 * @param array Passenger* Pointer to array of passenger
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initPassengers(Passenger array[], int len);

Passenger CargaDatos(Passenger aux);

int addPassenger(Passenger list[], int len);

int modificarPassenger(Passenger lista[], int len);

Passenger ModificarUno(Passenger copia);

int removePassenger(Passenger lista[], int len, int id);

int findPassengerById(Passenger lista[], int len);

int buscarLibre(Passenger list[], int len);

void menu(int* opcion);

void subMenu(int* resp);

#endif /* PRODUCTOS_H_ */
