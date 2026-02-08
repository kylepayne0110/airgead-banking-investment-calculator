#include <iostream>
#include <string>
#include <iomanip>
#include "InvestmentCalculator.h"

using namespace std;

// function definitions for the InvestmentCalculator class and intitializes all data member variables to 0 or 0.0
InvestmentCalculator::InvestmentCalculator() {
	initialInvestmentAmount = 0.0;
	monthlyDepositAmount = 0.0;
	annualInterestRatePercent = 0.0;
	numberOfYears = 0;
}

// function to run the calculator, calls the other functions in the correct order to execute the program and is called by main()
void InvestmentCalculator::Run() {
	DisplayInputScreen();
	GetUserInput();
	WaitForUserContinue();
	PrintReports();
}

// funciton to display the intput screen intially when the program starts
void InvestmentCalculator::DisplayInputScreen() {
    cout << "**********************************" << endl;
    cout << "********** Airgead Banking ********" << endl;
    cout << "**********************************" << endl;
    cout << endl;

    cout << "Initial Investment Amount: " << endl;
    cout << "Monthly Deposit: " << endl;
    cout << "Annual Interest: " << endl;
    cout << "Number of Years: " << endl;
    cout << endl;

    cout << "Press any key to continue..." << endl;
}

// function to get user input
void InvestmentCalculator::GetUserInput() {
    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;
    cout << "**********************************" << endl;

	initialInvestmentAmount = ReadPositiveDouble("Initial Investment Amount: ");   // read the initial investment amount from user input and validate it to be a positive double
	monthlyDepositAmount = ReadNonNegativeDouble("Monthly Deposit: ");   // read the monthly deposit amount from user input and validate it to be a non-negative double (0 or positive)
	annualInterestRatePercent = ReadPositiveDouble("Annual Interest (%): ");   // read the annual interest rate from user input and validate it to be a positive double (as a percentage, e.g., 5 for 5%)
	numberOfYears = ReadPositiveInt("Number of Years: ");   // read the number of years from user input and validate it to be a positive integer
}

// function that pauses the program to wait for the user to continue
void InvestmentCalculator::WaitForUserContinue() {
    string temp;

    cout << endl;
    cout << "Press Enter to continue..." << endl;

    // Consume leftover newline from previous cin >> reads
    getline(cin, temp);

    // Wait for the user to press Enter
    getline(cin, temp);
}

// function to print both of the reports by calling PrintReport twice, once with 0 for no monthly deposits, and once with the monthly deposit amount
void InvestmentCalculator::PrintReports() {
    cout << endl;
    PrintReport(0.0);                   // Report without monthly deposits
    cout << endl;
    PrintReport(monthlyDepositAmount);  // Report with monthly deposits
}

// function to print a single report, takes the monthly deposit amount as a parameter
void InvestmentCalculator::PrintReport(double depositForThisReport) {
    if (depositForThisReport == 0.0) {
        cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    }
    else {
        cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    }

    cout << "============================================================" << endl;
    cout << setw(6) << "Year"
        << setw(20) << "Year End Balance"
        << setw(25) << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------" << endl;

    double currentBalance = initialInvestmentAmount;
    double monthlyRate = (annualInterestRatePercent / 100.0) / 12.0;

    cout << fixed << setprecision(2);

    for (int year = 1; year <= numberOfYears; ++year) {
        double interestEarnedThisYear = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double total = currentBalance + depositForThisReport;
            double interest = total * monthlyRate;
            currentBalance = total + interest;
            interestEarnedThisYear += interest;
        }

        cout << setw(6) << year
            << setw(20) << currentBalance
            << setw(25) << interestEarnedThisYear << endl;
    }
}


// function to read a positive double from user input, takes a prompt string as a parameter and validates the input
double InvestmentCalculator::ReadPositiveDouble(const std::string& prompt) {
    double value;

    cout << prompt;
    cin >> value;

    while (cin.fail() || value <= 0) {
        cout << "Error: Please enter a positive number." << endl;

        cin.clear();                 // clear error flag
        cin.ignore(1000, '\n');      // discard bad input

        cout << prompt;
        cin >> value;
    }

    return value;
}

// function to read a non-negative double from user input, takes a prompt string as a parameter and validates the input
double InvestmentCalculator::ReadNonNegativeDouble(const std::string& prompt) {
    double value;

    cout << prompt;
    cin >> value;

    while (cin.fail() || value < 0) {
        cout << "Error: Please enter 0 or a positive number." << endl;

        cin.clear();                 // clear error flag
        cin.ignore(1000, '\n');      // discard bad input

        cout << prompt;
        cin >> value;
    }

    return value;
}


// function to read a positive integer from user input, takes a prompt string as a parameter and validates the input
int InvestmentCalculator::ReadPositiveInt(const std::string& prompt) {
    int value;

    cout << prompt;
    cin >> value;

    while (cin.fail() || value <= 0) {
        cout << "Error: Please enter a positive whole number." << endl;

        cin.clear();                 // clear error flag
        cin.ignore(1000, '\n');      // discard bad input

        cout << prompt;
        cin >> value;
    }

    return value;
}

