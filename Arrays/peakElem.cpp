#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums, int low, int high) {
    	if(high <= low ){ int res = nums[low]<nums[high]?high:low;}
        int mid = low + ((high-low)/2);
        int elem = nums[mid];
        
        int leftNeighbor = ((mid-1) == -1)?INT_MIN:nums[mid-1];
        int rightNeighbor = ((mid+1) == nums.size())?INT_MIN:nums[mid+1];

        if (leftNeighbor < elem && elem  > rightNeighbor){
        	return mid;
        }
        if (leftNeighbor > elem){
        	return findPeakElement(nums, low, mid-1);
        }else if (rightNeighbor > elem){
        	return findPeakElement(nums, mid+1, high);
        }
    }
    int findPeakElement(vector<int>& nums){
    	int n = nums.size();
        if(n <= 1){return 0;}
        return findPeakElement(nums, 0, n-1);
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
	vector<int> nums  = {1, 2, 3, 4, 5};
	int res = s.findPeakElement(nums);
	cout << "Array:" << print(nums) << " Peak:" << res << endl;

	vector<int> nums1  = {1, 2, 3, 2, 5};
	res = s.findPeakElement(nums1);
	cout << "Array:" << print(nums1) << " Peak:" << res << endl;

	vector<int> nums2  = {1, 2, 3, 4, 2};
	res = s.findPeakElement(nums2);
	cout << "Array:" << print(nums2) << " Peak:" << res << endl;

	vector<int> nums3  = {1, 0, 0, 0, 0, 0, 2};
	res = s.findPeakElement(nums3);
	cout << "Array:" << print(nums3) << " Peak:" << res << endl;

	vector<int> nums4  = {1, 1, 1, 1};
	res = s.findPeakElement(nums4);
	cout << "Array:" << print(nums4) << " Peak:" << res << endl;

	vector<int> nums5  = {1};
	res = s.findPeakElement(nums5);
	cout << "Array:" << print(nums5) << " Peak:" << res << endl;

	vector<int> nums6  = {};
	res = s.findPeakElement(nums6);
	cout << "Array:" << print(nums6) << " Peak:" << res << endl;

	vector<int> nums7 = {-2147483647,-2147483648};
	res = s.findPeakElement(nums7);
	cout << "Array:" << print(nums7) << " Peak:" << res << endl;

	vector<int> nums8 = {-2147483648,-2147483647};
	res = s.findPeakElement(nums8);
	cout << "Array:" << print(nums8) << " Peak:" << res << endl;

	vector<int> nums9 = {1, 2};
	res = s.findPeakElement(nums9);
	cout << "Array:" << print(nums9) << " Peak:" << res << endl;

}