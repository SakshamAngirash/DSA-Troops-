// here we have to print only one subseq , with the ans 

#include<iostream>
#include<vector> 
using namespace std; 

void printVector(vector<int> &temp)
{
    for(int i = 0 ; i<temp.size(); i++)
    {
        cout<<temp[i]<<" "; 
    }
    cout<<endl;
}

bool printSub(int idx, vector<int>&v, vector<int>&temp, int curr_sum, int k)
{
    if(idx>=v.size())
    {
        // base case 
        if(curr_sum == k) 
        {
            printVector(temp); 
            return true; 
        }
        // condition not satisfied 
        return false;
    }
    temp.push_back(v[idx]); 
    curr_sum +=v[idx]; 
    if(printSub(idx+1,v,temp,curr_sum,k)==true) return true; 

    curr_sum -= temp.back(); 
    temp.pop_back(); 
    if(printSub(idx+1,v,temp,curr_sum,k)==true) return true; 
    return false; 

}
int main ()
{
    vector<int> v ={1,2,1}; 
    int sum = 2 ; 
    vector<int> temp; 
    printSub(0,v,temp,0,sum); 
}