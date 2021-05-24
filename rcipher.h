#ifndef RCIPHER_H_ 
#define RCIPHER_H_
#include "ccipher.h"

using namespace std;

/* A class that implements a
   ROT13 cipher class. It 
   inherts class CCipher */
// TODO: Implement this class
class RCipher : public CCipher
{
public:
	RCipher();
	~RCipher();
	virtual string encrypt(string raw);
	virtual string decrypt(string enc);
};
#endif

