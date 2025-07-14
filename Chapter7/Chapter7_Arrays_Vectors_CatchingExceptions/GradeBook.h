// Chapter7_Arrays_Vectors_CatchingExceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <iomanip>
#include <string>

// Class GradeBook Example
class GradeBook {
	// fields
public:
	// public and shared data on number of students
	static const size_t students{ 10 };
	// constructor
	GradeBook(const std::string& name, const std::array<int, students>& gradesArray) :
		courseName{ name }, grades{ gradesArray } {
	}

	// set course name
	void setCourseName(std::string newName) {
		courseName = newName;
	}

	// retrieve course name
	const std::string getCourseName() const {
		return courseName;
	}

	// display welcome message to GradeBook user
	// NOTE: 'const' in signature because function promises
	// not to modify any variables of class to avoid bugs!
	void displayMessage() const {
		std::cout << "Welcome to the GradeBook for " << getCourseName()
			<< std::endl;
	}

	// perform operations on data (do not modify data)
	void processGrades() const {
		// output grades array
		outputGrades();

		// get class average
		std::cout << std::endl << "Class average is " << getAverage() << std::endl;

		// get minimum grade
		std::cout << "Lowest grade is " << getMinimum() << std::endl;

		// get maximum grade
		std::cout << "Highest grade is " << getMaximum() << std::endl;

		// output grade distribution chart
		outputBarChart();
	}

	// find minimum grade
	int getMinimum() const {

		// initially low grade is 100
		int lowGrade{ 100 };

		for (int grade : grades) {
			if (grade < lowGrade) {
				lowGrade = grade;
			}
		}

		return lowGrade;
	}

	// find maximum grade
	int getMaximum() const {

		// initially high grade is 0
		int highGrade{ 0 };

		for (int grade : grades) {
			if (grade > highGrade) {
				highGrade = grade;
			}
		}

		return highGrade;
	}

	// determine average grade for test
	double getAverage() const {
		double avg{ 0.0 };
		for (int grade : grades) {
			avg += grade;
		}
		avg /= grades.size();
		return avg;
	}

	// output bar chart displaying grade distribution
	void outputBarChart() const {
		std::cout << std::endl << "Grade distribution: " << std::endl;

		std::array<unsigned int, 11> gradeRangeFreqs{};

		for (int grade : grades) {
			++gradeRangeFreqs[grade / 10];
		}

		for (size_t count{ 0 }; count < 11; ++count) {
			if (count == 0) {
				std::cout << "  0-9: ";
			}
			else if (count == 10) {
				std::cout << "  100: ";
			}
			else {
				std::cout << count * 10 << "-"
					<< count * 10 + 9 << ": ";
			}

			for (unsigned int stars{ 0 }; stars < gradeRangeFreqs[count]; ++stars) {
				std::cout << '*';
			}

			std::cout << std::endl;
		}


	}

	// output contents of grades array
	void outputGrades() const {
		std::cout << "The grades are: " << std::endl << std::endl;

		for (int i = 0; i < grades.size(); i++) {
			std::cout << "Student " << i << ": " << grades[i] << std::endl;
		}
	}
private:
	// course name
	std::string courseName;
	// grades of students in this course
	std::array<int, students> grades;
};

