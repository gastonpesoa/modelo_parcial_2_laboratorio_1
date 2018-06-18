/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __Product
#define __Product
struct
{
    int id;
    char description[51];
    float price;
    int stock;
    int status;

}typedef Product;
#endif // __Product


/** \brief Hardcode of data testing of products in a products list recived as parameter.
 * \param productsList (ArrayList*) Pointer to the list of products to be hardcode
 * \return (void)
 */
void productsList_testing(ArrayList* productsList);


/** \brief Allocate and set a new product with the values recived as parameters
 * \param id (int)
 * \param description (char*)
 * \param price (float)
 * \param stock (int)
 * \return Product* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new product) if ok
 */
Product* product_newTest(int id, char* description,float price,int stock);


/** \brief Allocate a new product.
 * \param void
 * \return Product* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new product) if ok
 */
Product* product_new(void);

/** \brief Requests, validates and set all the values ​​of a new product received as a parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param id (int) Id of the product to be created
 * \param lowLimitId (int) Lower id limit allowed
 * \param hiLimitId (int) Higher id limit allowed
 * \param lowLimitDesc (int) Lower description limit allowed
 * \param hiLimitDesc (int) Higher description limit allowed
 * \param lowLimitPrice (float) Lower price limit allowed
 * \param hiLimitPrice (float) Higher price limit allowed
 * \param lowLimitStock (int) Lower stock limit allowed
 * \param hiLimitStock (int) Higher stock limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_enter(Product* pProduct,int id,int lowLimitId,int hiLimitId,\
    int lowLimitDesc,int hiLimitDesc,\
    float lowLimitPrice,float hiLimitPrice,int lowLimitStock,int hiLimitStock);


/** \brief Request a description to the product, validate that it is only letters and capitalize it
 * \param input (char*) Pointer to the string of characters where the entered description will be stored
 * \return void
 */
void product_askDescription(char* input);


/** \brief Request a price to the product, validate that it is only floating numbers and between the assigned range
 * \param lowLimit (float) Lower limit allowed
 * \param hiLimit (float) Higher limit allowed
 * \return (float) Price of the product
 */
float product_askPrice(float lowLimit, float hiLimit);


/** \brief Request a stock to the product, validate that it is only integer numbers and between the assigned range
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return (int) Stock of the product
 */
int product_askStock(int lowLimit, int hiLimit);


/** \brief Set pProduct Product the id recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param id (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setId(Product* pProduct, int id, int lowLimit, int hiLimit);


/** \brief Set pProduct Product the id recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param description (char*) Pointer to the description recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setDescription(Product* pProduct, char* description, int lowLimit, int hiLimit);


/** \brief Set pProduct Product the price recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param price (float) Price recived
 * \return void
 */
void product_setPrice(Product* pProduct, float price);


/** \brief Set pProduct Product the stock recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param stock (int) Stock recived
 * \return void
 */
void product_setStock(Product* pProduct, int stock);


/** \brief Set pProduct Product the status recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param status (int) Status recived
 * \return (void)
 */
void product_setStatus(Product* pProduct, int status);


/** \brief  Get the id of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Id of the product
 */
int product_getId(Product* pProduct);


/** \brief  Get the description of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (char*) Description of the product
 */
char* product_getDescription(Product* pProduct);


/** \brief  Get the price of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (float) Price of the product
 */
float product_getPrice(Product* pProduct);


/** \brief  Get the stock of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Stock of the product
 */
int product_getStock(Product* pProduct);


/** \brief  Get the status of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Status of the product
 */
int product_getStatus(Product* pProduct);


/** \brief Compare products by description
 * \param pProductA (void*) Pointer to first product to compare
 * \param pProductB (void*) Pointer to second product to compare
 * \return int Return (1) if description of pProductA is major than description of pProductB
 *                  - (-1) description of pProductA is minor than description of pProductB
 *                  - (0) description of pProductA is equal than description of pProductB
 */
int product_compareByDescription(void* pProductA,void* pProductB);


/** \brief Compare products by price
 * \param pProductA (void*) Pointer to first product to compare
 * \param pProductB (void*) Pointer to second product to compare
 * \return int Return (1) if price of pProductA is major than price of pProductB
 *                  - (-1) price of pProductA is minor than price of pProductB
 *                  - (0) price of pProductA is equal than price of pProductB
 */
int product_compareByPrice(void* pProductA,void* pProductB);


/** \brief Shows the selected product by screen
 * \param pProduct (Product*) Pointer to the product to be displayed
 * \return void
 */
void product_print(Product* pProduct);


/** \brief Shows all the product in the list of products
 * \param pProduct (Product*) Pointer to the product
 * \param productsList (ArrayList*) Pointer to the list of products to be displayed
 * \return void
 */
void product_printAll(Product* pProduct,ArrayList* productsList);


/** \brief Low logic of the product received as parameter
 * \param pProduct (Product*) Pointer to the product to be deleted
 * \return void
 */
void product_delete(Product* pProduct);

