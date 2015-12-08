#include <iostream>
using namespace std;
int findMaxChocolates(int a, int b, int c){
	
}
int main(int argc, char** argv){
	//TestCases: 
	//Case 1:
	// a = 1, b = 1, c = 1
	cout << "Box Dimesions: 1 x 1 x 1, Max Chocolates that can fit: " << findMaxChocolates(1, 1, 1) << endl;
	//Case 2:
	// a= 0, b = 0, c = 0
	cout << "Box Dimesions: 0 x 0 x 0, Max Chocolates that can fit: " << findMaxChocolates(0, 0, 0) << endl;

	//Case 3:
	// a = 8, b = 6, c = 10
	cout << "Box Dimesions: 8 x 6 x 10, Max Chocolates that can fit: " << findMaxChocolates(8, 6, 10) << endl;

	//Case 4:
	// a = 5, b = 7, c = 11
	cout << "Box Dimesions: 5 x 7 x 11, Max Chocolates that can fit: " << findMaxChocolates(5, 7 , 11) << endl;
	//Case 5: 
	// a = 10000, b = 2311211, c = 1212323
	cout << "Box Dimesions: 10000 x 2311211 x 1212323, Max Chocolates that can fit: " << findMaxChocolates(10000, 2311211, 1212323) << endl;
}