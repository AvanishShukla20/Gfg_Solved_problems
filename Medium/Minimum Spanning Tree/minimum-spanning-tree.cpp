//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(int x, vector<int>& parent)
	{
	    if(parent[x] == x) return x;
	    
	    return parent[x] = find(parent[x], parent);
	}
	
	void Union(int u, int v, vector<int>& rank, vector<int>& parent)
	{
	    int par_u = find(u, parent);
	    int par_v = find(v, parent);
	    
	    if(par_u == par_v) return;
	    
	    if(rank[par_u] < rank[par_v])
	    {
	        parent[par_u] = par_v ;
	    }
	    else if(rank[par_u] > rank[par_v])
	    {
	        parent[par_v] = par_u ;
	    }
	    else{
	        parent[par_u] = par_v;
	        rank[par_v] += 1;
	    }
	    
	    return;
	}
	
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // using Disjoint Set Union
        
        vector<vector<int>> vec;
        
        for(int u = 0; u < V; u++)
        {
            for(auto &it : adj[u])
            {
                int v = it[0];
                int wt = it[1];
                
                vec.push_back({u, v, wt});
            }
        }
        
        
        auto lambda_comparator = [&](vector<int>& a, vector<int>&b)
        {
            return a[2] < b[2];
        };
        
        sort(vec.begin(), vec.end(), lambda_comparator);
        
       int sum = 0;
       
       vector<int> parent(V);
       
       for(int i=0; i<V; i++)
       {
           parent[i] = i;
       }
       
       vector<int> rank(V, 0);
       
       for(int i=0; i<vec.size(); i++)
       {
           int a = vec[i][0];
           int b = vec[i][1];
           int wgt = vec[i][2];
           
           if(find(a, parent) != find(b, parent))
           {
               Union(a, b, rank, parent);
               sum += wgt;
           }
       }
       
       
       return sum;
     
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends