class Solution {
public:
    bool isSafe(int row,int col,vector<string> &tempBoard,int n)
    {
        int dupRow = row; 
        int dupCol = col;
        // checking upper diagonal
        while(row>=0 && col>=0)
        {
            if(tempBoard[row][col]=='Q') return false; 
            row--; 
            col--; 
        } 
        row = dupRow; 
        col = dupCol; 

        // left element 
        while(col>=0)
        {
            if(tempBoard[row][col]=='Q') return false; 
            col--; 
        }

        row = dupRow; 
        col = dupCol;

        // checking the lower diagonal
        while(row<n && col>=0)
        {
            if(tempBoard[row][col]=='Q') return false; 
            row++; 
            col--; 
        }  
        return true; 


    }
    void solve(int col,int &n,vector<string> &tempBoard,vector<vector<string>> &ans)
    {
        if(col >= n ) 
        {
            ans.push_back(tempBoard); 
            return; 
        }
        for(int row = 0 ; row<n ; row++)
        {
            if(isSafe(row,col,tempBoard,n))
            {
                tempBoard[row][col] = 'Q'; // add the queen 
                solve(col+1,n,tempBoard,ans); 
                tempBoard[row][col] = '.'; // remove the queen (backtrack)

            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> tempBoard(n); 
        string s(n,'.'); 

        for(int i=0; i<n;i++)
        {
            tempBoard[i]=s; // fill the each temp 
        }
        solve(0,n,tempBoard,ans); // col , n , board , collection 
        return ans; 
        
    }
};