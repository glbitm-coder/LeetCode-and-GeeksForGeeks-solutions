class DisjointSet
{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int parentU = findUPar(u);
        int parentV = findUPar(v);
        
        if(parentU == parentV)
            return;
            
        if(size[parentU] < size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> account_no;
        DisjointSet ds(n);
        for(int i = 0; i < accounts.size(); ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                string email = accounts[i][j];
                if(account_no.find(email) == account_no.end()){
                    account_no[email] = i;
                } else{
                    ds.unionBySize(i, account_no[email]);
                }
            }
        }

        vector<vector<string>> emailsByIndex(n);
        for(auto it:account_no){
            int no = it.second;
            int index = ds.findUPar(no);
            emailsByIndex[index].push_back(it.first);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; ++i){
            if(emailsByIndex[i].size() == 0){
                continue;
            }
            sort(emailsByIndex[i].begin(), emailsByIndex[i].end());
            vector<string> temp;

            temp.push_back(accounts[i][0]);
            for(auto it: emailsByIndex[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};