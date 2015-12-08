#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	int n = nums.size();
        if(n <= 1) { return false;}

        if(k == 0) { return true; }
		if(t < 0) { return false; }

		if(t == 0){
			//about finding dups within k distance. 
			return containsNearbyDuplicate(nums, k);
		}
        map<int, int> buckets;
        for(int i =0; i<n; i++){
        	if (i > k){
        		int oldBucketEntry = nums[i-k-1]/ t;
        		if(buckets.find(oldBucketEntry) != buckets.end()){
        			buckets.erase(oldBucketEntry);
        		}
        	}
    		int key = nums[i]/t;
    		if( buckets.find(key) != buckets.end()){
    			return true;
    		}else if(buckets.find(key+1) != buckets.end()){
    			if(abs(buckets[key+1] - i) <= k){
    				return true;
    			}
    		}else if(buckets.find(key-1) != buckets.end()){
    			if(abs(buckets[key-1] - i) <= k){
    				return true;
    			}
    		}else{
    			buckets.insert({key, i});
    		}
        	
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> pos;
        for(int i =0; i<nums.size(); i++){
            if(pos.find(nums[i]) == pos.end()){
                vector<int> temp; temp.push_back(i);
                pos.insert({nums[i], temp});
            }else{
                vector<int>& poss = pos[nums[i]];
                poss.push_back(i);
            }
        }

        bool overAllResult = false;
        for(auto x : pos){
            int prevPos = -1;
            bool nearbyDupFound = false;
            for(auto y: x.second){
                if(prevPos == -1) {
                    prevPos = y;
                }else{
                    int d = y - prevPos;
                    if( d <=k) {
                        nearbyDupFound = true;
                        break;
                    }
                    prevPos = y;
                }
            }
            overAllResult = overAllResult | nearbyDupFound;
        }
        return overAllResult;
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
    
    vector<int> nums = {0, 2, 3, 5, 4, 7, 11, 9, 13, 9, 20, 28 };
    for (int k=0; k<nums.size(); k++){
    	for(int t=0; t<3; t++){
    		bool containsDup = s.containsNearbyAlmostDuplicate(nums, k, t);
    		cout << "A: " << print(nums) << " k:" << k << " t:" << t << " containsDup:" << containsDup << endl;
    	}
    }

    nums.clear();
    nums.push_back(-1); nums.push_back(-1);
    bool containsDup = s.containsNearbyAlmostDuplicate(nums, 0, 1);
    cout << "A: " << print(nums) << " k:" << 0 << " t:" << 1 << " containsDup:" << containsDup << endl;

    containsDup = s.containsNearbyAlmostDuplicate(nums, 1, 0);
    cout << "A: " << print(nums) << " k:" << 1 << " t:" << 0 << " containsDup:" << containsDup << endl;


    nums.clear();
    nums.push_back(1); nums.push_back(0); nums.push_back(1), nums.push_back(1);
    containsDup = s.containsNearbyAlmostDuplicate(nums, 1, 1);
    cout << "A: " << print(nums) << " k:" << 1 << " t:" << 1 << " containsDup:" << containsDup << endl;


    nums.clear();
    nums.push_back(-3); nums.push_back(1); nums.push_back(-1), nums.push_back(0), nums.push_back(10), nums.push_back(9), nums.push_back(4);
    containsDup = s.containsNearbyAlmostDuplicate(nums, 1, 2);
    cout << "A: " << print(nums) << " k:" << 1 << " t:" << 2 << " containsDup:" << containsDup << endl;

    nums.clear();
    nums.push_back(0); nums.push_back(10), nums.push_back(-1), nums.push_back(900), nums.push_back(4), nums.push_back(-3); ;
    containsDup = s.containsNearbyAlmostDuplicate(nums, 1, 2);
    cout << "A: " << print(nums) << " k:" << 1 << " t:" << 2 << " containsDup:" << containsDup << endl;

    containsDup = s.containsNearbyAlmostDuplicate(nums, 2, 2);
    cout << "A: " << print(nums) << " k:" << 2 << " t:" << 2 << " containsDup:" << containsDup << endl;
	
	nums.clear();
    nums.push_back(0); nums.push_back(10), nums.push_back(-1), nums.push_back(900), nums.push_back(4), nums.push_back(-3); ;
    containsDup = s.containsNearbyAlmostDuplicate(nums, 3, 2);
    cout << "A: " << print(nums) << " k:" << 3 << " t:" << 2 << " containsDup:" << containsDup << endl;

    nums.clear();
    nums.push_back(-1); nums.push_back(5); nums.push_back(-3);
    containsDup = s.containsNearbyAlmostDuplicate(nums, 1, 1);
    cout << "A: " << print(nums) << " k:" << 1 << " t:" << 1 << " containsDup:" << containsDup << endl;

    containsDup = s.containsNearbyAlmostDuplicate(nums, 1, 2);
    cout << "A: " << print(nums) << " k:" << 1 << " t:" << 2 << " containsDup:" << containsDup << endl;

    nums.clear();
    nums.push_back(0);
    containsDup = s.containsNearbyAlmostDuplicate(nums, 0, 0);
    cout << "A: " << print(nums) << " k:" << 0 << " t:" << 0 << " containsDup:" << containsDup << endl;

}
