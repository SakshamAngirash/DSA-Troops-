class Solution{
    public:
    bool check(int idx,vector<int> &v, vector<int> &temp,int curr_sum , int k)
    {
        if(idx>=v.size())
        {
            if(curr_sum == k) return true; 
            else return false; 
        }
        temp.push_back(v[idx]); 
        curr_sum+=v[idx]; 
        if(check(idx+1,v,temp,curr_sum,k)==true) return true; 
        
        curr_sum-=temp.back(); 
        temp.pop_back(); 
        if(check(idx+1,v,temp,curr_sum,k)==true) return true; 

        return false;
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here
        vector<int> temp; 
        return check(0,nums,temp,0,k); 
    }
};