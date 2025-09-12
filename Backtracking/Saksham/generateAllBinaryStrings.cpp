class Solution {
public:

    void solve(int n,string &temp,vector<string>& result)
    {
        if(n==0)
        {
            result.push_back(temp);
            return;  
        }
        temp.push_back('0'); 
        solve(n-1,temp,result); 
        temp.pop_back(); 
       
        if(temp.empty() || temp.back()!='1')
        {
            temp.push_back('1'); 
            solve(n-1,temp,result); 
            temp.pop_back(); 

        }

    }

    vector<string> generateBinaryStrings(int n) {
        // Your code goes here
        vector<string> result; 
        string temp; 
        solve(n,temp,result);
        return result; 
    }
};
