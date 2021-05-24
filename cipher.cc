#include "cipher.h"

/* Cheshire smile implementation.
   It only contains the cipher alphabet
 */
struct Cipher::CipherCheshire {
    string cipher_alpha;
};

/* This function checks the cipher alphabet
   to make sure it's valid
 */
bool is_valid_alpha(string alpha);


// -------------------------------------------------------
// Cipher implementation
/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet

   *  Implementation:
   *  ---------------
   *  Allocates and initializes cipher alphabet as the normal alphabet
   *  using ASCII values (lower case).
 */
Cipher::Cipher()
{
    // TODO: Implement this default constructor
    smile = new CipherCheshire;
    long unsigned int i;

    for(i = 0; i < ALPHABET_SIZE; i++) 
    {
	    (smile->cipher_alpha) += " "; 

    }

    for(i = 0; i < ALPHABET_SIZE; i++)
    {
	    (smile->cipher_alpha)[i] = 'a' + i;
    }
}

/* This constructor initiates the object with a
   input cipher key

   *  Implementation:
   *  ---------------
   *  Allocates and initializes cipher alphabet with provided input cipher alphabet by
   *  copying the input into the object's cipher alphabet. 
   *
   *  Results in the object's cipher alphabet being equivalent to the inputted
   *  cipher alphabet.
 */
Cipher::Cipher(string cipher_alpha)
{
    // TODO: Implement this constructor
    smile = new CipherCheshire;
    long unsigned int i;

    for(i = 0; i < ALPHABET_SIZE; i++) 
    {
	    (smile->cipher_alpha) += " "; 

    }

    if(is_valid_alpha(cipher_alpha))
    {
	    // copying input cipher key to cipher_alpha
	    for(i = 0; i < ALPHABET_SIZE; i++) 
	    {
		    (smile->cipher_alpha)[i] = cipher_alpha[i];
	    }
    }
    else 
    {
	    cerr << "Invalid cipher alphabet/key" << cipher_alpha << endl;
	    exit(EXIT_FAILURE);
    }
}

/* Destructor
 *
 *  Implementation:
 *  ---------------
 *  Frees allocated memory for smile in constructor.
 */
Cipher::~Cipher()
{
    // TODO: Implement this constructor
    delete smile;
}

/* This member function encrypts the input text 
 * using the intialized cipher key
 * 
 *  Implementation:
 *  ---------------
 *  Gets normal alphabet index of each character in input string (raw) using ASCII values and 
 *  whether character is upper or lower case. If character is a space, space is preserved.
 *  
 *  Uses alphabet index to convert from normal alphabet to cipher alphabet.
 *  
 *  This works because cipher alphabet is normal alphabet replaced with different ordering of 
 *  characters.
 */
string Cipher::encrypt(string raw)
{
    cout << "Encrypting...";
    string retStr;
    // TODO: Finish this function
   
    // position in regular alphabet
    int pos;

    for(long unsigned int i = 0; i < raw.length(); i++)
    {
	    // is character a space?
	    if(raw[i] == ' ')
	    {
	    	    retStr += ' ';

		    // continue to next charcter
		    continue;
	    }

	    // is character upper or lower case?
	    else if(isupper(raw[i])) 
	    {
	            pos = (raw[i] - 'A');
	    	    // convert to cipher alphabet position using corresponding normal alphabet position
		    retStr += UPPER_CASE((smile->cipher_alpha)[pos]); 
	    }
	    
	    else if(islower(raw[i]))
	    {
	            pos = (raw[i] - 'a');
	    		// convert to cipher alphabet position using corresponding normal alphabet position
		    retStr += (smile->cipher_alpha)[pos];
	    }	
    }

    cout << "Done" << endl;

    return retStr;
}


/* This member function decrypts the input text 
   using the intialized cipher key
 */
string Cipher::decrypt(string enc)
{
    string retStr;
    cout << "Decrypting...";
    // TODO: Finish this function
    
    // position in cipher alphabet
    int pos;

    for(long unsigned int i = 0; i < enc.length(); i++) 
    {
	    // is the character a space? If so, keep the space
	    if(enc[i] == ' ') 
	    {
		    retStr += ' ';
		    continue;

	    }
	    // find position in cipher alphabet
	    pos = find_pos(smile->cipher_alpha, LOWER_CASE(enc[i]));

	    // convert to normal alphabet using ASCII Values, depends on lower or upper case
	    if(isupper(enc[i]))
	    {
		    retStr += 'A' + pos;
	    }
	    else if(islower(enc[i]))
	    {
		    retStr += 'a' + pos;
	    }
    }


    cout << "Done" << endl;

    return retStr;

}
// -------------------------------------------------------


//  Helper functions 
/* Find the character c's position in the cipher alphabet/key
 */
unsigned int find_pos(string alpha, char c)
{
    unsigned int pos = 0;

    // TODO: You will likely need this function. Finish it.
    for(long unsigned int i = 0; i < ALPHABET_SIZE; i++) 
    {
	    if(c == alpha[i])
	    {
		    pos = i;
		    // found c's position, no need to keep looking
		    break;
	    } 

    }

    return pos;
}

/* Make sure the cipher alphabet is valid - 
   a) it must contain every letter in the alphabet 
   b) it must contain only one of each letter 
   c) it must be all lower case letters 
   ALL of the above conditions must be met for the text to be a valid
   cipher alphabet.
 */
bool is_valid_alpha(string alpha)
{
    bool is_valid = true;
    if(alpha.size() != ALPHABET_SIZE) {
        is_valid = false; 
    } else {
        unsigned int letter_exists[ALPHABET_SIZE];
        for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            letter_exists[i] = 0;
        }
        for(unsigned int i = 0; i < alpha.size(); i++) {
            char c = alpha[i];
            if(!((c >= 'a') && (c <= 'z'))) {
                is_valid = false;
            } else {
                letter_exists[(c - 'a')]++;
            }
        }
        for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            if(letter_exists[i] != 1) {
                is_valid = false;
            }
        }
    }

    return is_valid;
}
