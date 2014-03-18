#ifndef PHONO_H
#define PHONO_H

/*
==========RULES==========
/ no vowel
- is vowel
~ is consonant
< same letter
A-Z is a-z
*/

static const std::string phonetics[28][5] = {
	{"a",	"a",	"Oi",	"",		""},
	{"eu",	"e",	"eu",	"oe",	""},
	{"i",	"i",	"y",	"ill",	""},
	{"o",	"o",	"au",	"eau",	""},
	{"u",	"u",	"",		"",		""},
	{"in", 	"in/",	"un/",	"ain/",	"ein/"},
	{"on", 	"on/",	"",		"",		""},
	{"ou", 	"ou",	"oI",	"",		""},
	{"ai", 	"ai", 	"e~<", 	"",		""},
	{"an", 	"an/", 	"en/", 	"",		""},
	{"b", 	"b",	"",		"",		""},
	{"k", 	"c",	"k",	"q",	"qu"},
	{"ch",	"ch",	"sh",	"",		""},
	{"d", 	"d",	"",		"",		""},
	{"f", 	"f",	"ph",	"",		""},
	{"g", 	"g",	"gu",	"",		""},
	{"gn",	"gn",	"",		"",		""},
	{"j", 	"j",	"ge",	"",		""},
	{"l", 	"l",	"ll",	"",		""},
	{"m", 	"m",	"mm",	"",		""},
	{"n", 	"n",	"nn",	"",		""},
	{"p", 	"p",	"pp",	"",		""},
	{"r", 	"r",	"rr",	"",		""},
	{"s", 	"s",	"ss",	"tION",	"sc-"},
	{"t", 	"t",	"tt",	"",		""},
	{"v", 	"v",	"w",	"",		""},
	{"x", 	"x",	"",		"",		""},
	{"z", 	"z",	"-s-",	"",		""}
};

#endif
