#include <iostream>
#include <stdexcept>
#include <memory>
#include <new>

// defining custom exception class for dividing by 0
class DivideByZeroException : public std::runtime_error {
public:
    DivideByZeroException() : std::runtime_error("attempted to divide by zero") {}

};

// random class ex to demonstrate member-object destructors
// are called only for member objects constructed before exception
class CustomNumber {
public:
    CustomNumber(double n = 0.0) {
        number = n;
    }
    ~CustomNumber() {
        std::cout << "Destructor called for number " << number << "\n";
    }
    CustomNumber(const CustomNumber& other) {
        std::cout << "Copy Constructor called for number " << number << "\n";
        number = other.number;
    }

    double getNumber() {
        return number;
    }
private:
    double number;
};


void customNewHandler() {
    std::cerr << "customNewHandler was called\n";
    exit(EXIT_FAILURE);
}

double quotient(int numerator, int denominator) {
    if (denominator == 0) {
        throw DivideByZeroException{};
    }
    return static_cast<double>(numerator) / denominator;
}

int main()
{
    int number1;
    int number2;

    std::cout << "Enter two integers (end-of-file to end): \n";
    while (std::cin >> number1 >> number2) {
        try {
            double result{ quotient(number1, number2) };
            std::cout << "Quotient: " << result << "\n";
        }
        catch (const DivideByZeroException& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    // NOTE: stack unwinding if exception occurs in function and not caught in that function
    // RECALL: if none found, program terminates
    // NOTE: exception handling appropriate for SYNCHRONOUS ERRORS

    // NOTE: noexcept -> function doesn't throw any exceptions and doesn't call any functions 
    // that throw exceptions

    // NOTE: avoid exceptions in constructor of global or static local object
    // since they won't be caught (constructed before main executes)

    // NOTE: if exception thrown from constructor for object created with new keyword,
    // dynamically allocated memory for that object is released

    // NOTE: constructor should throw exception if problem occurs when initializing
    // but FIRST RELEASE ANY DYNAMICALLY ALLOCATED MEMORY

    // NOTE: can initialize local objects to get resources (if exception occurs destructor called)
    // -> resource allocation is initialization (RAII) -> can use unique_ptr

    // bad_alloc thrown if unable to allocate memory with new operator
    // NOTE: older version new(nothrow) returned nullptr if unable to allocate

    
    double* ptr[50];
    try {
        for (size_t i{ 0 }; i < 50; i++) {
            int64_t size = 50000000000000;
            ptr[i] = new double[size]; // may throw exception
            std::cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
        }
    }
    catch (std::bad_alloc& memoryAllocExc) {
        std::cerr << "Exception occured: " << memoryAllocExc.what() << "\n";
    }

    // set_new_handler: takes in pointer to void func that is called when new fails
    // can handle failed memory allocation by deleting other dynamically allocated memory,
    // telling user to close other apps and trying new again, throwing exception bad_alloc,
    // abort or exit program (abort terminates program immediately whereas
    // exit calls destructors for global objects and local static objects before ending program)

    // ex.
    std::set_new_handler(customNewHandler);

    // unique_ptr and dynamic memory allocation
    // NOTE: explicitly prevents copying, one unique_ptr cannot be assigned to another or passed by value to a func
    // -> single ownership principle
    // NOTE: owenership can be TRANSFERRED using std::move (original becoes null and new pointer is responsible for managing memory)
    // NOTE: automatically deallocates memory when it goes out of scope or is reset() -> prevent memory leaks
    std::unique_ptr<int> ptrToInt{ std::make_unique<int>(5) };

    // ex. exceptions and destructors
    CustomNumber one{ 1 };
    CustomNumber oneCopy(one);
    CustomNumber two{ 2 };
    CustomNumber zero{ 0 };
    CustomNumber six{ 6 };


    CustomNumber* numbers = new CustomNumber[5];
    

    try {
        numbers[0] = CustomNumber{ quotient(one.getNumber(), one.getNumber()) };
        numbers[1] = CustomNumber{ quotient(two.getNumber(), one.getNumber()) };
        numbers[2] = CustomNumber{ quotient(one.getNumber(), two.getNumber()) };
        // destructors called for previous numbers
        numbers[3] = CustomNumber{ quotient(two.getNumber(), zero.getNumber()) };
        // destructor called after exiting main
        numbers[4] = CustomNumber{ quotient(six.getNumber(), two.getNumber()) };
    }
    catch (const DivideByZeroException& e) {
        std::cout << "Error: " << e.what() << "\n";
    }




    delete[] ptr;
    delete[] numbers;

    std::cout << "Exiting\n";

} 