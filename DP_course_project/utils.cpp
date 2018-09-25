#include "utils.h"

#include <iostream>
#include <limits>

using std::cin;
using std::string;

bool get_user_input_strng(string* dest) {
	cin >> *dest;

    if (cin.eof()) {
		exit(0);
		// TODO: figure out how to recover cin/stdin from eof state
        // return false;
    }

    if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

bool not_alphanumeric(char c) {
	for (auto i : ALPHANUMERIC) {
		if (c == i)
			return false;
	}
	
	return true;
}
