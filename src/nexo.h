/*
 * nexo.h
 *
 *  Created on: 22 oct. 2021
 *      Author: matia
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "funciones.h"
#include "pedidos.h"
#include "cliente.h"
#include "localidad.h"

/*********************************************************************************************************/
/**
 * @brief sirve para ingresar kilos a recolectar
 * @param pedidos
 * @param tamPedidos
 * @param idPedido
 * @param clientes
 * @param tamClientes
 * @param idCliente
 * @return int
 */
int crearPedidos(Pedidos* pedidos,int tamPedidos,int* idPedido,Clientes* clientes,int tamClientes,int* idCliente,Localidad* localidades,int tamLocalidades);
/*********************************************************************************************************/
/**
 * @brief  Permite definir cuantos kilos del total de kilos ingresados seran procesados dentro de los diferentes tipos de plastico
 * @param pedidos
 * @param tamPedidos
 * @param clientes
 * @param tamClientes
 * @return int
 */
int procesarResiduos(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes);
/*********************************************************************************************************/
/**
 * @brief Permite mostrar un pedido
 * @param unPedido
 * @param unCliente
 * @return int
 */
 int mostrarPedido(Pedidos unPedido,Clientes unCliente);
 /*********************************************************************************************************/
 /**
   *@brief sirve para mostrar todos los pedidos
  * @param pedidos
  * @param tamPedidos
  * @param clientes
  * @param tamClientes
  * @return int
  */
 int mostrarPedidos(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes);
  /*********************************************************************************************************/
  /**
   * @brief sirve para mostrar un cliente con las veces que pidio
   * @param unCliente
   * @param unPedido
   * @return int
   */
 int mostrarCliente2(Clientes unCliente,Localidad unLocalidad);
 /*********************************************************************************************************/
 /**
   *@brief sirve para mostrar todos los clientes con las veces que pidio
  * @param clientes
  * @param tamClientes
  * @param pedidos
  * @param tamPedidos
  * @return int
  */
 int mostrarClientes2(Clientes* clientes,int tamClientes,Localidad* localidades,int tamLocalidades);
 /*********************************************************************************************************/
 /**
   *@brief sirve para mostrar un solo pedido con la información(pendiente): Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
  * @param unPedido
  * @param unCliente
  * @return int
  */
   int mostrarPedido2(Pedidos unPedido,Clientes unCliente);
  /*********************************************************************************************************/
  /**
   * @brief sirve para mostrar pedidosPendientes
   * @param pedidos
   * @param tamPedidos
   * @param clientes
   * @param tamClientes
   * @return int
   */
   int mostrarPedidosPendientes(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes);
   /*********************************************************************************************************/
   /**
    * @brief sirve para mostrar un solo pedido con la información(completado): Cuit del cliente, dirección del cliente,cantidad de kilos reciclados de cada tipo
      de plástico.
    * @param unPedido
    * @param unCliente
    * @return int
    */
   int mostrarPedido3(Pedidos unPedido,Clientes unCliente);
   /*********************************************************************************************************/
   int mostrarPedidosProcesados(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes);
   /*********************************************************************************************************/
   int promedioPolipropileno(Pedidos* pedidos,int tamPedidos,Clientes* clientes,int tamClientes);
#endif /* NEXO_H_ */
