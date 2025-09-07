// recurssion using two pointers 
#include<iostream> 
#include<vector>
using namespace std; 
// using two pointers
void reverse(vector<int>&v, int l,int r)
{
    if(l>=r) return; // no need to swap 
    swap(v[l],v[r]); 
    reverse(v,l+1,r-1);

}
// using a single pointer 
void reverse_single(vector<int> &v, int ptr)
{
    if(ptr>v.size()/2) return; 
    swap(v[ptr],v[v.size()-ptr-1]); 
    reverse_single(v,ptr+1);
}

int main ()
{
    vector<int> v= {1,2,3,4,5,6,7}; 
    int n = v.size();
    reverse(v,0,n-1); 
    reverse_single(v,0);
    for(int i = 0; i<n ; i++)
    {
        cout<<v[i]<<" "; 
    }
}