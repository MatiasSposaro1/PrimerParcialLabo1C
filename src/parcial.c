/*
 ============================================================================
 Name        : parcial.c
 Author      : Matias Sposaro  1°DIV C
 Version     :
 Copyright   :
 Description : ParcialLaboratorio 1eraParte
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "nexo.h"
#include "localidad.h"

#define TAMCLIENTES 100
#define TAMPEDIDOS 1000
#define TAMLOCALIDAD 3

/**
 * @brief retorna la opcion ingresada por el usuario
 * @return int
 */
int menu();

int main(void)
{

	Localidad localidades [TAMLOCALIDAD] = {{1, "La Plata"} , {2, "AlejandroKorn"}, {3, "San Vicente"}};

	setbuf(stdout,NULL);

	char opcion = 'N';

	int contadorClientes = 0;
	int contadorPedidos = 0;
	int codigoCliente = 1;
	int codigoPedidos = 1;

	Clientes clientes[TAMCLIENTES];
	Pedidos pedidos[TAMPEDIDOS];
	Localidad localidades[TAMLOCALIDAD];

	inicializarClientes(clientes,TAMCLIENTES);
	inicializarPedidos(pedidos,TAMPEDIDOS);

	do
	{
		switch(menu())
		{
		case 1:
			if(contadorClientes < TAMCLIENTES)
			{
				if(altaCliente(clientes,TAMCLIENTES,&codigoCliente,localidades,TAMLOCALIDAD))
				{
					 contadorClientes++;
				}
			}
			else
			{
				printf("Sistema lleno..");
			}
			break;


		case 2:
			if(contadorClientes > 0)
			{
				modificarCliente(clientes,TAMCLIENTES,localidades,TAMLOCALIDAD);
			}
			else
			{
				printf("No hay clientes cargados para modificar \n");
			}
			break;
		case 3:
			if(contadorClientes > 0)
			{
				if(bajaCliente(clientes,TAMCLIENTES,localidades,TAMLOCALIDAD) == 1)
				{
					contadorClientes--;
				}
			}else
			{
				printf("No hay clientes cargados para eliminar \n");
			}
			break;
		case 4:
			if(contadorPedidos < TAMPEDIDOS && contadorClientes > 0)
			{
				if(crearPedidos(pedidos,TAMPEDIDOS,&codigoPedidos,clientes,TAMCLIENTES,&codigoCliente))
				{
					contadorPedidos++;
				}
			}
			else
			{
				printf("No hay clientes cargados para pedir pedidos \n");
			}
			break;

		case 5:
			if(contadorPedidos > 0 && contadorClientes > 0)
			{
				if(procesarResiduos(pedidos,TAMPEDIDOS,clientes,TAMCLIENTES))
				{
					printf("Residuos procesados con exito!! \n");
				}
			}
			else
			{
				printf("Cargue un cliente para procesar!! \n");
			}
			break;
		case 6:
			if(contadorPedidos > 0 && contadorClientes > 0)
			{
				mostrarClientes2(clientes,TAMCLIENTES,localidades,TAMLOCALIDADES);
			}
			else
			{
				printf("No hay clientes para mostrar \n");
			}
			break;
		case 7:
			if(contadorPedidos > 0)
			{
				mostrarPedidosPendientes(pedidos,TAMPEDIDOS,clientes,TAMCLIENTES);
			}
			else
			{
				printf("No hay pedidos pendientes para mostrar \n");
			}
			break;
		case 8:
			if(contadorPedidos > 0)
			{
				mostrarPedidosProcesados(pedidos,TAMPEDIDOS,clientes,TAMCLIENTES);
			}
			else
			{
				printf("No hay pedidos para mostrar \n");
			}
			break;
		case 9:
			if(contadorPedidos > 0 && contadorClientes > 0)
			{
				localidadPedidos(clientes,TAMCLIENTES);
			}
			else
			{
				printf("No hay localidades que mostrar \n");
			}
			break;
		case 10:
			if(contadorPedidos > 0 && contadorClientes > 0)
			{
				promedioPolipropileno(pedidos,TAMPEDIDOS,clientes,TAMCLIENTES);
			}
			else
			{
				printf("No hay ningun promedio que informar \n");
			}
			break;

		case 11:
			printf("Seguro desea salir S/N: ");
			fflush(stdin);
			scanf("%c",&opcion);
			opcion = toupper(opcion);

			while(opcion != 'S' && opcion != 'N')
			{
				printf("Opcion incorrecta.Ingrese nuevamente: ");
				fflush(stdin);
				scanf("%c",&opcion);
				opcion = toupper(opcion);
			}

			if(opcion == 'N')
			{
				printf("Salir cancelado\n");
			}
			break;

		}


		system("PAUSE");
	}while(opcion == 'N');
	printf("Salio del programa...");


	return EXIT_SUCCESS;
}


int menu()
{
	int opcion;

	  	printf("=======================================================\n");
	    printf("                MENU DE EMPLEADOS\n");
	    printf("=======================================================\n");
	    printf("    1 - Alta de Cliente\n");
	    printf("    2 - Modificar datos de Cliente\n");
	    printf("    3 - Baja de Cliente\n");
	    printf("    4 - Crear pedido de recolección\n");
	    printf("    5 - Procesar residuos\n");
	    printf("    6 - Imprimir Clientes\n");
	    printf("    7 - Imprimir Pedidos pendientes\n");
	    printf("    8 - Imprimir Pedidos procesados\n");
	    printf("    9 - Cantidad de pedidos pendientes por localidad\n");
	    printf("   10 - Cantidad kilos de polipropileno promedio por cliente\n");
	    printf("   11 - Salir\n");
	    printf("=======================================================\n");

	    printf("Ingrese una opcion: ");
	    fflush(stdin);
	    scanf("%d",&opcion);

	    while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6 && opcion != 7 && opcion != 8 && opcion != 9 && opcion != 10 && opcion != 11)
	    {
	    	printf("Error.Opcion incorrecta,Ingresa nuevamente: ");
	    	fflush(stdin);
	    	scanf("%d",&opcion);
	    }

	return opcion;
}
