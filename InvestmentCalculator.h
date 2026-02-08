#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>

// create the class and define it
class InvestmentCalculator {

    // create the public sections of the class
public:
	InvestmentCalculator();   // constructor
	void Run();   // main function to run the calculator
	void DisplayInputScreen();   // function to display the input screen
	void GetUserInput();   // function to get user input
	void WaitForUserContinue();   // function to wait for user to continue (pauses the program until user input)
	void PrintReports();   // function to print the reports (calls PrintReport twice, once with 0 for no monthly deposits, and once with the monthly deposit amount)
	void PrintReport(double depositForThisReport);   // function to print a single report, takes the monthly deposit amount as a parameter

	double ReadPositiveDouble(const std::string& prompt);  // function to read a positive double from user input, takes a prompt string as a parameter
	double ReadNonNegativeDouble(const std::string& prompt);   // function to read a non-negative double from user input, takes a prompt string as a parameter
	int ReadPositiveInt(const std::string& prompt);   // function to read a positive integer from user input, takes a prompt string as a parameter

private:
	double initialInvestmentAmount;   // declared a variable to hold the initial investment amount
	double monthlyDepositAmount;   // declared a variable to hold the monthly deposit amount
	double annualInterestRatePercent;   // declared a variable to hold the annual interest rate as a percentage (e.g., 5 for 5%)
	int numberOfYears;   // declared a variable to hold the number of years for the investment
};

#endif