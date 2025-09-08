class Solution {
public:
    void subseq(int idx,vector<int>&v, vector<int>&temp,vector<vector<int>> &result )
    {
        if(idx>=v.size())
        {
            // we need to store the thing in the 2d vector
            result.push_back(temp); 
            // then return 
            return; 
        }
        temp.push_back(v[idx]); 
        subseq(idx+1,v,temp,result); 
        temp.pop_back(); 
        subseq(idx+1,v,temp,result); 

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; 
        vector<int>temp; 
        subseq(0,nums,temp,result); 
        return result;

        
    }
};