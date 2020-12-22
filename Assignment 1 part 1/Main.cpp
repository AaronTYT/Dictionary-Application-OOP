#include "Header.h"

int main() {
	//Start the main program.

	//Introduce the message to the user, load the options data and display the options to the user and load the dictionary file.
	cout << "Welcome to this dictionary program!" << endl;
	cout << "You have 4 options to choose from and they are: " << endl << endl;

	Option myOptions;
	vector<string>optionData;

	//Set options and display the options to the user
	optionData = myOptions.getOptions();
	myOptions.setOptions(optionData);
	myOptions.displayOptions();

	//Load the dictionary file and set the dictionary data.
	Dictionary myDictionary;
	vector<string>dictionaryArray;
	dictionaryArray = myDictionary.loadDictionary();
	myDictionary.setDictionary(dictionaryArray);

	//Infinite loop for a user to keep selecting options except option D to end the program.
	for (;;) {
		cout << "\nType in either A, B, C or D." << endl;
		cout << "Option: ";

		string userInputOption;
		getline(cin, userInputOption);

		if (userInputOption == "A" || userInputOption == "a") {
			cout << "You have selected option A." << endl;
			cout << "Please enter any word: ";

			string inputWord;
			//Important to use getline() when the user enters a word.
			//If not, it will go back the loop and without prompting the userOption.
			getline(cin, inputWord);

			//Goes through a for loop to check each character (user input) to be lowercase.
			for (int eachCharCount = 0; eachCharCount < inputWord.length(); eachCharCount++) {
				char eachChar = inputWord[eachCharCount];
				if (isupper(inputWord[eachCharCount])) {
					inputWord[eachCharCount] = tolower(eachChar);
				}
			}

			vector<string>wordArray;
			wordArray = myDictionary.findWord(inputWord);

			//Setters for word, definiton and type.
			Word user;
			user.setWord(wordArray[0]);
			user.setDefintion(wordArray[1]);
			user.setType(wordArray[2]);

			//Getters for word, definiton and type.
			string word, definition, type;
			word = user.getWord();
			definition = user.getDefinition();
			type = user.getType();

			//Print the user's word, defintion and type.
			cout << "\nWord: " << word << endl;
			user.printDefinition();
			cout << "Type: " << type << endl;
		}

		//Task 2
		else if (userInputOption == "B" || userInputOption == "b") {
			cout << "You have selected option B." << endl;

			vector<string> zWords;
			zWords = myDictionary.findZWords();

			Word user;
			user.setZWords(zWords);
			user.displayZWords();
		}

		//Task 3
		else if (userInputOption == "C" || userInputOption == "c") {
			cout << "You have selected option C." << endl;

			vector<string> qWords;
			qWords = myDictionary.findQWords();

			Word user;
			user.setQWords(qWords);
			user.displayQWords();
		}
		else if (userInputOption == "D" || userInputOption == "d") {
			cout << "You have selected option D." << endl;
			cout << "Thank you for using this dictionary program and have a wonderful day." << endl;
			system("pause");
			exit(1);
		}
		else {
			cout << "You have not pick either A, B, C or D." << endl;
			cout << "Please try again." << endl;
		}
	}
	system("pause");
	return 0;
}