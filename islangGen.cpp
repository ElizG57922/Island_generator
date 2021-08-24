#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>


using namespace std;


int generateNumber(int low, int high);

char generateConsonant();

char generateVowel();

string generateName();


	int main()
	{
		
		srand((unsigned)time(0));
		string name = generateName();
		int size = generateNumber(0, 2);
		int numCivilizations = 0;
		if(size == 0){ //large islands have more civilizations
			numCivilizations = generateNumber(1, 2);
		}
		else if(size == 1){
			numCivilizations = generateNumber(2, 4);
		}
		else{
		    numCivilizations = generateNumber(3, 6);
		}
		vector <string> civilizations (numCivilizations);
		
		for(int i = 0; i < numCivilizations; i++){
			civilizations[i] = generateName();
		}
		
		cout<<"In the middle of the sea, there is an island. The island is called "<<generateName()<<". It is a ";
		
		if(size == 0){
			cout<<"small";
		}
		else if(size == 1){
			cout<<"medium sized";
		}
		else{
			cout<<"large";
		}
		cout<<" island."<<endl;
		
		cout<<numCivilizations<<" burgeoning civilizations call this place home. They are the:"<<endl;
		for(int i = 0; i < numCivilizations; i++){
			cout<<civilizations[i]<<endl;
		}
		
		cout<<"All this on the beautiful island."<<endl;
	}

	
	int generateNumber(int low, int high)
	{
	
		return rand()%(high - low + 1) + low;
	}
	
	char generateConsonant()  //from 0 to 20
	{
		switch(generateNumber(0, 20)){
			case 0:
				return 'b';
				break;
			case 1:
				return 'c';
				break;
			case 2:
				return 'd';
				break;
			case 3:
				return 'f';
				break;
			case 4:
				return 'g';
				break;
			case 5:
				return 'h';
				break;
			case 6:
				return 'j';
				break;
			case 7:
				return 'k';
				break;
			case 8:
				return 'l';
				break;
			case 9:
				return 'm';
				break;
			case 10:
				return 'n';
				break;
			case 11:
				return 'p';
				break;
			case 12:
				return 'q';
				break;
			case 13:
				return 'r';
				break;
			case 14:
				return 's';
				break;
			case 15:
				return 't';
				break;
			case 16:
				return 'v';
				break;
			case 17:
				return 'w';
				break;
			case 18:
				return 'x';
				break;
			case 19:
				return 'y';
				break;
			case 20:
				return 'z';
				break;
			default:
				return ' ';
				break;
		}
	}
	char generateVowel()  //from 0 to 4
	{
		switch(generateNumber(0, 4)){
			case 0:
				return 'a';
				break;
			case 1:
				return 'e';
				break;
			case 2:
				return 'i';
				break;
			case 3:
				return 'o';
				break;
			case 4:
				return 'u';
				break;
			default:
				return ' ';
				break;
		}
	}
	
	string generateName(){
		string name = "";
		int nameLength = generateNumber(2, 5);
		int vowelStart = generateNumber(0, 3); // 25% chance to start with a vowel
		if (vowelStart == 3){
			name += generateVowel();
		}
		for(int i = 0; i <nameLength; i++){
		
		    name += generateConsonant();
		    int doubleConsonants = generateNumber(0, 1); // 50% chance to have a second consonant
		    if(doubleConsonants == 1){
		    	name += generateConsonant();
			}
			name += generateVowel();
	    }
	    return name;
	}
