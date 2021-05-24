#ifndef KCIPHER_H_
#define KCIPHER_H_
#include "cipher.h"
#include "ccipher.h"

using namespace std;

const unsigned int MAX_LENGTH = 100;

/* A class that implements a
   Running key cipher class. It 
   inherts class Cipher */
// TODO: Implement this function
class KCipher : public Cipher
{
protected:
	struct KCipherCheshire;
	KCipherCheshire* k_smile;
public:
	KCipher();
	KCipher(string page);
	~KCipher();
	void add_key(string page);
	void set_id(unsigned int page);
	virtual string encrypt(string raw);
	virtual string decrypt(string enc);
};

void valid_page(string page);
#endif

