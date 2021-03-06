#include <iostream>
#include "airdb.h"
using namespace std;

int AirDB::list_length() {
  int length = 0;
  new_node = head;
    
  while(new_node) {
    new_node = new_node->next;
    length++;
  }//while
  
  return length;
}// list_length()

/*
 * Add a new flight to the list of flights
 *
 */
void AirDB::addFlight(int flightNo) {
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
void AirDB::deleteFlight(int flightNo) {
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
void AirDB::addPassenger(int flightNo, string lastName, string firstName, int seatNo) {
  int length;  
  int count;
  length, count = 0;

  new_node = head;    
  while(new_node) {
    if(flightNo == new_node->data) {
      
      //case if node is not the first node
      if(!new_node->first_node_p){

	//while loop through passenger list
	new_node->new_node_p = new_node->head_p;
	while(new_node->new_node_p) {

	  //checks if lastName in list is less than lastName param
	  if(new_node->new_node_p->lastName < lastName) {
	    new_node->insert_p = new_node->new_node_p;
	    count++;
	  }//if
	    
	  //checks if lastName in list is equal to lastName param
	  else if(new_node->new_node_p->lastName == lastName) {
	    //if it is equal, sort by first name
	    if(new_node->new_node_p->firstName < firstName) {
	      new_node->insert_p = new_node->new_node_p;
	      count++;
	    }//if
	  }//else if
	    
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
void AirDB::removePassenger(int flightNo, string lastName, string firstName, int seatNo) {
  int count = 0;
  
  new_node = head;
  while(new_node) {
    if(new_node->data == flightNo) {
      
      new_node->new_node_p = new_node->head_p;
      while(new_node->new_node_p) {
	if(new_node->new_node_p->lastName < lastName) {
	  new_node->insert_p = new_node->new_node_p;
	  count++;
	}//if
	else
	  break;
	new_node->new_node_p = new_node->new_node_p->next;
      }//while
      
      //check if node to be deleted is head
      if(count == 0) {
	new_node->head_p = new_node->new_node_p->next;
      }//if
      else
	new_node->insert_p->next = new_node->new_node_p->next;
      
    }//if
    new_node = new_node->next;
  }//while
}//removePassenger

/*
 * Print out the passenger information including seat number.
 *
 */
void AirDB::showPassenger(int flightNo, string lastName, string firstName) {
  int count;
  count = 0;
  
  new_node = head;    
  while(new_node) {
    if(flightNo == new_node->data) {
      
      //while loop through passenger list
      new_node->new_node_p = new_node->head_p;
      while(new_node->new_node_p) {
	if((new_node->new_node_p->lastName == lastName) && (new_node->new_node_p->firstName == firstName)) {
	  cout << new_node->new_node_p->lastName << ", " << new_node->new_node_p->firstName << " " << new_node->new_node_p->seatNo << endl;
	  break;
	}//if
	new_node->new_node_p = new_node->new_node_p->next;
      }//while 	  
    }//if

    new_node = new_node->next;
  }//while
}//showPassenger()

/*
 * Print out all the flight numbers
 *
 */
void AirDB::showAllFlights() {
  new_node = head;    
  while(new_node) {
    cout << new_node->data << endl;
    new_node = new_node->next;
  }//while
}//showAllFlights()

/*
 * Print out all the passengers in a flight
 *
 */
void AirDB::showAllPassengers(int flightNo) {
  new_node = head;    
  while(new_node) {
    if(flightNo == new_node->data) {
      new_node->new_node_p = new_node->head_p;
      while(new_node->new_node_p) {
	cout << new_node->new_node_p->lastName << ", " << new_node->new_node_p->firstName << " " << new_node->new_node_p->seatNo << endl;
	new_node->new_node_p = new_node->new_node_p->next;
      }//while	
      break;
    }//if          
    new_node = new_node->next;
  }//while
}//showAllPassengers()

/*
 * Print out all flight numbers and all passengers in each flight
 *
 */
void AirDB::showAllFlightsAndPassengers() {
  new_node = head;    
  while(new_node) {
    cout << "Flight Number: " << new_node->data << endl;       
    new_node->new_node_p = new_node->head_p;
    while(new_node->new_node_p) {
      if(!(new_node->new_node_p->lastName == ""))
	cout << "\t" << new_node->new_node_p->lastName << ", " << new_node->new_node_p->firstName << " " << new_node->new_node_p->seatNo << endl;
      new_node->new_node_p = new_node->new_node_p->next;
    }//while
    new_node = new_node->next;
  }//while          
}//showAllFlightsAndPassengers()
