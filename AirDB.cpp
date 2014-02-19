#include <iostream>
using namespace std;

 struct node {
  int data;
  node *next;
};

node * head = NULL;

/*
 * Add a new flight to the list of flights
 *
 */
void addFlight(int flightNo) {
  int *temp;
  tmep = new node;

  temp->data = flightNo;
  temp->next = head;

  head = temp;  
}

/*
 * Delete a list from the list of flights
 *
 */
void deleteFlight(int flightNo) {
}

/*
 * Add a passenger to a flight
 *
 */
void addPassenger(int flightNo, string lastName, string firstName, int seatNo) {
}

/*
 * remove a passenger from a flight
 *
 */
void removePassenger(int flightNo, string lastName, string firstName, int seatNo) {
}

/*
 * Print out the passenger information including seat number.
 *
 */
void showPassenger(int flightNo, string lastName, string firstName) {
}

/*
 * Print out all the flight numbers
 *
 */
void showAllFlights() {
}

/*
 * Print out all the passengers in a flight
 *
 */
void showAllPassengers(int flightNo) {
}

/*
 * Print out all flight numbers and all passengers in each flight
 *
 */
void showAllFlightsAndPassengers() {
}

int main(void) {
  addFlight();
  
}
