/*Find all the combinations of a string in lowercase and uppercase. For example, string "ab" >>> "ab", "Ab", "aB", "AB". So, you will have 2^n (n = number of chars in the string) output strings. */
bool isSet(int n, int offset){
    return (n>>offset & 1) != 0;
}

vector<string> str_comb(string text){
    vector<string> ans;
    if(text.empty()) return ans;
    for(int i=0;i<pow(2,text.size());i++){
	string tem;
	for(int j = 0;j<n;j++){
   	    tem.push_back(isSet(i,j)?toupper(text[i]):tolower(text[i]));
	}
	ans.push_back(tem);
    }
    return ans;
}
