#include "Node.h"
#include <iostream>

/* 
   This program takes a well formed, simplified S-expression whose 
   arguments include add and multiply, parses them using a binary 
   tree and returns the resulting integer. 
*/

int main(int argc, char* argv[]){

	// No expression case
	if(argc == 1){
		cout << "=> Error: please input an expression" << endl;
	}

	// Parse expression into tree
	else{

		Node * root = new Node();
		string arg = argv[1];
		string temp;
		stringstream * ss = new stringstream(arg);

		// Create and resolve expression tree
		root->createTree(ss);
		int result = root->resolveTree();
		cout << "=> " << result << endl;
		
		// Clean up memory
		delete ss;
		delete root;
		ss = NULL;
		root = NULL;

	}

	return 0;

}