#include <gtest/gtest.h>
#include "../CustomAllocator.h"
#include <sstream>
#include <string>
#include <iostream>

// construction tests
TEST(CustomAllocatorTest, ConstructionTest) {
	// custom allocator with 4 bytes memory
	CustomAllocator c1(4);

	// TEST: maximum space available is same as total allotted memory
	EXPECT_EQ(c1.getMaximumSpace(), 4);

	// TEST: custom allocator with 8 bytes memory
	CustomAllocator c2(8);

	// TEST: maximum space available is same as total allotted memory
	EXPECT_EQ(c2.getMaximumSpace(), 8);
}

// displayMemory() tests
TEST(CustomAllocatorTest, DisplayMemoryTest) {
	CustomAllocator c1(4);

	// redirect cout to stringstream output
	std::streambuf* oldCoutBuffer = std::cout.rdbuf();
	std::stringstream output;
	std::cout.rdbuf(output.rdbuf());

	// TEST: memory after construction
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Memory:  \n|____|\n");
	output.str("");
	output.clear();

	// TEST: memory after storing data
	char* a = c1.allocateMemory<char>('a');
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Successfully allocated space for data.\nMemory:  \n|X|___|\n");
	output.str("");
	output.clear();

	char* b = c1.allocateMemory<char>('b');
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Successfully allocated space for data.\nMemory:  \n|X|X|__|\n");
	output.str("");
	output.clear();

	char* c = c1.allocateMemory<char>('c');
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Successfully allocated space for data.\nMemory:  \n|X|X|X|_|\n");
	output.str("");
	output.clear();

	char* d = c1.allocateMemory<char>('d');
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Successfully allocated space for data.\nMemory:  \n|X|X|X|X|\n");
	output.str("");
	output.clear();

	// TEST: memory after freeing data
	c1.freeMemory<char>(d); d = nullptr;
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Memory slot of size 1 bytes freed.\nMemory:  \n|X|X|X|_|\n");
	output.str("");
	output.clear();

	c1.freeMemory<char>(b); b = nullptr;
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Memory slot of size 1 bytes freed.\nMemory:  \n|X|_|X|_|\n");
	output.str("");
	output.clear();

	c1.freeMemory<char>(a); a = nullptr;
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Memory slot of size 1 bytes freed.\nMemory:  \n|_|_|X|_|\n");
	output.str("");
	output.clear();

	c1.freeMemory<char>(c);
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Memory slot of size 1 bytes freed.\nMemory:  \n|_|_|_|_|\n");
	output.str("");
	output.clear();

	// TEST: using freed memory for new data
	c1.allocateMemory<int>(5);
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Successfully allocated space for data.\nMemory:  \n|XXXX|\n");

	// restore cout buffer
	std::cout.rdbuf(oldCoutBuffer);
}

// getMaximumSpace() tests
TEST(CustomAllocatorTest, GetMaximumTest) {
	CustomAllocator c1(5);

	// TEST: maximum space is initally total space allotted
	EXPECT_EQ(c1.getMaximumSpace(), 5);

	// TEST: maximum space decreases as data added
	char* a = c1.allocateMemory<char>('a');
	EXPECT_EQ(c1.getMaximumSpace(), 4);

	char* b = c1.allocateMemory<char>('b');
	EXPECT_EQ(c1.getMaximumSpace(), 3);

	char* c = c1.allocateMemory<char>('c');
	EXPECT_EQ(c1.getMaximumSpace(), 2);

	char* d = c1.allocateMemory<char>('d');
	EXPECT_EQ(c1.getMaximumSpace(), 1);

	// TEST: maximum space inreases if continuous data freed
	c1.freeMemory(a);
	c1.freeMemory(b);
	EXPECT_EQ(c1.getMaximumSpace(), 2);

	
	// TEST: maximum space does not change if non-continuous data freed
	c1.freeMemory(d);
	EXPECT_EQ(c1.getMaximumSpace(), 2);
}

// freeMemory() tests
TEST(CustomAllocatorTest, FreeMemoryTest) {
	CustomAllocator c1(9);

	// add data
	double* db1 = c1.allocateMemory<double>(6.43);
	c1.displayMemory();
	char* ch1 = c1.allocateMemory<char>('z');
	c1.displayMemory();


	// redirect cout to stringstream output
	std::streambuf* oldCoutBuffer = std::cout.rdbuf();
	std::stringstream output;
	std::cout.rdbuf(output.rdbuf());

	// TEST: free data stored in custom allocator
	
	output.str("");
	output.clear();
	c1.freeMemory(db1);
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Memory slot of size 8 bytes freed.\nMemory:  \n|________|X|\n");
	output.str("");
	output.clear();

	

	// TEST: freeing data not stored in custom allocator does not do anything
	char* b = new char('b');
	c1.freeMemory(b);
	EXPECT_EQ(output.str(), "Given data not stored in custom memory allocator.  Please delete manually.\n");
	output.str("");
	output.clear();
	delete b;

	// restore cout buffer
	std::cout.rdbuf(oldCoutBuffer);
}


// allocateMemory() tests
TEST(CustomAllocatorTest, AllocateMemoryTest) {
	CustomAllocator c1(9);

	// redirect cout to stringstream output
	std::streambuf* oldCoutBuffer = std::cout.rdbuf();
	std::stringstream output;
	std::cout.rdbuf(output.rdbuf());

	
	// data smaller than tracked data slot, need to split
	char* d = c1.allocateMemory<char>('d');
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Successfully allocated space for data.\nMemory:  \n|X|________|\n");
	output.str("");
	output.clear();

	// data fits perfectly into a tracked data slot
	int* one = c1.allocateMemory<int>(1);
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Successfully allocated space for data.\nMemory:  \n|X|XXXX|____|\n");
	output.str("");
	output.clear();

	int* two = c1.allocateMemory<int>(2);
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Successfully allocated space for data.\nMemory:  \n|X|XXXX|XXXX|\n");
	output.str("");
	output.clear();

	// data fits into combined slot
	c1.freeMemory(one);
	c1.freeMemory(two);
	output.str("");
	output.clear();
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Memory:  \n|X|____|____|\n");
	output.str("");
	output.clear();
	
	double* pi = c1.allocateMemory<double>(3.14);
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Successfully allocated space for data.\nMemory:  \n|X|XXXXXXXX|\n");
	output.str("");
	output.clear();

	// not enough continuous space to store data
	char* p = c1.allocateMemory<char>('p');
	c1.displayMemory();
	EXPECT_EQ(output.str(), "Unable to allocate space for new data.\nMemory:  \n|X|XXXXXXXX|\n");
	output.str("");
	output.clear();

	// restore cout buffer
	std::cout.rdbuf(oldCoutBuffer);
}