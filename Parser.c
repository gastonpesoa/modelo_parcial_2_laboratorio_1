#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"


//int parserProduct(FILE* pFile , ArrayList* productsList){
//
//    int readItem;
//    char idStr[256],name[256],lastName[256],isEmptyStr[256];
//    int idAux, isEmptyAux=0;
//    int flag = 0;
//
//    pFile = fopen("data.csv","r");
//    if (pFile==NULL) {
//
//        printf("\nNo se pudo abrir el archivo\n");
//        getChar("Enter para salir: ");
//        exit(1);
//    }
//
//    while(!feof(pFile)){
//
//        if(pFile == NULL){
//
//            printf("\nEl archivo no existe");
//            exit(1);
//        }
//        if(flag == 0){
//
//            fscanf(ptrFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,name,lastName,isEmptyStr);
//            flag = 1;
//            continue;
//        }
//
//        readItem = fscanf(ptrFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,name,lastName,isEmptyStr);
//        if(readItem==4){
//
//            Product* producto = product_new();
//
//            idAux = atoi(idStr);
//            product_setId(producto,idAux);
//            product_setName(producto,name);
//            product_setLastName(producto,lastName);
//
//            if(strncmp(isEmptyStr,"true",4)==0){
//                isEmptyAux = 1;
//            }
//            if(strncmp(isEmptyStr,"false",5)==0){
//                isEmptyAux = 0;
//            }
//
//            product_setIsEmpty(producto,isEmptyAux);
//
//            al_add(pArrayListProduct,producto);
//
//            //Product_print(producto);
//        }
//        else {
//
//            printf("\nNo se leyeron los datos correctamente\n");
//            getChar("Enter para salir: ");
//            exit(1);
//        }//if(readItem==4)
//    }//while(!feof(ptrFile))
//
//    printf("\nLista cargada con exito\n");
//    getChar("Presione una tecla para continuar: ");
//
//    fclose(ptrFile);
//    return 0;
//}
