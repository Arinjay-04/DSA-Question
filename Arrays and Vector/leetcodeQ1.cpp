//APPROACH 1

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums3;
    for(int i=0 ; i< nums1.size(); i++){
        nums3.push_back(nums1[i]);
    }

    for(int j =0; j< nums2.size(); j++){
        nums3.push_back(nums2[j]);
    }

    sort(nums3.begin(), nums3.end());

    int n = nums3.size();

    if(n%2==0){
       int middle1 = nums3[n/2  -1];
       int middle2  = nums3[n/2];
       return (static_cast<double>(middle1) + static_cast<double>(middle2));
    }

    else{
        return static_cast<double>(nums3[n/2]);
    }

    }
};