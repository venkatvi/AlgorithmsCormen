#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Solution {
private:
  int findMissingNumber(vector<int>& nums, int l, int h){
    if( h <= l){
      if(nums[h] != h){
        return h;
      }
    }
    int mid = l + ((h-l)/2);
    if(nums[mid] != mid){
      return findMissingNumber(nums, l, mid);
    }else{
      return findMissingNumber(nums, mid+1, h);
    }
    return -1;
  }
public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      if (n == 0) { return -1;}
      if (n == 1) { return (nums[0] == 0)? 1:0; }
      int res = findMissingNumber(nums, 0, n);
      if(res == -1){
        return nums.size();
      }
      return res;
    }
};

string print(vector<int>& nums){
  stringstream ss;
  ss << "{";
  for(auto x: nums){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}

int main(int argc, char** argv){
  Solution s;
  vector<int> nums = {1};
  int res = s.missingNumber(nums);
  cout << "Input: " << print(nums) << " Missing:" << res << endl;

  vector<int> nums1 = {0, 1, 2, 4};
  res = s.missingNumber(nums1);
  cout << "Input: " << print(nums1) << " Missing:" << res << endl;

  vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7};
  res = s.missingNumber(nums2);
  cout << "Input: " << print(nums2) << " Missing:" << res << endl;

  vector<int> nums3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
  res = s.missingNumber(nums3);
  cout << "Input: " << print(nums3) << " Missing:" << res << endl;

  vector<int> nums4 = {0};
  res = s.missingNumber(nums4);
  cout << "Input: " << print(nums4) << " Missing:" << res << endl;

  vector<int> nums5 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  res = s.missingNumber(nums5);
  cout << "Input: " << print(nums5) << " Missing:" << res << endl;


}
