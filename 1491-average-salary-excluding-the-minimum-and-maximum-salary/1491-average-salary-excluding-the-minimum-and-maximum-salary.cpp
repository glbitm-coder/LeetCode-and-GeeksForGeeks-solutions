class Solution {
public:
    double average(vector<int>& salary) {
        long long int sum = 0;
        for(int i =0 ; i < salary.size(); ++i)
        {
            sum += (long long int)salary[i];
        }
        int maxEle = *max_element(salary.begin(), salary.end());
        int minEle = *min_element(salary.begin(), salary.end());
        return (double)(sum - maxEle - minEle) / (salary.size() - 2);
    }
};