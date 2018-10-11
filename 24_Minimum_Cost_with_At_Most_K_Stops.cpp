//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
/*Given a flight itinerary consisting of starting city, destination city, and ticket price (2d list) - find the optimal price flight path to get from start to destination. (A variation of Dynamic Programming Shortest Path)*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int step = 0, ans = INT_MAX;
        unordered_map<int, vector<vector<int>>> mp;
        for(auto &t:flights)mp[t[0]].push_back({t[1],t[2]});
        queue<vector<int>> que;
        que.push({src,0});
        while(step<=K+1 && !que.empty()){
            for(int i=que.size();i>0;i--){
                auto f = que.front();que.pop();
                if(f[0]==dst) ans = min(ans, f[1]);
                for(auto &y:mp[f[0]]){
                    if(y[1]+f[1]>=ans)continue;
                    que.push({y[0],y[1]+f[1]});
                }
            }
            step++;
        }
        return ans==INT_MAX?-1:ans;
    }
};
