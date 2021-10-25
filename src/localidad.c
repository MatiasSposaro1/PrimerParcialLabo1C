/*
 * localidad.c
 *
 *  Created on: 25 oct. 2021
 *      Author: matia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "localidad.h"

int buscarLocalidadPorID(Localidad* localidades,int tamLocalidad,int idLocalidad)
{
	int retorno = -1;

		if(localidades != NULL && tamLocalidad > 0 && idLocalidad > 0)
		{
			for(int i=0; i<tamLocalidad;i++)
			{
				if(localidades[i].idLocaldiadStruct == idLocalidad )
				{
					retorno = i;
					break;
				}
			}
		}

		return retorno;
}

