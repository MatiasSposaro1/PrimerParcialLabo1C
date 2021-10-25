/*
 * localidad.h
 *
 *  Created on: 25 oct. 2021
 *      Author: matia
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

struct
{
	int idLocaldiadStruct;
	char descripcion[30];

}typedef Localidad;

int buscarLocalidadPorID(Localidad* localidades,int tamLocalidad,int idLocalidad);

#endif /* LOCALIDAD_H_ */
