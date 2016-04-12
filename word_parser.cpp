#include <iostream>

using namespace std;

bool getWord(char *string, char *word, int &wordOffset);


int main(){
    const int bufferSize=255;

    char buffer[bufferSize+1];
    char word[bufferSize+1];

    int wordOffset = 0;

    cout << "Enter a string: " ;
    cin.getline(buffer,bufferSize);

    cout << "You Wrote:  " << buffer << endl;

    while(getWord(buffer, word, wordOffset)){
        cout << "Word: " << word << endl;
    }

    return 0;
}


bool getWord(char *string, char *word, int &wordOffset){
    //end of string or... string empty?
    if (!string[wordOffset]){
        cout << "Empty!" << endl;
        return false;
    }   

    char *p1, *p2;
    p1 = p2 = string+wordOffset;

    for(int i=0; i < (int)strlen(p1) && !isalnum(p1[0]); i++){
        p1++;
    }
    
    if(!isalnum(p1[0]))
        return false;

    p2=p1;

    while(isalnum(p2[0]))
        p2++;

    int len = int(p2-p1);
    
    strncpy(word, p1, len);

    word[len]= '\0';

    for(int i= int(p2-string) ; i< (int)strlen(string) && !isalnum(p2[0]); i++){
        p2++;
    }

    wordOffset = int(p2-string);



    return true;
}
