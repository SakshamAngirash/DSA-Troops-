class Solution {
public:
    void solve (int idx,string digits,string& temp, vector<string>&result, vector<string>&mp)
    {
        if(idx>=digits.size())
        {
            result.push_back(temp); 
            return; 
        }
        int number = digits[idx]-'0'; 
        string value = mp[number]; // string asssociated with the number 

        for(int i = 0; i<value.size() ;i++)
        {
            temp.push_back(value[i]); 
            solve(idx+1,digits,temp,result,mp); 
            temp.pop_back(); 
        }
    }
    vector<string> letterCombinations(string digits) {
        
        
        vector<string> mp ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 

        string temp ; 
        vector <string> result; 
        if(digits.size()==0) return result;

        solve(0,digits,temp,result,mp); 

        return result; 
    }
};