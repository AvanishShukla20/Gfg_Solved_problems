//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = 1e9 + 7;
    int solve(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp)
    {
        if(idx == 0)
        {
            if(sum == 0 && arr[idx] == 0) return 2;
            if(sum == 0 || sum == arr[0]) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        //pick
        int pick = 0;
        if(sum >= arr[idx]) pick = solve(idx-1, sum - arr[idx], arr, dp) % mod;
        
        int non_pick = solve(idx-1, sum, arr, dp) % mod;
        
        return dp[idx][sum] = pick + non_pick;
        
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        int Sum = 0;
        for(int i = 0; i<n; i++)
        {
            Sum += arr[i];
        }
        int target = (d + Sum)/2;
        
        if((d+Sum)%2 != 0 || Sum < d) return 0;
        
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        
        return solve(n-1, target, arr, dp) % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends