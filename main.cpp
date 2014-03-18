#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "phonetics.h"
#include "const.h"
#include "strUtils.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: need one argument (string)." << std::endl;
		return -1;
	}
	std::string phoned = "";
	std::string toPhon = argv[1];
	unsigned int pos = 0;
	/*int y[3];
	StrUtils::ruleLength("-!As-", y);
	std::cout << "Test: " << y[0] << y[1] << y[2] << std::endl;*/
	while (toPhon.size() > pos) {
		int toCut = std::min(3, (int)(toPhon.size()-pos));
		bool testSucced = false;
		while (toCut > 0) {
			for (int i=0;i<28;i++) {
				for (int j=0;j<4;j++) {
					if (StrUtils::compare(phonetics[i][TRAN+j], toPhon, pos, toCut)) {
						testSucced = true;
						phoned += (" " + phonetics[i][PHON]);
						pos += toCut;
						break;
					}
				}
				if (testSucced)
					break;
			}
			if (testSucced)
				toCut = -1;
			else
				toCut--;
		}
		if (toCut == 0) {
			phoned += " !";
			phoned += toPhon[pos];
			phoned += "?";
			pos ++;
		}
	}
	std::cout << "Phonétisation: " << phoned << "." << std::endl;
	return 0;
}
