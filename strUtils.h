#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#ifndef STR_UTILS_H
#define STR_UTILS_H

class StrUtils {
	public:
		static bool compare(std::string rule, std::string word, unsigned int pos, int &len);
		static void ruleLength(std::string rule, int count[]);
		static bool isLetter(char charToTest);
		static bool noVowel(std::string word, unsigned int pos);
		static bool isVowel(std::string word, unsigned int pos);
		static bool isConsonant(std::string word, unsigned int pos);
		static bool checkLetter(std::string word, int letter, unsigned int pos);
};

#endif