#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;
string print(vector<int>& nums){
  stringstream ss;
  ss << "{";
  for(auto x : nums){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}
string print(vector<vector<int>>& nums){
  stringstream ss;
  ss << "{";
  for(auto x : nums){
    ss << print(x) << "," << endl;
  }
  ss << "}";
  return ss.str();
}
string print(map<int, int>& nums){
  stringstream ss;
  ss << "{";
  for(auto x : nums){
    ss << x.first << ":" << x.second << "," << endl;
  }
  ss << "}";
  return ss.str();
}
void print(vector<int>& input, vector<vector<int>>& output){
  cout << "Input:" << print(input) << endl;
  cout << "Output:" << endl;
  cout << print(output) <<endl;
  cout << "----------------------------------------" << endl;
}

class Solution {
private:
  void getAllSubsets(vector<int>& uniqueNums, vector<vector<int>>& subsets){
    if(uniqueNums.size() == 1){
      vector<int> temp(1, uniqueNums[0]);
      subsets.push_back(temp);
      return;
    }
    int n = uniqueNums.size();
    for(int i = 0; i<n; i++){
      vector<int> copyUniqueNums;
      std::copy(uniqueNums.begin(), uniqueNums.end(), std::back_inserter(copyUniqueNums));

      vector<int> newUniqueNums;
      if(i > 0){
        newUniqueNums.insert(newUniqueNums.end(), copyUniqueNums.begin(), copyUniqueNums.begin() + i );
      }
      if(i < n-1){
        newUniqueNums.insert(newUniqueNums.end(), copyUniqueNums.begin() + i + 1, copyUniqueNums.end());
      }
      getAllSubsets(newUniqueNums, subsets);

      //insert just that element in subset/
      vector<int> temp(1, uniqueNums[i]);
      subsets.push_back(temp);
    }
    subsets.push_back(uniqueNums);
  }
  string stringify(vector<int>& subset){
    stringstream ss;
    for(auto x:subset){
      ss << x << ",";
    }
    return ss.str();
  }
  vector<int> getUniqueElems(map<int, int>& repeatedCounts, vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> uniqueElems;
    int prev = nums[0];
    uniqueElems.push_back(nums[0]);
    for(int i=1; i<n; i++){
      if(nums[i] == prev){
        if(repeatedCounts.find(nums[i]) == repeatedCounts.end()){
          repeatedCounts.insert({nums[i], 1});
        }else{
          repeatedCounts[nums[i]] = repeatedCounts[nums[i]] + 1;
        }
      }else{
        uniqueElems.push_back(nums[i]);
      }
      prev = nums[i];
    }
    return uniqueElems;
  }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          int n = nums.size();
          sort(nums.begin(), nums.end());
          vector<vector<int>> subsets;
          getAllSubsets(nums, subsets);
          map<string, vector<int>> uniqueSubsets;
          vector<vector<int>> uniqueSubsetVec;
          for(int i=0; i<subsets.size(); i++){
            vector<int> subset = subsets[i];
            string subsetStr = stringify(subset);
            if(uniqueSubsets.find(subsetStr) == uniqueSubsets.end()){
              uniqueSubsets.insert({subsetStr, subset});
              uniqueSubsetVec.push_back(subset);
            }
          }
          return uniqueSubsetVec;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums, bool isUnique){
      int n = nums.size();
      map<int, int> repeatedCounts;
      vector<int> uniqueElems = getUniqueElems(repeatedCounts, nums);

      vector<vector<int>> subsets;
      getAllSubsets(uniqueElems, subsets);
      cout << "Subsets: " << subsets.size() << endl;
      cout << "Repeated: " << print(repeatedCounts) << endl;

      for(auto x:repeatedCounts){
        int elem = x.first;
        int count = x.second;
        for(int j=0; j<count;j++){
          vector<vector<int>> modifiedSubsets;
          for(auto y:subsets){
            vector<int> temp = y;
            temp.push_back(elem);
            modifiedSubsets.push_back(temp);
          }
          //add modified subsets to main subsets
          copy(modifiedSubsets.begin(), modifiedSubsets.end(), std::back_inserter(subsets));
        }
      }
      for(auto x:subsets){
        sort(x.begin(), x.end());
      }
      return subsets;
    }
};

int main(int argc, char** argv){
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
  vector<vector<int>> res = s.subsetsWithDup(nums, false);
  cout << "Output size:" << res.size() << endl;
  print(nums, res);
}
