// Using hash set : but exceeds the time limit 
class Solution {
public:
    void check(int idx,vector<int>&v, vector<int>&temp,set<vector<int>>&result, int curr_sum, int target)
    {   if(curr_sum>target) return; 
        if(idx>=v.size())
        {
            if(curr_sum==target)
            {
                result.insert(temp); 
            }
            return; 
        }
        temp.push_back(v[idx]); 
        curr_sum += v[idx]; 
        check(idx+1,v,temp,result,curr_sum,target); // donotallow the reuse

        while(v[idx]!= temp.back()) return; // thinking of something like move back till you find new unique element
        curr_sum -= v[idx]; 
        temp.pop_back(); 
        
        check(idx+1,v,temp,result,curr_sum,target); // backtrack 
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> result; 
        vector<int> temp; 
        sort(candidates.begin(),candidates.end()); 
        check(0,candidates,temp,result,0,target);

        return vector<vector<int>>(result.begin(),result.end()); 
        
    }
};



// combination sum : optimal approach 

class Solution {
public:
    void check (int idx,vector<int>&v,vector<int>&temp,vector<vector<int>>&result,int target)
    {
        if(target==0) 
        {
            result.push_back(temp); 
            return;
        } 
        if(idx>=v.size() || target<0) return; 
        temp.push_back(v[idx]); 
        check(idx+1,v,temp,result,target-v[idx]); 
        temp.pop_back();

        int next = idx+1; 
        while(next<v.size() && v[next]==v[idx])next++; 
        check(next,v,temp,result,target); 
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp; 
        vector<vector<int>> result; 
        sort(candidates.begin(),candidates.end());
        check(0,candidates,temp,result,target); 
        return result; 
        
    }
};