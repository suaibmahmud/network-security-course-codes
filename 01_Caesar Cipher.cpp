#include<iostream>
#include<string>
using namespace std;

int main(){
    string msg, enc, dec;
    int key, i;

    cout << "text:";
    getline(cin, msg);
    cout << "key:";
    cin >> key;

    // encryption
    for(i=0;i<msg.length();i++){
        if(isupper(msg[i]))
            enc += (msg[i] + key - 65)%26 + 65;
        else if(islower(msg[i]))
            enc += (msg[i] + key - 97)%26 + 97;
        else if(msg[i]==' ')
            enc += ' ';
    }

    //decryption
    for(i=0;i<enc.length();i++){
        if(isupper(enc[i])){
            if((enc[i] - key - 65)<0)
                dec += 91 + (enc[i] - key - 65);
            else
                dec += (enc[i] - key - 65)%26 + 65;
        }
        else if(islower(msg[i])){
            if((enc[i] - key - 97) < 0)
                dec += 123 + (enc[i] - key - 97);
            else
                dec += (enc[i] - key - 97)%26 + 97;
        }
        else if(msg[i]==' ')
            dec += ' ';
    }

    cout<<"cipher: "<<enc<<endl;
    cout<<"decipher: "<<dec;

    return 0;
}
