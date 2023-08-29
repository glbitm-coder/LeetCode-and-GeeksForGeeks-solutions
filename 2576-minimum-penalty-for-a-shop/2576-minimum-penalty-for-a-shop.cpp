class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int count_y = 0, count_n = 0;
        for(int i = 0; i < n; ++i){
            if(customers[i] == 'Y') count_y++;
            else count_n++;
        }
        int curr_y = 0, curr_n = 0;
        int penalty = INT_MAX;
        int ans = 0;
        for(int i = 0 ; i <= n; ++i){
            if(i == 0){
                penalty = count_y;
                continue;
            }
            int penalty1;
            if(customers[i - 1] == 'Y'){
                 ++curr_y;
                 penalty1 = curr_n + (count_y - curr_y);
            } else{
                ++curr_n;
                penalty1 = curr_n + (count_y - curr_y);
            }
            if(penalty1 < penalty){
                ans = i;
                penalty = penalty1;
            }
            // cout<<i<<" "<<penalty1<<"\n";
        }
        return ans;
    }
};