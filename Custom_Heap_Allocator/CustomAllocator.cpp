#include "CustomAllocator.h"
#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

CustomAllocator::CustomAllocator(size_t memorySize)
{
	// set size of custom memory allocator
	totalMemory = memorySize;
	try {
		memory = std::malloc(memorySize);
	}
	catch (std::bad_alloc& e) {
		std::cerr << "Unable to allocate space for custom memory allocator: " << e.what();
		exit(EXIT_FAILURE);
	}
	
	// initially create single tracked data that spans total memory and can be split later to store data
	TrackedData initial;
	initial.data = memory;
	initial.isFree = true;
	initial.size = memorySize;
	allTrackedData.push_back(initial);
	std::cout << "Custom memory allocator created.\n";
}

CustomAllocator::~CustomAllocator()
{
	for (TrackedData trackedData : allTrackedData) {
		if (!trackedData.isFree && trackedData.destroy) {
			trackedData.destroy();
		}
	}
	std::free(memory);

	std::cout << "Custom memory allocator and data deleted.\n";
}

void CustomAllocator::displayMemory() const
{	
	std::cout << "Memory:  " << std::endl;
	std::cout << '|';
	for (TrackedData trackedData : allTrackedData) {
		if (!trackedData.isFree) {
			for (size_t i = 0; i < trackedData.size; i++) {
				std::cout << 'X';
			}
		}
		else {
			for (size_t i = 0; i < trackedData.size; i++) {
				std::cout << '_';
			}
		}
		std::cout << '|';
	}
	std::cout << std::endl;
}

const void* CustomAllocator::getMemory() const
{
	return memory;
}

size_t CustomAllocator::getMaximumSpace() const
{
	size_t maxSpace = 0;
	size_t currentSpace = 0;

	for (TrackedData trackedData : allTrackedData) {
		if (!trackedData.isFree) {
			if (currentSpace > maxSpace) {
				maxSpace = currentSpace;
			}
			currentSpace = 0;
		}
		else {
			currentSpace += trackedData.size;
		}
	}

	if (currentSpace > maxSpace) {
		maxSpace = currentSpace;
	}

	return maxSpace;
}
