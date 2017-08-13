//ccc contest practice
//primary libraries 
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// add all functions prior to entry point at main

class responses {

public:
	//question 1 
	string processCharacteristics(const int antennas, const int eyes)
	{
		string possibleTypes = "";
		if (antennas > 4 && eyes < 5)
			possibleTypes = possibleTypes + "TroyMartian\n";
		if (antennas < 7 && eyes>1)
			possibleTypes = possibleTypes + "VladSaturnian\n";
		if (antennas < 3 && antennas < 4)
			possibleTypes = possibleTypes + "GraemeMercurian\n";
		//return local string
		return possibleTypes;
	}
	void question1() {
		int antennas, eyes;
		cout << "How many antennas? \n";
		cin >> antennas;
		cout << "How many eyes? \n";
		cin >> eyes;
		cout << processCharacteristics(antennas, eyes);
	}
	//question2
	void question2() {
		//get humidity
		int humidity;
		cin >> humidity;
		int hoursMax;
		cin >> hoursMax;

		int equationMax = 1, hourCount = 1;
			while (equationMax > 0 && hourCount<=hoursMax) {
				equationMax = -6 * pow(hourCount, 4) + humidity*pow(hourCount, 3) + 2 * pow(hourCount, 2) + hourCount;
				hourCount++;
		}
			if (equationMax > 0)
				cout << "The balloon does not touch ground in the given time.\n\n";
			else
				cout << "The ballon touches ground at hour: \n" << (hourCount-1)<<"\n\n";
	}
	//question3
	void question3() {
		int t1, t2;
		cin >> t1; cin >> t2;
		int currentTerm = 0, lastTerm1 = t1, lastTerm2=t2, counter=2;
		
		while (currentTerm < lastTerm1) {
			
			currentTerm = lastTerm1 - lastTerm2;
			lastTerm1 = lastTerm2;
			lastTerm2 = currentTerm;
			
			counter++;
		}
		cout << counter<<"\n";
	}

	int currentPosx = 200, currentPosy = 4;
	int ground[200][401];
	void question4() {
		
		ground[0][201] = 1;
		ground[1][201] = 1;
		ground[2][201] = 1;
		ground[2][201] = 1;
		ground[2][202] = 1;
		ground[2][203] = 1; 
		ground[2][204] = 1;
		ground[3][204] = 1;
		ground[4][204] = 1;
		ground[4][205] = 1;
		ground[4][206] = 1;
		ground[3][206] = 1;
		ground[2][206] = 1;
		ground[2][207] = 1;
		for (int i = 2; i < 7; i++)
			ground[i][208] = 1;
		for (int t = 207; t >199; t--)
			ground[6][t] = 1;
		ground[5][200] = 1;
		ground[4][200] = 1;

		bool valid = true;
		string input;
		while (valid) {
			
			getline(cin, input);
			char direction = input.at(0);
			int spaces;
			stringstream(input.substr(2,input.length()-1))>>spaces;
			//conditions to continue loop 
			valid=processValues(direction, spaces);
			cout << (currentPosx - 201) << " " << (currentPosy + 1)*-1;
			if (valid) {
				cout << " safe\n";
			}
			else 
				cout << " DANGER\n";
		}
	}

	bool processValues(char direction, const int spaces) {
		if (direction == 'l') {
			currentPosx = currentPosx - spaces;
			for (int i= 1; i < spaces; i++) {
				if (ground[currentPosy][currentPosx + i] != 1)
					ground[currentPosy][currentPosx + i] = 1;
				else return false;
			}
			
		}
		else if (direction == 'r') {
			currentPosx = currentPosx + spaces;
			for (int i = 1; i < spaces; i++) {
				if (ground[currentPosy][currentPosx - i] != 1)
					ground[currentPosy][currentPosx - i] = 1;
				else return false;
			}
		}
		else if (direction == 'u') {
			currentPosy = currentPosy - spaces;
			for (int i = 1; i < spaces; i++) {
				if (ground[currentPosy+i][currentPosx] != 1)
					ground[currentPosy+i][currentPosx] = 1;
				else return false;
			}
		}
		else if (direction == 'd') {
			currentPosy = currentPosy + spaces;
			for (int i = 1; i < spaces; i++) {
				if (ground[currentPosy-i][currentPosx] != 1)
					ground[currentPosy-i][currentPosx] = 1;
				else return false;
			}
		}
		else
			return false;
		return true;
	}

    
	
};

