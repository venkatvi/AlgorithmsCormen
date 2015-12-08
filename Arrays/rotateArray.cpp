#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <time.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k < 0 || nums.size() == 0) { return; }
        for(int i =1; i <= k; i++){
            int elem = nums[nums.size()-1];
            nums.pop_back();
            nums.insert(nums.begin(), elem);
        }
    }
    void rotate1( vector<int>& nums, int k){
    	if(k < 0 || nums.size() == 0) { return; }
    	int n = nums.size();
    	vector<int> newNums;

    	copy(nums.begin(), nums.end(), back_inserter(newNums));
    	copy(nums.begin(), nums.end(), back_inserter(newNums));
    	newNums.erase(newNums.begin(), newNums.begin()+n-k);
    	newNums.erase(newNums.begin()+n, newNums.end());
    	nums = newNums;
    }
    void rotate2(vector<int>& nums, int k){
    	if(k < 0 || nums.size() == 0) { return; }
    	int n = nums.size();
    	for(int i=0; i < k; i++){
    		int lastElem = nums[nums.size()-1];
    		for(int j=n-2; j >=0; j--){
    			nums[j+1] = nums[j];
    		}
    		nums[0] = lastElem;
    	}
    }
    void rotate3(vector<int>& nums, int k){
    	if(k < 0 || nums.size() <= 1) { return; }
    	int n = nums.size();
    	
    	k = k%n;
    	int i = 0, j = n-k-1;
    	while(i<j){
    		swap(nums[i], nums[j]);
    		i++;
    		j--;
    	}
    	i = n-k; j = n-1;
    	while(i<j){
    		swap(nums[i], nums[j]);
    		i++;
    		j--;	
    	}
    	i = 0, j = n-1;
    	while(i<j){
    		swap(nums[i], nums[j]);
    		i++;
    		j--;	
    	}
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

	vector<int> nums = {1, 2, 3,4, 5,6, 7};
	int numRotations = 7;
	clock_t t;
	t = clock();
	for(int i =0; i<numRotations; i++){
		int k = i;
		s.rotate(nums, k);
	//	cout << "Rotated: " << print(nums) << " K:" << k << endl;
	}
	t = clock() - t;
	cout << "Method 1 : vector pop!" << endl;
	cout << "Time taken: " << (float(t)/CLOCKS_PER_SEC) << " s,[O(k) + ?? for insert at front.] " << endl;
	cout << "Space: O(n) - depends on default vector size and doubling condition." << endl;
	cout << "-------------------------------------------" << endl;

	t = clock();
	for(int i =0; i<numRotations; i++){
		int k = i;
		s.rotate1(nums, k);
	//	cout << "Rotated: " << print(nums) << " K:" << k << endl;
	}
	t = clock() - t;
	cout << "Method 2 : rotate and extract!" << endl;
	cout << "Time taken: " << (float(t)/CLOCKS_PER_SEC) << " s, [O(n) for append and extract]" << endl; 
	cout << "Space: O(2n)" << endl;
	cout << "-------------------------------------------" << endl;
	
	t = clock();
	for(int i =0; i<numRotations; i++){
		int k = i;
		s.rotate2(nums, k);
	//	cout << "Rotated: " << print(nums) << " K:" << k << endl;
	}
	t = clock() - t;
	cout << "Method 3 : push elements to right from left for i=1:n" << endl;
	cout << "Time taken: " << (float(t)/CLOCKS_PER_SEC) << " s, [O(n*k)" << endl;
	cout << "Space: O(1)" << endl;
	cout << "-------------------------------------------" << endl;
	
	t = clock();
	for(int i =0; i<numRotations; i++){
		int k = i;
		s.rotate3(nums, k);
	//	cout << "Rotated: " << print(nums) << " K:" << k << endl;
	}
	t=clock() - t;
	cout << "Method 4: triple reverse" << endl;
	cout << "Time taken:  " << (float(t)/CLOCKS_PER_SEC) << " s, [O(n) for reverse]" << endl;
	cout << "Space: O(1)" << endl;
}	