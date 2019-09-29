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

	/* building map of replacements */
	for (unsigned int i = 0; i < fixedAlphabet.length(); i++) {
		replacementsMap.insert(pair<char, char>(fixedAlphabet.at(i), movedAlphabet.at(i)));
	}

	this->fixedAlphabet = fixedAlphabet;
	this->movedAlphabet = movedAlphabet;
}


AlbertiDisk::~AlbertiDisk()
{
}

/* encryption by map of replacements; building new string */
string AlbertiDisk::encryptText(string text)
{
	string encryptedText;
	for (unsigned int i = 0; i < text.length(); i++) {
		encryptedText = encryptedText + replacementsMap.at(text.at(i));
	}

	return encryptedText;
}

/* decryption by map of replacements; building new string */
string AlbertiDisk::decryptText(string text)
{
	map<char, char> invertedMap = invertMap();

	string decryptedText;
	for (unsigned int i = 0; i < text.length(); i++) {
		decryptedText = decryptedText + invertedMap.at(text.at(i));
	}

	return decryptedText;
}

string AlbertiDisk::findKey(string ciphertext, string originalText)
{
	string decryptedText;

	string nextPermutation = movedAlphabet;
	while (true) {
		replacementsMap.clear();
		/* building map of replacements */
		for (unsigned int i = 0; i < fixedAlphabet.length(); i++) {
			replacementsMap.insert(pair<char, char>(fixedAlphabet.at(i), nextPermutation.at(i)));
		}

		decryptedText = decryptText(ciphertext);
		if (decryptedText == originalText) {
			break;
		}

		next_permutation(nextPermutation.begin(), nextPermutation.end());
	}

	return nextPermutation;
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

void AlbertiDisk::shuffleMovedDisk()
{
	string alphabet = movedAlphabet;

	random_device rd;
	mt19937 mersenne(rd());
	shuffle(alphabet.begin(), alphabet.end(), mersenne);

	replacementsMap.clear();

	/* building map of replacements */
	for (unsigned int i = 0; i < fixedAlphabet.length(); i++) {
		replacementsMap.insert(pair<char, char>(fixedAlphabet.at(i), alphabet.at(i)));
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


