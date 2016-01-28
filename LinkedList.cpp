
#include <cstdlib>
#include <iostream>
using namespace std;

class List{
	private:
		typedef struct node{
			int data;
			node* next;

		} * nodePtr;

		nodePtr head;
		nodePtr curr;
		nodePtr temp;
	public:
		List();
		void AddNode(int data);
		void DeleteNode(int data);
		void PrintList();

};


List::List(){
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::AddNode(int addData){
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	if(head != NULL) {
		curr = head;
		while(curr->next != NULL){
			curr=curr->next;
		}
		curr->next = n;

	}
	else {
		head = n;
	}
}

void List::DeleteNode(int delData){
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while(curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;

	}
	if(curr == NULL) {
		cout << delData << "Not on the list " << endl;
		delete delPtr;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
		cout << "The value " << delData << " is delted " << endl;
	}
}

void List::PrintList() {
	curr = head;
	while(curr != NULL) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}


int main(int argc, char** argv){
	List Paul;
	Paul.AddNode(3);
	Paul.AddNode(7);
	Paul.AddNode(2);
	Paul.AddNode(8);
	Paul.PrintList();
	Paul.DeleteNode(2);
	Paul.AddNode(9);
	Paul.PrintList();

	return 0;




}
