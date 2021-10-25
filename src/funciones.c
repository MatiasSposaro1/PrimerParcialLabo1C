/*
 * funciones.c
 *
 *  Created on: 17 sep. 2021
 *      Author: matia
 */


#include "funciones.h"


int getInt(char* mensaje, int* pResultado, int minimo, int maximo)
{
    int retorno = -1;
    int auxInt;
    if(mensaje != NULL && pResultado != NULL && maximo < 32768)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &auxInt);
        while(auxInt < minimo || auxInt > maximo)
        {
            printf("Error. Ingrese entre (%d - %d): ", minimo, maximo);
            fflush(stdin);
            scanf("%d", &auxInt);
        }
        *pResultado = auxInt;
        retorno = 0;
    }else
    {
        printf("Error de parametros en la funcion\n");
    }
    return retorno;
}

int getFloat(char* mensaje, float* pResultado)
{
    int retorno = -1;
    int retornoScanf;
    float auxFloat;
    if(mensaje != NULL && pResultado != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        retornoScanf = scanf("%f", &auxFloat);
        while(retornoScanf == 0)
        {
            printf("Error. Ingrese solo numeros: ");
            fflush(stdin);
            retornoScanf = scanf("%f", &auxFloat);
        }
        *pResultado = auxFloat;

        retorno = 0;
    }
    return retorno;
}

int getString(char* mensaje, char pResultado[])
{
    int retorno = -1;
    char auxCad[100];
    if(mensaje != NULL && pResultado != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(auxCad);

        while(strlen(auxCad) > 50 || strlen(auxCad) < 1 || isdigit(*auxCad))
        {
            printf("Error. Ingrese solo caracteres: ");
            fflush(stdin);
            gets(auxCad);
        }

        strcpy(pResultado, auxCad);

        retorno = 0;
    }

    return retorno;
}

int getStringDigit(char* mensaje,char pResultado[])
{
	int retorno = 0;
	int auxWhile;
	char auxChar[30];

	if(mensaje!=NULL && pResultado !=NULL)
	{

		printf("%s",mensaje);
		fflush(stdin);
		gets(auxChar);

		do
		{
			auxWhile = 0;
			for(int i = 0; i<strlen(auxChar);i++)
			{
				if(isalpha(auxChar[i])!=0 || isdigit(auxChar[i]) == 0)
				{
					printf("ERROR! %s",mensaje);
					fflush(stdin);
					gets(auxChar);
					auxWhile = 1;
					break;
				}
			}
		}while(auxWhile==1);


		strcpy(pResultado,auxChar);
		retorno = 1;
	}
	return retorno;
}
