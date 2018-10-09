//https://leetcode.com/problems/ip-to-cidr/description/
class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        istringstream st(ip);
        string p;
        long d = 0;
        while(getline(st, p, '.')){
            d = d * 256 + stoi(p);
        }
        vector<string> ans;
        while(n){
            int m = d & -d;
            while(m > n) m /= 2;
            ans.push_back(convert(d, m));
            n-=m;
            d+=m;
        }
        return ans;
    }
private:
    string convert(long x, int mask){
        return to_string(x>>24 & 255) +"." + to_string(x >> 16 & 255) +"." + to_string(x>>8 & 255) +"." + to_string(x&255) +"/" + to_string(32 - (int)log2(mask));
    }
};
