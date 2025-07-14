#include <array>
#include "GradeBook.h"

int main() {
	const std::array<int, GradeBook::students> grades
	{ 87, 68, 94, 100, 83, 78, 85, 91, 76, 87 };
	std::string courseName{ "Introduction to C++ Programming" };

	GradeBook gradeBook(courseName, grades);
	gradeBook.displayMessage();
	gradeBook.processGrades();
}
