#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>

#include "utils.h"

using std::cout;
using std::endl;
using std::string;

const string OUTPUT_FILENAME = "model.txt";

int main(int argc, char **argv) {
	string fileName;

	if (argc == 2) {
		fileName = argv[1];
	} else if (argc > 2) {
		cout << "Invalid number of arguments: >1" << endl;
		exit(1);
	} else {
		bool ok = false;
		do {
			cout << "Enter filename: ";
			ok = get_user_input_strng(&fileName);
		} while (!ok);
	}

	std::ifstream inputFile;
	inputFile.open(fileName);
	if (!inputFile.is_open()) {
		cout << "Failed to open file " << fileName << endl;
		exit(1);
	}

	std::map<string, int> freqMap;

	string word;
	int wordCount = 0;

	for(inputFile >> word; !inputFile.eof(); inputFile >> word) {
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		word.erase(std::remove_if(word.begin(), word.end(), not_alphanumeric), word.end());

		if (word == "")
			continue;

		freqMap[word]++;

		wordCount++;
	}

	inputFile.close();

	cout << "End of file" << endl;

	cout << "Frequency of 'the': " << freqMap["the"] << endl;
	cout << "Frequency of 'he':  " << freqMap["he"] << endl;

	string outputFileName = "model.txt";
	cout << "Writing to file " << outputFileName << endl;

	std::ofstream outputFile;
	outputFile.open(outputFileName);
	for (auto& it : freqMap) {
		if (it.second == 0)
			continue;

		outputFile << it.first << ": " << std::to_string(it.second) << endl;
	}
	outputFile.close();

	cout << "Finished writing" << endl;

	return 0;
}
