#include<bits/stdc++.h>
using namespace std;

// memoization

 int find(int day, int last,vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(day == 0){
            int maxi = 0;
            for(int i=0; i<=2; i++){
                if(i != last){
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }
        
        if(dp[day][last] != -1) return dp[day][last];
        
        int maxi = 0;
        
        for(int i=0; i<=2; i++){
            if(i != last){
                int points = arr[day][i] + find(day-1, i, arr, dp);
                
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
        
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return find(n-1, 3,arr, dp);
        
    }


// Tabulization DP

  int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(4, 0));
        
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        for(int day=1; day<=n-1; day++){
            for(int last=0; last<=3; last++){
                dp[day][last] = 0;
                
                for(int task=0; task<=2; task++){
                     if(task != last){
                int points = arr[day][task] + dp[day-1][task];
                dp[day][last] = max(dp[day][last], points);
            }
                }
            }
        }
        return dp[n-1][3];
    }







// space optimization
int maximumPoints(vector<vector<int>>& arr) {
        // Code here
      int n = arr.size();
        vector<int>prev(4,0);
        
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        for(int day=1; day<=n-1; day++){
            vector<int>temp(4,0);
            for(int last=0; last<=3; last++){
                temp[last] = 0;
                
                for(int task=0; task<=2; task++){
                     if(task != last){
                temp[last] = max(temp[last], arr[day][task] + prev[task]);
            }
                }
            }
            prev = temp;
        }
        return prev[3];
    }