/*
 * funciones.h
 *
 *  Created on: 17 sep. 2021
 *      Author: matia
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** \brief obtiene un int y valida entre el maximo y el minimo colocado en parametros y lo guarda en pResultado
 * \param mensaje char*
 * \param pResultado int*
 * \return int
 *
 */
int getInt(char* mensaje, int* pResultado, int minimo, int maximo);

/** \brief
 *
 * \param mensaje char*
 * \param pResultado float*
 * \return int
 *
 */
int getFloat(char* mensaje, float* pResultado);

/** \brief
 *
 * \param mensaje char*
 * \param pResultado[] char
 * \return int
 *
 */
int getString(char* mensaje, char pResultado[]);


/**
 * @brief para validar que una cadena de string contenga solo numeros
 * @param mensaje
 * @param pResultado
 * @return int
 */
int getStringDigit(char* mensaje,char pResultado[]);

#endif /* FUNCIONES_H_ */
