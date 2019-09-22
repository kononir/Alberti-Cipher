#pragma once

#include <string>
#include <map>

using namespace std;

class AlbertiDisk
{
private:
	map<char, char> replacementsMap;

	map<char, char> invertMap();
public:
	AlbertiDisk(string fixedAlphabet, string movedAlphabet);
	~AlbertiDisk();

	string encryptText(string text);
	string decryptText(string text);

	void turnMovedDiskRight();
	void turnMovedDiskLeft();

	string printDisk();
};

