#include "../utils.hpp"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) { return true;}
        int index=0;
        while(index < n-1){
          int jumpLen = nums[index];
          if(jumpLen == 0){
            return false;
          }
          index = index+jumpLen;
        }
        if (index == n-1){
          return true;
        }
        return false;
    }
};
int main(int argc, char** argv){
  Solution s;
  vector<int> nums = {2, 3, 1, 1, 4};
  cout << print(nums) << " can jump? " << s.canJump(nums) << endl;

  vector<int> nums1 = {4, 0, 0, 0, 4};
  cout << print(nums1) << " can jump? " << s.canJump(nums1) << endl;

  vector<int> nums2 = {3, 2, 1, 0, 4};
  cout << print(nums2) << " can jump? " << s.canJump(nums2) << endl;

  vector<int> nums3 = {1};
  cout << print(nums3) << " can jump? " << s.canJump(nums3) << endl;

  vector<int> nums4 = {1, 1, 1, 1, 1};
  cout << print(nums4) << " can jump? " << s.canJump(nums4) << endl;

  vector<int> nums5 = {0, 0, 0, 0, 0};
  cout << print(nums5) << " can jump? " << s.canJump(nums5) << endl;
}
