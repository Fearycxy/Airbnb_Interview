/*
Menu Combination Sum

Given a menu (list of items prices), find all possible combinations of items that sum a particular value K. (A variation of the typical 2sum/Nsum questions).
*/


vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
        // write your code here
        vector<vector<vector<int>>> ans(target+1);
        ans[0].push_back({});
        for(int i:A){
            for(int j=target;j>=i;j--){
                for(auto v:ans[j-i]){
                    v.push_back(i);
                    ans[j].push_back(v);
                }
            }
        }
        return ans[target];
}
