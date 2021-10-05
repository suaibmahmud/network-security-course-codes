#include<iostream>
#include<string>
using namespace std;

int main(){
    string msg, enc, dec;
    int key, i, j;

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

    //brute-force
    for(i=0;i<26;i++){
        for(j=0;j<enc.length();j++){
            if(isupper(enc[j])){
                if((enc[j] - i - 65)<0)
                    dec += 91 + (enc[j] - i - 65);
                else
                    dec += (enc[j] - i - 65)%26 + 65;
            }
            else if(islower(msg[j])){
                if((enc[j] - i - 97) < 0)
                    dec += 123 + (enc[j] - i - 97);
                else
                    dec += (enc[j] - i - 97)%26 + 97;
            }
            else if(msg[j]==' ')
                dec += ' ';
        }
        cout<<"plain text for key "<<i<<" is: "<<dec<<endl;
        dec="";
    }

    return 0;
}
