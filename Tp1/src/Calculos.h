/*
 * Calculos.h
 *
 *  Created on: 11/04/2022
 *      Author: melys
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * Funcion para calcular el precio con tarjeta de debito, recibe el precio calcula
 * el descuento del 10% y lo guarda en la direccion de memoria dada
 * @param precio variable que se pasa para calcular el descuento del 10%
 * @param pResultado variable con direccion de memoria para guardar el resultado
 * @return retorna 0 si salio todo bien sino retorna -1
 */
int Debito(float precio, float* pResultado);

/**
 * Funcion para calcular el precio con tarjeta de credito, recibe el precio calcula
 * el aumento del 25% y lo guarda en la direccion de memoria dada
 * @param precio variable que se pasa para calcular el aumento del 25%
 * @param pResultado variable con direccion de memoria para guardar el resultado
 * @return retorna 0 si salio todo bien sino retorna -1
 */
int Credito(float precio, float* pResultado);

/**
 * Funcion para calcular el precio pagando con bitcoins, recibe el precio y calcula
 * el total y lo guarda en la direccion de memoria dada.
 * @param precio variable para calcular el total pagando con bitcoins
 * @param pResultado variable con la direccion de memoria para guardar el resultado
 * @return retorna 0 si salio todo bien sino retorna -1
 */
int Bitcoin(float precio, float* pResultado);

/**
 * * Funcion para calcular el precio de cada uno de los kilometros ingresados para luego
 * cargar en la direccion de memoria dada el resultado
 * @param precio precio variable para calcular el precio por unidad
 * @param km variable para calcular el precio
 * @param pResultado variable con direccion de memoria para guardar resultado
 * @return retorna 0 si salio todo bien sino retorna -1
 */
int Unitario(float precio, int km, float*pResultado);

/**
 *  Funcion para calcular la diferencia de los dos precios ingresados
 * @param precio1 variable para calcular la diferencia
 * @param precio2 variable para calcular el resultado
 * @param pResultado variable con direccion de memoria para guardar el resultado
 * @return retorna 0 si salio todo bien sino retorna -1
 */
int Diferencia(float precio1, float precio2, float* pResultado);

/**
 * Funcion para mostrar los resultados de los calculos y los kilometros ingresados
 * @param precioA variable para mostrar el precio
 * @param km variable para mostrar los kilometros
 * @param aA variable para mostrar el resultado de Debito
 * @param bA variable para mostrar el resultado de Credito
 * @param cA variable para mostrar el resultado de Bitcoin
 * @param dA variable para mostrar el resultado de Unidad
 */
void MostrarResultadosA(float precioA, int km, float aA, float bA, float cA, float dA);

/**
 * Funcion para mostrar los resultados de los calculos y la diferencia de precios
 * @param precioL variable para mostrar el precio
 * @param aL variable para mostrar el resultado de Debito
 * @param bL variable para mostrar el resultado de Credito
 * @param cL variable para mostrar el resultado de Bitcoin
 * @param dL variable para mostrar el resultado de Unidad
 * @param difPrecio variable para mostrar el resultado de la diferencia de precios
 */
void MostrarResultadosL(float precioL, float aL, float bL, float cL, float dL, float difPrecio);

/**
 * Funcion para mostrar los resultados de la carga forzada
 * @param precioA variable para mostrar el precio de Aerolineas
 * @param precioL variable para mostrar el precio de Latam
 * @param km variable para mostrar los kilometros ingresados
 * @param aA variable para mostrar el resultado del debito de aerolineas
 * @param aL variable para mostrar el resultado del debito de Latam
 * @param bA variable para mostrar el resultado del credito de aerolineas
 * @param bL variable para mostrar el resultado del credito de Latam
 * @param cA variable para mostrar el resultado del bitcon de Aerolineas
 * @param cL variale para mostrar el resultado del bitcoin de Latam
 * @param dA variable para mostrar el resultado de unidades de Aerolineas
 * @param dL variable para mostrar el resultado de unidades de Latam
 * @param difPrecio variable para mostrar la diferencia de precios ente Latam y Aerolineas
 */
void CargaForzada(float precioA, float precioL, int km, float aA, float aL, float bA, float bL, float cA, float cL, float dA, float dL, float difPrecio);

#endif /* CALCULOS_H_ */
