#include <vector>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;
class Solution {
private:
	void getSubVersions(vector<string>& subVersions, string version){
		stringstream ss;
		for(int i=0; i<version.length(); i++){
			if(version[i] == '.'){
				subVersions.push_back(ss.str());
				ss.str("");
			}else{
				ss << version[i];
			}
		}
		subVersions.push_back(ss.str());
	}
public:
	int compareVersion(string version1, string version2, bool subVersionCompare){
		if((version1.length() == 0 || version1.empty()) && (version2.length() == 0 || version2.empty())) { return 0;}
        if((version1.length() == 0 || version1.empty()) && version2.length() !=0) { 
        	if(version2.length() == 1){
        		int v2 = atoi(version2.c_str());
        		if(!v2) { return 0;}
        	}
        	return -1; 
        }
        if((version2.length() == 0 || version2.empty()) && version1.length() !=0) { 
        	if(version1.length() == 1){
        		int v1 = atoi(version1.c_str());
        		if(!v1) { return 0;}
        	}
        	return 1; 
        }
        if (subVersionCompare){
        	int v1 = atoi(version1.c_str());
			int v2 = atoi(version2.c_str());
			if(v1 < v2){ return -1;}
			if(v1 > v2){ return 1;}
			if(v1 == v2) { return 0;}
    	}else{
	        //get all indices of '.'
			vector<string> subVersion1, subVersion2;
			getSubVersions(subVersion1, version1);
			getSubVersions(subVersion2, version2);

			int i=0, j=0;
			while(i < subVersion1.size() && j < subVersion2.size()){
				int res = compareVersion(subVersion1[i], subVersion2[j], true);
				if(res){
					return res;
				}else{
					i++;
					j++;
				}
			}
			//i is shorter than j or j is shorter than i
			while( i < subVersion1.size()){
				return compareVersion(subVersion1[i], "", true);
			}
			while ( j < subVersion2.size()){
				return compareVersion("", subVersion2[i], true);
			}
			return 0;
		}
	}
    int compareVersion(string version1, string version2) {
        if(version1.length() == 0 && version2.length() == 0) { return 0;}
        if(version1.length() == 0 && version2.length() !=0) { return -1; }
        if(version2.length() == 0 && version1.length() !=0) { return 1; }

        if(version1 == version2){ return 0;}
        std::size_t dotPos1 = version1.find('.');
        std::size_t dotPos2 = version2.find('.');
        
        int majorVersion1 = 0, majorVersion2 = 0, minorVersion1 = 0, minorVersion2 = 0;
        if(dotPos1 == string::npos){
        	minorVersion1 = 0;
        	dotPos1 = version1.length();
        }
        if(dotPos2 == string::npos){
        	minorVersion2 = 0;
        	dotPos2 = version2.length();
        }

     	stringstream ss1, ss2;
     	for(int it = 0; it < dotPos1; ++it){
     		ss1 << version1[it];
     	}   
     		 
     	for(int it = 0; it < dotPos2; ++it){
     		ss2 << version2[it];
     	}

     	if(!ss1.str().empty()){
     		 majorVersion1 = atoi((ss1.str()).c_str());
     	}
     	if(!ss2.str().empty()){
     		majorVersion2 = atoi((ss2.str()).c_str());
     	}
     	if(majorVersion1 > majorVersion2) { return 1;}
     	if(majorVersion1 < majorVersion2) { return -1;}
     	if(majorVersion1 == majorVersion2){
	     	ss1.str("");
	     	ss2.str("");
	     	for(int it = dotPos1+1; it < version1.length(); ++it){
	     		ss1 << version1[it];
	     	}    
	     	for(auto it = dotPos2+1; it < version2.length(); ++it){
	     		ss2 << version2[it];
	     	}
	     	if(!ss1.str().empty()){
	     		 minorVersion1 = atoi(ss1.str().c_str());
	     	}
	     	if(!ss2.str().empty()){
	     		minorVersion2 = atoi(ss2.str().c_str());
	     	}
	     	if(minorVersion1 > minorVersion2) { return 1;}
	     	if(minorVersion1 < minorVersion2) { return -1;}
	     	return 0;
     	}
     }
};
int main(int argc, char** argv){
	Solution s;
	//TestCases:
	//Case 1:
	string s1("");
	string s2("");
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;

	//Case 2:
	s1 = "0.0";
	s2 = "0.0";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	

	//Case 3:
	s1 = "";
	s2 = "0.0";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	


	//Case 4:
	s1 = "0.0";
	s2 = "";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	


	//Case 5:
	s1 = "0.1";
	s2 = "0.2";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	


	//Case 6:
	s1 = "1.0";
	s2 = "0.0";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	


	//Case 8:
	s1 = "1.3";
	s2 = "1.1";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	


	//Case 9:
	s1 = "13.1";
	s2 = "15.0";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	

	//Case 10:
	s1 = "1";
	s2 = "0";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	

	//Case 11:
	s1 = "1.0.1";
	s2 = "1.0";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	

	//Case 12:
	s1 = "01";
	s2 = "1";
	cout << "S1: " << s1 << " S2:" << s2 << " Result:" << s.compareVersion(s1, s2, false) << endl;	

}