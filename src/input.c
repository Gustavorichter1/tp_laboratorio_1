#include <stdio.h>
#include <stdlib.h>

int getNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;

	if (pNumero != NULL && mensaje != NULL && mensajeError!= NULL && minimo<=maximo && reintentos>= 0) {
		do{
			fflush(stdin);
			printf("%s", mensaje);
			scanf("%d",&bufferInt);

			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pNumero = bufferInt;
				retorno = 0;
				break;
			}
			else {
				printf("%s", mensajeError);
				reintentos--;
			 }
		 }while(reintentos >= 0);
	}
	return retorno;
}

int getFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = -1;

	if (pNumero != NULL && mensaje != NULL && mensajeError!= NULL && minimo<=maximo && reintentos>= 0) {
		do{
			fflush(stdin);
			printf("%s", mensaje);
			scanf("%f",&bufferFloat);

			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pNumero = bufferFloat;
				retorno = 0;
				break;
			}
			else {
				printf("%s", mensajeError);
				reintentos--;
			 }
		 }while(reintentos >= 0);
	}
	return retorno;
}
