#ifndef VCIPHER_H_
#define VCIPHER_H_
#include "cipher.h"
#include "kcipher.h"

using namespace std;

/* A class that implements a
   Vigenere cipher class. It 
   inherts KCipher */
// TODO: Implement this class
class VCipher: public KCipher
{
public:
	VCipher();
	VCipher(string keyword);
	~VCipher();
	virtual string encrypt(string raw);
	virtual string decrypt(string enc);
};
#endif

