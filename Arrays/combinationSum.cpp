#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
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
string print(set<vector<int>>& nums){
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
  bool getCandidateCombos(vector<int>& candidates, int s, int e, int target, map<string, vector<int>>& discoveredPaths, vector<int>& currentPath, set<vector<int>>& allPaths){
    //cout << "C:" << print(candidates) << " Target:" << target << " CurrentPath:" << print(currentPath) << " All Paths:" << print(allPaths) << endl;
    int n = candidates.size();
    if(target== 0){
      allPaths.insert(currentPath);
      return true;
    }
    if (n == 0){
      return false;
    }
    stringstream ss;
    ss << s << "_" << e << "_" << target;
    string key = ss.str();
    if(discoveredPaths.find(key) != discoveredPaths.end()){
      return true;
    }
    for(int i=0; i<n; i++){
      int m = target/candidates[i];
      for(int j=0; j<=m; j++){
        int targetNew = target - (candidates[i]*j);
        if (targetNew >= 0){
          for (int k=0; k<j; k++){
            currentPath.push_back(candidates[i]);
          }
          bool res = getCandidateCombos(candidates, i+1, n-1,  targetNew, discoveredPaths, currentPath, allPaths);
          if(res){
            if (discoveredPaths.find(key) != discoveredPaths.end()){
              set<vector<int>>& paths = discoveredPaths[key];
              paths.insert(currentPath);
            }else{
              set<vector<int>>paths = {currentPath};
              discoveredPaths.insert({key, paths});
            }
          }
          for (int k=0; k<j; k++){
            currentPath.pop_back();
          }
        }
      }
    }
    if(discoveredPaths.find(key) != discoveredPaths.end()){
      return true;
    }
    return false;
  }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      set<vector<int>> allPaths;
      vector<int> currentPath;
      map<string, set<vector<int>>> discoveredPaths;
      sort(candidates.begin(), candidates.end());
      getCandidateCombos(candidates, 0, candidates.size()-1, target, discoveredPaths, currentPath, allPaths);

      vector<vector<int>> allPathsVec;
      for(auto x:allPaths){
        allPathsVec.push_back(x);
      }
      return allPathsVec;
    }
};
int main(int argc, char** argv){
  Solution s;
  vector<int> nums = {2, 3, 6, 7};
  vector<vector<int>> res = s.combinationSum(nums, 7);
  cout << "Input:" << print(nums) << " Output:" << print(res)  << endl;

  vector<int> nums1 = {1, 6, 12};
  vector<vector<int>> res1 = s.combinationSum(nums1, 18);
  cout << "Input:" << print(nums1) << " Output:" << print(res1)  << endl;

  //[48,22,49,24,26,47,33,40,37,39,31,46,36,43,45,34,28,20,29,25,41,32,23]
  //69
  //Answer: [[20,20,29],[20,23,26],[20,24,25],[20,49],[22,22,25],[22,23,24],[22,47],[23,23,23],[23,46],[24,45],[26,43],[28,41],[29,40],[32,37],[33,36]]
}
