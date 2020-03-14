#include <iostream>
#include <vector>

using namespace std;

int main() {
    string sentence;
    int idxBegin=0;
    int numChar=0;
    int j=0;

    getline(cin,sentence);
    string word[100];

    for(int i=0;i<sentence.size();i++){ // move each of word to the array of string
        numChar +=1;
        if (sentence[i]==' ' || i==sentence.size()-1){
            word[j]=sentence.substr(idxBegin,numChar-1);
            if (i==sentence.size()-1) break;
            idxBegin=i+1;
            j+=1;
            numChar=0;
        }
    }
    word[j]=sentence.substr(idxBegin,numChar); // there is a problem in the last looping, so this line to fix it


    int numWord=j+1;
    int idxFind;
    for (int idxUniq=0;idxUniq<numWord;idxUniq++) { // looking for same word and erase it
        idxFind=idxUniq+1;
        while (idxFind<numWord){
            if (word[idxUniq]==word[idxFind]){
                word[idxFind]="";
            }
            idxFind++;
        }
    }

    for (int i=0;i<numWord;i++) { // printing the result
        if (i==numWord-1) {
            cout<<word[i];
        } else if (word[i]!=""){
            cout<<word[i]<<" ";
        }
    }
    return 0;
}
