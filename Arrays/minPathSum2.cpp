#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string print(vector<int>& nums){
  stringstream ss;
  ss << "{";
  for(auto x: nums){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}
string print(vector<char>& chars){
  stringstream ss;
  ss << "{";
  for(auto x: chars){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}
string print(vector<vector<int>>& nums){
  stringstream ss;
  ss << "{";
  for(auto x:nums){
    ss << print(x) << "," << endl;
  }
  ss << "}";
  return ss.str();
}
string print(vector<vector<char>>& path){
  stringstream ss;
  ss << "{";
  /*for(auto x:path){
    ss << print(x) << "," << endl;
  }*/
  int i=0, j=0;
  int m = path.size(), n = path[0].size();
  while(i <= m-1 && j <= n-1){
    char dir = path[i][j];
    ss << dir << "->";
    if(dir == 'D'){
      i = i+1;
    }else if(dir == 'R'){
      j = j+1;
    }else{
      break;
    }
  }
  ss << "}";
  return ss.str();
}
class Solution {
private:
  void findMinPathSum(vector<vector<int>>& grid, int i, int j, vector<vector<char>>& memoizedPath, vector<vector<int>>& memoizedSum){
    int m = grid.size(), n = grid[0].size();
    if(memoizedSum[i][j] == -1 ){
      int downSum = -1;
      int rightSum = -1;
      if (i<m-1){
        if(memoizedSum[i+1][j] == -1){
          findMinPathSum(grid, i+1, j, memoizedPath, memoizedSum);
        }
        downSum = memoizedSum[i+1][j];
      }
      if( j < n-1){
        if(memoizedSum[i][j+1] == -1){
          findMinPathSum(grid, i, j+1, memoizedPath, memoizedSum);
        }
        rightSum = memoizedSum[i][j+1];
      }
      if (downSum != -1 && rightSum != -1) {
        if (downSum < rightSum){
          memoizedSum[i][j] = grid[i][j] + memoizedSum[i+1][j];
          memoizedPath[i][j] = 'D';
        }else {
          memoizedSum[i][j] = grid[i][j] + memoizedSum[i][j+1];
          memoizedPath[i][j] = 'R';
        }
      }
      else{
        if (downSum == -1){
          memoizedSum[i][j] = grid[i][j] + memoizedSum[i][j+1];
          memoizedPath[i][j] = 'R';
        }else if (rightSum == -1) {
          memoizedSum[i][j] = grid[i][j] + memoizedSum[i+1][j];
          memoizedPath[i][j] = 'D';
        }else{
          memoizedSum[i][j] = grid[i][j];
          memoizedPath[i][j] = 'N';
        }
      }
    }
  }
public:
    int minPathSum(vector<vector<int>>& grid) {
      vector<int> temp(grid[0].size(), -1);
      vector<vector<int>> memoizedSum(grid.size(), temp);

      vector<char> tempC(grid[0].size(), 'N');
      vector<vector<char>> memoizedPath(grid.size(), tempC);

      findMinPathSum(grid, 0, 0, memoizedPath, memoizedSum);
      //cout << "Min Path: " << endl;
      //cout << print(memoizedPath) << endl;
      //cout << print(memoizedSum) << endl;
      return memoizedSum[0][0];
    }
};
int main(int argc, char** argv){
  Solution s;
  vector<vector<int>> grid = {{1,2}, {1,1}};//{{1, 2, 3}, {3, 4, 21}, {1, 1, 50}};
  int minsum = s.minPathSum(grid);
  cout << "Input:" << print(grid) << endl;
  cout << "MinPathSum:" << minsum << endl;

}
