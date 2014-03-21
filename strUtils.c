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
	int shift = 0;
	bool negative = false;
	for (int i=0;i<ruleSize[0];i++) {
		if (rule[i] == '!') {
			negative = true;
			i++;
		}
		if (rule[i] == '/') {
			test = test && (noVowel(word, pos-ruleSize[0]+i)!=negative);
		}
		else if (rule[i] == '-') {
			test = test && (isVowel(word, pos-ruleSize[0]+i)!=negative);
		}
		else if (rule[i] == '~') {
			test = test && (isConsonant(word, pos-ruleSize[0]+i)!=negative);
		}
		else if (rule[i] == '<') {
			test = test && (doubleLetter(word, pos-ruleSize[0]+i)!=negative);
		}
		else if (rule[i] == '[') {
			test = test && (endChar(word, pos-ruleSize[0]+i)!=negative);
		}
		else if (rule[i] == '*') {
			test = test && (isLetter(word, pos-ruleSize[0]+i)!=negative);
		}
		else if (((int)rule[i] > 64) && ((int)rule[i] < 91)) {
			test = test && (checkLetter(word, (int)rule[i], pos-ruleSize[0]+i)!=negative);
		}
		negative = false;
	}
	shift = ruleSize[0];
	for (int i=0;i<ruleSize[1];i++)
		if (word[pos+i] != rule[i+shift])
				test = false;
	shift = ruleSize[0] + ruleSize[1];
	for (int i=0;i<ruleSize[2];i++) {
		if (rule[i+shift] == '!') {
			negative = true;
			i++;
		}
		if (rule[i+shift] == '/') {
			test = test && (noVowel(word, pos+i+ruleSize[1])!=negative);
		}
		else if (rule[i+shift] == '-') {
			test = test && (isVowel(word, pos+i+ruleSize[1])!=negative);
		}
		else if (rule[i+shift] == '~') {
			test = test && (isConsonant(word, pos+i+ruleSize[1])!=negative);
		}
		else if (rule[i+shift] == '<') {
			test = test && (doubleLetter(word, pos+i+ruleSize[1])!=negative);
		}
		else if (rule[i+shift] == '[') {
			test = test && (endChar(word, pos+i+ruleSize[1])!=negative);
		}
		else if (rule[i+shift] == '*') {
			test = test && (isLetter(word, pos+i+ruleSize[1])!=negative);
		}
		else if (((int)rule[i+shift] > 64) && ((int)rule[i+shift] < 91)) {
			test = test && (checkLetter(word, (int)rule[i+shift], pos+i+ruleSize[1])!=negative);
		}
		negative = false;
	}
	if (test)
		len = ruleSize[1];
	return test;
}

void StrUtils::ruleLength(std::string rule, int count[]) {
	for (int i=0;i<3;i++)
		count[i] = 0;
	bool firstRulesPassed = false;
	for (unsigned int i=0;i<rule.size();i++) {
		if (isLetter(rule, i)) {
			count[1]++;
			firstRulesPassed = true;
		}
		else if (!firstRulesPassed) {
			count[0]++;
		}
	}
	count[2] += (rule.size() - count[0] - count[1]);
}

bool StrUtils::isLetter(std::string word, unsigned int pos) {
	std::string letters = "abcdefghijklmnopqrstuvwxyz";
	for (int i=0;i<26;i++)
		if (word[pos] == letters[i])
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
	std::string consonant = "bcdfghjklmnpqrstvwxz";
	for (int i=0;i<20;i++)
		if (word[pos] == consonant[i])
			return true;
	return false;
}

bool StrUtils::checkLetter(std::string word, int letter, unsigned int pos) {
	if (word.size() <= pos)
		return false;
	if ((int)word[pos] == (letter+32))
		return true;
	return false;
}

bool StrUtils::doubleLetter(std::string word, unsigned int pos) {
	if (pos == 0)
		return false;
	if (word.size() <= pos)
		return false;
	if (word[pos] == word[pos-1])
		return true;
	return false;
}

bool StrUtils::endChar(std::string word, unsigned int pos) {
	if (pos >= word.size())
		return true;
	if (!isLetter(word, pos))
		return true;
	return false;
}