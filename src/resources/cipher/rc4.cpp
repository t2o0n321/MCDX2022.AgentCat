/**
* https://github.com/elidill653/RC4-Stream-Cipher
*/
#include "rc4.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string decrypt(vector<int> s, string p)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int k = 0;

	int b;
	int c;

	int* plain = new int[p.length()];
	string plain_T;

	for (int r = 0; r < int(p.length()); r++)
	{

		i = (i + 1) % 256;
		j = (j + s[i]) % 256;

		// swap section
		b = s[i];
		s[i] = s[j];
		s[j] = b;

		tmp = (s[i] + s[j]) % 256;
		k = s[tmp];

		c = ((int)p[r] ^ k); // cast the p string as and int then xor with k

		plain[r] = c;

		plain_T += (char)plain[r]; // Cast plaintext int array as a char
	}
	return plain_T;
}

/**
* S vector, T vector, plaintext
*/
string encrypt(vector<int> s, string p)
{

	int i = 0;
	int j = 0;
	int tmp = 0;
	int k = 0;

	//Temp variables
	int b;
	int c;

	int* cipher = new int[p.length()];
	string cipher_T;

	for (int r = 0; r < int(p.length()); r++)
	{

		i = (i + 1) % 256;
		j = (j + s[i]) % 256;

		// swap section
		b = s[i];
		s[i] = s[j];
		s[j] = b;

		tmp = (s[i] + s[j]) % 256;
		k = s[tmp];

		c = ((int)p[r] ^ k); //Cast p char as an int then xor with k

		cipher[r] = c;

		cout << cipher[r] << " ";

		cipher_T += (char)cipher[r]; //cast int as char then append to string
	}
	cout << endl;
	return cipher_T;
}

vector<int> permute(vector<int> s, vector<int> t)
{
	int j = 0;
	int tmp;
	for (int i = 0; i < 256; i++)
	{
		j = (j + s[i] + t[i]) % 256;

		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	return s;
}