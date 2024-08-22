#include<bits/stdc++.h>
using namespace std;

class importantStack{

    public:

    vector<long long> NextSmallerElement(long long n,vector<long long> arr){
        stack<long long> s;
        vector<long long> ans;
        for(long long i=n-1;i>=0;i--){
            while((!s.empty()) && (arr[s.top()]>=arr[i])){
                s.pop();
            }
            if(s.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
    }

    vector<long long> PreviousSmallerElement(long long n,vector<long long> arr){
        stack<long long> s;
        vector<long long> ans(n);
        for(long long i=0;i<n;i++){
            while((!s.empty()) && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);

        }
        return ans;
    }

    vector<long long> NextGresterElement(long long n,vector<long long> arr){
        stack<long long> s;
        vector<long long> ans(n);
        for(long long i=n-1;i>=0;i--){
            while((!s.empty()) && (arr[s.top()]<=arr[i])){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }

    vector<long long> NextGreaterElementWithCircularity(long long n,vector<long long> arr){
        stack<long long> s;
        vector<long long> ans(n);
        for(long long i=2*n-1;i>=0;i--){
            while((!s.empty()) && arr[s.top()]<=arr[i%n]){
                s.pop();
            }
            if(i<n){
                if(s.empty()){
                    ans[i]=-1;
                }
                else{
                    ans[i]=s.top();
                }
            }
            s.push(i%n);
        }
        return ans;
    }

    vector<long long> PreviousGreaterElement(long long n,vector<long long> arr){
        stack<long long> s;
        vector<long long> ans(n);
        for(long long i=0;i<n;i++){
            while((!s.empty()) && arr[s.top()]<=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }

};