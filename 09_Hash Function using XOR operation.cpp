#include<iostream>
#include<string>
#include<sstream>
using namespace std;

unsigned int SHF(string msg){
    unsigned int num = 69172846;      // random number
    unsigned int Hash;

    // generate hash value using XOR operation
    // ^ is XOR operator
    for(int i=0; i<msg.length(); i++){

        // XOR each byte of message
        // msg[i] letter ASCII value is used for XOR
        Hash = Hash ^ (msg[i]);
        Hash = Hash * num;
    }
    return Hash;
}

// Hash in hex format
string toHEX(unsigned int Hash){
    string hexHash;
    stringstream ss;
    ss << hex << Hash;       // here hex is format
    hexHash = ss.str();

    // uppercase
    for(int i=0; i<hexHash.length(); i++)
        hexHash[i] = toupper(hexHash[i]);

    return hexHash;
}

int main(){
    string msg;
    cout << "Message: ";
    cin >> msg;
    string Hash = toHEX(SHF(msg));
    cout << "Hash value: " << Hash;

    return 0;
}
