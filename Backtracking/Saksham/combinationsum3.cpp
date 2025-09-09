class Solution {
public:
    void check(int idx,vector<int>&temp,vector<vector<int>>&result,int k,int n,int curr_sum)
    {
        if(curr_sum>n) return; 
        // base case 
        if(temp.size()==k)
        {
            if(curr_sum==n) result.push_back(temp); 
            return; 
        }

        if(idx>9) return; // sop when numbers>9

        temp.push_back(idx);
        check(idx+1,temp,result,k,n,curr_sum+idx); 

        temp.pop_back(); 
        check(idx+1,temp,result,k,n,curr_sum); 

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp; 
        vector<vector<int>> result; 
        check(1,temp,result,k,n,0);
        return result; 
    }
};