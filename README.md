# Airgead Banking App

## Project Summary

The Airgead Banking App is a C++ program designed to help users understand how their investments can grow over time through compound interest. The program allows the user to enter an initial investment amount, a monthly deposit amount, an annual interest rate, and the number of years they want to invest. It then displays two reports: one showing the investment growth without monthly deposits and another showing the growth with monthly deposits. This helps users compare how regular monthly contributions can impact long-term savings.

The main problem this project solves is helping users visualize the benefit of consistent investing. Instead of only seeing a final number, the program breaks the investment growth down year by year, making the results easier to understand.

## What I Did Particularly Well

One thing I did particularly well was organizing the program using object-oriented programming principles. I separated the investment data and calculations into their own class instead of putting all of the logic directly into `main.cpp`. This made the program cleaner and easier to follow.

I also did well with formatting the output reports. The program displays the results in a clear table format, which makes it easier for the user to compare the year-end balances and earned interest. I also included input validation so the user cannot enter values that would not make sense, such as a negative investment amount or zero years.

## Where I Could Enhance the Code

One area where I could enhance the code would be adding even stronger input validation. For example, the program currently checks for valid numeric ranges, but it could be improved by better handling non-numeric input, such as letters or symbols. This would make the program more secure and reliable because it would reduce the chance of unexpected behavior from incorrect input.

Another improvement would be allowing the user to save the investment reports to a text file. This would make the program more useful because users could keep a copy of their results for later review. I could also add more options, such as allowing different compounding frequencies or comparing multiple investment plans at once.

## Most Challenging Parts

The most challenging part of this project was making sure the compound interest calculations were correct for both reports. The program needed to calculate interest monthly, track the yearly interest, and then display the year-end balance for each year. It was important to reset the yearly interest at the correct time and make sure the balance carried forward properly.

I overcame this by breaking the problem into smaller steps. First, I focused on the version without monthly deposits. Then I added the version with monthly deposits. Testing the program with sample values helped me confirm that the calculations were working as expected.

The tools and resources I used included Visual Studio, course resources, assignment requirements, and debugging/testing within the program. These are resources I will continue using as part of my support network in future programming assignments.

## Transferable Skills

This project helped me build several skills that will transfer to other projects and coursework. One major skill is object-oriented programming, especially using classes to organize data and behavior. I also practiced input validation, formatting output, writing functions, and using loops for repeated calculations.

Another transferable skill is debugging. I learned how important it is to test a program with different values and check whether the output makes sense. These skills will be useful in future C++ projects, other programming languages, and real-world software development.

## Maintainability, Readability, and Adaptability

I made the program maintainable by separating responsibilities across different files. The `InvestmentData` class handles the investment information and calculations, while `main.cpp` controls the main program flow. This structure makes the code easier to update because changes to the investment calculations can be made in one area without rewriting the entire program.

I made the program readable by using clear variable names, consistent formatting, and comments to explain important sections of the code. The code is also adaptable because new features could be added without completely changing the structure. For example, future updates could include saving results to a file, adding more investment options, or improving the user interface.

## Files Included

- `main.cpp` - Contains the main program flow and user interaction
- `InvestmentData.h` - Header file for the investment data class
- `InvestmentData.cpp` - Contains the investment calculation and display logic
- `AirgeadBanking.sln` - Visual Studio solution file
- `AirgeadBanking.vcxproj` - Visual Studio project file
- `AirgeadBanking_Pseudocode.txt` - Pseudocode planning document for the project
