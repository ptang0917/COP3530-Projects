
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
		void AddStepNode(int data);

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

void List::AddStepNode(int Data, int Step, int Num){
	nodePtr n = new node;
	nodePtr temp = new node;
	n->next = NULL;
	n->data = Data;
	
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
	for(int i = 0; i < Step*(num+1); i++) {
		curr = head->next;
		
	}
	temp = curr->next;
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
	List list;
	int size = 0; 
	int nodenum = 0;
	int addlist = 0;
	int j = 0;
	int step = 0;
	cout << "Enter the size of the node" << endl;
	cin >> size;
	cout << "Add the following nodes" << endl;
	for(int i = 0; i < size; i++) {
		cin >> nodenum;
		list.AddNode(nodenum);
	}
	cout << " " << endl;
	list.PrintList();

	cout << "Enter any additional list " << endl;
	cin >> addlist;
	while(j < addlist) {
		cout << "Enter the number of steps" << endl;
		cin >> step;
		cout << "Enter the size of the node" << endl;
		cin >> size;
		cout << "Add the following nodes" << endl;
		for(int k = 0; k < size; k++) {
			cin >> nodenum;
			list.AddStepNode(nodenum,step,k);
		}
		j++;
	}
	cout << " " << endl;
	list.PrintList();

	return 0;




}
