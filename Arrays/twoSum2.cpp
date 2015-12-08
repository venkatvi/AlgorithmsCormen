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
      int n = nums.size();
      vector<int> twoSums;
      if(n <=1){
        return twoSums;
      }
      int i=0, j=n-1;
      while(i < j){
        int s = nums[i] + nums[j];
        while(s > target && j > i){
          j--;
          s = nums[i] + nums[j];
        }
        if ( s == target){
          twoSums.push_back(i+1);
          twoSums.push_back(j+1);
          return twoSums;
        }else{
          // i+j < target
          while (s < target && i < j){
            i++;
            s = nums[i] + nums[j];
          }
          if (s == target){
            twoSums.push_back(i+1);
            twoSums.push_back(j+1);
            return twoSums;
          }
        }
      }
      return twoSums;
    }
};
int main(int argc, char** argv){
  Solution s;
  int target = 0;
  vector<int> nums = { -2, -1, 0, 1,  2};
  vector<int> res = s.twoSum(nums, target);
  cout << "Input: " << print(nums) << " Output:" << print(res) << endl;

  vector<int> nums1 = {-1, 0, 1, 2};
  vector<int> res1 = s.twoSum(nums1, target);
  cout << "Input: " << print(nums1) << " Output:" << print(res1) << endl;

  target = 3;
  vector<int> nums2 = {-3, -1, 1, 4};
  vector<int> res2 = s.twoSum(nums2, target);
  cout << "Input: " << print(nums2) << " Output:" << print(res2) << endl;


}
