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

  int list_length() {
    int length;
    new_node = head;
    while(new_node) {
      new_node = new_node->next;
      length++;
    }
    return length;
  }

  void traverse_list() {
    new_node = head;
    while(new_node) {
      cout << new_node->data << endl;
      new_node = new_node->next;
    }
  }
  
  int get_temp_data() {
    return temp->data;
  }

  /*
   * Add a new flight to the list of flights
   *
   */
  void addFlight(int flightNo) {
    if(list_length() > 1){
      new_node = new Node;
      new_node->data = flightNo;
      temp->next = new_node;
      temp = new_node;
    }
    else {
      head->data = flightNo;
    }
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
  db->addFlight(47);
  cout << db->get_temp_data() << endl;

  cout << db->list_length() << endl;

  cout << "Traverse Nodes:" << endl;
  db->traverse_list();
}
