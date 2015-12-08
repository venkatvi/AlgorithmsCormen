#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
private:
	int findInsertPos(vector<int>& nums, int low, int high, int target){
		if(high <= low){
			if(nums[low] == target){
				return low;
			}else{
				return -1;
			}
		}
		if(nums[low] == target){ return low;}
		if(nums[high] == target){ return high;}
		int mid = low + ((high-low)/2);
		if(nums[mid] == target){
			return mid;
		}else if(nums[mid] < target){
			int pos = findInsertPos(nums, mid+1, high, target);
			if(pos == -1){
				if(target > nums[high]){
					pos = high + 1;
				}else if(target < nums[mid+1]){
					pos = mid + 1;
				}
			}
			return pos;
		}else{
			int pos = findInsertPos(nums, low, mid-1, target);
			if( pos == -1){
				if(target < nums[low]){
					pos = low;
				}else if(target > mid-1) {
					pos = mid;
				}
			}
			return pos;
		}
	}
public:
    int searchInsert(vector<int>& nums, int target) {
    	if(nums.size() == 0) { return 0;}
    	if(nums.size() == 1) {
    		if(nums[0] >= target){
    			return 0;
    		}else{
    			return 1;
    		}
    	}
        return findInsertPos(nums, 0, nums.size()-1, target);
    }
};
string print(vector<int>& nums){
    stringstream ss;
    ss << "[";
    for(auto x: nums){
        ss << x << ",";
    }
    ss << "]";
    return ss.str();
}
int main(int argc, char** argv){
	Solution s;

	//TestCases:
	//{1}, 1
	//{}, 0
	vector<int> smallNums = {1};
	int pos = s.searchInsert(smallNums, 0);
	cout << "A: " << print(smallNums) << " Target:" << 0 << " Pos:" << pos << endl;
	
	pos = s.searchInsert(smallNums, 1);
	cout << "A: " << print(smallNums) << " Target:" << 1 << " Pos:" << pos << endl;
	
	pos = s.searchInsert(smallNums, 2);
	cout << "A: " << print(smallNums) << " Target:" << 2 << " Pos:" << pos << endl;
	
	smallNums.clear();
	pos = s.searchInsert(smallNums, 0);
	cout << "A: " << print(smallNums) << " Target:" << 0 << " Pos:" << pos << endl;
	
	pos = s.searchInsert(smallNums, 1);
	cout << "A: " << print(smallNums) << " Target:" << 1 << " Pos:" << pos << endl;
	
	pos = s.searchInsert(smallNums, 2);
	cout << "A: " << print(smallNums) << " Target:" << 2 << " Pos:" << pos << endl;
	
	smallNums.clear();
	smallNums.push_back(1), smallNums.push_back(3), smallNums.push_back(4);
	pos = s.searchInsert(smallNums, 0);
	cout << "A: " << print(smallNums) << " Target:" << 0 << " Pos:" << pos << endl;
	
	pos = s.searchInsert(smallNums, 2);
	cout << "A: " << print(smallNums) << " Target:" << 2 << " Pos:" << pos << endl;
	
	pos = s.searchInsert(smallNums, 3);
	cout << "A: " << print(smallNums) << " Target:" << 3 << " Pos:" << pos << endl;
	
	pos = s.searchInsert(smallNums, 4);
	cout << "A: " << print(smallNums) << " Target:" << 4 << " Pos:" << pos << endl;
	
	pos = s.searchInsert(smallNums, 5);
	cout << "A: " << print(smallNums) << " Target:" << 5 << " Pos:" << pos << endl;


	vector<int> nums = {1, 2, 3, 5, 8};
	// {1, 2, 3, 5}, 2
	for(int i =0; i<=9; i++){
		int pos = s.searchInsert(nums, i);
		cout << "A: " << print(nums) << " Target:" << i << " Pos:" << pos << endl;
	}

	// {1, 2, 3, 5}, 1
	// {1, 2, 3, 5}, 0
	// {1, 2, 3, 5}, 3
	// {1, 2, 3, 5}, 4
	// {1, 2, 3, 5}, 5
	// {1, 2, 3, 5}, 6
}