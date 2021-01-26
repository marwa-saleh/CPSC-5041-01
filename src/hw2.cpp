// AUTHOR: Sample Solution HW2-5041
// DATE: Winter 5041 2021
// PURPOSE: This program is used to test the custom designed
//          division method for converting decimal numbers to binary.
// INPUT:   Prompts from user.
// PROCESS: There are one tests, to verify divison by base.
//          After the tests, a client program runs, prompting the user
//          for values that will be used to divide by the
//          number entered.
// OUTPUT:  Prints results of tests and division of value by number entered by user
#include <iostream>
#include <string>
using namespace std;
// Function:    runProgram
// Purpose:     Calls function decimalToBinary().
// Parameters:  None
// Returns:     None
void runProgram();

// Function:    validate and convert decimal to binary
// Purpose:     validate the num and then Divide num by the base 2.
// Parameters:  The input value input
// Returns:     None
void validateAndConvertDecToBinary(double input);

// Function:    convert decimal to binary
// Purpose:     Divide num by the base 2.
// Parameters:  The number num
// Returns:     None
void decimalToBinary(int num);

// Function:    testConvertDecimalToBinary
// Purpose:     Tests the function decimalToBinary
// Parameters:  None
// Returns:     None
void testConvertDecimalToBinary();

int main() {
	std::cout << "\n---- HOMEWORK 2 ----" << std::endl;
	testConvertDecimalToBinary();
	runProgram();
	return 0;
}

void runProgram() {
	std::cout << "\n---- CLIENT PROGRAM ----" << std::endl;
	cout << "\nEnter number: ";
	double input;
	cin >> input;

	if (!cin) {
		cout << "\n ERROR, input value is not a number";
		return;
	}

	validateAndConvertDecToBinary(input);
}

void validateAndConvertDecToBinary(double input) {
	int num = (int) input;
	float float_num = input - num;

	if (float_num > 0) {
		cout << "\n" << "floating numbers are not handelled" << std::endl;
		return;
	}

	decimalToBinary(num);
}

void decimalToBinary(int num) {
	if (num < 0) {
		cout << "\n" << "number must be positive number" << std::endl;
		return;
	}

	string result;
	int quotient = num;

	if (quotient == 0) {
		result = "0";
	}

	while (quotient > 0) {
		int remainder = quotient % 2;
		quotient = quotient >> 1;
		result.insert(0, to_string(remainder));
	}

	cout << "\n" << num << " to base " << 2 << " is " << stol(result)
			<< std::endl;
}

void testConvertDecimalToBinary() {
	std::cout << "\n---- Assumptions ----" << std::endl;
	std::cout << "* Test #1:  100 to base 2: ";
	validateAndConvertDecToBinary(100);
	std::cout << "* Test #2:  657 to base 2: ";
	validateAndConvertDecToBinary(657);
	std::cout << "* Test #3:  54.6 to base 2: ";
	validateAndConvertDecToBinary(54.6);
	std::cout << "* Test #4:  8 to base 2: ";
	validateAndConvertDecToBinary(8);
	std::cout << "* Test #5:  -2 to base 2: ";
	validateAndConvertDecToBinary(-2);
	std::cout << "* Test #6:  0 to base 2: ";
	validateAndConvertDecToBinary(0);
}
