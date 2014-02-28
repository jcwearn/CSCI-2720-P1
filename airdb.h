#include <iostream>
using namespace std;

class AirDB {
protected:

  //Node class to manage linked list of flights
  class Node {
  public:
    //struct Node_p to handle linked list of passengers for each flight
    struct Node_p {
      string lastName;
      string firstName;
      int seatNo;
      Node_p * next;
    }; //struct Passenger

    Node_p * new_node_p;
    Node_p * insert_p;
    Node_p * temp_p;
    Node_p * head_p;
    bool first_node_p;
    //public:
    Node() {
      new_node_p = new Node_p;
      insert_p = new_node_p;
      temp_p = new_node_p;
      head_p = new_node_p;
      first_node_p = true;
    }
    int data;
    Node * next;
  };

  Node * new_node;
  Node * insert;
  Node * temp;
  Node * head;
  bool first_node;  
  
public:
  AirDB(){
    new_node = new Node();
    insert = new_node;
    temp = new_node;
    head = new_node;
    first_node = true;
  }//AirDB constructor
  ~AirDB() {
  }//AirDB destuctor

  int list_length();
  
  /*
   * Add a new flight to the list of flights
   *
   */
  void addFlight(int);

  /*
   * Delete a flight from the list of flights
   *
   */
  void deleteFlight(int);

  /*
   * Add a passenger to a flight
   *
   */
  void addPassenger(int, string, string, int);

  /*
   * remove a passenger from a flight
   *
   */
  void removePassenger(int, string, string, int);

  /*
   * Print out the passenger information including seat number.
   *
   */
  void showPassenger(int, string, string);

  /*
   * Print out all the flight numbers
   *
   */
  void showAllFlights();

  /*
   * Print out all the passengers in a flight
   *
   */
  void showAllPassengers(int);

  /*
   * Print out all flight numbers and all passengers in each flight
   *
   */
  void showAllFlightsAndPassengers();
};
