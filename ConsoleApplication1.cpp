/* Created by: Aquiles Gomez on June 29th, 2017
This will be a sample program that will house multiple functions. It will eventually expand as I add more and more ideas to it.*/
//TODO: Add exceptions for all of these functions, ensure that they are robust to user input as well as the ability to loop back to the main function should they type EXIT

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>		// std::setprecision
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function will check that the user inputs a float into the function  

// This function will calculate the tax after the user inputs a price and a tax value and return the total amount of tax as well as the final price 
double TAX_CALCULATOR(){
	double price = 0.00; 
	double tax_rate = 0.00; 
	double total_tax = 0.00; 
	double total_value = 0.00;

	std::cout << "You have selected TAX CALCULATOR.\nThis function caculates the tax and total value for a speicified price" << std::endl; 
	std::cout << "What is the price of the item? \nPlease input in dollars and cents" << std::endl;
	std::cin >> price;
	/*TODO: What if they enter only dollars, but no cents? what if they enter zero, string or a negative number?*/
	// Check that the input is valid 
		// Check if the user used a string as an input 
		// Check if they used a negative number as an input (!cin)? 
	std::cout << "Thank you. \nWhat's the tax rate? Input the value in percentage up to two decimal places." << std::endl;
	std::cin >> tax_rate;
	/*TODO: What if they input a single digit, string, or a negative number?*/
	tax_rate = tax_rate / 100; 
	total_tax = tax_rate * price; 
	total_value = total_tax + price; 

	std::cout << "Thanks! The result is:" << std::endl;
	std::cout << std::fixed;										// Set the value fixed so that it rounds to the nearest hundreth 
	std::cout << "The total price of the item is:" << std::endl;
	std::cout << std::setprecision(2) << total_value << std::endl;
	std::cout << "The total tax applied is:" << std::endl;
	std::cout << std::setprecision(2) << total_tax << std::endl;
	return 0; 
}

// This function will calculate the factorial of any positive integer the user inputs 
float FACTORIAL() {
	float n; 
	int i = 1;
	std::cout << "You have selected the FACTORIAL calculator. \nThis function will calculate the factorial for any positive integer you enter." << std::endl;
	std::cout << "Please input a positive integer" << std::endl;
	std::cin >> n; 
	/*TODO: What if they enter a string, or negative number or deicimal number*/
	float factorial = n;
	if (n == 0) {
		std::cout << "The factorial of 0 is: 1" << std::endl;
		return 0;
	}
	while (i != n) {
		factorial = factorial *(n - i);
		i++;
	}
	std::cout << "The factorial of " << n << " is: " << factorial << std::endl;
	return 0;
}

// This function will simulate a coin flip and return the results for the specified number of flips. 
int COIN_FLIP()
{
	int flip_number;
	int flip_result;
	int counter; 
	std::cout << "You selected the coin flip simulator." << std::endl;
	std::cout << "This function will allow you select the number of flips and then display the results for the flips." << std::endl;
	std::cout << "What is the total number of flips?\nPlease enter the number as a positive integer." << std::endl;
	std::cin >> flip_number; 
	/*TODO: What if they enter a string or negative number or very large number? */
	if (flip_number == 0) {
		std::cout << "You need to flip the coin at least once to obtain a result" << std::endl;
	}
	else {
		std::cout << "The result is displayed with the flip number on the left and result on the right." << std::endl;
		std::cout << "[flip number, flip result]" << std::endl;
		for (counter = 1; counter <= flip_number; counter++) {
			srand(time(NULL));	
			flip_result = rand() % 2 + 1; 
			std::cout << "The result for flip " << counter << " is " << flip_result << std::endl;
			_sleep(2000);								// Prevents the number from being generated again 

		}
	}
	return 0;
}

/*Calculate Pi to the Nth digit 
int CALCULATE_PI() {

}
// Calculate e to the nth digit 
int CALCULATE_E() {

}
// Perform the Fibonacci sequence to the nth number 
int FIBONACCI() {

}
*/
int main() {
	TAX_CALCULATOR();
	return 0;
}

