#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Passenger.h"
#include <string.h>


#define MAX_PASAJEROS 2000
#define MAX_TIPOPASAJEROS 2
#define MAX_STATUSVUELO 2

void menuModificacion(Passenger *listadoPassenger, int longitud) {
	int opcion;
	int retorno;
	int res;
	int idBuscado;
	int retornoBuscado;
	char nName[51];
	char nLastN[51];
	float nPrice;
	int nTypeP;
	char nFlycode[10];

	setbuf(stdout, NULL);
	do {
		retorno =
				utn_getInt(&opcion,
						"\nSeleccione una opcion:\n1-Modificar nombre\n2-Modificar apellido\n-3Modificar precio"
								"\n4-Modificar Tipo de Pasajero\n5-Modificar codigo de vuelo\n6-Salir",
						"Opcion Incorrecta", 1, 6, 3);

		if (!retorno) {
			switch (opcion) {

			case 1:
				printf("\nModificar el nombre");
				utn_getInt(&idBuscado, "\nIngrese el id del pasajero a buscar",
						"Error", 1, 2000, 3);
				retornoBuscado = findPassengerById(listadoPassenger, longitud,
						idBuscado);
				if (retornoBuscado != -1) {
					utn_getTexto(&nName, "\nIngrese el nuevo nombre","\nError");
					strcpy(listadoPassenger[retornoBuscado].name, nName);

				} else {
					printf("\nPasajero no encontrado");
				}

				break;

			case 2:
				printf("\nModificar el apellido");
				utn_getInt(&idBuscado, "\nIngrese el id del pasajero a buscar","Error", 1, 2000, 3);
				retornoBuscado = findPassengerById(listadoPassenger, longitud,
						idBuscado);
				if (retornoBuscado != -1) {
					utn_getTexto(&nLastN, "\nIngrese el nuevo apellido","\nError");
					strcpy(listadoPassenger[retornoBuscado].lastName, nLastN);

				} else {
					printf("\nPasajero no encontrado");
				}
				break;

			case 3:
				printf("\nModificar el el precio");
				utn_getInt(&idBuscado, "\nIngrese el id del pasajero a buscar",
						"Error", 1, 2000, 3);
				retornoBuscado = findPassengerById(listadoPassenger, longitud,
						idBuscado);
				if (retornoBuscado != -1) {
					utn_getFloat(&nPrice, "\nIngrese el precio nuevo ",
							"\nPrecio Incorrecto", 1, 9999999999);
					listadoPassenger[retornoBuscado].price = nPrice;

				} else {
					printf("\nPasajero no encontrado");
				}
				break;

			case 4:
				printf("\nModificar el tipo de pasajero");
				utn_getInt(&idBuscado, "\nIngrese el id del pasajero a buscar",
						"Error", 1, 2000, 3);
				retornoBuscado = findPassengerById(listadoPassenger, longitud,
						idBuscado);
				if (retornoBuscado != -1) {
					utn_getInt(&nTypeP,
							"\nIngrese Tipo:\n1-Primera Clase\n2-Clase Turista ",
							"Error. Ingrese una opción valida.\n", 1, 2, 3);
					listadoPassenger[retornoBuscado].typePassenger = nTypeP;

				} else {
					printf("\nPasajero no encontrado");
				}
				break;

			case 5:
				printf("\nModificar el codigo del vuelo");
				utn_getInt(&idBuscado, "\nIngrese el id del pasajero a buscar",
						"Error", 1, 2000, 3);
				retornoBuscado = findPassengerById(listadoPassenger, longitud,
						idBuscado);
				if (retornoBuscado != -1) {
					utn_getTexto(&nFlycode,
							"\nIngrese el nuevo codigo del vuelo", "\nError");
					strcpy(listadoPassenger[retornoBuscado].flycode, nFlycode);

				} else {
					printf("\nPasajero no encontrado");
				}
				break;

			} //fin switch
		} //fin if

		if (opcion != 6) {
			retorno =utn_getInt(&res,"\nDesea continuar en el menu de modificaciones Si(1) y No(0)","Opcion invalida", 0, 1, 3);
		}
	} while (opcion != 6 && retorno != -1 && res != 0);
}

