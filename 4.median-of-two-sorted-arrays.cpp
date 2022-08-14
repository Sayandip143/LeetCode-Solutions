#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x=nums1.size();
        int y=nums2.size();
        if(x>y){
            return findMedianSortedArrays(nums2,nums1);
        }

        int start=0;
        int end=x;

        while(start<=end){
            int partitionx=(start+end)/2;
            int partitiony=((x+y+1)/2)-partitionx;
            int maxleftx=(partitionx==0)?INT_MIN:nums1[partitionx-1];
            int minrightx=(partitionx==x)?INT_MAX:nums1[partitionx];
            int maxlefty=(partitiony==0)?INT_MIN:nums2[partitiony-1];
            int minrighty=(partitiony==y)?INT_MAX:nums2[partitiony];
            if(maxleftx>minrighty){
                end=partitionx-1;
            }
            else if(maxlefty>minrightx){
                start=partitionx+1;
            }
            else{
                if((x+y)%2==0){
                    return ((double)max((double)maxleftx,(double)maxlefty)+min((double)minrightx,(double)minrighty))/2;
                }else{
                    return (double)max((double)maxleftx,(double)maxlefty);
                }
            }
        }
        return -1;
    }
};
