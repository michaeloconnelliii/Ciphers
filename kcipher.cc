#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"




/* Helper function definitions
 */
void valid_page(string page);

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------
struct KCipher::KCipherCheshire 
{
	vector <string> book;
	unsigned int id;
};

struct Cipher::CipherCheshire
{
	string cipher_alpha;
};

void KCipher::add_key(string page)
{
	// is page valid? (no characters other than lower-case or spaces)
	valid_page(page);

	(k_smile->book).push_back(page);
}
void KCipher::set_id(unsigned int page)
{
	if(page > (k_smile->book).size())
	{
		cerr << "Error: Index exceeds number of pages in book" << endl;
		exit(EXIT_FAILURE);
	}

	k_smile->id = page;

}

KCipher::KCipher()
{
	k_smile = new KCipherCheshire;
	k_smile->id = 0;
}

KCipher::KCipher(string page) : Cipher()
{
	// is page valid? (no characters other than lower-case or spaces)
	valid_page(page);

	k_smile = new KCipherCheshire;
	(k_smile->book).push_back(page);
	k_smile->id = 0;
}

KCipher::~KCipher()
{
	delete k_smile;
}

string KCipher::encrypt(string raw)
{
	if(k_smile->book.size() == 0)
	{
		cout << "Encrypting...";
		cout << "Done" << endl;
		return Cipher::encrypt(raw);
	}
	
	// Is key longer than or equal to text you're trying to encrypt? (not counting spaces)
	unsigned int key_non_ws_count = 0;
	unsigned int raw_non_ws_count = 0;	
	for(char& c: ((k_smile->book)[k_smile->id]))
	{
		if(c != ' ') 
		{
			key_non_ws_count++;
		}

	}
	for(char& c: raw) 
	{
		if(c != ' ') 
		{
			raw_non_ws_count++;
		}
	}

	if(raw_non_ws_count > key_non_ws_count) 
	{
		cerr << "Error: Key is not longer than or equal to text you're trying to encrypt (not counting the spaces)" << endl;
		exit(EXIT_FAILURE);
	}

	// encrypting
	cout << "Encrypting...";
	unsigned int raw_ind = 0; 
	unsigned int key_ind = 0;
	unsigned int shift_index = 0;
	unsigned int lookup_index = 0;
	bool upper;
	string shift_alpha;
	string ret_str;


	for(long unsigned int i = 0; i < raw.length(); i++)
	{
		upper = false;
		
		if(raw_ind >= raw.length() or key_ind >= ((k_smile->book)[k_smile->id]).length())
		{
			break;
		}

		if(raw[raw_ind] == ' ')
		{
			ret_str += ' ';
			raw_ind++;
		}
		
		if(isupper(raw[raw_ind]))
		{
			raw[raw_ind] = tolower(raw[raw_ind]);
			upper = true;
		}

		if((k_smile->book)[k_smile->id][key_ind] == ' ')
		{
			key_ind++;
		}	
	
		// generating tableau on the fly
		shift_index = find_pos(smile->cipher_alpha, (k_smile->book)[k_smile->id][key_ind]);
		shift_alpha = smile->cipher_alpha;

		rotate_string(shift_alpha, shift_index);

		// lookup
		lookup_index = find_pos(smile->cipher_alpha, raw[raw_ind]);
		
		if(upper)
		{
			ret_str += toupper(shift_alpha[lookup_index]);
		}
		else
		{
			ret_str += shift_alpha[lookup_index];
		}

		raw_ind++;
		key_ind++;
		
	}	

	cout << "Done" << endl;

	return ret_str;
}


string KCipher::decrypt(string enc)
{
	cout << "Decrypting...";
	if(k_smile->book.size() == 0)
	{
		cout << "Done." << endl;
		return Cipher::decrypt(enc);
	}
	// get position in key for enc msg
	unsigned int shift_ind, dec_ind;
	unsigned int key_ind = 0;
	unsigned int enc_ind = 0;
	string ret_str;
	bool upper;

	for(long unsigned int i = 0; i < enc.length(); i++) 
	{
		upper = false;

		if(enc_ind >= enc.length())
		{
			break;
		}

		string shift_alpha = smile->cipher_alpha;
		
		if(enc[enc_ind] == ' ')
		{
			ret_str += ' ';
			enc_ind++;
		}
		
		if((k_smile->book)[k_smile->id][key_ind] == ' ')
		{
			key_ind++;
		}

		if((isupper(enc[enc_ind])))
		{
			enc[enc_ind] = tolower(enc[enc_ind]);
			upper = true;
		}	

		shift_ind = find_pos(smile->cipher_alpha, (k_smile->book)[k_smile->id][key_ind]);
		
		rotate_string(shift_alpha, shift_ind);
		dec_ind = find_pos(shift_alpha, enc[enc_ind]);

		if(upper) 
		{
			ret_str += toupper(smile->cipher_alpha[dec_ind]);
		}
		else
		{
			ret_str += smile->cipher_alpha[dec_ind];
		}
		key_ind++;
		enc_ind++;

	}

	cout << "Done." << endl;

	return ret_str;
}

void valid_page(string page) 
{
	if(page.length() <= 0)
	{
		cerr << "Error: Page is empty string" << endl;
		exit(EXIT_FAILURE);
	}

	for(char const &c: page)
	{
		if(not islower(c) and c != ' ')
		{
			cerr << "Error: Invalid character found in page (not a space and not a lower-case character)" << endl;
			exit(EXIT_FAILURE);
		}
		
	}
}

