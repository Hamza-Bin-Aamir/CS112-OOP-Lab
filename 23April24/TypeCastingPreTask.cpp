/** @author	Hamza Bin Aamir
 * 	@brief	Typecasting Lab
 * 	@date	23rd April 2024
 */

#include <iostream> // contains cout, cin
using namespace std; // so we don't have to keep doing std::cout, std::cin

bool ImplicitConversion(); bool AssignmentConversion(); 
bool ConstantConversion(); bool ReinterpretCast();
bool StaticCast(); bool DynamicCast();
void printDivider();
int ModifyStuff(int); int ModifyStuff(int*); 

int main()
{
	printDivider();
	ImplicitConversion(); // Implicit convertsion
	printDivider();
	AssignmentConversion(); // First Explicit conversion
	printDivider();
	ConstantConversion(); // Second Explicit Conversion, make a non-constant member constant
	//printDivider();
    // i don't know what's wrong with this
	//ReinterpretCast();
	printDivider();
	StaticCast();
	printDivider();
	DynamicCast();

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
	c = float(a)/b; // note that (datatype)value is the same as datatype(value) but dt(v) will be guaranteed to call the constructor
	cout << c << endl;

	cout << "This even works if you first do an explicit conversion, then an implicit conversion: ";
	c = double(a)/b; // Note that 'c' is still a float here!
	cout << c << endl;

	return true;
}

/**
 * @brief Explicitly converts from constant to non-constant 
 * @returns false if error
*/
bool ConstantConversion()
{
	int a = 4;
	const int b = 5;
	const int* c = &a;

	// this is example code that shows what happens if you don't use const conversion
#	ifdef THIS_CODE_WONT_WORK
		ModifyStuff(c); // This won't work because the modify stuff function is expecting a constant pointer not a pointer
#	endif

	// correctly working code
	ModifyStuff(
		const_cast 	// calling constant cast operation
		<int*>  	// expected output data type
		(c) 		// the input value to modify
		);
	// in a single line
	cout << "The constant pointer's value was converted to: " << ModifyStuff(const_cast <int*> (c)) << endl;

#	ifdef THIS_CODE_WONT_WORK
		// This code will run but it is a runtime error, as it will cause undefined behavior
		ModifyStuff(
			const_cast <int> (b); // the problem here is, that we are DIRECTLY trying to modify b, which is a constant value
		)
#	endif

	return true;
}

/**
 * @brief Dereferences the pointer and adds one to it
 * @returns The new value
*/
int ModifyStuff(int* NonConstantPointer)
{
	return *NonConstantPointer = *NonConstantPointer + 1; 	// Note how we do not edit the pointer, but rather only READ it
															// We will edit the value NonConstantPointer is pointing to
}

/**
 * @brief Takes the reference of an object and adds one to it
 * @returns The new value
*/
int ModifyStuff(int& NonConstantValue)
{
	return NonConstantValue + 1;
}

/**
 * @brief Uses the reinterpret operator and adds one to it
 * @returns false if error
*/
bool ReinterpretCast()
{
	// this directly converts the value between each other
	// Note: VERY dangerous, and should be used sparingly
	long *ptr = new long(97);
	int *ch = reinterpret_cast<int*>(ptr);

	cout << "ptr: \t" 	<< ptr 	<< endl;
	cout << "ch: \t" 	<< ch 	<< endl;
	cout << "*ptr: \t" 	<< *ptr	<< endl;
	cout << "*ch: \t"	<< *ch 	<< endl;

	delete ptr; // always remember to free your memory 
}

/**
 * @brief Explicitly converts the values
 * @returns false if error
*/
bool StaticCast()
{
	size_t a = static_cast<size_t>(3.14159264f);
	cout << "3.14159264f statically converted from float to an unsigned integer: " << a;
}
