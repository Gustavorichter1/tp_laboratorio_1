
#ifndef OPERACIONES_H_
#define OPERACIONES_H_
/**
 * \brief
 *
 * \param km
 */
void cargarKm(int* km);
/**
 * \brief
 * Funcion para que el usuario cargue la cantidad de kms.
 * \param precioVueloAe
 * \param precioVueloLa
 */
void cargarPreciosVuelos(float* precioVueloAe, float* precioVueloLa);
/**
 * \brief
 * funcion para que el usuario cargue primero los precios de Aerolineas, y luego los de Latam
 * \param km
 * \param precioAe
 * \param precioTddAe
 * \param precioTdcAe
 * \param precioBitAe
 * \param precioUniAe
 * \return
 */
int calcularCostosVuelosAe(int* km, float* precioAe, float* precioTddAe, float* precioTdcAe, float* precioBitAe, float* precioUniAe);
/// \brief
/// Calcula el interes, el descuento, en bitcoin, y el precio unitario de Aerolineas
/// \param km
/// \param precioLa
/// \param precioTddLa
/// \param precioTdcLa
/// \param precioBitLa
/// \param precioUniLa
/// \return
int calcularCostosVuelosLa(int* km, float* precioLa, float* precioTddLa, float* precioTdcLa, float* precioBitLa, float* precioUniLa);
/// \brief
/// Calcula el interes, el descuento, en bitcoin, y el precio unitario de Latam
/// \param precioAe
/// \param precioLa
/// \param diferencia
void calcularDiferenciaPrecios(float precioAe, float precioLa, float* diferencia);
/// \brief
/// funcion que resta ambos costos para obtener la diferencia de dinero entre los vuelos
/// \param precioVueloAe
/// \param precioTddAe
/// \param precioTdcAe
/// \param precioBitAe
/// \param precioUniAe
void imprimirDatosAe(float precioVueloAe, float precioTddAe, float precioTdcAe, float precioBitAe, float precioUniAe);
void imprimirDatosLa(float precioVueloLa, float precioTddLa, float precioTdcLa, float precioBitLa, float precioUniLa);
void imprimirDiferencia(float diferencia);
/// \brief
/// estas tres funciones imprimen los resultados
void cargaForzada();
/// \brief
/// funcion para la carga forzada de datos, en la cual utilizo CambiarFlags();
void CambiarFlags();
///
/// funcion para asignar todos a todos los valores 0 para la carga forzada de datos
#endif /* OPERACIONES_H_*/
