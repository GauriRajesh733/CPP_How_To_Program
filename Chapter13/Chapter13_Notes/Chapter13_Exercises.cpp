#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <iomanip>


double mean(std::vector<double>);
double median(std::vector<double>);
double minimum(std::vector<double>);
double maximum(std::vector<double>);
std::vector<double> sort(const std::vector<double>);
std::vector<double> insertIntoSorted(const double, const std::vector<double>);



int main()
{
	std::vector<double> numbers;
	double currentNumber;
	std::string currentInput;

	// read sequence of numbers from user
	std::cout << "Enter numbers to perform statistics on one at a time.  Enter when done entering numbers. " << std::endl;

	while (true) {
		std::getline(std::cin, currentInput);
		if (currentInput.empty()) {
			break;
		}
		try {
			currentNumber = std::stod(currentInput);
			numbers.push_back(currentNumber);
		}
		catch (const std::invalid_argument& e) {
			std::cout << "Invalid number entered, will not be included in statistics." << std::endl;
		}
	}
	std::cout << "Numbers: ";
	for (double number : numbers) {
		std::cout << number << " ";
	}
	std::cout << std::endl;

	// calculate mean, median, minimum, maximum
	std::cout << "Mean: " << std::fixed << std::showpoint << std::setprecision(2) << mean(numbers) << std::endl;
	std::cout << "Median: " << median(numbers) << std::endl;
	std::cout << "Minimum: " << minimum(numbers) << std::endl;
	std::cout << "Maximum: " <<maximum(numbers) << std::endl;


	// display statistics with two digits of precision
}

double mean(std::vector<double> numbers) {
	if (numbers.size() == 0) {
		throw std::invalid_argument("cannot calculate mean of empty list of numbers");
	}

	double sum = 0;
	double count = numbers.size();
	for (double number : numbers) {
		sum += number;
	}

	return sum / count;
}

double median(std::vector<double> sortedNumbers) {
	if (sortedNumbers.size() == 0) {
		throw std::invalid_argument("cannot calculate median of empty list of numbers");
	}
	if (sortedNumbers.size() == 1) {
		return sortedNumbers[0];
	}

	if (sortedNumbers.size() % 2 == 0) {
		return (sortedNumbers[(sortedNumbers.size() / 2) - 1] + sortedNumbers[sortedNumbers.size() / 2]) / 2;
	}
	else {
		return sortedNumbers[sortedNumbers.size() / 2];
	}
}

double minimum(std::vector<double> sortedNumbers) {
	if (sortedNumbers.size() == 0) {
		throw std::invalid_argument("cannot calculate minimum of empty list of numbers");
	}

	return sortedNumbers[0];
}

double maximum(std::vector<double> sortedNumbers) {
	if (sortedNumbers.size() == 0) {
		throw std::invalid_argument("cannot calculate maximum of empty list of numbers");
	}

	return sortedNumbers[sortedNumbers.size() - 1];
}

std::vector<double> sort(const std::vector<double> numbers) {
	std::vector<double> sortedNumbers;
	
	for (double number : numbers) {
		insertIntoSorted(number, sortedNumbers);
	}

	return sortedNumbers;
}

std::vector<double> insertIntoSorted(const double toInsert, const std::vector<double> numbers) {
	std::vector<double> sortedNumbers;
	bool inserted = false;
	for (int i = 0; i < numbers.size(); i++) {
		if (toInsert < numbers[i]) {
			sortedNumbers.push_back(toInsert);
			inserted = true;
		}
		sortedNumbers.push_back(numbers[i]);
	}

	if (!inserted) {
		sortedNumbers.push_back(toInsert);
	}

	return sortedNumbers;
}
