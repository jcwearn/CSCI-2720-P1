#include <iostream>
using namespace std;

class AirDB {
protected:
  struct Node {
    int data;
    Node * next;
  };

  Node * new_node;
  Node * temp;
  Node * head;

  // new_node = new Node;
  //temp = new_node;
  //head = new_node;
  
public:
  // void set_node_data(int, struct Node);
  //int get_node_data(struct Node);
  void addFlight(int);
  void deleteFlight(int);
  void addPassenger(int, string, string, int);
  void removePassenger(int, string, string, int);
  void showPassenger(int, string, string);
  void showAllFlights();
  void showAllPassengers(int);
  void showAllFlightsAndPassengers();
};



//void AirDB::set_node_data(int value, struct Node n) {
  
//}

//int AirDB::get_node_data(Node n) {
  
//}


/*
 * Add a new flight to the list of flights
 *
 */
void AirDB::addFlight(int flightNo) {
  new_node = new Node;
  temp = new_node;
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
