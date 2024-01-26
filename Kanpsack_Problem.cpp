#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& values, int n, int givenlimit) {
    vector<vector<int>> dp(n, vector<int>(givenlimit + 1, 0));

    for (int i = weight[0]; i <= givenlimit; i++) {
        dp[0][i] = values[0];
    }

    for (int i = 1; i < n; i++) {
        for (int c = 0; c <= givenlimit; c++) {
            int ntk = dp[i - 1][c];
            int tk = INT_MIN;

            if (weight[i] <= c) {
                tk = values[i] + dp[i - 1][c - weight[i]];
            }

            dp[i][c] = max(ntk, tk);
        }
    }

    return dp[n - 1][givenlimit];
}

int main() {
    vector<int> weight = {3,1,4};
    vector<int> values = {4,5,7};
    int givenlimit = 5;
    int n = 3;

    cout << "The maximum value achieveble : " << knapsack(weight, values, n, givenlimit);

    return 0;
}