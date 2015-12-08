#include <iostream>
#include <vector>
#include <algorithm>
#include "../utils.hpp"
using namespace std;
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int uniqueSets = 0;
      for(int i=0; i<nums.size(); i++){
        int j = i+1;
        int k = nums.size()-1;
        while(j<k){
          if(nums[i] + nums[j] + nums[k] < target){
            uniqueSets += k-j;
            j++;
          }else{
            k--;
          }
        }
      }
      return uniqueSets;
    }
};
int main(int argc, char** argv){
  Solution s;
  vector<int> nums = {-2, 0, 1, 3};
  int res = s.threeSumSmaller(nums, 2);
  cout << print(nums) << " : " << res << endl;
}
