#include<bits/stdc++.h>
using namespace std;



   
   // memoization
   int find(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = find(i-1, j, dp);
        int left = find(i, j-1, dp);

        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return find(m-1, n-1, dp);
    }

    // tabulation
        int find(int i, int j, vector<vector<int>>& dp){
            
        for(int a=0; a<=i; a++){
            for(int b=0; b<=j; b++){
                int up = 0;
                int left = 0;
                if(a==0 && b==0){
                    dp[0][0] = 1;
                    continue;
                } 
                if(a>0){
                    up = dp[a-1][b];
                }
                if(b>0){
                    left = dp[a][b-1];
                }
                dp[a][b] = up + left;
            }

        }
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        return find(m-1, n-1, dp);
        
    }
   
   
   // space optimization
   int uniquePaths(int m, int n) {
        vector<int>prevCol(n,0);

        for(int i=0; i<m; i++){
            vector<int>currRow(n,0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) currRow[j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0){
                    up = prevCol[j];
                }
                if(j>0){
                    left = currRow[j-1];
                }
                 currRow[j] = up + left;
                }
            }
            prevCol = currRow;
        }
        return prevCol[n-1];
       
        
    }