#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


using namespace std;

int main() {
	string holder;
	int num;
	int z;
    int maxNumRulesIndex = 0;
    int const maxRulesNum = 15;
	int currentIndex = 0;
    vector<int> rulesList;
    vector<string> leftStringVec;
	vector<string> rightStringVec;
	//vector<string> printOut;
    bool mainStringSet = false;
    bool emptyStringSkip = false;
	bool leftStringChoice = true;
    //if the above is false, then the nextRule is being set

    struct ruleSet
    {
        //ruleNum is indicated by index of array
        string leftStr = "";
        string rightStr = "";
        int nextRule = 0;
    };
    ruleSet rulesArr[maxRulesNum];

	ifstream infile;
	infile.open("data.markov.txt");

	// while(!infile.eof())
    // {
    //     getline(infile,holder, '\'');
    //     cout << "Holder val is " << holder << endl;
    //     cout << endl;
	// 	//printOut.push_back(holder);
    //     if(isdigit(holder[0])) // numList correctly holds the nextRule values for each line
    //     {
    //         num = stoi(holder);
    //         rulesList.push_back(num);
    //         cout << num << " has been pushed" << endl;
    //         cout << endl;

    //     }else if(!mainStringSet)
    //     {
    //         string mainString = holder;
    //         cout << "Mainstring is: " << mainString << endl;
    //         cout << endl;
	// 		rightStringVec.push_back(holder);
	// 		leftStringChoice = true;
    //         mainStringSet = true;
    //     }
    //     else if(holder == "" && !emptyStringSkip && leftStringChoice)
    //     {
    //         cout << "Empty string inserted left." << endl;
    //         leftStringVec.push_back(holder);
	// 		emptyStringSkip = true;
    //     }
	// 	else if(holder == "" && !emptyStringSkip && !leftStringChoice)
    //     {
    //         cout << "Empty string inserted right." << endl;
    //         rightStringVec.push_back(holder);
	// 		emptyStringSkip = true;
    //     }
	// 	else if(holder == "" && emptyStringSkip)
    //     {
    //         cout << "Empty string ignored." << endl;
    //         cout << endl;
	// 		emptyStringSkip = false;
    //     }
        
    //     else if(leftStringChoice)
    //     {
    //         leftStringVec.push_back(holder);
	// 		leftStringChoice = false;
    //     }
	// 	else if(!leftStringChoice)
	// 	{
	// 		rightStringVec.push_back(holder);
	// 		leftStringChoice = true;
	// 	}
		
    // }

	// for(int i = 1; i < printOut.size(); i++)
	// {
	// 	cout << printOut.at(i);
	// 	cout << " ";
	// 	if(i == 4 || i == 8 || i == 12 || i == 16 || i == 20 || i == 24 || i == 28 || i == 32 || i == 36 || i == 40)
	// 	{
	// 		cout << endl;
	// 	}
	// }
	cout << "Rules list" << endl << endl;
	for(int i = 0; i < rulesList.size(); i++)
	{
		cout << i << ": " << rulesList[i] << endl;

	}

	for(int i = 0; i < leftStringVec.size(); i++)
	{
		cout << i << ": " << leftStringVec[i] << endl;

	}

	for(int i = 0; i < rightStringVec.size(); i++)
	{
		cout << i << ": " << rightStringVec[i] << endl;

	}

	return 0;
}