//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char, int> mpp;
        
        int l =0, r = 0, ans = -1, n = s.size();
        
        while(r < n)
        {
            mpp[s[r]]++;
            
            // if size of map is greater than k shrink
            
            while(mpp.size() > k)
            {
                mpp[s[l]]--;
                
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            
            if(mpp.size() == k) ans = max(ans, r - l + 1);
            r++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends