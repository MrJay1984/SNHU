#ifndef AIRGEAD_BANKING_INVESTMENTDATA_H_
#define AIRGEAD_BANKING_INVESTMENTDATA_H_

class InvestmentData {
public:
    // Create an empty investment object with default starting values.
    InvestmentData();

    // Create an investment object with values already supplied.
    InvestmentData(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears);

    // Setters update each investment input value.
    void setInitialInvestment(double t_initialInvestment);
    void setMonthlyDeposit(double t_monthlyDeposit);
    void setAnnualInterest(double t_annualInterest);
    void setNumberOfYears(int t_numberOfYears);

    // Getters return each stored investment input value.
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterest() const;
    int getNumberOfYears() const;

    // Public functions used by main() to run the program.
    void getUserInput();
    void displayInputScreen() const;
    void displayReports() const;
    void askToRunAgain(bool& t_runAgain) const;

private:
    // Private member data stores the values entered by the user.
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

    // Helper functions validate user input before storing it.
    double readPositiveDouble(const char* t_prompt, bool t_allowZero = true);
    int readPositiveInt(const char* t_prompt);

    // Helper function prints one report at a time.
    void printReport(bool t_withMonthlyDeposit) const;
};

#endif // AIRGEAD_BANKING_INVESTMENTDATA_H_
