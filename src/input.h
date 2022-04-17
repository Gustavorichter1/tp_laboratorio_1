#ifndef INPUT_H_
#define INPUT_H_
/// \brief
/// utilizo estas dos funciones para obtener int y float
/// \param pNumero
/// \param mensaje
/// \param mensajeError
/// \param minimo
/// \param maximo
/// \param reintentos
/// \return
int getNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


#endif /* INPUT_H_*/
