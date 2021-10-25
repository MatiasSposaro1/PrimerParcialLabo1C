/*
 * cliente.c
 *
 *  Created on: 19 oct. 2021
 *      Author: matia
 */


#include "cliente.h"
#include "nexo.h"
#include "localidad.h"

int inicializarClientes(Clientes* clientes,int tamClientes)
{
	int retorno = -1;

	if(clientes != NULL && tamClientes > 0)
	{
		for(int i = 0; i<tamClientes;i++)
		{
			clientes[i].isEmpty = 1;
			clientes[i].totalPedidosPendientes = 0;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarLibreClientes(Clientes* clientes,int tamClientes)
{
	int retorno = -1;

	if(clientes !=NULL && tamClientes > 0)
	{
		for(int i = 0; i<tamClientes; i++)
		{
			if(clientes[i].isEmpty == 1) //si esta vacio entra
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaCliente(Clientes* clientes, int tamClientes, int* idCliente,Localidad* localidad,int tamLocalidad)
{
	int retorno = -1;
	int indice;

	Clientes nuevoCliente;


	if(clientes!=NULL && tamClientes >0 && idCliente != NULL)
	{
		indice = buscarLibreClientes(clientes,tamClientes); //al indice le consigo un espacio la funcion buscarLibre

		if(indice != -1)
		{
			printf("ALTA CLIENTE \n\n");

			nuevoCliente.id = *idCliente; //autoincremental
			(*idCliente)++;

			printf("ID:%d\n",nuevoCliente.id);

			getString("Ingrese el nombre: ",nuevoCliente.nombre);

			getStringDigit("Ingrese cuit: ",nuevoCliente.cuit);

			printf("Ingrese la localidad: ");
			fflush(stdin);
			scanf("%d\n",&nuevoCliente.idLocalidad);

			printf("Ingrese la direccion: ");
			fflush(stdin);
			gets(nuevoCliente.direccion);

			nuevoCliente.isEmpty = 0; //ocupado
			nuevoCliente.totalPedidosPendientes = 0;

			clientes[indice] = nuevoCliente;

			printf("Cliente dado de alta con exito!! \n");
			retorno = 1;

		}
	}


	return retorno;
}

int modificarCliente(Clientes* clientes, int tamClientes,Localidad* localidad,int tamLocalidad)
{
	int retorno = -1;
	int indice;
	int opcion;
	int codigoCliente;

	Clientes auxCliente;

	if(clientes!=NULL && tamClientes>0)
	{
		mostrarClientes(clientes,tamClientes,localidad,tamLocalidad);
		getInt("Ingrese el id del cliente que desea modificar: ",&codigoCliente,1,10000);
		indice = buscarClientePorID(clientes,tamClientes,codigoCliente);

		if(indice != -1)
		{
			auxCliente = clientes[indice];

			printf("Cliente selecionado\n");
			//mostrarCliente(clientes[indice]);

			 getInt("\nEliga que desea modificar:\n1.Direccion\n2Localidad\n3.Volver\nEscoja su opcion: ", &opcion,1,3);

			 switch(opcion)
			 {
			 	case 1:
			 		printf("Ingrese la direccion: ");
			 		fflush(stdin);
			 		scanf("%c\n",auxCliente.direccion);

			 		break;
			 	case 2:
			 		printf("Ingrese el id de la localidad(1-La Plata,2-Alejandro Korn,3-SanVicente): ");
			 		fflush(stdin);
			 		scanf("%d\n",&auxCliente.idLocalidad);
			 		break;
			 	case 3:
			 		printf("Se cancelo la modificacion.\n");
			 		break;
			 }
			 if(opcion != 3)
			 {
				 clientes[indice] = auxCliente;
				 printf("Cliente modificado con exito.\n");
				 ///mostrarCliente(clientes[indice]);
			 }
			 retorno = 0;
		}
		else
		{
			printf("El id ingresado es erroneo.\n");
		}

	}
	return retorno;
}

int mostrarCliente(Clientes unCliente,Localidad unLocalidad)
{
	   printf("|%5d |%14s |%6s |%17s |%20s           |\n",
			   unCliente.id,
	           unCliente.nombre,
	           unCliente.cuit,
	           unCliente.direccion,
			   unLocalidad.descripcion);

	    return 0;
}

int mostrarClientes(Clientes* clientes, int tamClientes,Localidad* localidades,int tamLocalidad)
{
	int retorno = -1;

	if(clientes != NULL && tamClientes > 0 && localidades != NULL && tamLocalidad > 0)
	{
		printf("+======+===============+===============+=============+============================+\n");
		printf("|  ID  |    Nombre     |  Cuit |   Direccion      |           Localidad           |\n");
		printf("+======+===============+===============+=============+============================+\n");

		for(int i = 0; i<tamClientes;i++)
		{
			for(int j=0;j<tamLocalidad;j++)
			{
				if(clientes[i].isEmpty == 0)
				{
					mostrarCliente(clientes[i],localidades[j]);
					retorno = 0;
				}
			}

		}
	}
	return retorno;
}

int buscarClientePorID(Clientes* clientes, int tamClientes, int idCliente)
{
	int retorno = -1;

	if(clientes!=NULL && tamClientes > 0 && idCliente > 0)
	{
		for(int i = 0;i<tamClientes;i++)
		{
			if(clientes[i].id == idCliente && clientes[i].isEmpty == 0 )
			{
				retorno = i; //retorna el espacio encontrado
				break;
			}
		}
	}

	return retorno;
}

int bajaCliente(Clientes* clientes, int tamClientes,Localidad* localidades,int tamLocalidad)
{
	int retorno = -1;
	int idCliente;
	int indice;
	char opcion;

	if(clientes != NULL && tamClientes > 0)
	{
		mostrarClientes(clientes,tamClientes,localidades,tamLocalidad);
		getInt("Ingrese el ID que desea dar de baja: ",&idCliente,1,10000);
		indice = buscarClientePorID(clientes,tamClientes,idCliente);

		if(indice !=-1)
		{
				printf("Seguro desea eliminar? S/N: ");
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

				if(opcion == 'S')
				{
					printf("Eliminando... \n");
					clientes[indice].isEmpty = 1;
					retorno = 1;
				}

		}
		else
		{
			printf("Cliente inexistente \n");
		}

	}
	return retorno;
}

int localidadPedidos(Clientes* clientes,int tamClientes,Localidad* localidades,int tamLocalidades)
{
	int retorno = 1;
	char localidad[50];
	int suma = 0;

	if(clientes != NULL && tamClientes > 0 && localidades!=NULL && tamLocalidades > 0)
	{
		mostrarClientes2(clientes,tamClientes,localidades,tamLocalidades);
		getString("Ingrese la localidad que desea: ",localidad);

		for(int i = 0;i<tamClientes;i++)
		{
			if(strcmp(clientes[i].idLocalidad,localidad)==0)
			{
				suma = suma + clientes[i].totalPedidosPendientes;
			}
		}
		printf("La localidad:%s tiene %d \n",localidad,suma);
	}
	return retorno;
}
