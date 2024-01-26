#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Function to initialize vector of string of dots
void solve1(vector<string> &cur, int n)
{
     string str = "";
     for (int i = 0; i < n; i++)
          str += ".";

     for (int i = 0; i < n; i++)
     {
          cur[i] = str;
     }
}

//solve using backtracking
void solve2(vector<int> &c, vector<int> &d1, vector<int> &d2, int n, int i, vector<vector<string>> &result, vector<string> &cur)
{
     //Base Case
     if (i == n)
     {
          result.push_back(cur);

          return;
     }

     for (int j = 0; j < n; j++)
     {
          //to check if the position is safe
          if (!c[j] && !d1[i - j + n - 1] && !d2[i + j])
          {
               //Marking column and diagonal 1 and diagonal 2 as visited
               c[j] = 1;
               d1[i - j + n - 1] = 1;
               d2[i + j] = 1;
               cur[i][j] = 'Q';
               //Recursive placing queens in next row
               solve2(c, d1, d2, n, i + 1, result, cur);
               //Backtrack
               c[j] = 0;
               d1[i - j + n - 1] = 0;
               d2[i + j] = 0;
               cur[i][j] = '.';
          }
     }
}
//Main function to solve the problem
vector<vector<int>> solve(int n)
{
     vector<int> col(n, 0);
     //Initailize dp1 and dp2 vectors with 0
     vector<int> d1(2 * n, 0);
     vector<int> d2(2 * n, 0);
     vector<vector<string>> result;
     vector<string> curr(n);
     solve1(curr, n);
     solve2(col, d1, d2, n, 0, result, curr);
     vector<vector<int>> answer;
     if(result.size()==0) return answer;
     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               if(result[0][i][j]=='Q')
                answer.push_back({i+1,j+1});
          }
     }
     return answer;
}

int main()
{    
     int n;
     cin>>n;
     vector<vector<int>> res=solve(n);
     if(res.empty()){
          cout<<"Invalid Answer\n";
     }
     else{
     for(auto i:res)
     cout<<i[0]<<" "<<i[1]<<endl;
     }
     return 0;
}
