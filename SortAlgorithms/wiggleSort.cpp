#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int sIndex, int destIndex, bool isAscending){
        if((isAscending && (nums[sIndex] > nums[destIndex])) ||
            (!isAscending && (nums[sIndex] < nums[destIndex]))){
                int temp = nums[sIndex];
                nums[sIndex] = nums[destIndex];
                nums[destIndex] = temp;
        }
    }
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) { return ;}
        for(int i=0; i<nums.size()-1;i++){
            if(i%2 ==0){
                int minIndex = (std::min_element(nums.begin()+i+1, nums.end()) - nums.begin());
                swap(nums, i, minIndex, true);
                //else dont swap.
            }else{
                int maxIndex = (std::max_element(nums.begin()+i+1, nums.end()) - nums.begin());
                swap(nums, i, maxIndex, false);
            } 
        }   
    }
};
int main(int argc, char** argv){
	Solution s;
	vector<int> nums = {3, 5, 2, 1, 6, 4};
	s.wiggleSort(nums);

	for(auto x: nums){
		cout << x << endl;
	}
}
