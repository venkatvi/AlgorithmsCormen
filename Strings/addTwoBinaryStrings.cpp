#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
class Solution {
private:
    int addTwoBits(char& sum, const int carryOver, const char& bit1, const char& bit2){
        bitset<1> b1(std::string(bit1));
        bitset<1> b2(std::string(bit2));
        bitset<1> b3; 
        b3[0] = carryOver;
        bitset<2> result = b1&b2&b3;
        sum = result[0] == 0?'0': '1';
        return (result[1]);
    }
public:
    string addBinary(string a, string b) {
        int n = 0;
        int k = 0;
        string
        if(a.length() > b.length()){
            n = b.length();
            k = a.length();
        }else{
            n = a.length();
            k = b.length();
        }

        string output(k, '0');
        int carryOver = 0;
        
        for(int i=0; i< n; i++){
            //add two bits with a carry
            carryOver = addTwoBits(output[n-i-1], carryOver, a[n-i-1], b[n-i-1]);
        }
        for(int i=k-n-1; i>=0; i++){
            carryOver = addTwoBits(output[i], carryOver, )
        }
        
    }
};