//https://leetcode.com/problems/pyramid-transition-matrix/description/

class Solution {
public:
    typedef unordered_map<char, unordered_map<char,vector<char>>> UM;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        UM mp;
        for(string &s:allowed){
            mp[s[0]][s[1]].push_back(s[2]);
        }
        return dfs(bottom,"",mp);
    }
    
private:
    bool dfs(string bottom,string cur,UM &mp){
        if(bottom.size()==1) return true;
        if(cur.size()==bottom.size()-1) return dfs(cur,"",mp);
        int a = cur.size();
        for(char c:mp[bottom[a]][bottom[a+1]]){
            cur.push_back(c);
            if(dfs(bottom,cur,mp)) return true;
            cur.pop_back();
        }
        return false;
    }
};
