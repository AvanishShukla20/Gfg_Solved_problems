//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void toposort(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj)
	{
	    vis[node] = 1;
	    for(auto &it : adj[node])
	    {
	        if(!vis[it]) toposort(it, vis, st, adj);
	    }
	    
	    st.push(node);
	}
	void dfs(int node, vector<vector<int>>& reversedgraph, vector<int>& vis)
	{
	    vis[node] = 1;
	    
	    for(auto &p : reversedgraph[node])
	    {
	        if(!vis[p])
	        {
	            dfs(p, reversedgraph, vis);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<vector<int>> reversedgraph(V);
        
        stack<int> st;
        
        for(int u = 0; u< V; u++)
        {
            for(auto &v: adj[u])
            {
                reversedgraph[v].push_back(u);
            }
        }
        
        vector<int> vis(V, 0), visr(V, 0);
        
        for(int i=0; i < V; i++)
        {
            if(!vis[i])
            {
                toposort(i, vis, st, adj);
            }
        }
        
        
        
        int scc = 0;
        
        while(!st.empty())
        {
            int t = st.top();
            st.pop();
            
            if(!visr[t])
            {
                dfs(t, reversedgraph, visr);
                scc++;
            }
        }
        
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends