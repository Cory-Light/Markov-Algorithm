#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	string holder;
	int num;
    int const maxRulesNum = 11;
    vector<int> rulesList;
    vector<string> leftStringVec, rightStringVec, allWords;
	bool leftStringChoice = true;
    //string mainString;
    const char * cStringLeft;
    const char * cStringRight;
    const char * cStringMain;
    int cStringLeftLength, cStringRightLength, cStringMainLength;
    string mainPre;
    string mainPost;
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

        // cout << "Holder val is " << holder << endl;
        // cout << endl;
		//printOut.push_back(holder);
        if(holder[0] == '0' || holder[0] == '1' || holder[0] == '2' || holder[0] == '3' ||
        holder[0] == '4' || holder[0] == '5' || holder[0] == '6' || holder[0] == '7' ||
        holder[0] == '8' || holder[0] == '9') 
        // numList correctly holds the nextRule values for each line
        {
            num = stoi(holder);
            rulesList.push_back(num);
            cout << num << " has been pushed" << endl;
            cout << endl;

        }
        else
        {
            allWords.push_back(holder);
        }
		
    }
	for(int i = 0; i < allWords.size(); i++)
	{
		if(allWords[i]  == "" && allWords[i+1] == "" && leftStringChoice)
        {
            //cout << i << ": " << allWords[i] << endl;
            leftStringVec.push_back(allWords[i]);
            //cout << "Pushed left 1st if" << endl;
            leftStringChoice = !leftStringChoice;
            i++;
        }
        else if(allWords[i]  == "" && allWords[i+1] == "" && !leftStringChoice)
        {
            //cout << i << ": " << allWords[i] << endl;
            rightStringVec.push_back(allWords[i]);
            //cout << "Pushed right 2nd if" << endl;
            leftStringChoice = !leftStringChoice;
            i++;
        }
        else if(leftStringChoice && allWords[i] != "")
        {
            //cout << i << ": " << allWords[i] << endl;
            leftStringVec.push_back(allWords[i]);
            //cout << "Pushed left 3rd if" << endl;
            leftStringChoice = !leftStringChoice;
        }
        else if(!leftStringChoice && allWords[i] != "")
        {
            //cout << i << ": " << allWords[i] << endl;
            rightStringVec.push_back(allWords[i]);
            //cout << "Pushed right 4th if" << endl;
            leftStringChoice = !leftStringChoice;
        }
        else
        {
            //do nothing
        }

	}

    cout << "Num        Left       Right       NextRule" << endl;
    for(int i = 0; i < maxRulesNum; i++)
    {
        rulesArr[i].leftStr = leftStringVec[i];
        rulesArr[i].rightStr = rightStringVec[i];
        rulesArr[i].nextRule = rulesList[i+1];
        cout << i << "       " << rulesArr[i].leftStr << "       "
        <<rulesArr[i].rightStr << "       " << rulesArr[i].nextRule << endl;    
    }

    int currRule = 1;
    string mainString = "[AAABB";
    cout << "Pre-check" << endl;
    cStringLeft = rulesArr[currRule].leftStr.c_str();
    cStringLeftLength = strlen(cStringLeft);
    cout << "In-check" << endl;

    cStringMain = mainString.c_str();
    //cout << cStringMain << endl;
    cStringMainLength = strlen(cStringMain);
    //cout << cStringMainLength << endl;
    cout << "Post-Check" << endl;
    for(int i = 0; i < cStringMainLength; i++)
    {
        if(cStringLeft[i] == cStringMain[i])
        {
            cout << "we have a match" << endl;
            currRule = 20;
        }
    }

    //int currRule = 0;
    // while(currRule < rulesList[0]) //rulesList[0] holds the total number of rules
    // {
    //     if(rulesArr[currRule].leftStr == "")
    //     {
    //         mainString = rulesArr[currRule].rightStr;
    //         currRule == rulesArr[currRule].nextRule;
    //     }
    //     else
    //     //grab the size of the leftString so we know how much to check
    //     //iterate through the mainString to find the left string
    //     //split mainString and add the rightString in its place
    //     {
    //         strcpy(cStringLeft, rulesArr[currRule].leftStr.c_str());
    //         cStringLeftLength = strlen(cStringLeft);

    //         strcpy(cStringMain, mainString.c_str());
    //         cStringMainLength = strlen(cStringMain);
    //         for(int i = 0; i < cStringMainLength; i++)
    //         {
    //             if(cStringLeft[i] == cStringMain[i])
    //             {
    //                 cout << "we have a match" << endl;
    //                 currRule = 20;
    //             }
    //         }

    //     }
    // }

    // cout << "LeftString list" << endl << endl;
	// for(int i = 0; i < leftStringVec.size(); i++)
	// {
	// 	cout << i << ": " << leftStringVec[i] << endl;

	// }

    // cout << "RightString list" << endl << endl;
	// for(int i = 0; i < rightStringVec.size(); i++)
	// {
	// 	cout << i << ": " << rightStringVec[i] << endl;

	// }

    // cout << "AllWords list" << endl << endl;
	// for(int i = 0; i < allWords.size(); i++)
	// {
	// 	cout << i << ": " << allWords[i] << endl;

	// }


	return 0;
}