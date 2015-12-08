#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
        	nums1 = nums2;
        	return ;
        }
        if(n == 0){
        	return;
        }
	    int i=m-1, j=n-1, k = nums1.size()-1;
	    while(i >= 0 && j >=0){
	    	nums1[k--] = (nums1[i] > nums2[j] ? nums1[i--]:nums2[j--]);
	    }
	    if(i < 0){
	    	while(j >=0){
	    		nums1[k--] = nums2[j--];
	    	}
	    }else{
	    	while( i >= 0){
	    		nums1[k--] = nums1[i--];
	    	}
	    }

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
void merge(vector<int>& a, vector<int>& b){
	Solution s;
	cout << "Inputs: A:" <<print(a) << "Size: " << a.size() << " B:" << print(b)<< " Size: " << b.size() << endl;
	s.merge(a, a.size()-b.size(), b, b.size());
	cout << "Output: " << print(a) << endl;
	cout << "------------------------------" << endl;

}
void vectorAssign(vector<int>& nums, std::initializer_list<int> data){
	copy(data.begin(), data.end(), back_inserter(nums));
}
int main(int argc, char** argv){
	//TestCases: 
	//{1,2} {3,4,5,6}
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {3,4,5,6};
	nums1.resize(nums1.size() + nums2.size());
	merge(nums1, nums2);

	//{1,2,3,5} {7,8}
	nums1.clear(); nums2.clear();
	vectorAssign(nums1, {1,2,3,5});
	vectorAssign(nums2, {7,8});
	nums1.resize(nums1.size() + nums2.size());
	merge(nums1, nums2);
	

	//{1,3,5,7} {2,4,6,8}
	nums1.clear(); nums2.clear();
	vectorAssign(nums1, {1,3,5,7});
	vectorAssign(nums2, {2,4,6,8});
	nums1.resize(nums1.size() + nums2.size());
	merge(nums1, nums2);

	//{1,2,3, 4} {1,2,3,4}
	nums1.clear(); nums2.clear();
	vectorAssign(nums1, {1,2,3,4});
	vectorAssign(nums2, {1,2,3,4});
	nums1.resize(nums1.size() + nums2.size());
	merge(nums1, nums2);


	// {} {1,2,3}
	nums1.clear(); nums2.clear();
	vectorAssign(nums2, {1,2,3});
	nums1.resize(nums1.size() + nums2.size());
	merge(nums1, nums2);

	// {1,2,3} {}
	nums1.clear(); nums2.clear();
	vectorAssign(nums1, {1,2,3});
	nums1.resize(nums1.size() + nums2.size());
	merge(nums1, nums2);

	// {} {}
	nums1.clear(); nums2.clear();
	nums1.resize(nums1.size() + nums2.size());
	merge(nums1, nums2);

}