# modelo_parcial_2_laboratorio_1
Modelo del parcial del segundo cuatrimestre del 2015 de la materia Laboratorio de computación I UTN FRA

/**************************************************************************************************************

 Programación I – Laboratorio I
 Programa: Modelo parcial segundo cuatrimestre 2015
 
 Objetivo:
 
 Desarrollar en ANSI C:
 Un comercio necesita administrar sus productos (desconociéndose cuantos son).
 Para ello se deberá realizar un programa que trabaje con
 estructuras, archivos y administración dinámica de memoria de acuerdo a lo siguiente:

    • Datos:
        o Código de Producto (1 a 1000) Validar
    	o Descripción (máximo 50 caracteres) Validar o Importe Validar
  	o Cantidad Validar
    	o Activo (0 para activo – 1 para NO activo)

    • Estructura: Se utilizará una estructura con los datos mencionados precedentemente.
 
    • Archivo: Se utilizarán dos archivos:
      	o datos.dat: como archivo principal para trabajar con los datos.
        o temporal.dat: como archivo temporal para utilizar de auxiliar en la baja física; y de auxiliar en la			  
          generación del archivo datos.dat ordenado luego de aplicar una lista simplemente enlazada.
 
    • Asignación dinámica de memoria: Se realizará una lista simplemente enlazada que lea el archivo datos.dat 
      desde el primer registro hasta el último, insertando de este modo cada registro leído (ordenado por el campo
      Descripción de manera descendente) en la lista, por último generar el datos.dat ordenado.

    1. ALTAS: Se ingresará un producto escribiéndose en el archivo datos.dat y luego se regresará al menú.
    2. MODIFICAR: Se ingresará el Código de Producto, permitiendo modificar en el archivo datos.dat:
 	o Descripción o Importe
 	o Cantidad
    3. BAJA LÓGICA: Se ingresará el Código de Producto y se escribirá con valor cero el campo Activo en el archivo datos.dat.
    4. BAJA FÍSICA: Se ingresará el Código de Producto y se escribirán en el archivo todos los registros, menos el que se eliminando.
       Informar si no existe el registro buscado en el archivo.
       Utilizar en este punto los archivos datos.dat y temporal.dat.
    5. LISTAR: Realizar un listado de los datos ordenados por Descripción, utilizando el archivo datos.dat.
 
 *NOTA: Se deberá realizar el menú de opciones, las validaciones y cada uno de las cinco opciones del menú a través de funciones.
  Tener en cuenta que no se podrá ingresar a los casos 2, 3, 4 y 5; sin antes haber realizado el alta de algún producto o tener al menos     un producto escrito en el archivo (utilizar bandera).

Version: 0.1 del 18 de junio de 2018
Autor: Gaston Pesoa

******************************************************************************************************************/
