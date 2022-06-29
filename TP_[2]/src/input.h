/*
 * input.h
 *
 *  Created on: 11/04/2022
 *      Author: Melina Ochoa
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Validaciones




int esNumerica(char* cadena, int longitud);



int esNumeroDecimal(char* cadena);



int soloLetra(char* pResultado);

int esConEspacio(char *pResultado);



//Ingreso de Datos

/**
 * Funcion para pedir un numero flotante a traves de un mensaje, en el caso de ingresar un valor menor que
 * el minimo o mayor que el maximo posible, muestra un mensaje de error sino guarda el numero ingresado
 * en la direccion de memoria dada.
 * @param pResultado variable que contiene una direccion de memoria para escribir el resultado
 * @param mensaje variable que contiene el mensaje deseado
 * @param mensajeError variable que contiene el mensaje de Error
 * @param maximo variable de rango
 * @param minimo variable de rango
 * @param reintentos variable con la cantidad de reintentos posibles
 * @return retorna 0 si salio todo bien o 1 si salio mal
 */
float getNumeroFloat(float* pResultado,char mensaje[],char mensajeError[],int maximo,int minimo,int reintentos);

/**
 * Funcion para pedir un numero entero a traves de un mensaje, en el caso de ingresar un valor menor que
 * el minimo o mayor que el maximo posible, muestra un mensaje de error sino guarda el numero ingresado
 * en la direccion de memoria dada
 * @param pResultado variable que contiene una direccion de memoria para escribir el resultado
 * @param mensaje variable que contiene el mensaje para ingresar un valor
 * @param mensajeError variable que contiene un mensaje de error
 * @param maximo variable de rango
 * @param minimo variable de rango
 * @param reintentos variable con la cantidad de reintentos posibles
 * @return retorna 0 si todo salio bien o 1 si salio mal
 */
int getNumero(int* pResultado,char mensaje[],char mensajeError[],int maximo,int minimo,int reintentos);

/**
 * Funcion que muestra un menu, el cual muestra variables cargadas, y pide elegir una opcion la cual
 * posteriormente se guarda en la direccion de memoria guardada
 * @param opcion variable con la direccion de memoria para escribir
 * @param km variable para mostrar
 * @param aerolineas variable para mostrar
 * @param latam variable para mostrar
 */
int utn_getString(char letras[],char mensaje[],char mensajeError[],int reintentos);

int getChar(char* letra,char mensaje[],char mensajeError[],int reintentos);

int get_Int(char mensaje[], char mensajeEror[]);

int utn_getCaracterSN(void);

int esNombre(char* cadena,int longitud);

int getNombre(char* pResultado, int longitud);

void formaNombre(char *pResultado);

int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError,int reintentos, int longitud);

int getNumeroShort(short int* pResultado,char mensaje[],char mensajeError[],int maximo,int minimo,int reintentos);

int numRango(char mensaje[],char mensajeError[],int max, int min);

#endif /* INPUT_H_ */
