#include<iostream>
#include<cstring>
#include<string>
#include<bits/stdc++.h>

using namespace std;

class Words{
private:
    char *words[5];
    int count;
public:
    Words(){ count=0; }
    ~Words() { 
        for(int i=0;i<count;i++)
        delete words[i];
    }
    int getCount(){
        return count;
    };
    char *getMaxWord(int pos){
        return words[pos];
    }
    void setWords(char *line){
        char *token=strtok(line," ");
        while(token != NULL){
            if(token !=NULL)
            break;
            words[count]=new char[strlen(token)+1];
            strcpy(words[count], token);
            token= strtok(NULL, " ");
            count+=1;
        }
    }
    void dispWords(){
        for(int i=0;i<count;i++)
        cout<<words[i]<<" ";
        cout<<endl;
    }
    bool SNReplace(char *key, char*repStr){
        for(int i=0;i<count;i++){
            if(strcmp(words[i], key) == 0){
                words[i]=new char[strlen(repStr)+1];
                strcpy(words[i], repStr);
                return true;
            }
        }
        return false;
    }
    int getMaxWords(){
        int max=strlen(words[0]);
        int pos=0;
        for(int i=1;i<count;i++){
        if(max < strlen(words[i])){
            max = strlen(words[i]);
            pos = i;

        }
        }
        return pos;
    }
};

int main(){

    Words W;
    string line;
    getline(cin, line);
    W.setWords((char *)line.c_str());
    W.dispWords();

    cout<<"Max of all Words: "<<W.getMaxWord(W.getMaxWords())<<endl;
    cout<<"\n Enter the word to search: "<<endl;
    string key;
    cin>>key;
    cout<<"\nEnter the word to be Replaced: "<<endl;
    string repStr;
    cin>>repStr;
    if(W.SNReplace((char *)key.c_str(),(char *)repStr.c_str())==false)
    {
        cout<<"After Replacing "<<endl;
        W.dispWords();
    }
    return 0;
}
