#include<iostream> 
#include<vector> 
using namespace std; 
void printVector(vector<int> &temp)
{
    for(int i = 0; i<temp.size(); i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;


}
void subseq(int idx, vector<int>&v, vector<int>&temp, int curr_sum, int k)
{
    if(idx==v.size())
    {
        // print only if curr_sum == k 
        if(curr_sum == k ) printVector(temp); 
        return; // return in either case 
    }
    temp.push_back(v[idx]); 
    curr_sum += v[idx]; 
    subseq(idx+1,v,temp,curr_sum,k); // including 
    curr_sum -=temp.back();
    temp.pop_back(); 
    subseq(idx+1,v,temp,curr_sum,k); // not including 

}



int main()
{
    vector<int> v = {1,2,1};
    int k = 2 ; // desired sum 
    // print all the sub with the desired sum 
    vector<int> temp; 
    subseq(0,v,temp,0,k); 
    return 0; 

}

// striver sheet 
class Solution{
    public: 

    void subseq(int idx, vector<int> &nums, vector<int>&temp, int curr_sum , int k,int &count)
    {
        if(idx==nums.size())
        {
            if(curr_sum==k) count++; 
            return; 
        }
        temp.push_back(nums[idx]); 
        curr_sum+=nums[idx]; 
        subseq(idx+1,nums,temp,curr_sum,k,count); 

        curr_sum-=temp.back(); 
        temp.pop_back(); 
        subseq(idx+1,nums,temp,curr_sum,k,count); 
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        int count = 0; 
        vector<int> temp ; 

        subseq(0,nums,temp,0,k,count); 
        // idx , nums , temp , curr_sum, desired_sum , count 

        return count; 



    }
};


class Solution{
    public: 

    int subseq(int idx, vector<int> &nums, vector<int>&temp, int curr_sum , int k)
    {
        if(idx==nums.size())
        {
            if(curr_sum==k) return 1; 
            return 0; 
        }
        temp.push_back(nums[idx]); 
        curr_sum+=nums[idx]; 
        int l = subseq(idx+1,nums,temp,curr_sum,k); 

        curr_sum-=temp.back(); 
        temp.pop_back(); 
        int r = subseq(idx+1,nums,temp,curr_sum,k); 
        return l+r;
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        vector<int> temp ; 

        return subseq(0,nums,temp,0,k); 
        // idx , nums , temp , curr_sum, desired_sum , count 





    }
};