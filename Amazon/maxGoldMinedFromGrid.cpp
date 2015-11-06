#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
/* Problem: Given a grid of size mxn, find max gold that can be collected by a cell to cell traversal
Rules: 1. You always start from column 1, (any row equally likely)
2. You can go only in three possible directions - right, right-up, righ-down

Solution: Idea: Dynamic programming to memoize the possible max gold collected at each column's cell. 
Time: O(mn), Space: O(1) write inmemory 
*/
int getMaxGoldCollected(int** goldMine, int rowCount, int colCount){
	int maxGoldCollected = 0;
	for (int i=0; i<rowCount; i++){
		for(int j=0; j<colCount; j++){
			if(j != 0){
				int a = 0, b = 0;
				if(i-1 >= 0){
					a = goldMine[i-1][j-1];
				}
				if(i+1 <= rowCount-1){
					b = goldMine[i+1][j-1];
				}
				goldMine[i][j] = max(max(a, b), goldMine[i][j-1]) + goldMine[i][j];
			}
			if(j == colCount-1 && maxGoldCollected < goldMine[i][j]){
				maxGoldCollected = goldMine[i][j];
			}
		}
	}
	return maxGoldCollected;
}
int main(int argc, char** argv){
	//TestCases:
	//Case 1 : Random Matrix
	clock_t t;
	int m = 5, n = 5;
	int** goldMine = new int*[m];
	for(int i=0; i<m; i++){
		goldMine[i] = new int[n];
		for(int j=0; j<n; j++){
			goldMine[i][j] = rand()%100+1;
			cout << "goldMine[" << i<< "][" << j << "] = " << goldMine[i][j] << endl; 
		}
	}
	t = clock();
	cout << "Max gold collected: " << getMaxGoldCollected(goldMine, m, n) << endl;
	t = float(clock() -t)/CLOCKS_PER_SEC;
	cout << "Completed in " << t << " seconds" << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Case 2: Single Column
	m=5, n =1;
	goldMine = new int*[m];
	for(int i=0; i<m; i++){
		goldMine[i] = new int[n];
		for(int j=0; j<n; j++){
			goldMine[i][j] = i;
			cout << "goldMine[" << i<< "][" << j << "] = " << goldMine[i][j] << endl; 
		}
	}
	t = clock();
	cout << "Max gold collected: " << getMaxGoldCollected(goldMine, m, n) << endl;
	t = float(clock() -t)/CLOCKS_PER_SEC;
	cout << "Completed in " << t << " seconds" << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Case 3: Single Row
	m=1, n =5;
	goldMine = new int*[m];
	for(int i=0; i<m; i++){
		goldMine[i] = new int[n];
		for(int j=0; j<n; j++){
			goldMine[i][j] = j;
			cout << "goldMine[" << i<< "][" << j << "] = " << goldMine[i][j] << endl; 
		}
	}
	t = clock();
	cout << "Max gold collected: " << getMaxGoldCollected(goldMine, m, n) << endl;
	t = float(clock() -t)/CLOCKS_PER_SEC;
	cout << "Completed in " << t << " seconds" << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Case 4: Single value
	m=1, n =1;
	goldMine = new int*[m];
	for(int i=0; i<m; i++){
		goldMine[i] = new int[n];
		for(int j=0; j<n; j++){
			goldMine[i][j] = 10;
			cout << "goldMine[" << i<< "][" << j << "] = " << goldMine[i][j] << endl; 
		}
	}
	t = clock();
	cout << "Max gold collected: " << getMaxGoldCollected(goldMine, m, n) << endl;
	t = float(clock() -t)/CLOCKS_PER_SEC;
	cout << "Completed in " << t << " seconds" << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Case 5: Empty matrix
	m=0, n =0; 
	goldMine = new int*[m];
	for(int i=0; i<m; i++){
		goldMine[i] = new int[n];
		for(int j=0; j<n; j++){
			goldMine[i][j] = 10;
			cout << "goldMine[" << i<< "][" << j << "] = " << goldMine[i][j] << endl; 
		}
	}
	t = clock();
	cout << "Max gold collected: " << getMaxGoldCollected(goldMine, m, n) << endl;
	t = float(clock() -t)/CLOCKS_PER_SEC;
	cout << "Completed in " << t << " seconds" << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Case 6: Negative Values
	m=3, n =3;
	goldMine = new int*[m];
	for(int i=0; i<m; i++){
		goldMine[i] = new int[n];
		for(int j=0; j<n; j++){
			goldMine[i][j] = i*j*-1;
			cout << "goldMine[" << i<< "][" << j << "] = " << goldMine[i][j] << endl; 
		}
	}
	t = clock();
	cout << "Max gold collected: " << getMaxGoldCollected(goldMine, m, n) << endl;
	t = float(clock() -t)/CLOCKS_PER_SEC;
	cout << "Completed in " << t << " seconds" << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Case 6: Overflows
	m=3, n =3;
	goldMine = new int*[m];
	for(int i=0; i<m; i++){
		goldMine[i] = new int[n];
		for(int j=0; j<n; j++){
			goldMine[i][j] =  INT_MAX;
			cout << "goldMine[" << i<< "][" << j << "] = " << goldMine[i][j] << endl; 
		}
	}
	t = clock();
	cout << "Max gold collected: " << getMaxGoldCollected(goldMine, m, n) << endl;
	t = float(clock() -t)/CLOCKS_PER_SEC;
	cout << "Completed in " << t << " seconds" << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Case 7: Large M, N
	m=10000, n =100000;
	goldMine = new int*[m];
	for(int i=0; i<m; i++){
		goldMine[i] = new int[n];
		for(int j=0; j<n; j++){
			goldMine[i][j] =  rand()%10000 + 1;
			//cout << "goldMine[" << i<< "][" << j << "] = " << goldMine[i][j] << endl; 
		}
	}
	t = clock();
	cout << "Max gold collected: " << getMaxGoldCollected(goldMine, m, n) << endl;
	t = float(clock() -t)/CLOCKS_PER_SEC;
	cout << "Completed in " << t << " seconds" << endl;
	cout << "-----------------------------------------------------------" << endl;

	return 0;
}