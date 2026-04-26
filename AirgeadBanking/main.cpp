#include "InvestmentData.h"

#include <exception>
#include <iostream>

int main() {
    try {
        bool runAgain = true;

        // Keep running until the user chooses to stop testing scenarios.
        while (runAgain) {
            // Create a new investment object for the current set of user inputs.
            InvestmentData investmentData;

            // Gather input, show the entered values, and print both required reports.
            investmentData.getUserInput();
            investmentData.displayInputScreen();
            investmentData.displayReports();

            // Ask the user whether they want to test another investment scenario.
            investmentData.askToRunAgain(runAgain);

            std::cout << std::endl;
        }
    }
    catch (const std::exception& t_exception) {
        // Display a readable error message and exit gracefully.
        std::cerr << "An unexpected error occurred: " << t_exception.what() << std::endl;
        return 1;
    }
    catch (...) {
        // Catch any unknown error so the program does not crash without a message.
        std::cerr << "An unknown error occurred. The program will now close." << std::endl;
        return 1;
    }

    return 0;
}
