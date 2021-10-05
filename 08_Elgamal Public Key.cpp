// Key Generation
/*
prime number P
primitive root of P is g
receiver random number b
then computes B = g^b
receiver sends P, g and B to Sender
*/

// Encryption
/*
sender random number a
secret key s1 = B^a
compute A = g^a
encrypted text E = (message converted into number) * s1
sender sends A and E to receiver
*/

// Decryption
/*
secret key s2 = A^b
find 1/s2
decrypted text D = E * s2
*/

#include<iostream>
#include<math.h>
#include<sstream>
using namespace std;

// num to string
string numTostring(double a) {
    string text;
    stringstream ss;
    ss << a;
    text = ss.str();
    return text;
}

// string to num
int stringTonum(string text) {
    double value = 0;
    stringstream ss(text);
    ss >> value;
    return value;
}

int main(){
    string c_letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s_letter = "abcdefghijklmnopqrstuvwxyz";
    string msg = "HI";
    string msg_num;
    double pos;

    // convert message characters into number string
    for(int i = 0; i < msg.size(); i++){
        if(isupper(msg[i])){
            pos = c_letter.find(msg[i])+1;
            msg_num += numTostring(pos);
        }
        else{
            pos = s_letter.find(msg[i])+1;
            msg_num += numTostring(pos);
        }
    }

    // Key Generation

    double P = 101;     // prime number
    double g = 3;       // primitive root

    // Receiver random number b (private key)
    double b = 2;
    double B = pow(g, b);
    // Receiver sends P, g and B to Sender

    // Encryption

    // Sender random number a
    double a = 6;
    double s1 = pow(B, a);      // secret key (Sender)
    double A = pow(g, a);
    double E = stringTonum(msg_num) * s1;       // encrypted number = message * secret key(sender)
    // Sender sends A and X to Receiver

    // Decryption

    double s2 = pow(A, b);      // secret key (Receiver)
    s2 = 1/s2;
    double D = E * s2;      // encrypted text * secret key(receiver)

    cout << "Prime number: " << P << endl;
    cout << "Primitive root of " << P <<": " << g << endl;
    cout << "Message: " << msg << endl;
    cout << "Message number: " << msg_num << endl;
    cout << "Receiver random number: " << b << endl;
    cout << "Sender random number: " << a << endl;
    cout << "Encrypted number: " << E << endl;
    cout << "Decrypted number: " << D << endl;

    return 0;
}
