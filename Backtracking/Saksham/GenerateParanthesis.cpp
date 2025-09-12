class Solution {
public:
    void solve(int open,int close,string &temp,vector<string>&result)
    {
        if(open==0 && close==0)
        {
            result.push_back(temp); 
            return; 
        }
        if(open>0){ //if we have open brackets left 
            temp.push_back('('); // push back a open paranthesis 
            solve(open-1,close,temp,result); 
            temp.pop_back(); 
        }
        if(open<close)
        {
            temp.push_back(')'); 
            solve(open, close-1,temp,result); 
            temp.pop_back(); 
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>result; 
        string temp=""; 
        solve(n,n,temp,result); 
        return result; 
    }
};