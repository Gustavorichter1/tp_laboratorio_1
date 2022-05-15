#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;


#endif /* PASSENGER_H_ */
