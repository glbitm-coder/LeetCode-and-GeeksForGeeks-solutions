class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int j = 0;
        string sub_ans="";
        bool start = true;
        vector<string> ans;
        for(int i = 0; i < words.size(); ++i){
            if(start){
                if(ans.size() != 0){
                    ans[ans.size() - 1] = sub_ans;
                }
                ans.push_back(words[i]);
                sub_ans = words[i];
                start = false;
                continue;
            }
            if(words[i].size() + sub_ans.size() + 1 <= maxWidth){
                sub_ans = sub_ans + ' ' + words[i];
            }
            else{
                i = i - 1;
                start = true;
            }
        }
        ans[ans.size() - 1] = sub_ans;

        for(int i = 0; i < ans.size(); ++i){
            cout<<ans[i]<<"\n";
            string str = ans[i];
            if(str.size() == maxWidth) continue;
            int count_space = 0;
            for(int k = 0; k < str.size(); ++k){
                if(str[k] == ' ') count_space++;
            }
            int space_needed = maxWidth - str.size();
            if(count_space == 0 || i == ans.size() - 1){
                for(int k = 0; k < space_needed; ++k){
                    str = str + ' ';
                }
                ans[i] = str;
                continue;
            }
            int to_all = space_needed / count_space;
            int to_selected = space_needed % count_space;
            count_space = 1;
            string str2 = "";
            for(int k = 0; k < str.size(); ++k){
                if(count_space <= to_selected && str[k] == ' '){
                    for(int p = 0; p < to_all + 1; ++p){
                        str2 = str2 + ' ';
                    }
                    ++count_space;
                }
                else if(count_space > to_selected && str[k] == ' '){
                    for(int p = 0; p < to_all; ++p){
                        str2 = str2 + ' ';
                    }
                }
                str2 = str2 + str[k];
            }
            ans[i] = str2;
        }
        return ans;
    }
};