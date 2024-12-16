class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        for(; i >= 0 && j >= 0 && k >= 0; ){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                --k;
                nums1[i] = 0;
                --i;
            }
            else{
                nums1[k] = nums2[j];
                --k;
                nums2[j] = 0;
                --j;
            }
        }

        while(j >= 0){
            nums1[k] = nums2[j];
            --j;
            --k;
        }
        return ;
    }
};