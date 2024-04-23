/** @author	Hamza Bin Aamir
 * 	@brief	Typecasting Lab
 * 	@date	23rd April 2024
 */

#include <iostream> // contains cout, cin
using namespace std; // so we dont have to keep doing std::cout, std::cin

bool ImplicitConversion(); bool AssignmentConversion(); void printDivider();

int main()
{
	printDivider();
	ImplicitConversion(); // Implicit convertsion
	printDivider();
	AssignmentConversion(); // First Explicit conversion
	printDivider();

	return 0;
}

/**
 * @brief prints a divider to make the output neater
 * @returns false if error
*/
void printDivider()
{
	cout << "-----------------------------------------------------" << endl;
}

/**
 * @brief Implicitly converts values and outputs them 
 * @returns false if error
*/
bool ImplicitConversion()
{
	int i_Value = 10; cout << "i_Value is: " << i_Value << endl;
	char c_Value = 'a'; cout << "c_Value is: " << c_Value << endl;

	i_Value += 'a';

	cout << "After adding 'a' to i_Value, the new value is: " << i_Value << endl;

	i_Value += c_Value;

	cout << "After adding c_Value to i_Value after this, the new value is: " << i_Value << endl;

	return true;
}

/**
 * @brief Explicitly converts values (using assignment operator) and outputs them
 * @returns false if error
*/
bool AssignmentConversion()
{
	int a = 3;
	int b = 2;

	cout << "If you directly divide " << a << " by " << b << ", you will get the answer: ";
	float c = a/b;
	cout << c << endl;

	cout << "However, if you specify the explicit conversion using assignment operator, you will get the answer: ";
	c = (float)a/b;
	cout << c << endl;

	cout << "This even works if you first do an explicit conversion, then an implicit conversion: ";
	c = (double)a/b; // Note that 'c' is still a float here!
	cout << c << endl;

	return true;
}