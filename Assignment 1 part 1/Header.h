//Import preprocessing directives (class libraries).
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//Class section
class Word {

private:
	string word;
	string definition;
	string type;

	vector<string>zWords;

	vector<string>qWords;

public:
	//word functions (task 1)
	void setWord(string);
	void setDefintion(string);
	void setType(string);

	string getWord();
	string getDefinition();
	string getType();

	void printDefinition();

	//zWord functions (task 2)
	void setZWords(vector<string>);
	void displayZWords();

	//q functions (task 3)
	void setQWords(vector<string>);
	void displayQWords();
};


class Dictionary {
private:
	vector<string>words;
	vector<string>definitions;
	vector<string>types;

public:
	//dictionary functions (task 1)
	vector<string> loadDictionary();
	void setDictionary(vector<string>);
	vector<string> findWord(string);

	//dictionary function (task 2)
	vector<string> findZWords();

	//dictionary function (task 3)
	vector<string> findQWords();
};

class Option {
private:
	vector<string>optionName;
	vector<string>optionDescription;
public:
	vector<string>getOptions();
	void setOptions(vector<string>);

	void displayOptions();
};