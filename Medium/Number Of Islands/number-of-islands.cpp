//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int> rank, parent;
    
    public:
    
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        
        for(int i=0; i<=n; i++)
        {
            parent[i] = i;
        }
    }
    
    int findUlPar(int node)
    {
        if(parent[node] == node) return node;
        
        return parent[node] = findUlPar(parent[node]);
    }
    
    void UnionByRank(int a, int b)
    {
        int ulpa = findUlPar(a);
        int ulpb = findUlPar(b);
        
        if(ulpa == ulpb) return;
        
        if(rank[ulpa] < rank[ulpb]) parent[ulpa] = ulpb;
        else if(rank[ulpb] < rank[ulpa]) parent[ulpb] = ulpa;
        else
        {
            parent[ulpa] = ulpb;
            rank[ulpb] += 1;
        }
     
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // we give each set a number for efficient union and find operation and implementation
        DisjointSet ds(n*m);
        
        int cnt = 0;
        int drow[4] = {0, -1, 0, 1};
        int dcol[4] = {-1, 0, 1,0};
        
        vector<int> ans;
        
        for(auto &it : operators)
        {
            int row = it[0];
            int col = it[1];
            
            int currCellNo = row*m + col;
            
            if(vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            else
            {
                vis[row][col] = 1;
                cnt++;
                
                for(int i=0; i < 4; i++)
                {
                    int newrow = row + drow[i];
                    int newcol = col + dcol[i];
                    
                    int adjCellNo = newrow*m + newcol;
                    
                    if(newrow<n && newrow >= 0 && newcol < m && newcol >= 0)
                    {
                        if(vis[newrow][newcol])
                        {
                        //now check if both have same parents or not 
                            if(ds.findUlPar(currCellNo) != ds.findUlPar(adjCellNo))
                            {
                                cnt--;
                                ds.UnionByRank(currCellNo, adjCellNo);
                            }
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends