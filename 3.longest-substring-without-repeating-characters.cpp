#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        if(len<=1){
            return len;
        }
        int p1=0;
        int p2=0;
        unordered_map<char,int> m;
        int maxlength=INT_MIN;
        while(p2<len){
            if(m.find(s[p2])!=m.end()){
              
                m.erase(s[p1]);
                p1++;
            }else{
                m[s[p2]]=p2;
                maxlength=max(maxlength,p2-p1+1);
                p2++;
            }
        }
        return maxlength;
    }
};
