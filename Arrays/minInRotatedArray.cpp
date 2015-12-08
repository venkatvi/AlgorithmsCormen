#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Solution {
public:
	int findMin(vector<int>&nums, int low, int high){
		if((high - low) == 1){
			return min(nums[high], nums[low]);
		}
		int mid = low + ((high-low)/2);
		if (nums[low] > nums[mid]){
			return findMin(nums, low, mid);
		}else if(nums[mid+1] > nums[high]){
			return findMin(nums, mid+1, high);
		}else if(nums[mid+1] < nums[mid]){
			return nums[mid +1];
		}
		return nums[0];
	}
    int findMin(vector<int>& nums) {
    	int n = nums.size();
		if(n == 0){return -1;}
		if(n == 1){ return nums[0];}
		return findMin(nums, 0, n-1);
    }
};
string print(vector<int>& nums){
	stringstream ss;
	ss << "{";
	for(auto x : nums){
		ss << x << ",";
	}
	ss << "}";
	return ss.str();
}
int main(int argc, char** argv){
	Solution s;
	vector<int> nums = {2, 4, 6, 8, 0};
	int res = s.findMin(nums);
	cout << "Array: " << print(nums) << " Min:" << res << endl;

	vector<int> nums1 = {1, 2, 3, 4, 5};
	res = s.findMin(nums1);
	cout << "Array: " << print(nums1) << " Min:" << res << endl;	

	vector<int> nums2 = {0, 1, 1000, 25000, -33, -6};
	res = s.findMin(nums2);
	cout << "Array: " << print(nums2) << " Min:" << res << endl;	


	vector<int> nums3 = {5, 6, 7, 8, 1, 2, 3, 4};
	res = s.findMin(nums3);
	cout << "Array: " << print(nums3) << " Min:" << res << endl;	

	vector<int> nums4 = {1};
	res = s.findMin(nums4);
	cout << "Array: " << print(nums4) << " Min:" << res << endl;	
}