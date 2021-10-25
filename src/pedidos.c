/*
 * pedidos.c
 *
 *  Created on: 22 oct. 2021
 *      Author: matia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pedidos.h"

int inicializarPedidos(Pedidos* pedidos,int tamPedidos)
{
	int retorno = -1;

	if(pedidos != NULL && tamPedidos > 0)
	{
		for(int i = 0; i<tamPedidos; i++)
		{
			pedidos[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarLibrePedidos(Pedidos* pedidos,int tamPedidos)
{
	int retorno = -1;

	if(pedidos !=NULL && tamPedidos > 0)
	{
		for(int i = 0; i<tamPedidos;i++)
		{
			if(pedidos[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int buscarPedidosPorID(Pedidos* pedidos,int tamPedidos,int idPedido)
{
	int retorno = -1;

	if(pedidos!=NULL && tamPedidos > 0 && idPedido > 0)
	{
		for(int i=0; i<tamPedidos;i++)
		{
			if(pedidos[i].idPedido == idPedido && pedidos[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
