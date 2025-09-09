class Solution {
public:
    void check(int idx,vector<int>&v, vector<int>&temp,vector<vector<int>>&result, int curr_sum, int target)
    {   if(curr_sum>target) return; //prune unnecessary path 
        if(idx>=v.size())
        {
            if(curr_sum==target)
            {
                result.push_back(temp); 
            }
            return; 
        }
        temp.push_back(v[idx]); 
        curr_sum += v[idx]; 
        check(idx,v,temp,result,curr_sum,target); // allow the reuse
        
        curr_sum -= v[idx]; 
        temp.pop_back(); 
        check(idx+1,v,temp,result,curr_sum,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result; 
        vector<int> temp; 
        check(0,candidates,temp,result,0,target);
        return result; 
    }
};