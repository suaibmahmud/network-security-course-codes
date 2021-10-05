#include<iostream>
#include<string>
using namespace std;

// generate key
string get_Key(string msg, string keyword){
    string key, keyUp;
    for(int i=0; ; i++){
        if(keyword.length()==i)
            i=0;
        else if(keyword.length()==msg.length() || key.length()==msg.length())
            break;
        key += keyword[i];
    }
    // upper case
    for(int i=0; i<key.length(); i++)
        keyUp += toupper(key[i]);
    return keyUp;
}

// generate cipher
string cipherText(string msg, string key){
    string encrypted, msgUp;
    // upper case
    for(int i=0; i<msg.length(); i++){
        msgUp += toupper(msg[i]);
    }
    for(int i=0; i<msgUp.length(); i++){
        // Rule: E(i) = ( P(i) + K(i) ) mod 26
        encrypted += char((int(msgUp[i])+int(key[i]))%26+65);
    }
    return encrypted;
}

// decrypt cipher text
string decryptText(string encrypted, string key){
    string decrypted;
    for(int i=0; i<encrypted.length(); i++){
        // Rule: D(i) = ( E(i) - K(i) + 26 ) mod 26
        decrypted += char((int(encrypted[i])-int(key[i])+26)%26+65);
    }
    return decrypted;
}

int main(){
    string msg, key;
    cout << "Text: ";
    cin >> msg;
    cout << "Key: ";
    cin >> key;
    string keyword = get_Key(msg, key);
    string encrypted = cipherText(msg, keyword);
    string decrypted = decryptText(encrypted, keyword);
    cout << "Cipher text: " << encrypted << endl;
    cout << "Decrypted text: " << decrypted;
    return 0;
}
