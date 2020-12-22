#include "Header.h"
//Implementation section (methods only)

//Option class methods:
vector<string> Option::getOptions() {
	ifstream openFile;
	string dictionaryFileName = "options.txt";
	openFile.open(dictionaryFileName);

	//If the dictionaryFileName does not exists in one of the resouce file.
	//End the program.
	if (!openFile) {
		cerr << "The dictionary file name: " << dictionaryFileName << " cannot be opened.\n";
		system("pause");
		exit(1);
	}
	else {
		string data;
		vector<string>optionArray;
		//Loop through every line within the dictionary.txt file.
		while (getline(openFile, data)) {
			optionArray.push_back(data);
		}
		return optionArray;
	}
}

void Option::setOptions(vector<string>optionData) {
	for (int i = 0; i < optionData.size(); i++) {

		//Appends only the word to the words vector.
		if (i % 3 == 0) {
			optionName.push_back(optionData[i]);
		}

		//Appends only the definition to the definitions vector.
		else if (i % 3 == 1) {
			optionDescription.push_back(optionData[i]);
		}
	}
}

//Displays each option name and their description.
void Option::displayOptions() {
	for (int i = 0; i < optionName.size(); i++) {
		cout << "Option: " << optionName[i] << endl;
		cout << "Description: " << optionDescription[i] << endl << endl;
	}
}

//Dictionary Methods:
vector<string> Dictionary::loadDictionary() {
	ifstream openFile;
	string dictionaryFileName = "dictionary.txt";
	openFile.open(dictionaryFileName);

	//Opens the dictionary and goes through a check to see if the dictionary file exist.
	//If not, terminate the program.
	if (!openFile) {
		cerr << "The dictionary file name: " << dictionaryFileName << " cannot be opened.\n";
		system("pause");
		exit(1);
	}
	else {
		string data;
		vector<string>dictionaryArray;
		//Loop through every line within the dictionary.txt file and append every line (data) into the array.
		while (getline(openFile, data)) {
			dictionaryArray.push_back(data);
		}
		return dictionaryArray;
	}
}

void Dictionary::setDictionary(vector<string>dictionaryData) {
	for (int i = 0; i < dictionaryData.size(); i++) {

		//Appends only the word to the words vector.
		if (i % 4 == 0) {
			words.push_back(dictionaryData[i]);
		}

		//Appends only the definition to the definitions vector.
		else if (i % 4 == 1) {
			definitions.push_back(dictionaryData[i]);
		}

		//Appends only the type to the types vector.
		else if (i % 4 == 2) {
			types.push_back(dictionaryData[i]);
		}
	}
}

vector<string> Dictionary::findWord(string word) {
	vector<string>userWordArray;

	for (int c = 0; c <= words.size(); c++) {

		//If the user's word is found in the words vector.
		//Append the word, defintion and type to "userWordArray".
		if (word == words[c]) {
			userWordArray.push_back(word);
			userWordArray.push_back(definitions[c]);
			userWordArray.push_back(types[c]);
			break;
		}

		//If the word search has not found in the words vector.
		//Appendt the error messages.
		if (c == words.size()) {
			userWordArray.push_back("No word has been found.");
			userWordArray.push_back("No definition has been found.");
			userWordArray.push_back("No type has been found.");
		}
	}
	return userWordArray;
}

vector<string> Dictionary::findZWords() {
	vector<string>zWordsArray;

	int zCount = 0;
	for (string eachWord : words) {

		//Adds to the zCount variable if a character within a word has a 'z'.
		for (char eachChar : eachWord) {
			if (eachChar == 'z') {
				zCount++;
			}
		}
		//If the zCount variable is more then 3, append the current word to the zWordList.
		if (zCount > 3) zWordsArray.push_back(eachWord);

		zCount = 0;
	}
	return zWordsArray;
}

vector<string> Dictionary::findQWords() {
	vector<string>qWordList;
	int qCount = 0;

	//Goes through a nested for loop statement to verify if the word has a 'q' and does not have a 'u' letter
	//after the letter q.
	//If so, append the word to "qWordList" vector.
	for (string eachWord : words) {
		for (char eachChar : eachWord) {
			if (eachChar == 'q' && eachWord[qCount + 1] != 'u') {
				qWordList.push_back(eachWord);
				break;
			}
			else qCount++;
		}
		qCount = 0;
	}
	return qWordList;
}

//Word methods:
//Task 1 setters
void Word::setWord(string word) {
	this->word = word;
}

void Word::setDefintion(string definition) {
	this->definition = definition;
}

void Word::setType(string type) {
	this->type = type;
}

//Task 1 getters
string Word::getWord() {
	return word;
}

string Word::getDefinition() {
	return definition;
}

string Word::getType() {
	return type;
}

void Word::printDefinition() {
	cout << "Definition: " << definition << endl;
}

void Word::setZWords(vector<string>zWords) {
	this->zWords = zWords;
}

void Word::displayZWords() {
	cout << "\nI have found " << zWords.size() << " words that has more then 3 z's." << endl;
	cout << "The following words that I have found are:\n" << endl;

	//Outputs every more then 3'z word.
	for (string eachZWord : zWords) {
		cout << eachZWord << endl;
	}
}


void Word::setQWords(vector<string>qWords) {
	this->qWords = qWords;
}

void Word::displayQWords() {
	int count = 0;
	cout << "\nI have found " << qWords.size() << " words that has a letter q and does not have a letter u after the letter q." << endl;
	cout << "The following words that I have found are:\n" << endl;
	for (string eachWord : qWords) {
		cout << "Word " << count + 1 << ": " << eachWord << endl;
		count++;
	}
	count = 0;
}
