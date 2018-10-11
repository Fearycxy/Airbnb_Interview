class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vec;
        int cur = 0;
        while(cur <words.size()){
            int start = getLine(words, cur, maxWidth);
            vec.push_back(modify(words, maxWidth, start, cur));
        }
        return vec;
    }
private:    
    int getLine(vector<string>& words, int &cur, int maxWidth){
        int start = cur;
        while(maxWidth >=0 && cur< words.size()){
            maxWidth -= words[cur++].size();
            if(maxWidth<0) cur--;
            else if(maxWidth>=0) maxWidth--;
        }
        return start;
    }
    
    string modify(vector<string> &words, int width, int start, int end){
        string str;int len=0;
        if(end-1==start || end == words.size()){
            for(int i=start;i<end;i++){
                str+= words[i] + " ";
            }
            str.pop_back();
            return str + string(width-str.size(),' ');
        } 
        for(int i = start;i<end;i++) len+= words[i].size();
        int need = width - len;
        int add = need % (end-start-1);
        int space = need / (end-start-1);
        for(int i=start;i<end-1;i++) {
            str+= words[i] + string(add-- > 0?space+1:space, ' ');
        }
        str+=words[end-1];
        return str;
    }
};
