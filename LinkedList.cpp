#include <iostream>
using namespace std;

struct node {
	int number;
	node* next;

	
};

bool isEmpty(node* head);
char menu();
void InsertAsFirstElement(node *&head, node *&last, int number);
void InsertNode(node *&head, node *&last, int number);
void remove(node *&head, node *&last);
void showList(node *current);


bool isEmpty(node* head) {
	if(head == NULL){
		return false;
	}
	else{
		return true;
	}
}




void InsertAsFirstElement(node *&head, node *&last, int number) {
	   node * temp = new node;
	   temp->number = number;
	   temp->next = NULL;
	   head = temp;
	   last = temp;

}

void InsertNode(node *&head, node *&last, int number){
	  if(isEmpty(head)){
	  		InsertAsFirstElement(head,last,number);
	  }
	  else {
	   node * temp = new node;
	   temp->number = number;
	   temp->next = NULL;
	   last->next = temp;
	   last = temp;
	 }
}

void remove(node *&head, node *&last) {
		if(isEmpty(head)) {
			cout << "List is alredy empty" << endl;
		}
		else if (head == last) {
			 delete head;
			 head == NULL;
			 last == NULL;
		}
		else {
			node * temp = head;
			head = head->next;
			delete temp;
		}
}

void showList(node *current) {
		if(isEmpty(current)){
			cout << "The list is empty " << endl;
		}
		else {
			cout << "List contains: \n" << endl;
			while(current != NULL){
				cout << current->number << endl;
				current = current->next;
			}

		}
}

int main() {
	node * head = NULL;
	node * last = NULL;
	int choice = 8;
	int number;
	std::cout << "0. exit" << std::endl;
      std::cout << "1. insert" << std::endl;
      std::cout << "2. remove" << std::endl;
      std::cout << "3. show" << std::endl;
	while(choice != 0) {
	  cout << "Enter a choice" << endl;
	  cin >> choice;

      if(choice == 0) {
      	break;
      }
      else if(choice == 1) {
      	  cout << "Enter a number " << endl;
      	  cin >> number;
      	  InsertNode(head, last, number);
      }
      else if(choice == 2){
      	 remove(head, last);
      }
      else if(choice == 3){
      	showList(head);
      }
	}
	return 0;

}
