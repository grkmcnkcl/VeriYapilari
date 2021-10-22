#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib> // for exit function
// This program reads values from the file 'example.dat'
// and echoes them to the display until a negative value
// is read.
int main()
{

	char x, y, z;
	ifstream indata; // indata is like cin
	int num; // variable for input value
	indata.open("Text.txt"); // opens the file
	if (!indata) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		system("pause");
		exit(1);
	}

	while (!indata.eof()) { // keep reading until end-of-file
		char word[10]; // variable for input value
		indata.getline(word, 10, '\n');
		if (word[0] == 'A') {
			x = word[2];
			cout << x << endl;
		}
		else if (word[0] == 'B') {
			y = word[2];
			cout << y << endl;
		}
		
	}
	int iy = (int)x;
	int ix = (int)y;

	cout << ix + iy << endl;
	indata.close();
	cout << "End-of-file reached.." << endl;
	system("pause");
	return 0;
}