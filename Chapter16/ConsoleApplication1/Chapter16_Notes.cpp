#include <iostream>
#include <array>
#include <algorithm>
#include<iterator>

// ex. generator function
char nextLetter() {
	static char letter{ 'A' };
	return letter++;
}

int main()
{
	const size_t SIZE{ 4 };
	std::array<int, SIZE> values{ 1,2,3,4 };
	std::ostream_iterator<int> output{std::cout, " "};

	std::cout << "Starting Values:\n";
	std::copy(values.cbegin(), values.cend(), output);

	// ex. for each and lambdas
	std::cout << "Values X 2:\n";
	// NOTE: for each executes from position of arrays first elem 
	// here up to but not including end, which is one position after last element

	// NOTE: if iterators passed in are not to const data, function can modify elem
	// NOTE: lambda expressions
	// -> [] lambda introducer
	// -> (params)
	// -> {expression;}
	// -> ex. [&sum] -> local variable sum by reference and can modify value
	
	// NOTE: compiler can infer type if statement return expression; or specify using trailing return type 
	// syntax: [] (params) -> type {lambda body;}

	for_each(values.cbegin(), values.cend(),
		[](auto i) {std::cout << i * 2 << " "; });

	int sum = 0;

	for_each(values.begin(), values.end(), [&sum](auto i) { sum += i; });
	std::cout << "Sum of Values: " << sum << std::endl;

	// fill, fill_n, generate, generate_n
	std::array<char, 10> chars;
	fill(chars.begin(), chars.end(), 'S'); // set all elems to 'S'
	for_each(chars.cbegin(), chars.cend(),
		[](char i) {std::cout << i<< " "; });
	std::cout << std::endl;
	fill_n(chars.begin(), 5, 'A'); // set first 5 to 'A'
	for_each(chars.cbegin(), chars.cend(),
		[](char i) {std::cout << i << " "; });
	std::cout << std::endl;
	generate(chars.begin(), chars.end(), nextLetter); // generate all elems
	for_each(chars.cbegin(), chars.cend(),
		[](char i) {std::cout << i << " "; });
	std::cout << std::endl;
	generate_n(chars.begin(), 5, 
		[]() {static char letter{ 'A' };
	return letter++; }); // generate first 5
	for_each(chars.cbegin(), chars.cend(),
		[](char i) {std::cout << i << " "; });
	std::cout << std::endl;

	// equal, mismatch, lexicographical_compare
	// -> equal: built in or overrided == operator compares elements
	// -> mismatch: returns pair of iterators indicating location in 
	//    each sequence of first mismatched elems (if all elems match
	//    then both iterators are equal to end iterator for each sequence)
	// -> lexicographical_compare: compare contents of two char built in arrays
	
	// remove, remove_if, remove_copy, remove_copy_if
	// -> remove: remove all instances of given value in range
	// -> remove_if: 
	// -> remove_copy: copy all elems that do not have given value in range
	// -> remove_if: remove all elems given predicate function such as {return x > 9;}

	// replace, replace_if, replace_copy, replace_copy_if
	// replace -> replace all instances of given elem with other given elem
	// replace_if -> similar to remove_if with predicate function
	// replace_copy_if -> copy all elems and replace elems with given value if they pass predicate
	// replace_copy -> same as replace_copy_if but with value not predicate
	
	// math algorithms
	// shuffle, count, count_if, minmax(smallest and largest), transform, etc.

	// basic searching and sorting algorithms
	// find, find_if, sort, binary_search, all_of, etc.
	// swap, iter_swap, swap_ranges
	// copy_backward, merge, unique, reverse
	// inplace_merge, unique_copy, reverse_copy
	// set operations
	// lower_bound, upper_bound, equal_range
	// min, max, minmax, minmax_element
	
	// Function Objects
	// object of class that overloads () operator
	// ex. accumulate algorithm (similar to fold)
}