#include<iostream>
using namespace std;
class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;

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
            root->children[index]=child;
        }
        //recursion
        insertUtil(child,word.substr(1));

    } 
    void insertWord(string word){
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
    //base
    if(word.length()==0){
        return root->isTerminal;
    }
        TrieNode* child=root;
        int index=word[0]-'A';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;

        }
        return searchUtil(child,word.substr(1));
        
    
       
    }
    bool search(string word){
         return searchUtil(root,word);
    }
};
int  main(){
    Trie *t=new Trie();
    t->insertWord("ABCD");
    t->insertWord("DO");
    t->insertWord("TRIM");
    t->insertWord("ARM");

    cout<<"present or not"<<t->search("abc");
    return 0;

}