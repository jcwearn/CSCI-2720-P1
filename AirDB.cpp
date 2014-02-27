#include <iostream>
using namespace std;

class AirDB {
protected:
  struct Node {
    int data;
    Node * next;
  }; //struct Node

  Node * new_node;
  Node * insert;
  Node * temp;
  Node * head;
  bool first_node;
  
public:
  AirDB(){
    new_node = new Node;
    insert = new_node;
    temp = new_node;
    head = new_node;
    first_node = true;
  }//AirDB constructor
  ~AirDB() {
  }//AirDB destuctor

  int list_length() {
    int length = 0;
    new_node = head;
    
    while(new_node != NULL) {
      new_node = new_node->next;
      length++;
    }//while
    
    return length;
  }// list_length()

  void traverse_list() {
    new_node = head;
    
    while(new_node) {
      cout << new_node->data << endl;
      new_node = new_node->next;
    }//while
  }//traverse_list()
  
  int get_temp_data() {
    return temp->data;
  }//get_temp_data()

  /*
   * Add a new flight to the list of flights
   *
   */
  void addFlight(int flightNo) {
    //case if node is not the first node
    if(!first_node){
            
      int count;
      count = 0;

      new_node = head;
      while(new_node) {
	if(new_node->data < flightNo) {
	  insert = new_node;
	  count++;
	}//if
	else
	  break;
	new_node = new_node->next;
      }//while
      
      //cout << "count:" << count << endl;
      //cout << "list length: " << list_length() << endl;
      //cout << "flight no: " << flightNo << endl;

      //checks if node needs to be inserted
      if(count < list_length()) {
	//check if node needs to become head
	if(count == 0){
	  new_node = new Node;
	  new_node->data = flightNo;
	  new_node->next = head;
	  head = new_node;
	}//if
	//does a normal insert
	else{
	  new_node = new Node;
	  new_node->data = flightNo;
	  new_node->next = insert->next;
	  insert->next = new_node;
	}//else
      }//if
      //checks if node needs to be appended
      else {
       	new_node = new Node;
	new_node->data = flightNo;
	temp->next = new_node;
	temp = new_node;
      }//else

    }//if
    //case if node is first node
    else {
      cout << "First Node\n\n";
      head->data = flightNo;
      first_node = false;
    }//else
  }//addFlight()

  /*
   * Delete a flight from the list of flights
   *
   */
  void deleteFlight(int flightNo) {
    int count = 0;

    new_node = head;
    while(new_node) {
      if(new_node->data < flightNo) {
	insert = new_node;
	count++;
      }//if
      else
	break;
      new_node = new_node->next;
    }//while

    insert->next = new_node->next;
  }//deleteFlight()

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
  db->addFlight(2);
  db->addFlight(1);
  db->addFlight(4);
  db->addFlight(3);
  
  cout << "Traverse Nodes:" << endl;
  db->traverse_list();

  db->deleteFlight(3);

  cout << "Traverse Nodes:" << endl;
  db->traverse_list();
}
