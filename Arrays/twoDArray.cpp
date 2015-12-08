#include <iostream>
#include <random>
using namespace std;
int main(int argc, char** argv){
	int n=10;
	int m=10;
	int** arr = new int*[n];
	for(int i=0; i<n; i++){
		arr[i] = new int[m];
		for(int j=0; j<m; j++){
			arr[i][j] = rand()%10 + 1;
		}
	}
	for(int i=0; i<n; i++){
		int* vals = *(arr + i);
		cout << "{" ;
		for(int j=0; j<m; j++){
			cout << vals[j] << ",";
		}
		cout << "}" << endl;
	}

}