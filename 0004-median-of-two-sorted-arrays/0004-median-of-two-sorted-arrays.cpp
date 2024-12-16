class Solution {
public:
    double median(vector<int>& nums1, vector<int>& nums2, int n1, int n2){
        int total = n1 + n2, half = total / 2, N1Right = 0, N2Left = 0, N2Right = 0;
        int start = 0, end = n1 - 1, mid = 0, midN1 = 0, midN2 = 0, N1Left = 0;
        while(true){
            midN1 = floor(start + (double)(end - start) / 2);
            midN2 = half - midN1 - 2;

            N1Left = midN1 >= 0 ? nums1[midN1] : INT_MIN;
            N1Right = (midN1 + 1) < n1 ? nums1[midN1 + 1] : INT_MAX;
            N2Left = midN2 >= 0 ? nums2[midN2] : INT_MIN;
            N2Right = (midN2 + 1) < n2 ? nums2[midN2 + 1] : INT_MAX;
            
            if(N1Left <= N2Right && N2Left <= N1Right){
                if(total % 2 == 0){
                    return (double)(max(N1Left, N2Left) + min(N1Right, N2Right) ) / 2;
                }
                else{
                    return min(N2Right, N1Right);
                }
            }
            else if(N1Left > N2Right){
                end = midN1 - 1;
            } 
            else{
                start = midN1 + 1;
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 < n2){
            return median(nums1,nums2,n1,n2);
        }
        else{
            return median(nums2, nums1, n2, n1);
        }
    }
};