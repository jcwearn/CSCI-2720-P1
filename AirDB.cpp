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

  int list_length() {
    int length = 0;
    new_node = head;
    
    while(new_node) {
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

  void traverse_list_p(int flightNo) {
    new_node = head;    
    while(new_node) {
      if(flightNo == new_node->data) {
	new_node->new_node_p = new_node->head_p;
	while(new_node->new_node_p) {
	  cout << new_node->new_node_p->lastName << endl;
	  new_node->new_node_p = new_node->new_node_p->next;
	}//while	
	break;
      }//if          
      new_node = new_node->next;
    }//while
  }//traverse_list_p()
  
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

      //checks if node needs to be inserted
      if(count < list_length()) {
	//check if node needs to become head
	if(count == 0){
	  new_node = new Node();
	  new_node->data = flightNo;
	  new_node->next = head;
	  head = new_node;
	}//if
	//does a normal insert
	else{
	  new_node = new Node();
	  new_node->data = flightNo;
	  new_node->next = insert->next;
	  insert->next = new_node;
	}//else
      }//if
      //checks if node needs to be appended
      else {
       	new_node = new Node();
	new_node->data = flightNo;
	temp->next = new_node;
	temp = new_node;
      }//else

    }//if
    //case if node is first node
    else {
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
    
    //check if node to be deleted is head
    if(count == 0) {
      head = new_node->next;
    }//if
    else
      insert->next = new_node->next;
  }//deleteFlight()

  /*
   * Add a passenger to a flight
   *
   */
  void addPassenger(int flightNo, string lastName, string firstName, int seatNo) {
    new_node = head;    
    while(new_node) {
      if(flightNo == new_node->data) {
	
	//case if node is not the first node
	if(!new_node->first_node_p){
          int length;  
	  int count;
	  length, count = 0;
	  
	  new_node->new_node_p = new_node->head_p;
	  while(new_node->new_node_p) {
	    if(new_node->new_node_p->lastName < lastName) {
	      new_node->insert_p = new_node->new_node_p;
	      count++;
	    }//if
	    else
	      length++;
	    new_node->new_node_p = new_node->new_node_p->next;
	  }//while 
	  
	  //checks if node needs to be inserted
	  if(count < length) {
	    //check if node needs to become head
	    if(count == 0){
	      new_node->new_node_p = new Node::Node_p;
	      new_node->new_node_p->lastName = lastName;
	      new_node->new_node_p->firstName = firstName;
	      new_node->new_node_p->seatNo = seatNo;
	      new_node->new_node_p->next = new_node->head_p;
	      new_node->head_p = new_node->new_node_p;
	    }//if
	    //does a normal insert
	    else{
	      new_node->new_node_p = new Node::Node_p;
	      new_node->new_node_p->lastName = lastName;
	      new_node->new_node_p->firstName = firstName;
	      new_node->new_node_p->seatNo = seatNo;
	      new_node->new_node_p->next = new_node->insert_p->next;
	      new_node->insert_p->next = new_node->new_node_p;
	    }//else
	  }//if
	  //checks if node needs to be appended
	  else {
	    new_node->new_node_p = new Node::Node_p;
	    new_node->new_node_p->lastName = lastName;
	    new_node->new_node_p->firstName = firstName;
	    new_node->new_node_p->seatNo = seatNo;
	    new_node->temp_p->next = new_node->new_node_p;
	    new_node->temp_p = new_node->new_node_p;
	  }//else
	
	}//if 
	//case if node is first node
	else {
	  new_node->head_p->lastName = lastName;
	  new_node->head_p->firstName = firstName;
	  new_node->head_p->seatNo = seatNo;
	  new_node->first_node_p = false;
	}//else
	
	
      }//if

      new_node = new_node->next;
    }//while
  }

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

  db->deleteFlight(1);

  cout << "Traverse Nodes:" << endl;
  db->traverse_list();

  cout << "Traverse Passengers:" << endl;
  db->addPassenger(2, "bar", "bar", 12);
  db->addPassenger(2, "jar", "tar", 13);
  db->traverse_list_p(2);
  
}
