#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;

int main() {
	string holder;
	int num;
	int z;

	ifstream infile;
	infile.open("data.markov.txt");

	getline(infile,holder, '\'');

	num = stoi(holder);
    int const maxRuleNum = num;
    int intList[maxRuleNum];


	return 0;
}