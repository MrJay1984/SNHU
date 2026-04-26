#include "InvestmentData.h"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>

InvestmentData::InvestmentData()
    : m_initialInvestment(0.0),
      m_monthlyDeposit(0.0),
      m_annualInterest(0.0),
      m_numberOfYears(0) {
}

InvestmentData::InvestmentData(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears)
    : m_initialInvestment(t_initialInvestment),
      m_monthlyDeposit(t_monthlyDeposit),
      m_annualInterest(t_annualInterest),
      m_numberOfYears(t_numberOfYears) {
}

void InvestmentData::setInitialInvestment(double t_initialInvestment) {
    m_initialInvestment = t_initialInvestment;
}

void InvestmentData::setMonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentData::setAnnualInterest(double t_annualInterest) {
    m_annualInterest = t_annualInterest;
}

void InvestmentData::setNumberOfYears(int t_numberOfYears) {
    m_numberOfYears = t_numberOfYears;
}

double InvestmentData::getInitialInvestment() const {
    return m_initialInvestment;
}

double InvestmentData::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

double InvestmentData::getAnnualInterest() const {
    return m_annualInterest;
}

int InvestmentData::getNumberOfYears() const {
    return m_numberOfYears;
}

double InvestmentData::readPositiveDouble(const char* t_prompt, bool t_allowZero) {
    double value = 0.0;

    while (true) {
        // Prompt the user for a numeric value.
        std::cout << t_prompt;

        if (std::cin >> value) {
            // Accept either zero-or-greater or greater-than-zero based on the field.
            if ((t_allowZero && value >= 0.0) || (!t_allowZero && value > 0.0)) {
                return value;
            }

            std::cout << "Invalid entry. Please enter "
                      << (t_allowZero ? "0 or a positive number." : "a positive number greater than 0.")
                      << std::endl;
        }
        else {
            // Clear the failed input state when non-numeric data is entered.
            std::cout << "Invalid entry. Please enter a numeric value." << std::endl;
            std::cin.clear();
        }

        // Remove leftover characters from the input buffer before retrying.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int InvestmentData::readPositiveInt(const char* t_prompt) {
    int value = 0;

    while (true) {
        // Prompt the user for the number of years.
        std::cout << t_prompt;

        if (std::cin >> value) {
            // The number of years must be a whole number greater than zero.
            if (value > 0) {
                return value;
            }

            std::cout << "Invalid entry. Please enter a whole number greater than 0." << std::endl;
        }
        else {
            // Clear the failed input state when non-integer data is entered.
            std::cout << "Invalid entry. Please enter a whole number." << std::endl;
            std::cin.clear();
        }

        // Remove leftover characters from the input buffer before retrying.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void InvestmentData::getUserInput() {
    // Read and store each required input from the user.
    setInitialInvestment(readPositiveDouble("Initial Investment Amount: $", false));
    setMonthlyDeposit(readPositiveDouble("Monthly Deposit: $", true));
    setAnnualInterest(readPositiveDouble("Annual Interest (%): ", false));
    setNumberOfYears(readPositiveInt("Number of Years: "));
}

void InvestmentData::displayInputScreen() const {
    std::cout << std::endl;
    std::cout << "**************************************************" << std::endl;
    std::cout << "****************** Data Input ********************" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    // Echo the values back to the user before showing the reports.
    std::cout << "Initial Investment Amount: $" << getInitialInvestment() << std::endl;
    std::cout << "Monthly Deposit: $" << getMonthlyDeposit() << std::endl;
    std::cout << "Annual Interest: %" << getAnnualInterest() << std::endl;
    std::cout << "Number of Years: " << getNumberOfYears() << std::endl;
    std::cout << "Press Enter to continue . . ." << std::endl;

    // Clear the leftover newline from the last numeric input.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Pause so the user can review the entered values.
    std::cin.get();
}

void InvestmentData::printReport(bool t_withMonthlyDeposit) const {
    double yearlyBalance = getInitialInvestment();
    double yearlyInterest = 0.0;
    const double monthlyDeposit = t_withMonthlyDeposit ? getMonthlyDeposit() : 0.0;
    const double monthlyInterestRate = (getAnnualInterest() / 100.0) / 12.0;

    std::cout << std::endl;

    // Print the correct title for the selected report type.
    if (t_withMonthlyDeposit) {
        std::cout << "     Balance and Interest With Additional Monthly Deposits" << std::endl;
    }
    else {
        std::cout << "      Balance and Interest Without Additional Monthly Deposits" << std::endl;
    }

    std::cout << "======================================================================" << std::endl;
    std::cout << std::left << std::setw(10) << "Year"
              << std::setw(25) << "Year End Balance"
              << std::setw(25) << "Year End Earned Interest" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    // Process one year at a time so the program can print a yearly summary.
    for (int year = 1; year <= getNumberOfYears(); ++year) {
        yearlyInterest = 0.0;

        // Compound the investment monthly for the current year.
        for (int month = 1; month <= 12; ++month) {
            // Calculate monthly interest using the required Airgead formula.
            const double interest = (yearlyBalance + monthlyDeposit) * monthlyInterestRate;

            // Track how much interest was earned during the current year.
            yearlyInterest += interest;

            // Update the balance with the monthly deposit and earned interest.
            yearlyBalance += monthlyDeposit + interest;
        }

        // Print the year-end balance and year-end earned interest.
        std::cout << std::left << std::setw(10) << year
                  << "$" << std::setw(24) << std::fixed << std::setprecision(2) << yearlyBalance
                  << "$" << std::setw(24) << std::fixed << std::setprecision(2) << yearlyInterest << std::endl;
    }
}

void InvestmentData::displayReports() const {
    // Print the report without monthly deposits first.
    printReport(false);

    // Print the report with monthly deposits second.
    printReport(true);
}

void InvestmentData::askToRunAgain(bool& t_runAgain) const {
    char userChoice = 'n';

    std::cout << std::endl;
    std::cout << "Would you like to enter another set of values? (y/n): ";
    std::cin >> userChoice;

    // Convert the response to lowercase so Y and y are treated the same.
    userChoice = static_cast<char>(std::tolower(static_cast<unsigned char>(userChoice)));

    // Continue only when the user explicitly chooses yes.
    if (userChoice == 'y') {
        t_runAgain = true;
    }
    else if (userChoice == 'n') {
        t_runAgain = false;
    }
    else {
        std::cout << "Invalid choice. The program will close." << std::endl;
        t_runAgain = false;
    }
}
