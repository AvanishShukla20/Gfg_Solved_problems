//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool check(int arr[],int& n, int& mid, int k)
    {
        int cnt = 1;
        int i = 0, sum = 0; 
        while(i < n)
        {
            if(arr[i] > mid) return false;
            sum += arr[i];
            if(sum > mid)
            {
                cnt++;
                sum = 0;
            }
            else i++;
        }
        if(cnt <= k) return true;
        return false;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        int low = 0, high = 1e6, mid, ans = 0;
        while(low <= high)
        {
            mid = low + (high - low)/2;
            if(check(arr,n, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends