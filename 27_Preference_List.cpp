//http://massivealgorithms.blogspot.com/2017/07/preference-list-airbnb.html
//每个人都有一个preference的排序，在不违反每个人的preference的情况下得到总体的preference的排序 拓扑排序解决(https://instant.1point3acres.com/thread/207601)
vector<int> preferenceList(vector<vector<int> > &preList) {
    unordered_map<int, unordered_set<int> > mp;
    unordered_map<int, int> in;
    vector<int> ans;
    for(auto lt : preList) {
        for(int i = 1; i < lt.size(); ++i)
            mp[lt[i - 1]].insert(lt[i]);
    }
    for(auto m : mp)
        for(auto s : m.second)
            in[s]++;
    queue<int> q;
    for(int i = 0; i < preList.size(); ++i)
        if(!in.count(i)) {
            q.push(i);
            ans.push_back(i);
        }
    while(!q.empty()) {
        int c = q.front();
        q.pop();
        auto next = mp[c];
        for(auto s : next) {
            if(--in[s] == 0) {
                q.push(s);
                ans.push_back(s);
            }
        }
    }
    return ans;
}
