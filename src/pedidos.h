/*
 * pedidos.h
 *
 *  Created on: 22 oct. 2021
 *      Author: matia
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "funciones.h"

#define PENDIENTE  1
#define COMPLETADO 0
#define BASURA -1

#define CARGADO 0
#define VACIO 1
struct
{
	int idPedido;
	int idCliente;

	int kilosTotales;
	int HDPE;
	int LDPE;
	int PP;

	int status; //PENDIENTE-COMPLETADO

	int isEmpty;


}typedef Pedidos;

/*********************************************************************************************************/
/**
 * @brief inicializa la bandera de los pedidos en 1 , retorna -1 si algo salio mal y 0 si esta bien
 * @param pedidos
 * @param tamPedidos
 * @return int
 */
int inicializarPedidos(Pedidos* pedidos,int tamPedidos);
/*********************************************************************************************************/
/**
 * @brief busca si hay alguna de bandera de isEmpty en 1  y retorna el indice donde lo encontro
 * @param pedidos
 * @param tamPedidos
 * @return int
 */
int buscarLibrePedidos(Pedidos* pedidos,int tamPedidos);
/*********************************************************************************************************/
/**
 * @brief encuentra un pedido por su id
 * @param pedidos
 * @param tamPedidos
 * @param idPedido
 * @return int
 */
int buscarPedidosPorID(Pedidos* pedidos,int tamPedidos,int idPedido);
/*********************************************************************************************************/


#endif /* PEDIDOS_H_ */
