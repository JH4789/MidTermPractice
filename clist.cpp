#include "clist.h"

clist::clist() {
  rear = NULL;
}

clist::~clist() {
  node* temp = rear;
  rear = rear->next;
  temp->next = NULL;
  while (rear->next != NULL) {
    temp = rear;
    rear = rear->next;
    delete temp;
  }
  rear->next = NULL;
  delete rear;
}

void clist::build() {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  rear = current;
  node* previous = current;
  int additionalValues = (rand()%5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  current->next = rear;
}
void clist::copy(node* copied) {
  if(current->data != 2) {
    if(current->next == NULL) {
        current->data = copied->data;
        current->next = NULL;
         
    }
    else {
      current->data = copied->data;
    }
  }

  copy(copied->next);
}
void clist::copy(clist entry) {
  copy(rear->next, entry.returnRear());
}
node* clist::returnRear() {
  return rear;
}
void clist::display() {
  node* current = rear->next;
  while (current != rear) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << rear->data << " ";
  cout << endl;
}
