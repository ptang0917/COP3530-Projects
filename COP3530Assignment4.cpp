#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Node {
public:
	//Node(int d);
	Node(string s);
	string data;
	Node *left;
	Node *right;

};

Node::Node(string s) {
	data = s;
	left = NULL;
	right = NULL;
}

class BinaryTree {
	
public:
	Node * root;
	BinaryTree();
	~BinaryTree();
	void InsertNode(string s);//, int x, int y);
	void MagicNode(string s, Node *);
	void InOrder(Node *);
	void PreOrder(Node *);
	void PostOrder(Node *);
	void FreeNode(Node *);
	
};

BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	FreeNode(root);
}

void BinaryTree::FreeNode(Node * leaf) {
	if (leaf != NULL) {
		FreeNode(leaf->left);
		FreeNode(leaf->right);
		delete leaf;
	}
}

void BinaryTree::InsertNode(string s){
	if (root == NULL) {
		Node * n = new Node(s);
		root = n;

	}
	else {
		MagicNode(s, root);
	}
	
}

void BinaryTree::MagicNode(string s, Node * leaf) {
	if (s <= leaf->data) {
		if (leaf->left != NULL) {
			MagicNode(s, leaf->left);
		}
		else {
			Node * n = new Node(s);
			n->data;
			leaf->left;

		}
	}
	else {
		if (leaf->right != NULL) {
			MagicNode(s, leaf->right);
		}
		else {
			Node * n = new Node(s);
			n->data;
			leaf->right;
		}
	}
}


void BinaryTree::InOrder(Node * n) {
	if (n) {
		InOrder(n->left);
		cout << n->data << endl;
		InOrder(n->right);
		

	}	
}

void BinaryTree::PreOrder(Node * n) {
	if (n) {
		cout << n->data << endl;
		PreOrder(n->left);
		PreOrder(n->right);
	}
}

void BinaryTree::PostOrder(Node * n) {
	if (n) {
		PostOrder(n->left);
		PostOrder(n->right);
		cout << n->data << endl;

	}
}


int main() {
	BinaryTree* tree = new BinaryTree();
	tree->InsertNode("A");
	tree->InsertNode("B");
	tree->InsertNode("C");
	tree->InsertNode("D");
	tree->InsertNode("E");
	tree->InsertNode("F");
	tree->InsertNode("G");
	tree->InsertNode("H");
	tree->InsertNode("I");
	tree->InsertNode("J");
	tree->InsertNode("K");
	tree->InsertNode("L");

	


	cout << "Pre order traversal" << endl;
	tree->PreOrder(tree->root);
	cout << endl;


	cout << "In order traversal" << endl;
	tree->InOrder(tree->root);
	cout << endl;

	cout << "Post order traversal" << endl;
	tree->PostOrder(tree->root);
	cout << endl;

	cin.get();
	return 0;

	

}
