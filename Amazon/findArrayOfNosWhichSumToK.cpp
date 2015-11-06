#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void findArrayOfNosWhichSumToK(vector<int>& output, const vector<int>& input, int targetVal){
	int**  scoreboard = new int*[input.size()]
	for(int i=0; i < input.size(); i++){
		scoreboard[i] = new int[targetVal+1];
		for(int j=0; j<targetVal+1; j++){
			scoreboard[i][j] = 0;
		}
	}

	findArrayOfNosWhichSumToK()
}
int main(int argc, char** argv){
	//TestCases:
	//Case 1: Empty Array
	vector<int> input = {};
	vector<int> output;
	findArrayOfNosWhichSumToK(output, input, 10);

	//Case 2: Array with input 1
	input = {1};
	findArrayOfNosWhichSumToK(output, input, 10);

	//Case 3: Array with few numbers as input
	input = {1, 2, 3, 4, 5};
	findArrayOfNosWhichSumToK(output, input, 10);

	//Case 4: Array with INTMAxMIN boundaries
	input = {INT_MAX, INT_MIN, 1, -1};
	findArrayOfNosWhichSumToK(output, input, 10);
	findArrayOfNosWhichSumToK(output, input, INT_MAX);
	findArrayOfNosWhichSumToK(output, input, INT_MIN-1);
	findArrayOfNosWhichSumToK(output, input, 0);

	//Case 5: Large array of 10000 integers.
	input.clear();
	for(int i =0; i< 10000; i++){
		input.push_back(rand()%1000 + 1);
	}
	findArrayOfNosWhichSumToK(output, input, 10);
}