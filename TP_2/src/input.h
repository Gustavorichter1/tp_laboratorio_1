#ifndef INPUT_H_
#define INPUT_H_

int myGets(char *cadena, int longitud);
int getInt(int *pResultado);
int esNumerica(char *cadena);
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);
int getFloat(float *pResultado);

int isValidTexto(char *stringRecibido);
int utn_getTexto(char *pCadena, char *mensaje, char *mensajeError);

#endif /* INPUT_H_ */
