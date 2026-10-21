// MP2 -- Emerson Beesley -- October 22, 2026
// We're getting the student's grades! I gotta get all the scores inputted,
// weigh them (grade * weight[decimal]), get the final grade by adding the weights,
// and see if it's an A, B, C, D, or F.
// This all above is in a while loop that ends once you put in a negative value.
// After the loop, count how many of each grade and get the final average course grade.


#include <iostream>
using namespace std;


int main() {
	// Ok, first: constant the weights!
	const double HW_WEIGHT = 0.15; // weight of homework average
	const double LAB_WEIGHT = 0.25; // weight of lab average
	const double QUIZ_WEIGHT = 0.10; // weight of quiz average
	const double MIDTERM_1_WEIGHT = 0.125; // weight of midterm 1
	const double MIDTERM_2_WEIGHT = 0.125; // weight of midterm 2
	const double FINAL_WEIGHT = 0.25; // weight of final exam

	// These are for the user inputs
	double hwAvg = 0; // average homework score
	double labAvg; // average lab score
	double quizAvg; // average quiz score
	double midterm1; // midterm 1 score
	double midterm2; // midterm 2 score
	double final; // final exam score

	// Calculations and Counters
	double studentAvg; // course grade for each student
	int studentRound; // to round grade to tenths place
	double courseSum = 0; // to add all the student grades to eventually get average
	double courseAvg; // OVERALL course grade (aka, average of all students)
	int Acounter = 0; // number of As in the class
	int Bcounter = 0; // number of Bs in the class
	int Ccounter = 0; // number of Cs in the class
	int Dcounter = 0; // number of Ds in the class
	int Fcounter = 0; // number of Fs in the class
	int studentNumber = 1; // what number the student is (starting with 1)

	// The instructions just say "when a negative value is entered" for when to end the loop
	// so we're gonna give the chance to break for every input if its less than 0.
	// Which means we're just gonna have while as true always!
	while (true) {

		// We're gonna get all the outputs and corresponding inputs
		cout << "Student #" << studentNumber << ":" << endl;

		cout << "Enter homework average: ";
		cin >> hwAvg;
		// This if statement is to catch if any input is negative
		if (hwAvg < 0) {
			break;
		}

		cout << "Enter lab average: ";
		cin >> labAvg;
		if (labAvg < 0) {
			break;
		}

		cout << "Enter quiz average: ";
		cin >> quizAvg;
		if (quizAvg < 0) {
			break;
		}

		cout << "Enter Midterm 1: ";
		cin >> midterm1;
		if (midterm1 < 0) {
			break;
		}

		cout << "Enter Midterm 2: ";
		cin >> midterm2;
		if (midterm2 < 0) {
			break;
		}

		cout << "Enter final exam score: ";
		cin >> final;
		if (final < 0) {
			break;
		}

		// For the average for each student
		studentAvg = (hwAvg * HW_WEIGHT) + (labAvg * LAB_WEIGHT) + (quizAvg * QUIZ_WEIGHT);
		studentAvg = studentAvg + ((midterm1 * MIDTERM_1_WEIGHT) + (midterm2 * MIDTERM_2_WEIGHT) + (final * FINAL_WEIGHT));

		// We need to round to tenths place!!
		studentRound = studentAvg * 10;
		studentAvg = (double)(studentRound / 10.0);
		cout << "Course average: " << studentAvg << endl;

		// To find the letter grade, we have to do an if statement
		cout << "Letter grade: ";

		if (studentAvg >= 90) {
			cout << "A" << endl;
			// Also, add one to the counter for how many of each grade
			Acounter++;
		}
		else if (studentAvg >= 80) {
			cout << "B" << endl;
			Bcounter++;
		}
		else if (studentAvg >= 70) {
			cout << "C" << endl;
			Ccounter++;
		}
		else if (studentAvg >= 60) {
			cout << "D" << endl;
			Dcounter++;
		}
		else {
			cout << "F" << endl;
			Fcounter++;
		}
		
		// Add all the grades to eventually calculate the average using sum and # of students
		courseSum += studentAvg;

		// Just to seperate :)
		cout << endl;

		// Next student!
		studentNumber++;
	}
	// Once negative value inserted, we jump to overall course average and counter for grade letters
	studentNumber--; //we gotta do this, the final student was just to get a negative value
	courseAvg = (double)(courseSum / studentNumber);
	cout << endl << endl << "OVERALL AVERAGE: " << courseAvg << endl;

	// We show the user how many students got each letter grade
	cout << "A's: " << Acounter << endl; 
	cout << "B's: " << Bcounter << endl;
	cout << "C's: " << Ccounter << endl;
	cout << "D's: " << Dcounter << endl;
	cout << "F's: " << Fcounter << endl;
	
	return 0;
}