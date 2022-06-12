/*
 * input.h
 *
 *  Created on: 13/05/2022
 *      Author: melys
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


//Validaciones

/**
 *brief Recibe una cadena y valida que sea numerica
 *@param char* es un puntero al espacio de memoria donde se guardara el resultado de la funcion
 *return Retorna 0 si salio bien o 1 si no
 *
 */
int esNumerica(char* cadena);


/**
 * brief Recibe una cadena y valida que sean numeros flotantes
 * @param char* cadena es un puntero al espacio de memoria donde se guardara el resultado de la funcion
 * return Retorna 0 si salio bien o 1 si no.
 */
int esNumeroDecimal(char* cadena);


/**
 * brief Recibe una cadena y valida que sean solo letras
 * @param char* pResultado es un puntero al espacio de memoria donde se guardara el resultado de la funcion
 * return Retorna 0 si salio bien o 1 si no
 */
int soloLetra(char* pResultado);

/**
 * brief Recibe una cadena y valida que sean letras con espacio
 * @param char* pResultado es un puntero al espacio de memoria donde se guardara el resultado
 * return Retorna 0 si salio bien o 1 si no.
 */
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
 * @return retorna 0 si salio bien o 1 si salio mal
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
 * Funcion para pedir una cadena de carecteres a traves de un mensaje,valida que sean solo letras con espacio
 * guarda la cadena ingresada en la direccion de memoria dada, sino muestra el mensaje de error
 * @param pResultado variable que contiene una direccion de memoria para escribir el resultado
 * @param mensaje variable que contiene el mensaje para ingresar un valor
 * @param mensajeError variable que contiene un mensaje de error
 * @param reintentos variable con la cantidad de reintentos posibles
 * @return retorna 0 si salio bien o 1 si salio mal
 */
int utn_getString(char letras[],char mensaje[],char mensajeError[],int reintentos);

/**
 * brief Pide un caracter a travez de un mensaje, valida que sea un caracter y lo guarda en el puntero dado,
 * sino muestra mensaje error y sigue dando un reintentos hasta que ya no tenga.
 * @param pResultado varieble que contiene una direccion de memoria para escribir el resultado
 * @param mensaje variable que contiene el mensaje que pide ingresar el valor
 * @param mensajeError variable con el mensaje de error
 * @param reintentos variable con la cantidad de reintentos posibles
 * @return retorna 0 si salio bien o 1 si salio mal
 */
int getChar(char* letra,char mensaje[],char mensajeError[],int reintentos);

/**
 * Funcion que muestra un mensaje pidiendo un numero entero, valida que sea entero y lo retorna. Si no es entero
 * tira el mensaje Error y devuelve un -1
 * @param mensaje contiene el mensaje para ingresar un numero
 * @param mensajeError contiene un mensaje de error
 * @return retorna el numero entero
 */
int get_Int(char mensaje[], char mensajeEror[]);

/**
 * Funcion que pide el ingreso de una letra s por Si o n por No, valida que la letra ingresada sean esas, sino muestra
 * un mensaje de error, si la validacion es correcta retorna 0.
 * @return Retorna 0 si salio bien o -1 si no
 */
int utn_getCaracterSN(void);

/**
 * Funcion que pide ingresar un numero a traves de un mensaje, valida que no sea mas grande que el maximo ni mas chico que
 * el minimo, sino muestra un mensaje de error. Si la validacion es exitosa retorna el numero.
 * @param mensaje contiene el mensaje para pedir un numero
 * @param mensajeError contiene el mensaje de Error
 * @param max variable de rango
 * @param min variable de rango
 * @return retorna 0 si salio bien y -1 si no
 */
int numRango(char mensaje[],char mensajeError[],int max, int min);

/**
 * Funcion para pedir un short int, muestra un mensaje pidiendo el numero, valida que no sea mas grande que el maximo
 * ni mas chico que el minimo, sino muestra el mensaje de error y da otro reintento hasta que no tenga mas. Si la
 * validacion es exitosa se guarda el numero en la direccion de memoria dada
 * @param pResultado variable que contiene una direccion de memoria para escribir el resultado
 * @param mensaje variable que contiene el mensaje de ingreso
 * @param mensajeError variable que contiene el mensaje de error
 * @param maximo variable de rango
 * @param minimo variable de rango
 * @param reintentos variable que contiene cantidad de reintentos
 * @return retorna 0 si salio bien y -1 si no
 */
int getNumeroShort(short int* pResultado,char mensaje[],char mensajeError[],int maximo,int minimo,int reintentos);

#endif /* INPUT_H_ */
