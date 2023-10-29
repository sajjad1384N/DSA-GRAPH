#include<iostream>
using namespace std;
#include<vector>
class TrieNode{
public:
    char data;
    int prefixCount;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
        prefixCount=0;

    }

};
class Trie{
    public:
    TrieNode* root;
       Trie(){
        root=new TrieNode('\0');
       }
    void insertUtil(TrieNode* root,string word){
        //TrieNode* child=root;
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return ;
        }
        //present
        int index=word[0]-'A';
        TrieNode* child=root;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->prefixCount++;
            root->children[index]=child;
             
        }
        //recursion
        insertUtil(child,word.substr(1));

    } 
    void insertWord(string word){
        insertUtil(root,word);
    }
    void lcp(string word,string &ans){
        TrieNode* current=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            
                
                //age badho
                int index=ch-'a';
                TrieNode* child=current->children[index];
                if(child==NULL || current->prefixCount!=1){
                    break;
                }
                
               

                else{
                    ans+=ch;

                  current =child;

                }
            }
            
            
        }

    };

int  main(){
    vector<string> lcp;
    lcp.push_back("coding");
    lcp.push_back("codingninja");
    lcp.push_back("coder");
    lcp.push_back("codez");
    Trie *t=new Trie();
   

    int n=lcp.size();
    for(int i=0;i<n;i++){
        t->insertWord(lcp[i]);
    }
    string ans="";
    string first=lcp[0];
    t->lcp(first,ans);
    cout<<"prefix is"<<ans;
    return 0;

}