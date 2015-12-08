#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
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
string print(vector<vector<int>>& nums){
  stringstream ss;
  ss << "{";
  for(auto x:nums){
    ss << print(x) << "," << endl;
  }
  ss << "}";
  return ss.str();
}
class Solution {
private:
  int findMinSum(vector<vector<int>>& triangle, int row, vector<int>& memoizedSum){
    if(row == 0){
      memoizedSum[0] = triangle[0][0];
      return findMinSum(triangle, row+1, memoizedSum);
    }else{
      vector<int> newSum(memoizedSum.size(), 0);
      int n = triangle[row].size();
      for(int i=0; i<n; i++){
        if(i==0){
          newSum[i] = memoizedSum[0] + triangle[row][i];
        }
        else if(i == n-1){
          newSum[i] = memoizedSum[i-1]+ triangle[row][i];
        }else{
          newSum[i] = min(memoizedSum[i-1], memoizedSum[i]) + triangle[row][i];
        }
      }
      memoizedSum = newSum;

      if(row == triangle.size()-1){
        return *(std::min_element(memoizedSum.begin(), memoizedSum.end()));
      }else{
        return findMinSum(triangle, row+1, memoizedSum);
      }
    }
  }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      vector<int> levelSums(triangle.size());
      return findMinSum(triangle, 0, levelSums);
    }
};

int main(int argc, char** argv){
  Solution s;

  vector<vector<int>> triangle = {{1}, {2,3}, {4,5,6},{7,8,9,10}};
  int minSum = s.minimumTotal(triangle);
  cout << "Triangle:" << endl;
  cout << print(triangle) << endl;
  cout << "MinSum: " << minSum << endl;
  cout << "--------------------------" << endl;

  vector<vector<int>> triangle1 = {{1}, {-1, -4}, { -1, 2, -1}, {-3, 4, 0, 1}};
  minSum = s.minimumTotal(triangle1);
  cout << "Triangle:" << endl;
  cout << print(triangle1) << endl;
  cout << "MinSum: " << minSum << endl;
  cout << "--------------------------" << endl;

 }
