#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Solution{
private:
  int searchIn(vector<int>& elems, int low, int high, int target){
    if(high <= low){
      if (elems[low] == target){
        return low;
      }else if(elems[high] == target){
        return high;
      }else{
        return -1;
      }
    }
    int mid = low + ((high-low)/2);
    if(elems[mid] == target){
      return mid;
    }
    // 5 1 4
    //low - mid is out of order
    //mid - high and in order
    if (elems[low] > elems[mid]){
      if(elems[mid+1] <= target && target <= elems[high]){
        return searchIn(elems, mid+1, high, target);
      }else{
        return searchIn(elems, low, mid, target);
      }
    }else{
    // low - mid in order
    // mid - high out of order
    // 5 9 1
      if(elems[low] <= target && target <= elems[mid]){
        return searchIn(elems, low, mid, target);
      }else{
        return searchIn(elems, mid+1, high, target);
      }
    }
  }
public:
  int search(vector<int>& elems, int target){
    int n = elems.size();
    if(n == 0) { return -1;}
    if(n ==1 ){return (target == elems[0])?0:-1;}
    return searchIn(elems, 0, n-1, target);
  }
};
string print(vector<int>& colors){
  stringstream ss;
  ss << "{";
  for(auto x : colors){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}
int main(int argc, char** argv){
  Solution s;
  vector<int> nums = { 5, 6, 7, 1, 2, 3, 4};
  int target = 2;
  int res = s.search(nums, target);
  cout << "Input:" << print(nums) << " Target:" << target << " Res:" << res << endl;

  target = 5;
  res = s.search(nums, target);
  cout << "Input:" << print(nums) << " Target:" << target << " Res:" << res << endl;

  target = 7;
  res = s.search(nums, target);
  cout << "Input:" << print(nums) << " Target:" << target << " Res:" << res << endl;

  target = 3;
  res = s.search(nums, target);
  cout << "Input:" << print(nums) << " Target:" << target << " Res:" << res << endl;

  target =3;
  res = s.search(nums, target);
  cout << "Input:" << print(nums) << " Target:" << target << " Res:" << res << endl;

}
