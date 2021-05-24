#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"


// -------------------------------------------------------
// Caesar Cipher implementation
struct Cipher::CipherCheshire 
{
	string cipher_alpha;
};

CCipher::CCipher() : Cipher()
{
}


CCipher::CCipher(int offset) : Cipher() 
{
	if(offset < 0)
	{
		cerr << "Error: Caesar cipher is less than 0" << endl;
		exit(EXIT_FAILURE);
	}
	rotate_string(smile->cipher_alpha, offset);
}

string CCipher::encrypt(string raw) 
{
	return Cipher::encrypt(raw);
}

string CCipher::decrypt(string enc)
{
	return Cipher::decrypt(enc);
}

CCipher::~CCipher()
{
}
// -------------------------------------------------------


/* Rotates (shifts forward) the input string in_str by rot positions
 * 
 * (step 1) Does so by reversing the first subsection of the string (indices
 * 0 to rot - 1),  (step 2) then reversing the second subsection of the string
 * (indices rot to length of in_str - 1). 
 *
 * Reverses each subsection by swapping first and last indices
 * until entire string is reversed (size of the subsection // 2).
 *
 * (step 3) Once there each subsection is reversed, the entire resulting string 
 * is reversed using the same method. This combined effort results in a 
 * rotated string.
 *
 * e.g. shift the array [1, 2, 3, 4, 5, 6] by 2 (match steps above with steps below)
 *
 * step 1: [2, 1, 3, 4, 5, 6]
 * step 2: [2, 1, 6, 5, 4, 3]
 * step 3: [3, 4, 5, 6, 1, 2]
 * 
 */ 
void rotate_string(string& in_str, int rot)
{
	// TODO: You will likely need this function. Implement it.
    	// Reverse the first subsection of the string
	char tmp;
	long unsigned int i;
	unsigned int first_iter;

	// a rotation of >= 26 is equivalent to some rotation between 0 and 25
	if(rot >= 26)
	{
		rot = rot % 26;
	}

	first_iter = (unsigned int) rot / 2;

	for(i = 0; i < first_iter; i++) 
    	{
		tmp = in_str[rot - 1 - i];
		in_str[rot - 1 - i] = in_str[i];
		in_str[i] = tmp;
    	}

	// Reverse the second subsection of the string
	long unsigned int length = in_str.length();
	unsigned int second_iter = (unsigned int) (length - rot) / 2;

	for(i = 0; i < second_iter; i++) 
	{
		tmp = in_str[length - 1 - i];
		in_str[length - 1 - i] = in_str[rot + i];
		in_str[rot + i] = tmp;
	}

	// Rotate the string based on reversal
	unsigned int third_iter = (unsigned int) length / 2;
	for(i = 0; i < third_iter; i++) 
	{
		tmp = in_str[length - 1 - i];
		in_str[length - 1 - i] = in_str[i];
		in_str[i] = tmp;
	}
}
