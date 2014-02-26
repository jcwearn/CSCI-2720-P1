#include <iostream>
using namespace std;

class AirDB {
protected:
  AirDB * next;
  int data;
public:
  void addFlight(int);
  void deleteFlight(int);
  void addPassenger(int, string, string, int);
  void removePassenger(int, string, string, int);
  void showPassenger(int, string, string);
  void showAllFlights();
  void showAllPassengers(int);
  void showAllFlightsAndPassengers();
};

/*
 * Add a new flight to the list of flights
 *
 */
void AirDB::addFlight(int flightNo) {
  //int *temp;
  //temp = new node;
    
  //temp->data = flightNo;
  //temp->next = head;
  
  //head = temp;  
}

/*
 * Delete a list from the list of flights
 *
 */
void AirDB::deleteFlight(int flightNo) {
}

/*
 * Add a passenger to a flight
 *
 */
void AirDB::addPassenger(int flightNo, string lastName, string firstName, int seatNo) {
}

/*
 * remove a passenger from a flight
 *
 */
void AirDB::removePassenger(int flightNo, string lastName, string firstName, int seatNo) {
}

/*
 * Print out the passenger information including seat number.
 *
 */
void AirDB::showPassenger(int flightNo, string lastName, string firstName) {
}

/*
 * Print out all the flight numbers
 *
 */
void AirDB::showAllFlights() {
}

/*
 * Print out all the passengers in a flight
 *
 */
void AirDB::showAllPassengers(int flightNo) {
}

/*
 * Print out all flight numbers and all passengers in each flight
 *
 */
void AirDB::showAllFlightsAndPassengers() {
}

int main(void) {



  
}
