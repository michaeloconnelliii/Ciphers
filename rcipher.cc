#include <string>
#include <iostream>
#include "rcipher.h"

// -------------------------------------------------------
// Caesar Cipher implementation
// -------------------------------------------------------

struct Cipher::CipherCheshire {
	string cipher_alpha;
};

RCipher::RCipher() : CCipher(13)
{
}
string RCipher::encrypt(string raw)
{
	return CCipher::encrypt(raw);
}
string RCipher::decrypt(string enc)
{
	return CCipher::decrypt(enc);
}
RCipher::~RCipher()
{
}
