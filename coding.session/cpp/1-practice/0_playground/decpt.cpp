// CPP program to implement
// ROT13 Caesar Cipher

#include<bits/stdc++.h>
using namespace std;

// Map to lookup the index of alphabets
map <char,int> dict1;

// Map to lookup alphabets corresponding
// to the index after shift
map <int,char> dict2;

// Function to create map to lookup
void create_dict()
{
	for(int i = 1; i < 27; i++)
		dict1[char(64 + i)] = i;
	
	dict2[0] = 'Z';
	
	for(int i = 1; i < 26; i++)
		dict2[i] = char(64 + i);
		
	return;
}

// Function to encrypt the string
// according to the shift provided
string encrypt(string message, int shift)
{
	string cipher = "";
	for(int i = 0; i < message.size(); i++)
	{
		// Checking for namespace
		if(message[i] != ' ')
		{
			// looks up the map and
			// adds the shift to the index
			int num = (dict1[message[i]] + shift) % 26;
			
			// looks up the second map for the
			// shifted alphabets and adds them
			cipher += dict2[num];
		}
		else
		{
			// adds space
			cipher += " ";
		}
	}
	return cipher;
}

// Function to decrypt the string
// according to the shift provided
string decrypt(string message, int shift)
{
	string decipher = "";
	for(int i = 0; i < message.size(); i++)
	{
		// checks for space
		if(message[i] != ' ')
		{
			// looks up the map and
			// subtracts the shift to the index
			int num = (dict1[message[i]] - shift + 26) % 26;
			// looks up the second map for the
			// shifted alphabets and adds them
			decipher += dict2[num];
		}
		else
		{
			// adds space
			decipher += " ";
		}
	}
	return decipher;
}

// Driver code
int main()
{
	create_dict();
	
	string message = "GEEKS FOR GEEKS";
	int shift = 13;
	
	cout << encrypt(message, shift) << "\n";
	
	message = "TRRXF SBE TRRXF";
	shift = 13;
	
	cout << decrypt(message, shift) << "\n";
	
	return 0;
}
// This code is contributed by Sachin Bisht
