//Longest Increasing Subsequence
// Time Complexity : O(nlogn)


#include <bits/stdc++.h>
using namespace std;
class Subsequence{
    public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>dp.back()){
                dp.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
                *it = nums[i];
            }
        }
        return dp.size();
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Subsequence s;
    cout<<s.lengthOfLIS(a)<<endl;
}