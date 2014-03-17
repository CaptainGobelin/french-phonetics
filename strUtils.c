#include "strUtils.h"

bool StrUtils::compare(std::string rule, std::string word, unsigned int pos, int &len) {
	if (rule == "")
		return false;
	int ruleSize[3];
	ruleLength(rule, ruleSize);
	if (word.size() < (pos+ruleSize[1]))
		return false;
	if (rule.size() < (unsigned int)len)
		return false;
	bool test = true;
	for (int i=ruleSize[0];i>0;i--) {
		if (rule[i] == '/') {
			test = test && noVowel(word, pos-i);
		}
		else if (rule[i] == '-') {
			test = test && isVowel(word, pos-i);
		}
		else if (rule[i] == '|') {
			test = test && isConsonant(word, pos-i);
		}
	}
	for (int i=0;i<ruleSize[1];i++)
		if (word[pos+i] != rule[i+ruleSize[0]])
				test = false;
	for (int i=0;i<ruleSize[2];i++) {
		if (rule[i+ruleSize[0]+ruleSize[1]] == '/') {
			test = test && noVowel(word, pos+i+ruleSize[1]);
		}
		else if (rule[i+ruleSize[0]+ruleSize[1]] == '-') {
			test = test && isVowel(word, pos+i+ruleSize[1]);
		}
		else if (rule[i+ruleSize[0]+ruleSize[1]] == '|') {
			test = test && isConsonant(word, pos+i+ruleSize[1]);
		}
		else if (((int)rule[i+ruleSize[0]+ruleSize[1]] > 64) && ((int)rule[i+ruleSize[0]+ruleSize[1]] < 91)) {
			test = test && checkLetter(word, (int)rule[i+ruleSize[0]+ruleSize[1]], pos+i+ruleSize[1]);
		}
	}
	if (test)
		len = ruleSize[1];
	return test;
}

void StrUtils::ruleLength(std::string rule, int count[]) {
	for (int i=0;i<3;i++)
		count[i] = 0;
	bool firstRulesPassed = false;
	for (unsigned int i=0;i<rule.size();i++)
		if (isLetter(rule[i])) {
			count[1]++;
			firstRulesPassed = true;
		}
		else if (!firstRulesPassed)
			count[0]++;
	count[2] = rule.size() - count[0] - count[1];
}

bool StrUtils::isLetter(char charToTest) {
	std::string letters = "abcdefghijklmnopqrstuvwxyz";
	for (int i=0;i<26;i++)
		if (charToTest == letters[i])
			return true;
	return false;
}

bool StrUtils::noVowel(std::string word, unsigned int pos) {
	if (word.size() <= pos)
		return true;
	std::string vowels = "aeiouy";
	for (int i=0;i<6;i++)
		if (word[pos] == vowels[i])
			return false;
	return true;
}

bool StrUtils::isVowel(std::string word, unsigned int pos) {
	if (word.size() <= pos)
		return false;
	std::string vowels = "aeiouy";
	for (int i=0;i<6;i++)
		if (word[pos] == vowels[i])
			return true;
	return false;
}

bool StrUtils::isConsonant(std::string word, unsigned int pos) {
	if (word.size() <= pos)
		return false;
	std::string vowels = "aeiouy";
	for (int i=0;i<6;i++)
		if (word[pos] == vowels[i])
			return false;
	return true;
}

bool StrUtils::checkLetter(std::string word, int letter, unsigned int pos) {
	if ((int)word[pos] == (letter+32))
		return true;
	return false;
}