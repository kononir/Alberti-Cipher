#include "pch.h"
#include <algorithm>
#include <random>
#include <ctime>
#include "AlbertiDisk.h"

map<char, char> AlbertiDisk::invertMap()
{
	map<char, char> invertedMap;
	for (auto it = replacementsMap.begin(); it != replacementsMap.end(); ++it) {
		invertedMap.insert(pair<char, char>(it->second, it->first));
	}
	return invertedMap;
}

AlbertiDisk::AlbertiDisk(string fixedAlphabet, string movedAlphabet)
{
	if (fixedAlphabet.length() != movedAlphabet.length() || fixedAlphabet.length() == 0) {
		throw "Wrong arguments! (fixedAlphabet > 0, movedAlphabet > 0, fixedAlphabet = movedAlphabet)";
	}

	random_device rd;
	mt19937 mersenne(rd());
	shuffle(movedAlphabet.begin(), movedAlphabet.end(), mersenne);

	/* building map of replacements */
	for (unsigned int i = 0; i < fixedAlphabet.length(); i++) {
		replacementsMap.insert(pair<char, char>(fixedAlphabet.at(i), movedAlphabet.at(i)));
	}
}


AlbertiDisk::~AlbertiDisk()
{
}

string AlbertiDisk::encryptText(string text)
{
	/* encryption by map of replacements; building new string */
	string encryptedText;
	for (unsigned int i = 0; i < text.length(); i++) {
		encryptedText = encryptedText + replacementsMap.at(text.at(i));
	}

	return encryptedText;
}

string AlbertiDisk::decryptText(string text)
{
	/* decryption by map of replacements; building new string */
	map<char, char> invertedMap = invertMap();

	string decryptedText;
	for (unsigned int i = 0; i < text.length(); i++) {
		decryptedText = decryptedText + invertedMap.at(text.at(i));
	}

	return decryptedText;
}

/* turn values of map right to one position */
void AlbertiDisk::turnMovedDiskRight()
{
	map<char, char> movedMap;
	auto lastEl = replacementsMap.rbegin();
	char turnValue = lastEl->second;
	for (auto it = replacementsMap.begin(); it != replacementsMap.end(); ++it) {
		char currValue = it->second;
		it->second = turnValue;
		turnValue = currValue;
	}
}

/* turn values of map left to one position */
void AlbertiDisk::turnMovedDiskLeft()
{
	map<char, char> movedMap;
	auto beginIt = replacementsMap.begin();
	char turnValue = beginIt->second;
	for (auto it = replacementsMap.rbegin(); it != replacementsMap.rend(); ++it) {
		char currValue = it->second;
		it->second = turnValue;
		turnValue = currValue;
	}
}

string AlbertiDisk::printDisk()
{
	string printedDisk;
	for (auto it = replacementsMap.begin(); it != --replacementsMap.end(); ++it) {
		printedDisk = printedDisk + it->first + "-" + it->second + ", ";
	}

	auto it = --(replacementsMap.end());
	printedDisk = printedDisk + it->first + "-" + it->second + "\n";

	return printedDisk;
}


