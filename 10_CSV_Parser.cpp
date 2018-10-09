//Write a method to parse input string in CSV format.
/*csv parser
    如果有逗号，转化成|
    如果有引号，把不考虑引号里逗号，把引号里的内容去引号整体打印。
    如果有两重引号，只去掉一重引号。

    例子
        aa, bb, “aa”,”aa,bb”, “aa””aa”””
    输出
        aa|bb|aa|aa,bb|aa”aa”   */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string parseCsv(string cs) {
        string ans;
        string cur;
        bool isEnter = false, isP = false;
        for (int i = 0; i < cs.size(); i++) {
            bool isEnd1 = cs[i] == '"' && (i + 1 == cs.size() || cs[i + 1] == ',');
            if (isEnd1 || cs[i] == ',' && !isP) {
                if (!ans.empty()) ans.push_back('|');
                ans += cur;
                cur.clear();
                if (isEnd1)i++;
                isEnter = false;
                isP = false;
            } else if (!isEnter && cur.empty()) {
                isEnter = true;
                if (cs[i] == '"' && (i + 1 < cs.size() && cs[i + 1] != '"')) isP = true;
                if (!isP)i--;
            } else if (cs[i] == '"' && (i + 1 < cs.size() && cs[i + 1] == '"')) {
                cur.push_back('"');
                i++;
            } else {
                cur.push_back(cs[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "aa,bb,\"aa\",\"aa,bb\",\"aa\"\"aa\"\"\"";
    cout << solution.parseCsv(s);
    return 0;
}
