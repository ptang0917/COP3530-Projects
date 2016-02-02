#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
	
public:
	Node();
	Node(int d);
	Node* next;
	int data;
};

Node::Node(){
	// data = 0;
	next = NULL;
}

Node::Node(int d) {
	data = d;
	next = NULL;
}

class LinkedList {
	Node * head;
	Node * tail;

public:
	LinkedList();
	void add(int d);
	void addeff(int d);
	void print();
	void delete();	
};

LinkedList::LinkedList() {
	// head = new Node();
	head = NULL;
	tail = NULL;
}

void LinkedList::add(int d) {
	Node * n = new Node(d);
	Node * tracker = head;
	if(tracker == NULL) {
		head = n;
	}
	else {
	  while(tracker->next != NULL){

			tracker = tracker->next;

	   }


	   tracker->next = n;
   }
	
}

void LinkedList::addeff(int d){
	Node * n = new Node(d);
		if(head == NULL) {
		head = n;
		tail = head;
		
	}
	else {
		tail->next = n;
		tail = n;

		
		
		
				
	}

}

void LinkedList::print() {
	Node* tracker = head;
	while(tracker != NULL){
		cout << tracker->data << endl;
		tracker = tracker->next;
	}
}





int main(int argc, char** argv) {
	LinkedList list;
	int size;
	int num;
	cout << "Enter the size of the LinkedList " << endl;
	cin >> size;
	cout << "Enter the number " << endl;

	for(int i = 0; i < size; i++){
		 cin >> num;
		 list.addeff(num);
	}

	cout << " " << endl;
	list.print();
	return 0;
}








