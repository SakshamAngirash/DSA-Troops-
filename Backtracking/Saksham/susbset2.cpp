class Solution {
public:

    void check(int idx,vector<int> &v,vector<int> &temp,vector<vector<int>>&result)
    {
        if(idx>=v.size())
        {
            result.push_back(temp); 
            return; 
        }
        temp.push_back(v[idx]); 
        check(idx+1,v,temp,result); 
        temp.pop_back(); 

        int next = idx+1; 
        while(next<v.size() && v[next]==v[idx])next++; 
        check(next,v,temp,result); 

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp; 
        sort(nums.begin(),nums.end());
        vector<vector<int>> result; 
        check(0,nums,temp,result); 
        return result; 

    }
};