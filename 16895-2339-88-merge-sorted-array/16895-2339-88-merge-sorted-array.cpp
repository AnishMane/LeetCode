class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num1copy(nums1.begin(),nums1.begin()+m);
        int i=0,j=0,k=0;

        while(k<m+n){
            if(j>=n || (i<m && num1copy[i]<nums2[j])){
                nums1[k++] = num1copy[i++];
            }
            else{
                nums1[k++] = nums2[j++];
            }
        }

    }
};