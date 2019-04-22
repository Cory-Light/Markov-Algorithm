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
    int maxNumRulesIndex = 1;
    int const maxRulesNum = 15;
    vector<int> rulesList;
    bool mainStringSet = false;
    bool indexSet = true;
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

	while(!infile.eof())
    {
        getline(infile,holder, '\'');
        cout << "Holder val is " << holder << endl;
        cout << endl;
        if(isdigit(holder[0]) && indexSet)
        {
            num = stoi(holder);
            rulesList.push_back(num);
            cout << num << " has been pushed" << endl;
            cout << endl;

        }
        else if(isdigit(holder[0]) && !indexSet)
        {
            num = stoi(holder);
            rulesList.push_back(num);
            cout << num << " has been pushed" << endl;
            cout << endl;

        }
        else if(holder == "")
        {
            cout << "Empty string ignored." << endl;
            cout << endl;
        }
        else if(!mainStringSet)
        {
            string mainString = holder;
            cout << "Mainstring is: " << mainString << endl;
            cout << endl;
            mainStringSet = true;
        }
        else
        {
            //c
        }
    }


	return 0;
}