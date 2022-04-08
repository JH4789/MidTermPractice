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
void clist::copy(node* original, node * source) {
  if(source->next->data == 2 && source->next == original) {
      node* newnode = new node();
    newnode->data = source->data;
    rear->next = newnode;
    rear = rear->next;
    rear->next = current;
    return;
  }
  if(source->data != 2) {
  if(source == original) {
    node* newnode = new node();
    newnode->data = source->data;
    rear->next = newnode;
    rear = rear->next;
    rear->next = current;
    return;
  }
  else {
      
      node* newnode = new node();
      newnode->data = source->data;
    if(rear == NULL) {
      rear = newnode;
      current = rear;
    }
    else {
      rear->next = newnode;
      rear = rear->next;
    }
    }
}
  copy(original, source->next);
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
