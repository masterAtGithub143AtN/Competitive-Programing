#include<bits/stdc++.h>

struct Node
{
    Node *links[26];
    bool isEnd=false;
    bool Contains(char c){
        return links[c-'a']!=nullptr;
    }
    Node* Get(char c){
        return links[c-'a'];
    }
    void Put(char c){
        links[c-'a']=new Node();
    }
    void setEnd(){
        isEnd=true;
    }

    /* data */
};


class Trie{
    private: 
    Node* root;
    public:

    Trie(){
        root=new Node;
    }
    void insert(std::string s){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            if(!node->Contains(s[i])){
                node->Put(s[i]);
            }
            node=node->Get(s[i]);

        }
        node->setEnd();
    }
    bool search(std::string s){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            if(!node->Contains(s[i])){
                return false;
            }
            node=node->Get(s[i]);
        }
        return node->isEnd;
    }
    bool startsWith(std::string s){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            if(!node->Contains(s[i])){
                return false;
            }
            node=node->Get(s[i]);
        }
        return true;
    }


};
