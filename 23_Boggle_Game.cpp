/*
23 Boggle Game

Given 2d matrix of letters, and a word dictionary, find a path which has largest number of words (existed inside the dictionary).
*/
//https://leetcode.com/problems/word-search-ii/description/
class Trie{
public:    
    Trie* child[26];
    string str;
    
    Trie():str(""),isVisited(false){
        for(int i = 0;i<26;i++) child[i] = NULL;
    }
    
    ~Trie(){
        for(int i=0;i<26;i++) if(child[i]) delete child[i];
    }
    
    static void build(Trie* root, string &s){
        for(char c:s){
            if(!root->child[c-'a'])root->child[c-'a'] = new Trie;
            root=root->child[c-'a'];
        }
        root->str = s;
    }
    
    bool visit(){
        bool cur = isVisited;
        isVisited = true;
        return cur;
    }
private:
    bool isVisited;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> vec;
        if(board.empty()) return vec;
        int m = board.size(),n = board[0].size();
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        Trie *root = new Trie;
        for(string s:words) Trie::build(root,s);
        for(int i=0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(root->child[board[i][j]-'a'])dfs(vec, root->child[board[i][j]-'a'], board,i,j,visit);
        return vec;
    }
private:    
    vector<vector<int>> dirs = {{0, -1},{0, 1},{1,0},{-1,0}};
    
    void dfs(vector<string> &vec, Trie *root, vector<vector<char>>& board,int i ,int j,vector<vector<bool>> &visit){
        visit[i][j] = true;
        if(!root->str.empty() && !root->visit())vec.push_back(root->str);
        for(auto &st:dirs){
            int x = i+st[0], y = j+st[1];
            if(x<0 || x >=board.size() || y<0 || y>=board[0].size() || visit[x][y] || !root->child[board[x][y]-'a'])continue;
            dfs(vec,root->child[board[x][y]-'a'],board,x,y,visit);
        }
        visit[i][j] = false;
    }
};
