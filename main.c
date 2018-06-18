/******************************************************************
 *
 * Programación I – Laboratorio I
 * Programa: Modelo parcial segundo cuatrimestre 2015
 *
 * Objetivo:
 *
 * Desarrollar en ANSI C:
 * Un comercio necesita administrar sus productos (desconociéndose cuantos son).
 * Para ello se deberá realizar un programa que trabaje con
 * estructuras, archivos y administración dinámica de memoria de acuerdo a lo siguiente:
 *
 *	    • Datos:
 *      	o Código de Producto (1 a 1000) Validar
 *			o Descripción (máximo 50 caracteres) Validar o Importe Validar
 *			o Cantidad Validar
 *			o Activo (0 para activo – 1 para NO activo)
 *
 *      • Estructura: Se utilizará una estructura con los datos mencionados precedentemente.
 *
 *		• Archivo: Se utilizarán dos archivos:
 *			o datos.dat: como archivo principal para trabajar con los datos.
 *			o temporal.dat: como archivo temporal para utilizar de auxiliar en la baja física; y de auxiliar en la
 *			  generación del archivo datos.dat ordenado luego de aplicar una lista simplemente enlazada.
 *
 *		• Asignación dinámica de memoria: Se realizará una lista simplemente enlazada que lea el archivo datos.dat
 *		  desde el primer registro hasta el último, insertando de este modo cada registro leído (ordenado por el campo
 *		  Descripción de manera descendente) en la lista, por último generar el datos.dat ordenado.
 *
 *		1. ALTAS: Se ingresará un producto escribiéndose en el archivo datos.dat y luego se regresará al menú.
 *		2. MODIFICAR: Se ingresará el Código de Producto, permitiendo modificar en el archivo datos.dat:
 *				o Descripción o Importe
 *				o Cantidad
 *		3. BAJA LÓGICA: Se ingresará el Código de Producto y se escribirá con valor cero el campo Activo en el archivo datos.dat.
 *		4. BAJA FÍSICA: Se ingresará el Código de Producto y se escribirán en el archivo todos los registros, menos el que se está dando de baja.
 *		   Informar si no existe el registro buscado en el archivo.
 *	   	   Utilizar en este punto los archivos datos.dat y temporal.dat.
 *		5. LISTAR: Realizar un listado de los datos ordenados por Descripción, utilizando el archivo datos.dat.
 *
 * NOTA: Se deberá realizar el menú de opciones, las validaciones y cada uno de las cinco opciones del menú a través de funciones.
 * Tener en cuenta que no se podrá ingresar a los casos 2, 3, 4 y 5; sin antes haber realizado el alta de algún producto o tener al menos un producto escrito en el archivo (utilizar bandera).
 *
 * Version: 0.1 del 18 de junio de 2018
 * Autor: Gaston Pesoa
 *
 * *******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"

#define ARCH_1 "datos.dat"
#define ARCH_2 "temporal.dat"

int main(){

	//Se define puntero a estructura FILE
	FILE* pFile;

	//Se crea una lista del tipo arrayList
	ArrayList* productsList = al_newArrayList();
	if(productsList == NULL){
		printf("\r\nEspacio en memoria insuficiente\r\n");
		return 0;
	}

	//Hardcodeo de productos para testing
	productsList_testing(productsList);


    int opcionMenuPrincipal = 0;
    int opcionMenuModificar = 0;

    //Menu principal
    while(opcionMenuPrincipal != 6){

        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1: //Altas

            	//Se abre en modo lectura
            	if((pFile = fopen(ARCH_1,"rb+")) == NULL){
            		//Si el modo anterior dio error el archivo no existe, por lo tanto se crea
            		if((pFile = fopen(ARCH_1,"wb+")) == NULL){
            			printf("\r\nEl archivo no puede ser abierto\r\n");
            			getChar("\r\nPresione una tecla para volver al menu principal\r\n");
            			break;
            		}
            	}

            	//Se crea una estructura Product de forma dinámica
            	Product* pProduct = product_new();
            	//Se define nuevo Id para el producto en funcion del size del arrayList
            	int productIdAux = productsList->len(productsList);

            	//Se solicitan, validan y setean los datos del producto en la estructura Product
            	if(product_enter(pProduct, productIdAux,1,1000,1,51,0.01,9999999.99,0,9999999) == -1){

            		printf("\r\nNo se pudo ingresar el nuevo producto, verifique espacio en memoria\r\n");
            		getChar("\r\nPresione una tecla para volver al menu principal\r\n");
            	}
            	if(productsList->add(productsList, pProduct) == -1){

            		printf("\r\nNo se pudo ingresar el nuevo producto, verifique espacio en memoria\r\n");
            		getChar("\r\nPresione una tecla para volver al menu principal\r\n");
            	}

            	//Se desplaza el indicador de posicion al final del archivo para escribir el nuevo producto
            	cleanStdin();
			    fseek(pFile, 0L, SEEK_END);
			    fwrite(productsList->get(productsList, productIdAux), sizeof(Product), 1, pFile);

            	fclose(pFile);

                break; //case 1: Altas

            case 2: //Modificar

                //Menu modificar
                	while(opcionMenuModificar != 4){

            		opcionMenuModificar = optionModifyMenu();

            		switch(opcionMenuModificar){

            			case 1: // Modificar descripcion


            				break;
            			case 2: // Modificar importe
            				break;
            			case 3: // Modificar cantidad
            				break;
            			case 4: // Regresar
            				continue;
            		} // switch(opcionMenuModificar)
            	} // while(opcionMenuModificar != 4)

                break; // case 2: Modificar

            case 3: // Baja logica

                break; // case 3: Baja logica

            case 4: // Baja fisica

                break; // case 4: Baja fisica

            case 5: // Listar

                break; // case 5: Listar

            case 6: //Salir
                continue;
        }
    }
    return 0;
}
