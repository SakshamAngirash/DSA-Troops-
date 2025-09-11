#include<iostream> 
#include<vector>

using namespace std; 

void insertTemp(vector<int> &v,int temp)
{
    if(v.size()==0 || v[v.size()-1]<temp) 
    {
        v.push_back(temp); 
        return; 
    }

    int val = v[v.size()-1]; 
    v.pop_back(); 
    insertTemp(v,temp); 
    v.push_back(val); 
}
void sortVector(vector<int>&v)
{
    if(v.size()==1){
        // means its already sorted 
        return; // base case 
    }
    // remove the last element //but donot loose it 
    int temp = v[v.size()-1]; 
    v.pop_back();
    sortVector(v); // recursive call 

    // lets suppose it become sorted // next task is to insert the right place 
    insertTemp(v,temp); 
}

int main()
{
    vector<int> v={2,3,7,6,4,3,2,1}; 
    sortVector(v); 
    for(int ele:v)
    {
        cout<<ele<<" ";
    }
    return 0; 
}