#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void encrypt(char &character) {
    if (isalnum(character)){
        if (character >= 48 && character <= 57){
            if (character == 57){
                character = 48;
            }else{
                character++;
            }
        }
        else if (character >= 65 && character <= 90){
            if (character == 90){
                character = 65;
            }else{
                character++;
            }
        }
        else if (character >= 97 && character <= 122){
            if (character == 122){
                character = 97;
            }else{
                character++;
            }
        }
    }
}
int main() {
    string user = "", test = "";
    while(true){
        cout << "Enter a string to encode:";
        getline(cin, user);
        test = user;
        for_each(test.begin(), test.end(), [](char &c){
            c = tolower(c);
        });
        if (test == "quit"){
            break;
        }
        for_each(user.begin(), user.end(), [](char &c){
            encrypt(c);
        });
        cout << user << endl;
    }
}
