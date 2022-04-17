#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

void menu() {
	int km;
		float precioVueloLa;
		float precioTddLa;
		float precioTdcLa;
		float precioBitLa;
		float precioUniLa;

		float precioVueloAe;
		float precioTddAe;
		float precioTdcAe;
		float precioBitAe;
		float precioUniAe;

		float diferencia;

	int retorno;
	int opcion;
	int operacionesRealizadasAe=-1;
	int operacionesRealizadasLa=-1;

	do {
		retorno =getNumero(&opcion, "\nSeleccione una opcion:\n1-IngresarKm\n2-Ingresar Precios de vuelos\n3-Calcular costos\n4-InformarResultados\n5-Carga forzada de datos\n6-Salir ","Opcion invalida\n", 1, 5, 2);

		if (!retorno) {
			switch (opcion) {

				case 1:
						cargarKm(&km);
						break;

				case 2:
						cargarPreciosVuelos(&precioVueloAe, &precioVueloLa);
						break;

				case 3:
						operacionesRealizadasAe = calcularCostosVuelosAe(&km, &precioVueloAe, &precioTddAe, &precioTdcAe, &precioBitAe, &precioUniAe);
						operacionesRealizadasLa = calcularCostosVuelosLa(&km, &precioVueloLa, &precioTddLa, &precioTdcLa, &precioBitLa, &precioUniLa);
						calcularDiferenciaPrecios(precioVueloAe, precioVueloLa, &diferencia);
						if(operacionesRealizadasAe==0 && operacionesRealizadasLa==0){
							printf("\nOperaciones Realizadas correctamente");
						}else{
							printf("\nOperaciones  no Realizadas");
						}
						break;

				case 4:
						if(operacionesRealizadasAe==0 && operacionesRealizadasLa==0){
							printf("\nKm ingresados: %d ",km);
							imprimirDatosAe(precioVueloAe, precioTddAe, precioTdcAe, precioBitAe, precioUniAe);
							imprimirDatosLa(precioVueloLa, precioTddLa, precioTdcLa, precioBitLa, precioUniLa);
							imprimirDiferencia(diferencia);
						}else{
							printf("\nDebe realizar los pasos posteriores");
						}
						break;

				case 5:
						km=7090;
						precioVueloAe=162965;
						precioVueloLa =159339;
						cargaForzada();
						calcularCostosVuelosAe(&km, &precioVueloAe, &precioTddAe, &precioTdcAe, &precioBitAe, &precioUniAe);
						calcularCostosVuelosLa(&km, &precioVueloLa, &precioTddLa, &precioTdcLa, &precioBitLa, &precioUniLa);
						calcularDiferenciaPrecios(precioVueloAe, precioVueloLa, &diferencia);

						printf("\nKm ingresados: %d ",km);
						imprimirDatosAe(precioVueloAe, precioTddAe, precioTdcAe, precioBitAe, precioUniAe);
						imprimirDatosLa(precioVueloLa, precioTddLa, precioTdcLa, precioBitLa, precioUniLa);
						imprimirDiferencia(diferencia);

						break;
			}
		}

	} while (opcion != 6);
	printf("\nHasta luego");
}


