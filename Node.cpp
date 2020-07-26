#include "Node.h"

Node::Node(){

	data = "";
	left = NULL;
	right = NULL;

}

Node::~Node(){

	delete left;
	delete right;
	left = NULL;
	right = NULL;
	data = "";

}

void Node::setData(string str){

	data = str;

}

void Node::setLeft(Node * newNode){

	left = newNode;

}

void Node::setRight(Node * newNode){

	right = newNode;

}

Node * Node::getLeft(){

	return left;

}

Node * Node::getRight(){

	return right;

}

string Node::getData(){

	return data;

}

// Helper function for resolveTree, checks if a node is one level 
// above two leaf nodes, or is a leaf node itself
bool Node::isAlmostLeaf(){

	// Check if node is one level above a leaf
	if(left->getLeft() == NULL && left->getRight() == NULL && 
		right->getLeft() == NULL && right->getRight() == NULL){
		return true;
	}

	else{return false;}

}

// Recursively create a binary tree using the given expression
void Node::createTree(stringstream * ss){

	string temp;
	if(*ss >> temp){

		// Each nested expression needs to have two leaves of its own
		if(temp.find("(") != string::npos){

			// Remove any brackets from the string
			boost::erase_all(temp, "(");
			boost::erase_all(temp, ")");

			// Set data and create leaf nodes
			this->setData(temp);
			this->left = new Node();
			this->left->createTree(ss);
			this->right = new Node();
			this->right->createTree(ss);

		}

		// If temp is not a nested expression, we can simply insert
		else{

			// Remove any brackets from the string
			boost::erase_all(temp, "(");
			boost::erase_all(temp, ")");

			// Set data
			this->setData(temp);

		}

	}

	return;

}

// Recursively resolve the binary tree to evaluate the expression
int Node::resolveTree(){

	int result; 

	// Check if we are at a leaf node
	if(this->left == NULL && this->right == NULL){
		result = stoi(this->data);
	}

	// If we are one level above two leaf nodes, we can evaluate
	// a sub-expression
	else if(this->isAlmostLeaf()){

		int l = stoi(this->left->data);
		int r = stoi(this->right->data);

		if(this->data.compare("add") == 0){
			result = l + r;
		}
		else if(this->data.compare("multiply") == 0){
			result = l * r;
		}

	}

	else{

		int l = this->left->resolveTree();
		int r = this->right->resolveTree();

		if(this->data.compare("add") == 0){
			result = l + r;
		}
		else if(this->data.compare("multiply") == 0){
			result = l * r;
		}

	}

	return result;

}