#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(n == 0 || m ==0){return -1;}
        if(n < m) {
        	return -1;
        }
        int i=m-1, j=m-1;

        while(i<n){

        	if(haystack[i] != needle[j]){
        		i++;
        	}else{
        		int count = 0; int k = i, l =j;
        		while(count < m){
        			if(haystack[k] == needle[l]){
        				k--;
        				l--;
        				count++;
        			}else{
        				break;
        			}
        		}
        		if(haystack == "mississipi"){
        			cout << "Count: " << count << " m:" << m << " k:" << k << endl;
        		}
        		if(count == m){
        			return k+1;
        		}else{
        			i++;
        		}
        	}
        }
        return -1;
    }
};
int main(int argc, char** argv){
	Solution s;
	//TestCases:
	string haystack ="abc";
	string needle = "";
	int output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	haystack = "";
	needle = "a";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;
		
	haystack = "abc";
	needle = "a";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;
	
	haystack = "abababab";
	needle = "ab";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;
	
	haystack = "apple";
	needle = "b";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;
	
	haystack = "aaaaaaaa";
	needle = "a";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;
	
	haystack = "abcdefgh";
	needle = "abcdefg";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;

	haystack = "abcdefgh";
	needle = "gh";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;


	haystack = "mississipi";
	needle = "pi";
	output = s.strStr(haystack, needle);
	cout << "HayStack:" << haystack << " Needle:" << needle << " Output:" << output << endl;
	
	
}