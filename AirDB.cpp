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
  
public:
  AirDB(){
    new_node = new Node;
    temp = new_node;
    head = new_node;
  }
  ~AirDB() {
  }

  
  int get_temp_data() {
    return temp->data;
  }

  /*
   * Add a new flight to the list of flights
   *
   */
  void addFlight(int flightNo) {
    new_node = new Node;
    new_node->data = flightNo;
    temp->next = new_node;
    temp = new_node;
  }

  /*
   * Delete a flight from the list of flights
   *
   */
  void deleteFlight(int flightNo);

  /*
   * Add a passenger to a flight
   *
   */
  void addPassenger(int flightNo, string lastName, string firstName, int seatNo);

  /*
   * remove a passenger from a flight
   *
   */
  void removePassenger(int flightNo, string lastName, string firstName, int seatNo);

  /*
   * Print out the passenger information including seat number.
   *
   */
  void showPassenger(int flightNo, string lastName, string firstName);

  /*
   * Print out all the flight numbers
   *
   */
  void showAllFlights();

  /*
   * Print out all the passengers in a flight
   *
   */
  void showAllPassengers(int flightNo);

  /*
   * Print out all flight numbers and all passengers in each flight
   *
   */
  void showAllFlightsAndPassengers();
};


int main(void) {
  AirDB * db = new AirDB();
  db->addFlight(1);
  cout << db->get_temp_data() << endl;
  db->addFlight(2);
  cout << db->get_temp_data() << endl;
}
