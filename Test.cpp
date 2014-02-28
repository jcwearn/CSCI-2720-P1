#include <iostream>
#include <cstdlib>
#include "airdb.h"

/*
   Test class.
   main() instantiates a pointer to an AirDB object.
   Tests and demonstrates functionality of the 10
   required methods for the AirDB project.
*/
int main() {
  AirDB* db = new AirDB();
  
  std::cout << "~~Adding flight 101 to list of flights by calling addFlight(101)" << std::endl;
  db->addFlight(101);

  std::cout << "~~Listing all flights with showAllFlights()" << std::endl;
  db->showAllFlights();

  std::cout << "~~Adding John Doe to flight 101 by calling addPassenger(101, \"Doe\", \"John\", 4)" << std::endl;
  db->addPassenger(101, "Doe", "John", 4);

  std::cout << "~~Listing all passengers on flight 101 with showAllPassengers(101)" << std::endl;
  db->showAllPassengers(101);

  std::cout << "------------------------" << std::endl;

  std::cout << "~~Adding flight 99 to list of flights by calling addFlight(99)" << std::endl;
  db->addFlight(99);
  std::cout << "~~Listing all flights with showAllFlights()" << std::endl;
  db->showAllFlights();

  std::cout << "~~Adding flight 88 to list of flights by calling addFlight(88)" << std::endl;
  db->addFlight(88);
  std::cout << "~~Adding flight 7 to list of flights by calling addFlight(7)" << std::endl;
  db->addFlight(7);
  std::cout << "~~Listing all flights with showAllFlights()" << std::endl;
  db->showAllFlights();

  std::cout << "~~Adding flight 105 to list of flights by calling addFlight(105)" << std::endl;
  db->addFlight(105);
  std::cout << "~~Adding flight 4 to list of flights by calling addFlight(4)" << std::endl;
  db->addFlight(4);
  std::cout << "~~Listing all flights with showAllFlights()" << std::endl;
  db->showAllFlights();

  std::cout << "~~Adding passenger (Boo, Far, 4) to flight 101 by calling addFlight(101, \"Boo\", \"Far\", 4)" << std::endl;
  db->addPassenger(101, "Bar", "Foo", 4);
  std::cout << "~~Listing all passengers in flight 101 with showAllPassengers(101)" << std::endl;
  db->showAllPassengers(101);
  std::cout << "~~Adding passenger (Bar, Foo, 7) to list of flights by calling addFlight(\"Bar\", \"Foo\", 7)" << std::endl;
  db->addPassenger(101, "Bar", "Foo", 7);
  std::cout << "~~Listing all passengers in flight 101 with showAllPassengers(101)" << std::endl;
  db->showAllPassengers(101);
  db->removePassenger(101, "B", "Foo", 8);

  db->removePassenger(101, "Bar", "Foo", 8);
  db->removePassenger(101, "Bar", "Foo", 7);
  std::cout << "~~Listing all passengers in flight 101 with showAllPassengers(101)" << std::endl;
  db->showAllPassengers(101);

  db->deleteFlight(88);
  std::cout << "~~Listing all flights with showAllFlights()" << std::endl;
  db->showAllFlights();
  std::cout << "~~Adding passenger (Boo, Foo, 1) to flight 4 by calling addFlight(4, \"Boo\", \"Foo\", 1)" << std::endl;
  db->addPassenger(4, "Bar", "Foo", 1);
  std::cout << "~~Adding passenger (Barber, Foo, 2) to flight 4 by calling addFlight(4, \"Barber\", \"Foo\", 2)" << std::endl;
  db->addPassenger(4, "Barber", "Foo", 2);
  std::cout << "~~Adding passenger (Anderson, Far, 3) to flight 4 by calling addFlight(4, \"Anderson\", \"Foo\", 3)" << std::endl;
  db->addPassenger(4, "Anderson", "Foo", 3);
  std::cout << "~~Adding passenger (Zander, Foo, 4) to flight 4 by calling addFlight(4, \"Zander\", \"Foo\", 4)" << std::endl;
  db->addPassenger(4, "Zander", "Foo", 4);

  db->addPassenger(7, "Bar", "Foo", 1);
  db->addPassenger(7, "Anderson", "Foo", 2);
  db->addPassenger(7, "Aderhold", "Foo", 3);
  db->addPassenger(7, "Carter", "Foo", 4);
  std::cout << "~~Listing all flights and passengers with showAllFlightsAndPassengers()" << std::endl;
  db->showAllFlightsAndPassengers();

  db->showPassenger(4, "Bar", "Foo");

  //db->showNewPassengers(4, 3);
  //db->showFirstPassengers(4, 3);

}
