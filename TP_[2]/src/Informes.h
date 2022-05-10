/*
 * Informes.h
 *
 *  Created on: 10/05/2022
 *      Author: melys
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "input.h"
#include "ArrayPassenger.h"
int sortPassengers(Passenger* list, int len, int order);

int sortPassengersByCode(Passenger* list, int len, int order);

int promPrecio(float* promedioResultado, Passenger list[], int len);


#endif /* INFORMES_H_ */
