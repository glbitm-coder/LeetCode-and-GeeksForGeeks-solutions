class Solution {
public:
    string convertToTitle(int columnNumber) {

        string ans;
        char temp;
        while(columnNumber){
            --columnNumber;
            temp = 'A' + (columnNumber % 26);
            ans = temp + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};