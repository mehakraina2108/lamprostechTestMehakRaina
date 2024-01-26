#include <iostream>
#include <bits/stdc++.h>
using namespace std;


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

void solve2(vector<int> &c, vector<int> &d1, vector<int> &d2, int n, int i, vector<vector<string>> &result, vector<string> &cur)
{
     if (i == n)
     {
          result.push_back(cur);

          return;
     }

     for (int j = 0; j < n; j++)
     {
          if (!c[j] && !d1[i - j + n - 1] && !d2[i + j])
          {
               c[j] = 1;
               d1[i - j + n - 1] = 1;
               d2[i + j] = 1;
               cur[i][j] = 'Q';
               solve2(c, d1, d2, n, i + 1, result, cur);
               c[j] = 0;
               d1[i - j + n - 1] = 0;
               d2[i + j] = 0;
               cur[i][j] = '.';
          }
     }
}

vector<vector<int>> solve(int n)
{
     vector<int> col(n, 0);
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