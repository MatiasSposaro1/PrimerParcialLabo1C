/*
 * nexo.c
 *
 *  Created on: 22 oct. 2021
 *      Author: matia
 */


#include "nexo.h"
#include "localidad.h"

int crearPedidos(Pedidos* pedidos,int tamPedidos,int* idPedido,Clientes* clientes,int tamClientes,int* idCliente,Localidad* localidades,int tamLocalidades)
{
	int retorno = 0;

	int indicePedidos;
	int indiceClientes;

	Pedidos nuevoPedido; //variable auxiliar para guardar datos

	if(pedidos!=NULL && tamPedidos >0 && idPedido != NULL && clientes!=NULL && tamClientes > 0)
	{
		indicePedidos = buscarLibrePedidos(pedidos,tamPedidos);

		if(indicePedidos != -1)
		{
			nuevoPedido.idPedido = *idPedido;
			(*idPedido)++;

			printf("---CREAR PEDIDO---\n");

			printf("Lista de clientes\n");
			mostrarClientes(clientes,tamClientes,localidades,tamLocalidades);

			getInt("Ingrese el ID del cliente que desea selecionar: ",&nuevoPedido.idCliente,1,32762);
			indiceClientes = buscarClientePorID(clientes,tamClientes,nuevoPedido.idCliente);

			while(indiceClientes == -1)
			{
				getInt("ERROR!Cliente no encontrado.Reingrese el ID del cliente que desea selecionar: ",&nuevoPedido.idCliente,1,32762);
				indiceClientes = buscarClientePorID(clientes,tamClientes,nuevoPedido.idCliente);
			}


			getInt("Ingrese la cantidad de kilos totales: ",&nuevoPedido.kilosTotales,1,30000);

			nuevoPedido.isEmpty = 0;
			nuevoPedido.status =  1; //PENDIENTE
			pedidos[indicePedidos] = nuevoPedido;
			clientes[indiceClientes].totalPedidosPendientes++;

			printf("Pedido cargado \n");

			retorno = 1;
		}
	}

	return retorno;
}

int procesarResiduos(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes)
{
	int retorno = 0;
	int indice;
	int codigoPedidos;


	if(pedidos!=NULL && tamPedidos > 0 && clientes != NULL && tamClientes > 0)
	{
		mostrarPedidos(pedidos,tamPedidos,clientes,tamClientes);
		printf("---PROCESAR RESIDUOS--- \n");
		getInt("Ingrese el ID del pedido: ",&codigoPedidos,1,10000);
		indice = buscarPedidosPorID(pedidos,tamPedidos,codigoPedidos);

		if(indice != -1)
		{
			printf("\nCANTIDADES A PROCESAR:\n");

			getInt("Ingrese KG de Polietileno de alta densidad:",&pedidos[indice].HDPE,1,30000);
			getInt("Ingrese KG de Polietileno de baja densidad:",&pedidos[indice].LDPE,1,30000);
			getInt("Ingrese KG de Polipropileno:",&pedidos[indice].PP,1,30000);

			pedidos[indice].status = COMPLETADO; //COMPLETADO

			printf("Pedido completado \n");


			retorno = 1;

		}
	}



	return retorno;
}

int mostrarPedido(Pedidos unPedido,Clientes unCliente)
{
	printf("|%5d |%14s |%10d     |\n",
			unCliente.id,
			unCliente.nombre,
			unPedido.kilosTotales);
	return 0;
}

int mostrarPedidos(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes)
{
	int retorno = -1;

	if(pedidos != NULL && tamPedidos > 0 && clientes != NULL && tamClientes >0)
	{
		printf("+======+===============+===============+\n");
		printf("|  ID  |    Nombre     | Kilos Totales |\n");
		printf("+======+===============+===============+\n");

		for(int i=0; i<tamPedidos;i++)
		{
			if(pedidos[i].isEmpty == 0 && pedidos[i].status == PENDIENTE)
			{
				for(int j=0; j<tamClientes;j++)
				{
					if(clientes[j].isEmpty == 0 && clientes[j].id == pedidos[i].idCliente)
					{
						mostrarPedido(pedidos[i],clientes[j]);
						retorno = 0;
					}
				}
			}

		}
	}
	return retorno;
}

