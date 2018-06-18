#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"


#define PRODUCT_INACTIVE  0
#define PRODUCT_ACTIVE  1


Product* product_newTest(int id, char* description,float price,int stock){

    Product* returnAux = NULL;
    Product* pProduct = (Product*)malloc(sizeof(Product));

    if(pProduct != NULL){

        pProduct->id = id;
        strcpy(pProduct->description,description);
        pProduct->price = price;
        pProduct->stock = stock;
        pProduct->status = PRODUCT_ACTIVE;
        returnAux = pProduct;
    }

    return returnAux;
}


Product* product_new(void){

    Product* returnAux = NULL;
    returnAux = (Product*)malloc(sizeof(Product));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


int product_enter(Product* pProduct,int id,int lowLimitId,int hiLimitId,\
    int lowLimitDesc,int hiLimitDesc,\
    int lowLimitPrice,int hiLimitPrice,int lowLimitStock,int hiLimitStock){

    int returnAux = -1;
    char* descriptionAux = NULL;
    float priceAux;
    int stockAux;

    if(product_setId(pProduct, id, lowLimitId, hiLimitId) == 0){

        product_askDescription(descriptionAux);
         while (product_setDescription(pProduct, descriptionAux, lowLimitDesc, lowLimitDesc) == -1) {
            product_askDescription(descriptionAux);
        }

        priceAux = product_askPrice(lowLimitPrice, hiLimitPrice);
        product_setPrice(pProduct, priceAux);

        stockAux = product_askStock(lowLimitStock, hiLimitStock);
        product_setStock(pProduct, stockAux);

        product_setStatus(pProduct, PRODUCT_ACTIVE);

        returnAux = 0;
    }

    return returnAux;
}


void product_askDescription(char *input){

    getValidString("Ingrese la descripcion del producto: ", "La descripcion debe ser solo letras", input);

    capitalize(input);
}


float product_askPrice(float lowLimit, float hiLimit){

    float priceAux;

    priceAux = getValidFloat("Ingrese el precio: ", "El precio debe ser numerico", lowLimit, hiLimit);

    return priceAux;
}


int product_askStock(int lowLimit, int hiLimit){

    int stockAux;

    stockAux = getValidInt("Ingrese el stock: ", "El stock debe ser numerico", lowLimit, hiLimit);

    return stockAux;
}


int product_setId(Product* pProduct, int id, int lowLimit, int hiLimit){

    int returnAux = -1;

    if(id >= lowLimit && id <= hiLimit){

        pProduct->id = id;
        returnAux = 0;
    }

    return returnAux;
}


int product_setDescription(Product* pProduct, char* description, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(description, lowLimit, hiLimit)) {

        strcpy(pProduct->description,description);
        returnAux = 0;
    }

    return returnAux;
}


void product_setPrice(Product* pProduct, float price){

    pProduct->price = price;
}


void product_setStock(Product* pProduct, int stock){

    pProduct->stock = stock;
}


void product_setStatus(Product* pProduct, int status){

    pProduct->status = status;
}


int product_getId(Product* pProduct){

    return pProduct->id;
}


char* product_getDescription(Product* pProduct){

    return pProduct->description;
}


float product_getPrice(Product* pProduct){

    return pProduct->price;
}


int product_getStock(Product* pProduct){

    return pProduct->stock;
}


int product_getStatus(Product* pProduct){

    return pProduct->status;
}


int product_compareByDescription(void* pProductA,void* pProductB){

    if(strcmp(((Product*)pProductA)->description,((Product*)pProductB)->description) > 0){

        return 1;
    }
    if(strcmp(((Product*)pProductA)->description,((Product*)pProductB)->description) < 0){

        return -1;
    }
    return 0;
}


int product_compareByPrice(void* pProductA,void* pProductB){

    if(((Product*)pProductA)->price > ((Product*)pProductB)->price){

        return 1;
    }
    if(((Product*)pProductA)->price < ((Product*)pProductB)->price){

        return -1;
    }
    return 0;
}


void product_print(Product* pProduct){

    printf("| Id: %4d | Descripcion: %15s | Precio: %10.2f | Stock: %6d |\r\n"\
        ,pProduct->id,pProduct->description,pProduct->price,pProduct->stock);
}


void product_printAll(Product* pProduct,ArrayList* productsList){

    int i;
    for (i=0; i<al_len(productsList); i++) {
        pProduct = al_get(productsList, i);
        product_print(pProduct);
    }
}


void product_delete(Product* pProduct){

    pProduct->status = PRODUCT_INACTIVE;
}

