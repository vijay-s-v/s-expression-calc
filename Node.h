#include <sstream>
#include <boost/algorithm/string.hpp>

using namespace std;

/* 
   This defines a node class that is used to build a binary tree
   to represent and evaluate a well defined, simplified S-expression
*/

class Node{

	public:

		Node();
		~Node();
		void setLeft(Node * left);
		void setRight(Node * right);
		void setData(string str);
		Node * getLeft();
		Node * getRight();
		string getData();
		void createTree(stringstream * ss);
		bool isAlmostLeaf();
		int resolveTree();


	private:

		string data;
		Node * left;
		Node * right;
		
};