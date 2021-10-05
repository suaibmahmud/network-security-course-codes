// generate public key
/*
two prime number P and Q
public key n = P*Q
*/

// generate private key
/*
X(n) = (P-1)(Q-1)
e will be an integer and not factor of X(n)
1 < e < X(n)
private key d
choosing d such that it satisfies (d*e) mod X(n) = 1
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

    // prime numbers should be large
    double p = 10789, q = 10799;
    double pos, e=2;

    string msg, msg_num;
    string c_letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s_letter = "abcdefghijklmnopqrstuvwxyz";

    cout << "Enter message: ";
    cin >> msg;

    // public key n
    double n = p*q;
    double phi = (p-1)*(q-1);

    // calculate value of e
    while(e < phi) {
        if (fmod(phi, e) == 0) // % is only for integers, fmod used for float or double
            e++;
        else
            break;
    }

    // private key d
    // d = (1/e) mod phi
    double d = fmod((1/e), phi);

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

    // store number string to double
    double number = stringTonum(msg_num);

    //encrypted and decrypted number
    // Rule: (character position numbers)^e mod n
    // Rule: (encrypted number)^d mod n
    double en = pow(number, e);
    double de = pow(en, d);
    en = fmod(en, n);
    de = fmod(de, n);

    cout << "Message number: " << number << endl;
    cout << "Encrypted number: " << en << endl;
    cout << "Decrypted number: " << de;

    return 0;
}
