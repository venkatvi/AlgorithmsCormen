#include <string>
#include <iostream>
using namespace std;
/* Problem: Find the minimal window in a string of characters which contains distinct characters. 
Idea: 
You need to find out the number of distinct characters present in all substrings of arbitrary length k of  the given string of length n
i.e for start position i = 1:n , for length j = 1:n, find distinct characters that the string has. 
Choose i,j s.t i,j are argmin of M where M of size nxn is the matrix which contains the distinct characters that occured at start position i for a length of substring j
How to do this?
O(n^2) solution 
for startpos = 1:n
	charBucketArray = 1x256 array
	for l=startpos:n
		if l == startpos
			M[startpos, l] = 1
		else
			char c = string[l] 
			if(charBucketArray[c]){ //char already occured
				M[startpos, l] = M[startpos, l-1]
			}else{
				M[startpos, l] = M[startpos, l-1] + 1;
			}

Alternative Solution: \
O(n)

distinctSqStart = 0;
distinctSqEnd = 0;
#distinctElems = 1;

soFarDistinctElemsSeen = #distinctElems
soFarDistinctStart = distinctSqStart;
soFarDistinctEnd = distinctSqEnd;


if s[i+1] != s[i]
	distrinctElems++;
	distinctSqEnd = i;
else
	
	if (#distinctElems > soFarDistinctElemsSeens){
		soFarDistinctElemsSeen = #distinctElems
		soFarDistinctStart = distinctSqStart;
		soFarDistinctEnd = distinctSqEnd;
	}

	distinctSqStart = i;
	distinctSqEnd = i;
	#distinctElems = 1;
*/

int findMaxWindowWithDistinctElems(string& s){
	int sqStart = 0, sqEnd = 0, numElems = 1;
	int resStart = sqStart, resEnd = sqEnd, res = numElems;

	int ascii[256];
	for(int i=0; i<256; i++){
		ascii[i] = 0;
	}
	ascii[s[0]] = 1;

	for(int i=1; i<s.length(); i++){
		if(ascii[s[i]] == 0){
			ascii[s[i]] = 1;
			sqEnd = i;
			numElems++;
		}else{
			if(numElems > res){
				res = numElems;
				resStart = sqStart;
				resEnd = sqEnd;
			}

			for(int j=0; j<256; j++){
				ascii[j] = 0;
			}
			ascii[s[i]] = 1;

			sqStart = i;
			sqEnd = i;
			numElems = 1;
		}
	}
	if (numElems > res){
		resStart = sqStart;
		resEnd = sqEnd;
		res = numElems; 
	}
	return res;
}
int main(int argc, char** argv){
	//Testcases
	//Case 1: empty string
	string s = "";
	int distinctElems = findMaxWindowWithDistinctElems(s);
	
	//Case 2: all distinct characters
	s = "abcde";
	distinctElems = findMaxWindowWithDistinctElems(s);
	
	//Case 3: all repeated characters
	s = "aaaaaa";
	distinctElems = findMaxWindowWithDistinctElems(s);
	
	//Case 4: distinct elems amidst repeated characters
	s = "aaabcdeebdeddcc";
	distinctElems = findMaxWindowWithDistinctElems(s);
	
	//Case 5: distinct elems of different length across string
	s = "abccccddedbcaaaa";
	distinctElems = findMaxWindowWithDistinctElems(s);
	
}