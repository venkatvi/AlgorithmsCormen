#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
    int maxSubArray(vector<int>& nums) {
      if(nums.size() < 1) { return 0;}
      int maxStart = 0, start=0;
      int maxSum = nums[0], sumSoFar = maxSum;
      int cur = 1;
      while( cur < nums.size()){
        if((sumSoFar + nums[cur]) < nums[cur]){
            if(sumSoFar > maxSum){
              maxSum = sumSoFar;
              maxStart = start;
            }
            start = cur;
            sumSoFar = nums[cur];
          }else if((sumSoFar + nums[cur]) < sumSoFar){
             if(sumSoFar > maxSum){
               maxSum = sumSoFar;
               maxStart = start;
             }
            sumSoFar += nums[cur];
          }
          else{
            sumSoFar += nums[cur];
          }
          cur++;
      }
      if( sumSoFar > maxSum){
        maxSum = sumSoFar;
        maxStart = start;
      }
      return maxSum;
    }
};
int main(int argc, char** argv){
  Solution s;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int res = s.maxSubArray(nums);
  cout << "Input:" << print(nums) << " Res:" << res << endl;

  vector<int> nums1 = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
  res = s.maxSubArray(nums1);
  cout << "Input:" << print(nums1) << " Res:" << res << endl;

  vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  res = s.maxSubArray(nums2);
  cout << "Input:" << print(nums2) << " Res:" << res << endl;

  vector<int> nums3 = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, 0};
  res = s.maxSubArray(nums3);
  cout << "Input:" << print(nums3) << " Res:" << res << endl;

  vector<int> nums4 = {0, 1, -1, 2, -2, 3, -3, 5};
  res = s.maxSubArray(nums4);
  cout << "Input:" << print(nums4) << " Res:" << res << endl;

  vector<int> nums5 = {-2, -1};
  res = s.maxSubArray(nums5);
  cout << "Input:" << print(nums5) << " Res:" << res << endl;

  vector<int> nums6 = {1};
  res = s.maxSubArray(nums6);
  cout << "Input:" << print(nums6) << " Res:" << res << endl;

  vector<int> nums7 = {-1, -2, 3, 1, -3, -1, -2, 1, 1, 1, -4};
  res = s.maxSubArray(nums7);
  cout << "Input:" << print(nums7) << " Res:" << res << endl;

}
