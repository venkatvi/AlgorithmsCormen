#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;
class Solution {
public:
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
    vector<int> nums = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 1, 3, 0, 0, 2, 2, 3, 4};
    for(int i =0; i<5; i++){
        bool res = s.containsNearbyDuplicate(nums, i);
        cout << "Array: " << print(nums) << " k:" << i << " Result: " << res << endl;
     }

     nums.clear();
     for(int i=0; i<10; i++){
        nums.push_back(i);
     }
     bool res = s.containsNearbyDuplicate(nums, 2);
     cout << "Array: " << print(nums) << " k:" << 2 << " Result: " << res << endl; 

     nums.clear();
     nums.push_back(-1); nums.push_back(-1);
     res = s.containsNearbyDuplicate(nums, 1);
     cout << "Array: " << print(nums) << " k:" << 1 << " Result: " << res << endl; 

     nums.clear();
     nums.push_back(1);
     res = s.containsNearbyDuplicate(nums, 1);
     cout << "Array: " << print(nums) << " k:" << 1 << " Result: " << res << endl; 

    nums.clear();
    nums.push_back(99); nums.push_back(99);
    res = s.containsNearbyDuplicate(nums, 2);
    cout << "Array: " << print(nums) << " k:" << 2 << " Result: " << res << endl; 

    nums.clear();
    nums.push_back(1); nums.push_back(0); nums.push_back(1); nums.push_back(1);
    res = s.containsNearbyDuplicate(nums, 1);
    cout << "Array: " << print(nums) << " k:" << 2 << " Result: " << res << endl; 


}