class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123456780";
        string start;
        for(auto &row:board)for(int t:row)start += to_string(t);
        queue<string> que;
        unordered_set<string> visited{start};
        vector<vector<int>> dirs = {{1,3},{0,2,4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7},{4,6,8},{5,7}};
        que.push(start);
        int step = 0;
        while(!que.empty()){
            for(int i = que.size();i>0;i--){
                string now = que.front();que.pop();
                if(now == target) return step;
                int cursor = now.find('0');
                for(int sp:dirs[cursor]){
                    string cand = now;
                    swap(cand[sp],cand[cursor]);
                    if(visited.count(cand)) continue;
                    visited.insert(cand);
                    que.push(cand);
                }
            }
            step++;
        }
        return -1;
    }
};
