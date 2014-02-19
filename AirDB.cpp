#include <iostream>
using namespace std;

typedef struct node {
  int data;
  node *next;
};

int main(void) {
  int input;
  node *head = NULL;  //empty linked list
  cout << "Enter some data";
  cin >> input;

  node *temp;
  temp = new node;

  temp->data = input;
  temp->next = head;
  head = temp;
  
  cout << head->data;
}


