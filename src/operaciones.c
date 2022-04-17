#include <stdio.h>
#include <stdlib.h>
#include "input.h"

//VALIDACIONES DE LOS CASE
int cargaKm=-1;
int cargaPrecioVuelosLa=-1;
int cargaPrecioVuelosAe=-1;
int operacionesRealizadasLa=-1;
int operacionesRealizadasAe=-1;

void CambiarFlags(){
	cargaKm=0;
	cargaPrecioVuelosLa=0;
	cargaPrecioVuelosAe=0;
	operacionesRealizadasLa=0;
	operacionesRealizadasAe=0;
}

void cargarKm(int* km){

	int retorno;
	retorno =getNumero(km, "Ingrese los km del vuelo ","Datos invalidos\n", 1, 10000000, 2);
	if(retorno==0){
		printf("\nDatos guardados correctamente\n ");
		cargaKm=0;
	}
	else{
		printf("Error, ingrese los datos nuevamente");
	}
}

void cargarPreciosVuelos(float* precioVueloAe, float* precioVueloLa){
	int retorno1;
	int retorno2;

	if(cargaKm==-1){
		printf("Debe cargar los kilometros primero\n");
	}

	if(cargaKm==0){
		retorno1 =getFloat(precioVueloAe, "Ingrese el precio del vuelo por Aerolineas ","Datos invalidos\n", 1,10000000, 2);
			if(retorno1==0){
				printf("\nDatos precio Aerolineas guardado correctamente\n");
				cargaPrecioVuelosAe=0;
			}
			else{
					printf("Error");
				}

		retorno2 =getFloat(precioVueloLa, "Ingrese el precio del vuelo por Latam ","Datos invalidos\n", 1, 10000000, 2);
			if(retorno2==0){
				printf("\nDatos precio Latam guardado correctamente\n");
				cargaPrecioVuelosLa=0;
			}
			else{
					printf("Error, ingrese los datos nuevamente");
				}
	}
}

int calcularCostosVuelosAe(int* km, float* precioVueloAe, float* precioTddAe, float* precioTdcAe, float* precioBitAe, float* precioUniAe){
	float precioDescuento;
	float precioConRecargo;
	float precioBitcoin;
	float precioUnitario;
	int cantKm = *km;
	float precioAe = *precioVueloAe;
	float bitcoin = 4606954.55;

	if(cargaKm==0 && cargaPrecioVuelosAe==0){

		precioDescuento= precioAe - (precioAe * 0.1);
		*precioTddAe= precioDescuento;

		precioConRecargo = precioAe + (precioAe * 0.2);
		*precioTdcAe = precioConRecargo;

		precioBitcoin =  (precioAe *100) / bitcoin;
		*precioBitAe = precioBitcoin;

		precioUnitario = precioAe / cantKm;
		*precioUniAe = precioUnitario;
		operacionesRealizadasAe=0;
	}

	else{
		printf("Debe realizar los pasos anteriores a esta opcion\n");
	}
	return operacionesRealizadasAe;
}

int calcularCostosVuelosLa(int* km, float*precioVueloLa, float*precioTddLa, float*precioTdcLa, float*precioBitLa, float*precioUniLa){
	float precioDescuento;
	float precioConRecargo;
	float precioBitcoin;
	float precioUnitario;
	int cantKm = *km;
	float precioLa = *precioVueloLa;
	float bitcoin = 4606954.55;
	if(cargaKm==0 && cargaPrecioVuelosAe==0 && cargaPrecioVuelosLa==0){

		precioDescuento= precioLa - (precioLa * 0.1);
		*precioTddLa= precioDescuento;

		precioConRecargo = precioLa + (precioLa * 0.2);
		*precioTdcLa = precioConRecargo;

		precioBitcoin = (precioLa *100) / bitcoin;
		*precioBitLa = precioBitcoin;

		precioUnitario = precioLa / cantKm;
		*precioUniLa = precioUnitario;
		operacionesRealizadasLa=0;
	}
	else{
		printf("Debe realizar los pasos anteriores a esta opcion\n");
	}

	return operacionesRealizadasLa;
}


void calcularDiferenciaPrecios(float precioAe, float precioLa, float* diferencia){
	float resta;

	if(precioAe >= precioLa){
		resta = precioAe - precioLa;
		*diferencia = resta;
	}
	else{
		resta = precioLa - precioAe;
				*diferencia = resta;
	}
}

void imprimirDatosAe(float precioVueloAe, float precioTddAe, float precioTdcAe, float precioBitAe, float precioUniAe){
	if(operacionesRealizadasAe==0){
			printf("\n\nPrecio Aerolineas: $%.2f",precioVueloAe);
			printf("\nPrecio con tarjeta de debito : $%.2f", precioTddAe);
			printf("\nPrecio con tarjeta de credito : $%.2f", precioTdcAe);
			printf("\nPrecio pagando con bitcoin : $%.2f", precioBitAe);
			printf("\nMostrar precio unitario : $%.2f",precioUniAe);
	}else{
		printf("\nDebe cargar los datos previamente");
	}
}

void imprimirDatosLa(float precioVueloLa, float precioTddLa, float precioTdcLa, float precioBitLa, float precioUniLa){
	if(operacionesRealizadasLa==0){
			printf("\n\nPrecio Latam: $%.2f", precioVueloLa);
			printf("\nPrecio con tarjeta de debito : $%.2f", precioTddLa);
			printf("\nPrecio con tarjeta de credito : $%.2f", precioTdcLa);
			printf("\nPrecio pagando con bitcoin : $%.2f", precioBitLa);
			printf("\nMostrar precio unitario : $%.2f", precioUniLa);
	}else{
		printf("\nDebe cargar los datos previamente");
	}
}

void imprimirDiferencia(float diferencia){
	if(operacionesRealizadasAe==0 && operacionesRealizadasLa==0){
		printf ("\nLa diferencia de precio es: $%.2f ", diferencia);
		}else{
			printf("\nDebe cargar los datos previamente");
		}
}

void cargaForzada(){
	CambiarFlags();
}
