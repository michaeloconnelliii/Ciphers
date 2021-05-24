#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"


// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------
void valid_keyword(string keyword);

struct KCipher::KCipherCheshire
{
	vector <string> book;
	unsigned int id;
};

VCipher::VCipher() : KCipher()
{
}

VCipher::VCipher(string keyword): KCipher(keyword)
{
	valid_keyword(keyword);
}

VCipher::~VCipher()
{
}

string VCipher::encrypt(string raw)
{
	if(k_smile->book.size() > 0)
	{
		// make keyword the same size (or larger) as what you're encrypting
		while(k_smile->book[0].length() < raw.length())
		{
			k_smile->book[0] += k_smile->book[0];
		}

		// now that keyword repitition is larger, call encrypt
	}

	return KCipher::encrypt(raw);

}

string VCipher::decrypt(string enc)
{
	return KCipher::decrypt(enc);
}

void valid_keyword(string keyword) 
{	
	// checks for special characters
	valid_page(keyword);

	// checking for blank spaces
	for(char& c: keyword)
	{
		if(c == ' ')
		{
			cerr << "Error: not a valid Vigenere key word" << endl;
			exit(EXIT_FAILURE);
		}
	}
}

