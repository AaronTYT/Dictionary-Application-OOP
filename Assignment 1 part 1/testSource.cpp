#include <iostream>
#include <string>

using namespace std;


int main() {
	string userInputOption;
	//Infinite loop for a user to keep selecting options except option D to end the program.


	for (;;) {
		cout << "\nType in either A, B, C or D" << endl;
		cout << "Option: ";
		getline(cin, userInputOption);

		//Task 1
		if (userInputOption == "A" || userInputOption == "a") {
			cout << "You have selected option A." << endl;

			string inputWord;
			cout << "Enter a word: ";
			cin >> inputWord;

			cout << inputWord;
		}

	}


	system("pause");
	return 0;
}