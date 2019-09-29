#pragma once

#include <string>
#include <map>

using namespace std;

class AlbertiDisk
{
private:
	string fixedAlphabet;
	string movedAlphabet;

	map<char, char> replacementsMap;

	map<char, char> invertMap();
public:
	AlbertiDisk(string fixedAlphabet, string movedAlphabet);
	~AlbertiDisk();

	string encryptText(string text);
	string decryptText(string text);

	string findKey(string ciphertext, string originalText);

	void turnMovedDiskRight();
	void turnMovedDiskLeft();
	void shuffleMovedDisk();

	string printDisk();
};