int mostrarCliente2(Clientes unCliente,Localidad unLocalidad)
{
	 printf("|%5d |%14s |%14s |%12s |%29s| %10d                |\n",
				   unCliente.id,
		           unCliente.nombre,
		           unCliente.cuit,
		           unCliente.direccion,
		           unLocalidad.descripcion,
				   unCliente.totalPedidosPendientes);

	return 0;
}

int mostrarClientes2(Clientes* clientes,int tamClientes,Localidad* localidades,int tamLocalidades)
{
	int retorno = -1;

	if(clientes != NULL && tamClientes >0)
	{
		printf("+======+===============+===============+=============+============================++============================+\n");
		printf("|  ID  |    Nombre     |     Cuit      |   Direccion |           Localidad         |         Pedidos			 \n");
		printf("+======+===============+===============+=============+============================++============================+\n");

		for(int i=0;i<tamClientes;i++)
		{
			for(int j=0;j<tamLocalidades;j++)
			{
				if(clientes[i].isEmpty == 0 && clientes[i].totalPedidosPendientes > 0)
				{
					mostrarCliente2(clientes[i],localidades[j]);
					retorno = 0;
				}
			}

		}

	}

	return retorno;
}

int mostrarPedido2(Pedidos unPedido,Clientes unCliente)
{
	printf("|%10s |%14s |%10d     |\n",
				unCliente.cuit,
				unCliente.direccion,
				unPedido.kilosTotales);
	return 0;
}

int mostrarPedidosPendientes(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes)
{
	int retorno = -1;

		if(pedidos != NULL && tamPedidos > 0 && clientes != NULL && tamClientes >0)
		{
			printf("+======+===============+===============+\n");
			printf("| Cuit |    Direccion  | Kilos Totales |\n");
			printf("+======+===============+===============+\n");

			for(int i=0; i<tamPedidos;i++)
			{
				for(int j=0; j<tamClientes;j++)
				{
					if(clientes[j].isEmpty == 0 && pedidos[i].isEmpty == 0 && pedidos[i].status == 1)
					{
						mostrarPedido(pedidos[i],clientes[j]);
						retorno = 0;
					}
				}
			}
		}
		return retorno;
}

int mostrarPedido3(Pedidos unPedido,Clientes unCliente)
{
	 printf("|%5s |%14s |%5d |%5ds |%5d                |\n",
					   unCliente.cuit,
			           unCliente.direccion,
			           unPedido.HDPE,
			           unPedido.LDPE,
					   unPedido.PP);

	 return 0;
}

int mostrarPedidosProcesados(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes)
{
	int retorno = 1;

	if(pedidos != NULL && tamPedidos > 0 && clientes != NULL && tamClientes >0)
	{
		printf("+======+===============+===============+===============+===============+\n");
		printf("| Cuit |    Direccion  |     HDPE 	   |	 LDPE	   |	 PP		   |\n");
		printf("+======+===============+===============+===============+===============+\n");

		for(int i=0; i<tamPedidos;i++)
		{
			if(pedidos[i].isEmpty == CARGADO && pedidos[i].status == COMPLETADO)
			{
				for(int j=0;j<tamClientes;j++)
				{
					if(pedidos[i].idCliente == clientes[j].id && clientes[j].isEmpty == CARGADO)
					{
						mostrarPedido3(pedidos[i],clientes[j]);
						retorno = 0;
					}
				}

			}
		}
	}

	return retorno;
}

int promedioPolipropileno(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes)
{
	int retorno = 1;
	int indice;
	int acumulador = 0;
	int contador = 0;

	float promedio;


	if(pedidos != NULL && tamPedidos > 0 && clientes != NULL && tamClientes >0)
	{
		for(int i = 0; i<tamPedidos; i++)
		{
			if(pedidos[i].isEmpty == CARGADO && pedidos[i].status == COMPLETADO)
			{
				indice = buscarClientePorID(clientes,tamClientes,pedidos[i].idCliente);

				if(indice != -1)
				{
					acumulador = acumulador + pedidos[indice].PP;
					contador++;
				}
			}

		}
		promedio = (float) acumulador / contador;
		printf("La cantidad de Polipropileno promedio es %.2f",promedio);
	}
	return retorno;
}