void menu() {

	int opcion;
	int retorno;
	int vInitPassenger;
	int vAddPassenger;

	int id = 0;
	char name[51];
	char lastName[51];
	float price;
	char flycode[5];
	int typePassenger;
	int statusFlight;
	int orden;

	float totalRecaudo=0;
	float promedioRecaudo=0;
	int contSuperiorPromedio=0;
	int longitudSinEmptys;

	int retornoBuscado;
	int idBuscado;

	Passenger listadoPassenger[MAX_PASAJEROS];
	int longitud = 0;

	setbuf(stdout, NULL);
	vInitPassenger = initPassengers(listadoPassenger, MAX_PASAJEROS);

	if (vInitPassenger == 0) {

		do {
			retorno =
					utn_getInt(&opcion,
							"\nSeleccione una opcion:\n1-Altas\n2-Modificar\n3-Baja\n4-Informar\n5-Salir",
							"Opcion Incorrecta", 1, 6, 3);

			if (!retorno) {
				switch (opcion) {

				case 1:
					id++;
					longitud++;
					utn_getTexto(&name, "\ningres el nombre ","\nDatos incorrectos ");
					utn_getTexto(&lastName, "\nIngrese el apellido ","\nDatos incorrectos");
					utn_getFloat(&price, "\nIngrese el precio","\nPrecio Incorrecto", 1, 9999999999);
					utn_getInt(&typePassenger,"\nIngrese Tipo:\n1-Primera Clase\n2-Clase Turista ","Error. Ingrese una opción valida.\n", 1, 2, 3);
					utn_getTexto(&flycode, "\nIngrese codigo del vuelo","\nDatos incorrectos");
					utn_getInt(&statusFlight, "Estatus del vuelo \n1-Cargando\n2-Inactivo\n3-Demorado ","Error. Ingrese una opción valida.\n", 1, 3, 3);
					vAddPassenger = addPassenger(listadoPassenger, longitud, id,name, lastName, price, typePassenger, flycode,statusFlight);
					if (vAddPassenger == 0) {
						printf("\nPasajero creado correctamente");

					} else {
						printf("\nError, no se pudo crear el pasajero");
					}
					break;

				case 2:
					if(vAddPassenger==0){
						menuModificacion(listadoPassenger, longitud);
					}else{
						printf("\nDebe agregar pasajeros");
					}
					break;

				case 3:
					if(vAddPassenger==0){
						utn_getInt(&idBuscado,"\nIngrese el id del pasajero a buscar", "Error", 1,2000, 3);
						retornoBuscado = findPassengerById(listadoPassenger,longitud, idBuscado);

						if (retornoBuscado != -1) {

							removePassenger(listadoPassenger, longitud, retornoBuscado);
							printf("\nPasajero eliminado");

						} else {
							printf("\nPasajero no encontrado");
						}
					}else{
						printf("\nDebe agregar pasajeros");
					}
					break;

				case 4:
					if (vAddPassenger == 0 && vInitPassenger == 0) {
						//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero
						utn_getInt(&orden,"\nIngrese como desea ordenar \n1-Descendentemente\n2-Ascendentemente", "Error", 1,2, 3);
						sortPassengers(listadoPassenger, longitud, orden);
						printPassenger(listadoPassenger, MAX_PASAJEROS);
						//Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.


						totalRecaudo= obtenerTotal(listadoPassenger,longitud);
						if(totalRecaudo!=-1){
							printf("\nEl total recaudado es: %f", totalRecaudo);
							longitudSinEmptys= longitudTotal(listadoPassenger,longitud);
							if(longitudSinEmptys!=-1){
								promedioRecaudo= totalRecaudo/ longitudSinEmptys;
								printf("\nEl promedio de lo recaudado es: %f", promedioRecaudo);
							}else{
								printf("\nError al obtener la longitud de usarios dados de baja");
							}
							contSuperiorPromedio = canPassengerSuperiorAlPromedio(listadoPassenger,longitud,promedioRecaudo);
							if(contSuperiorPromedio!=-1){
								printf("\nLa cantidad de pasajeros que superaron el precio promedio es: %d", contSuperiorPromedio);
							}else{
								printf("\nNo hay pasajeros que superen el precio promedio");
							}

						}else{
							printf("\nError al obtener el total recaudado");
						}

						//Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
						utn_getInt(&orden,"\nIngrese como desea ordenar \n1-Descendentemente\n2-Ascendentemente", "Error", 1,2, 3);
						sortPassengersByCode(listadoPassenger, longitud, orden);
						printPassenger(listadoPassenger, MAX_PASAJEROS);

					}else{
						printf("\nDebe agregar pasajeros");
					}
					break;

				} //fin switch
			} //fin if

		} while (opcion != 5);
		printf("\nHasta luego");
	} else {
		printf("\nNo se puedo inicializar el vuelo, error");
	}

}