class ccc2015s {

public:
	void question1() {
		string input = "";
		getline(cin, input);
		int stringLength = (int)input.length();
		char* allChars = new char[stringLength];
		int* counter = new int[stringLength];

		for (int i = 0; i<stringLength; i++)
			allChars[i] = input.at(i);
		string compare;
		getline(cin, compare);


		int numAsterisk = 0, numOtherChars = 0;
		for (int t = 0; t < stringLength; t++) {
			if (compare.at(t) == '*')
				numAsterisk++;
			else
			{
				for (int i = 0; i < stringLength; i++)
					if (compare.at(t) == allChars[i] && counter[i] != 1) {
						counter[i] = 1;
						numOtherChars++;
						break;
					}
			}
		}
		if (((numAsterisk + numOtherChars) == stringLength) && numAsterisk != 0)
			cout << "A\n";
		else
			cout << "N\n";

	}

	int* dSingleSpeeds;
	int* pSingleSpeeds;
	int* chosen;
	int currentNum;
	
	void question2() {
		int questionType, numPairs;
		cin >> questionType;
		cin >> numPairs;
		string dspeeds, pspeeds;
		getline(cin, dspeeds);
		getline(cin, pspeeds);
		//store individual speeds
		 dSingleSpeeds = new int[numPairs];
	     pSingleSpeeds = new int[numPairs];
		 chosen = new int[numPairs*2];
		 getNums(dspeeds, true);
		 getNums(pspeeds, false);

		
		 for (int m = 0; m < 3; m++) {
			 findExtrema(numPairs, questionType, true,true);
			 int localNum = currentNum;
			 if (currentNum >= numPairs) {
				 if (questionType == 2)
					 questionType == 1;
				 else
					 questionType == 2;
				 findExtrema(numPairs, questionType, true, false);
			 }
			 if (questionType == 2)
				 questionType == 1;
			 else
				 questionType == 2;
				
		 }
		
	}
	void getNums(string currentString, bool isFirst) {
		int stopper = 0;
		int currentNum = 0;
		for (int i = 0; i < (int)currentString.length; i++) {
			if (currentString.at(i) == ' ') {
				if (isFirst)
				    stringstream(currentString.substr(stopper, (i - stopper))) >> dSingleSpeeds[currentNum];
				else
					stringstream(currentString.substr(stopper, (i - stopper))) >> pSingleSpeeds[currentNum];
				currentNum++;
				stopper = i;
			}
		}
	}
	
	int findExtrema(int numPairs, int questionType, bool considerD, bool considerP) {
		int focus = -1;
		currentNum = -1;
		for (int t = 0; t < 2; t++) {
			for (int i = 0; i<numPairs; i++) {
				if (questionType == 1) {
					if (t == 0 && considerD) {
						if (dSingleSpeeds[i] < focus) {
							focus = dSingleSpeeds[i];
							currentNum = t*numPairs + i;
						}
												
					}
					if (considerP)
					{
						if (pSingleSpeeds[i] < focus) {
							focus = pSingleSpeeds[i];
							currentNum = t*numPairs + i;
						}
							
					}
				}
				else {
					if (t == 0 && considerD) {
						if (dSingleSpeeds[i] > focus) {
							currentNum = t*numPairs + i;
							focus = dSingleSpeeds[i];
						}
							
					}
					if (considerP)
					{
						if (pSingleSpeeds[i] > focus) {
							currentNum = t*numPairs + i;
							focus = pSingleSpeeds[i];
						}
							
					}
				}
				
			}
			
		}
		chosen[currentNum] = 1;
		return focus;
	}
};

int main() {
	ccc2015s allQuestions;
	allQuestions.question1();
	system("pause");
	return 0;
}
