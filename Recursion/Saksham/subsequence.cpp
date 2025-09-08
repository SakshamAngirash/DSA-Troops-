#include<iostream> 
#include<vector> 
using namespace std;

void printVector(vector<int> &vec)
{
    for(int i = 0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" "; 
    }
    cout<<endl;
}

void printSubseq(int idx, vector<int> &v,vector<int> &temp){
    // either we have to take or we dont have to take 
    // first : the base case 
    if(idx >= v.size())
    {
        printVector(temp);
        return ; 
    }
    temp.push_back(v[idx]); 
    printSubseq(idx+1,v,temp); // take 
    
    temp.pop_back(); 
    printSubseq(idx+1,v,temp); // not take 
}

int main ()
{
    vector<int> v = {3,1,2}; 
    vector<int> temp; 
    printSubseq(0,v,temp); 
}