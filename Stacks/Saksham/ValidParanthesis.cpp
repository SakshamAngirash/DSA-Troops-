class Solution {
public:
    bool isValid(string s) {
        if (s.size()==0) return true; 
        if(s.size()%2!=0) return false; 
        stack<char> st; 
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
            {
                //opening bracket 
                st.push(s[i]); 
            }
            else if(s[i]=='}'||s[i]==']'||s[i]==')')
            {
                // closing brackets
                if(st.size()==0) return false; 
                if(s[i]=='}')
                {
                    if(st.top()!='{') return false; 
                    st.pop(); 
                }
                else if(s[i]==']')
                {
                    if(st.top()!='[') return false; 
                    st.pop(); 
                }
                else if(s[i]==')')
                {
                    if(st.top()!='(') return false; 
                    st.pop(); 
                }
            }
        }
        if(st.size()==0) return true; 
        else return false; 
        
    }
};