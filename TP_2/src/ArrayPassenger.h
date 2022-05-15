#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include "Passenger.h"

int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int sortPassengers(Passenger* list, int len, int order);
int printPassenger(Passenger* list, int length);

float obtenerTotal(Passenger* list, int len);
int longitudTotal(Passenger* list, int len);
int canPassengerSuperiorAlPromedio(Passenger* list, int len, float promedio);


#endif /* ARRAYPASSENGER_H_ */
