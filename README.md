# Ciphers

## Background
### Encyrption and Decryption
* Encryption is the process of encoding a message or information in such a way that only authorized parties can access it and those who are not authorized cannot.

* Decryption is the process of decoding an encoded message (so that the authorized parties can read it).

### Ciphers
* A cipher is a set of steps (an algorithm) for perofrming both an encryption, and the corresponding decryption. 

#### Subsitution Cipher
* In a subsitution cipher every character in the normal alphabet is replaced by another. Therefore, the corresponding "cipher alphabet" has every character in the normal alphabet, but in a different order.

* For example:
    * plain alphabet:  abcdefghijklmnopqrstuvwxyz
    * cipher alphabet: phqgiumeaylnofdxjkrcvstzwb
    * The phrase "defend the east wall of the castle" becomes "giuifg cei iprc tpnn du cei qprcni"

#### Caesar Cipher
* A Substitution Cipher where the normal alphabet is "shifted" by some amount.

* For example, a Caesar Cipher with a shift of 1:
    * plain alphabet:  abcdefghijklmnopqrstuvwxyz
    * cipher alphabet: bcdefghijklmnopqrstuvwxyza
    * The phrase "hello friends" becomes "ifmmp gtjfoet"

#### ROT13 Cipher
* A Caesar Cipher with a shift of 13.

* For example:
    * plain alphabet:  abcdefghijklmnopqrstuvwxyz
    * cipher alphabet: nopqrstuvwxyzabcdefghijklm
    * The phrase "attack at dawn" becomes "nggnpx ng qnja"

#### Vigenere Cipher
* "Polyalphabetic substitution cipher", but that's not very helpful for most readers. Let's use an example instead. We need a phrase to encrypt (as usual), a keyword, and a "tableau". Let's define "tableau" and then describe the algorithm.

* A "tableau" is a 26 x 26 matrix where each row is a caesar cipher alphabet incrementally shifted. The first row has a shift of 0, the next has a shift of 1 and so on. <br>
![ScreenShot](/screenshots/tableau.png)

1. Repeat the keyword above the text:
    * Keyword: FORTIFICATION
    * Text:    DEFENDTHEEASTWALLOFTHECASTLE
    * Together: 
        * FORTIFICATIONFORTIFICATIONFO
        * DEFENDTHEEASTWALLOFTHECASTLE

2. For each letter of the text, find it along the x-axis of the tableau. For the corresponding keyword letter, find it along the y-axis of the tableau. The intersection is the ciphertext character. 
    * Repeating keyword:    FORTIFICATIONFORTIFICATIONFO
    * Text:                 DEFENDTHEEASTWALLOFTHECASTLE
    * Resulting ciphertext: ISWXVIBJEXIGGBOCEWKBJEVIGGOS

#### Running Key Cipher
* A Vigenere Cipher that uses a longer key (instead of a keyword, a key phrase). An example of a key is an excerpt from a book.

## Project Overview
* Implement the ciphers above using object-oriented programming (OOP). OOP is desired because of the natural inheritance hierarchy of the ciphers.<br>
![ScreenShot](/screenshots/inheritance.png)

* The program will take allow a user to input a message they would like to encrypt in a .txt file and specify the type of cipher they would like to use for the encryption. Additional details regarding the encryption will also need to be the .txt input file (see "How to use" below).

* The program will encypt the message using the appropriate cipher and output a file with the encrypted result.

## What is in this repository
* test1, test2, and test3_error
    * sample input and output files for testing
* Encryption101.pdf
    * Original specifications for the project.
* Makefile
    * Makefile recipe. Creates a 'cipher' executable.
* cipher.c, cipher.h
    * Main class that all other cipher classes inherit from (Substitution cipher). Contains the encrypt and decrypt methods that the Caesar Cipher and ROT13 classes use. 
* ccipher.cc, ccipher.h
    * Caesar Cipher class, inherits from Substitution Cipher and contains the rotate string method utilized in the ROT13 Cipher class.
* rcipher.cc, rcipher.h
    * ROT13 Cipher class, inherits from Caesar Cipher.
* kcipher.cc, kcipher.h
    * Running Key Cipher class. Inherits from Substitution Cipher.Contains encrypt and decrypt methods that utilize the tableau as well as a "book" member that allows for key words/key phrases.
* vcipher.cc, vcipher.h
    * Vigenere Cipher class. Inherits from Running Key Cipher. The "book" member described above is utilized for a repeating keyword.

## Implementation Details
This program uses the "Cheshire smile" technique for data hiding. Because encryption is a sensitive topic (we may not want the client to see our implementation details), we can "hide" private data members by wrapping them in a protected struct. This allows us to implement the struct (and the rest of the class) in the source code, compile it, and then only provide a client with an API/libarary with the header in order to facilitate an interface. This way, the client won't actually know what's inside the class. In other words, they'll only know of the single pointer "smile", not what it points to.

## How to use
1. Create an executable using the Makefile provided.
2. Example command: $ ./cipher -m c -i caesar.txt -o caesar_out.txt
    * './cipher' is the executable name
    * '-m c' means you are using the Caesar cipher method
    * '-i  caesar.txt' specifies that caesar.txt is the input file
    * '-o caesar.out' specifies that caesar.out is the output file
3. 'caesar.out' will have the encrypted message. The program will also generate def_caesar_out.txt which contains the cipher text and decrypted text when the Caesar cipher object was created using the default constructor (i.e. encryption is done using the 0 shift).

* The shortcuts for the 'm' flag above are as follows:
    * s = Substitution
    * c = Caesar
    * r = ROT13
    * k = Running Key
    * v = Vigenere

### Input files
* A substitution input file must have the cipher alphabet you'd like to use in line 1 and the message you'd like to encrypt in line 2. 

* A Caesar input file must have the amount you'd like to shift in line 1 and the message you'd like to encrypt in line 2.

* A ROT13 input file only needs the message you'd like to encrypt in line 1.

* A Vigenere input file needs to have the key you'd like to use in line 1 and the message you'd like to encrypt in line 2.

* A Running Key input file needs to have the number of lines the key you'd like to use are in line 1, the key you'd like to use in lines 2-2 + however many lines the key is, and the lines afterword are the message you'd like to encrypt.

* If there is any confusion on the formatting of the input files described, please see the test1 or test2 directory and look at the input files.

## System Information
* The program was tested and run on a virtual machine (VirtualBox Version 6.0.24) running Linux Mint 19.3 MATE.

## Aknowledgements
This project was for CIS 330, C, C++ and Unix at University of Oregon, Winter 2020.

Professor Jee Choi created the initial version (skeleton code and tests) and project specifications.