// AlbertiCipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "AlbertiDisk.h"

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

int main()
{
	AlbertiDisk disk = AlbertiDisk(alphabet, alphabet);

	int choice;
	string message, ciphertext, decryptedMessage;
	while (true)
	{
		cout << "1 - Show alberti disk,\n 2 - Encrypt message,\n 3 - Turn disk right,\n 4 - Turn disk left,\n 0 - Exit\n\n";
		choice = _getch();

		switch (choice)
		{
		case 49:
			cout << "Disk:" << endl;
			cout << disk.printDisk() << endl;
			break;
		case 50:
			cout << "Enter message:" << endl;
			cin >> message;

			ciphertext = disk.encryptText(message);
			cout << endl << "Ciphertext:" << endl;
			cout << ciphertext << endl << endl;

			decryptedMessage = disk.decryptText(ciphertext);
			cout << "Decrypted message:" << endl;
			cout << decryptedMessage << endl << endl;
			break;
		case 51:
			disk.turnMovedDiskRight();
			break;
		case 52:
			disk.turnMovedDiskLeft();
			break;
		case 48:
			return 0;
		default:
			break;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file