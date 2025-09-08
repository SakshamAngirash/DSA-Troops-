#include<iostream> 
#include<vector> 
using namespace std; 

void merge(vector<int> &a,vector<int>&b, vector<int>&v)
{
    // three pointers 
    int i = 0; 
    int k = 0; 
    int j = 0; 

    int n1 = a.size(); 
    int n2 = b.size(); 
    int n = n1+n2; 

    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            v[k] = a[i]; 
            i++; 
            k++; 
        }
        else // a[i]>b[i]
        {
            v[k] = b[j]; 
            j++; 
            k++; 
        }
    }
    while(i<n1)
    {
        v[k]=a[i]; 
        i++; 
        k++; 
    }
    while(j<n2)
    {
        v[k]=b[j]; 
        j++;
        k++; 
    }


}


void mergeSort(vector<int> &v)
{
    int n = v.size(); 
    if(n==1) return; // no further divide

    int n1 = n/2; 
    int n2 = n-n/2; 

    vector<int>a(n1); 
    vector<int>b(n2); 

    //copying
    for(int i=0; i<n1; i++) a[i]=v[i];
    for(int i=0; i<n2; i++) b[i]=v[i+n1];

    mergeSort(a); 
    mergeSort(b); 

    merge(a,b,v); 
    a.clear(); 
    b.clear(); 
    
}
using namespace std; 
int main ()
{
    vector<int>v = {3,4,2,1,4,6,8,9,10,2,1,3}; 
    mergeSort(v);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" "; 
    }
    cout<<endl;
    

}



