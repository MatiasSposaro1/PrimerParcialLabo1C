/*
 * cliente.h
 *
 *  Created on: 19 oct. 2021
 *      Author: matia
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "funciones.h"
#include "localidad.h"

struct
{
	int id; //autoincremental
	char cuit[40];
	char nombre[30];
	//char localidad[30];
	int idLocalidad;
	char direccion[30];
	int totalPedidosPendientes;
	int totalPedidosProcesados;
	int isEmpty;

}typedef Clientes;

/*********************************************************************************************************/
/**
 * @brief inicializa la bandera de los clientes en 1, retorna -1 si algo salio mal y 0 si toda esta bien
 * @param clientes
 * @param tamClientes
 * @return int
 */
int inicializarClientes(Clientes* clientes,int tamClientes);
/*********************************************************************************************************/
/**
 * @brief busca si hay alguna bandera de isEmpty en 1 del array clientes y retorna el indice de donde lo encontre o -1 si algo salio mal o no la encuentra
 * @param clientes
 * @param tamClientes
 * @return int
 */
int buscarLibreClientes(Clientes* clientes,int tamClientes);
/*********************************************************************************************************/
/**
 * @brief a de alta un cliente asignadole un id  pasado por referencia retorna 1 si salio  bien y -1 si salio algo mal
 * @param clientes
 * @param tamClientes
 * @param idCliente
 * @return int
 */
int altaCliente(Clientes* clientes, int tamClientes, int* idCliente,Localidad* localidad,int tamLocalidad);
/*********************************************************************************************************/
/**
 * @brief sirve para modificar un cliente retorna -1 si algo salio mal y 0 si  salio bien
 * @param clientes
 * @param tamClientes
 * @return int
 */
int modificarCliente(Clientes* clientes, int tamClientes,Localidad* localidad,int tamLocalidad);
/*********************************************************************************************************/
/**
 * @brief muestra un cliente
 * @param unCliente
 * @return int
 */
int mostrarCliente(Clientes unCliente,Localidad unLocalidad);
/*********************************************************************************************************/
/**
 * @brief muestra varios clientes
 * @param clientes
 * @param tamClientes
 * @return int
 */
int mostrarClientes(Clientes* clientes, int tamClientes,Localidad* localidades,int tamLocalidad);
/*********************************************************************************************************/
 /**
   *@brief Busca un cliente por el id pasado por valor retorna el indice donde lo encontre devuelve -1 si no encontro o algo salio mal
  * @param clientes
  * @param tamClientes
  * @param idCliente
  * @return int
  */
int buscarClientePorID(Clientes* clientes, int tamClientes, int idCliente);
/*********************************************************************************************************/
/**
 * @brief da de baja un cliente colocando el isEmpty de este en 1(vacio)
 * @param clientes
 * @param tamClientes
 * @return int
 */
int bajaCliente(Clientes* clientes, int tamClientes,Localidad* localidades,int tamLocalidad);
/*********************************************************************************************************/
/**
 * @brief sirve para informar una localidad pedida que esta en estado Pendiente
 * @param clientes
 * @param tamClientes
 * @return int
 */
int localidadPedidos(Clientes* clientes,int tamClientes,Localidad* localidades,int tamLocalidades);
#endif /* CLIENTE_H_ */
