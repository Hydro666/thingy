/* Created by: Aquiles Gomez on June 29th, 2017
This will be a sample program that will house multiple functions. It will eventually expand as I add more and more ideas to it.*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>		// std::setprecision
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// This function checks that an integer was used as an input 
int VALID_INT_INPUT() {
	int x; 
	std::cin >> x; 
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "I'm sorry, this input is not accepted. Please enter an integer: "; 
		std::cin >> x; 
	}
	return x; 
}

// This function checks that a number was used as an input (double)
double VALID_NUM_INPUT() {
	double x; 
	std::cin >> x; 
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "I'm sorry, this input is not accepted. Please enter a number: ";
		std::cin >> x;
	}
	return x; 
}

// This function will calculate the tax after the user inputs a price and a tax value and return the total amount of tax as well as the final price 
double TAX_CALCULATOR(){
	double price;
	double tax_rate;
	double total_tax;
	double total_value;

	std::cout << "You have selected TAX CALCULATOR.\nThis function caculates the tax and total value for a speicified price" << std::endl; 
	std::cout << "What is the price of the item? \nPlease input in dollars and cents" << std::endl;
	price = VALID_NUM_INPUT(); 
	// Verify that the input is valid 
	while (price == 0 || price == 0.00 || price < 0) {
		if (price == 0 || price == 0.00) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "I can't calculate the price and tax of an item if it's free! Please enter an non-zero value: ";
			price = VALID_NUM_INPUT();
		}
		if (price < 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
			std::cout << "I can't calculate the price of an item if it costs less than zero dollars! Please enter a positive value: ";
			price = VALID_NUM_INPUT();
		}
	}

	std::cout << "Thank you. \nWhat's the tax rate? Input the value in percentage up to two decimal places: ";
	tax_rate = VALID_NUM_INPUT();
	// Verify that the tax rate is valid
	while (tax_rate == 0 || tax_rate == 0.00 || tax_rate < 0) {
		if (tax_rate == 0 || tax_rate == 0.00) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "I cannot calculate the tax rate if there is no value! Please enter a non zero value: ";
			tax_rate = VALID_NUM_INPUT();
		}
		if (tax_rate < 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "I cannot calculate a tax rate for a negative value! Please enter a positive value: ";
			tax_rate = VALID_NUM_INPUT();
		}
	}

	tax_rate = tax_rate / 100;
	total_tax = tax_rate * price;
	total_value = total_tax + price;
	std::cout << std::fixed;										
	std::cout << "The total price of the item rounded to the nearest cent is:\n";
	std::cout << std::setprecision(2) << total_value << std::endl;
	std::cout << "The total tax applied rounded o the nearest cent is:\n";
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
			_sleep(2000);								// Prevents the same number from being generated again 

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

