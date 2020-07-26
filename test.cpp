#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	/* Writing to file
	ofstream outdata("test.dat"); 
	int num[5] = {4, 3, 7, 9, 11};

	if(!outdata.is_open()){
		cout << "Error: file could not be openend" << endl;
		return 1;
	}

	for(int i = 0; i < 5; ++i){
		outdata << num[i] << endl;
	}
	outdata.close();
	*/

	/* Reading from file
	ifstream indata("test.dat");
	string line;

	if(!indata.is_open()){
		cout << "Error: file could not be opened" << endl;
		return 1;
	}

	while(getline(indata, line)){
		cout << line << endl;
	}
	*/

	return 0;

}