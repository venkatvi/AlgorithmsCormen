#include <iostream>
#include <sstream>
#include <string>
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
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> result;
        for(int i=0; i<nums.size(); i++){
          for(int j=i+1; j<nums.size(); j++){
            if((nums[i] + nums[j]) == target){
              result.push_back(i+1);
              result.push_back(j+1);
              return result;
            }
          }
        }
        return result;
    }
};
int main(int argc, char** argv){
  Solution s;
  vector<int> nums = {1, 2, 3, -1, 2, 1, 0};
  vector<int> res = s.twoSum(nums, 2);
  cout << "Input: " << print(nums) << " Result:" << print(res) << endl;

  vector<int> nums1 = {2, 7, 11, 15};
  vector<int> res1 = s.twoSum(nums1, 9);
  cout << "Input: " << print(nums1) << " Result:" << print(res1) << endl;
}
