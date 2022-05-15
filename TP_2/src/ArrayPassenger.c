#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Passenger.h"

#define OCUPADO 0
#define LIBRE 1

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initPassengers(Passenger *list, int len) {

	int retorno = -1;

	if (list != NULL) {
		if (len > 0) {
			for (int i=0; i<len; i++) {
				list[i].isEmpty = LIBRE;
			}
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief add in a existing list of passengers the values received as parameters
 * in the first empty position
 * \param list passenger*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param price float
 * \param typePassenger int
 * \param flycode[] char
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 free space] - (0) if Ok*/

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],
		float price, int typePassenger, char flycode[], int statusFlight) {
	int retorno = -1;

	Passenger auxiliar;

	if (list != NULL) {
		if (len > 0) {
			for (int i = 0; i < len;) {
				if (list[i].isEmpty == LIBRE) {
					auxiliar.id = id;
					strcpy(auxiliar.name, name);
					strcpy(auxiliar.lastName, lastName);
					auxiliar.price = price;
					strcpy(auxiliar.flycode, flycode);
					auxiliar.typePassenger = typePassenger;
					auxiliar.isEmpty = OCUPADO;
					auxiliar.statusFlight = statusFlight;

					list[i] = auxiliar;
					retorno = 0;
				} else {
					i++;
				}
			}
		}
	}
	return retorno;
}

/** \brief find a Passenger by Id en returns the index position in array.
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return Return passenger index position or (-1) if [Invalid length or
 NULL pointer received or passenger not found]
 *
 */
int findPassengerById(Passenger* list, int len, int id) {

	int retorno =-1;

	for(int i=0; i<=len;i++){
		if(list[i].id==id){
			retorno=i;
		}
	}
	return retorno;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 find a passenger] - (0) if Ok
 *
 */
int removePassenger(Passenger *list, int len, int id) {
	int retorno = -1;

		if(list != NULL)
		{
			if(len >= 0)
			{
				list[id].isEmpty = LIBRE;
				retorno = 0;
			}
		}
		return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order
 indicate UP or DOWN order
 *
 * \param list Passenger*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortPassengers(Passenger *list, int len, int order) {
	Passenger aux;
		int retorno = -1;

		if (list != NULL)
			{
					if (order == 1)
					{
						for (int i = 0; i < len; i++)
						{
							for(int j = i + 1; j <=len-1; j++)
							{
								if ((strcmp(list[i].lastName, list[j].lastName) > 0) ||( strcmp(list[i].lastName, list[j].lastName) == 0) && (list[i].typePassenger >= list[j].typePassenger))
								{
									aux = list[j];
									list[j] = list[i];
									list[i] = aux;
								}
							}
						}
					}
					else
					{
						for (int i = 0; i < len; i++)
						{
							for(int j = i + 1; j <= len - 1; j++)
							{
								if ((strcmp(list[i].lastName, list[j].lastName) < 0 )|| (strcmp(list[i].lastName, list[j].lastName) == 0) && (list[i].typePassenger > list[j].typePassenger))
								{
									aux = list[j];
									list[j] = list[i];
									list[i] = aux;
								}
							}
						}
					}
					retorno = 0;

			}

		return retorno;
}

/** \brief print the content of passengers array
 *
 * \param list Passenger*
 * \param length int
 * \return int
 *
 */
int printPassenger(Passenger *list, int length) {

	int retorno = -1;
	int i;

	if (list != NULL) {
		if (length >0) {
			//printf("\nID\tNombre\t\tApellido\tPrecio\tCodigoV\tTipoPasajero\tEstadoV\n");
			for (i = 0; i < length; i++) {
				if (list[i].isEmpty == OCUPADO) {
					retorno = 0;
					printf("%d\t%s\t%s\t%.2f\t%s\t%d\t%d\n", list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, list[i].typePassenger, list[i].statusFlight);
				}
			}

		}
	}

	return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order
 indicate UP or DOWN order
 *
 * \param list Passenger*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 Programación I – Laboratorio I
 UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 7
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortPassengersByCode(Passenger* list, int len, int order)
{
	Passenger aux;

	int retorno = -1;

	if (list != NULL)
		{
			if (len >= 0)
			{
				if (order == 1)
				{
					for (int i = 0; i < len; i++)
						for(int j = i + 1; j <= len - 1; j++)
						{
							if ((strcmp(list[i].flycode, list[j].flycode) > 0) || (strcmp(list[i].flycode, list[j].flycode) == 0) && (list[i].statusFlight > list[j].statusFlight))
							{
								aux = list[j];
								list[j] = list[i];
								list[i] = aux;
							}
						}
					}

				else
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; j < len - 1; j++)
						{
							if ((strcmp(list[i].flycode, list[j].flycode) < 0) || (strcmp(list[i].flycode, list[j].flycode) == 0) && (list[i].statusFlight > list[j].statusFlight))
							{
								aux = list[j];
								list[j] = list[i];
								list[i] = aux;
							}
						}
					}
				}
				retorno = 0;
			}
		}
	return retorno;
}

float obtenerTotal(Passenger* list, int len){

	float retorno=-1;

	if(list!=NULL){
		for(int i=0; i<len;i++){
			if(list[i].isEmpty!=LIBRE){
				retorno+=list[i].price;
			}
		}
	}
	return retorno;
}

int longitudTotal(Passenger* list, int len){
	int retorno=-1;

	if(list!=NULL){
		for(int i=0; i<len;i++){
			if(list[i].isEmpty!=LIBRE){
				retorno=i;
			}

		}
	}
	return retorno;
}

int canPassengerSuperiorAlPromedio(Passenger* list, int len, float promedio){
	int retorno=-1;

	if(list!=NULL){
		for(int i=0; i<len;i++){
			if(list[i].isEmpty!=LIBRE && list[i].price>promedio){
				retorno=i;
			}
		}
	}

	return retorno;
}


