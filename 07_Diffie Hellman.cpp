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
    double s, r;
    double P = 53;      // prime number must be large
    double G = 5;       // primitive root of P

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
    cout << "Prime number: " << P << endl;
    cout << "Primitive root of " << P << ": " << G << endl;

    // private key must be smaller than prime number
    cout << "Sender private key: ";
    cin >> s;
    cout << "Receiver private key: ";
    cin >> r;

    // Key Generation

    // Rule: Public key = (primitive root)^(private key) mod (prime number)
    // Sender public key
    double x = pow(G, s);
    x = fmod(x, P);
    // Receiver public key
    double y = pow(G, r);
    y = fmod(y, P);

    // Rule
    // First, exchange public key
    // Secret key = (public key)^(private key) mod (prime number)
    double ks = pow(y, s);      // Sender secret key
    ks = fmod(ks, P);

    double kr = pow(x, r);      // Receiver secret key
    kr = fmod(kr, P);

    double E = stringTonum(msg_num) * ks;       // encrypted number = message * secret key(sender)
    double D = E * (1/kr);      // decrypted number = encrypted number * (1/secret key(receiver))

    cout << "Message: " << msg << endl;
    cout << "Message number: " << msg_num << endl;
    cout << "Sender secret key: " << ks << endl;
    cout << "Receiver secret key: " << kr << endl;
    cout << "Encrypted number: " << E << endl;
    cout << "Decrypted number: " << D << endl;

    return 0;
}
