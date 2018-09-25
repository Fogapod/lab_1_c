#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>

const char ALPHANUMERIC[] = "abcdefghijklmnopqrstuvwxyz0123456789_";

bool get_user_input_strng(std::string *dest);
bool not_alphanumeric(char c);

#endif /* UTILS_H_ */
