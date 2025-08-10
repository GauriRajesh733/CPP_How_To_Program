#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include <exception>
#include <algorithm>

struct TrackedData {
	TrackedData() {
		size = 0;
		data = nullptr;
		isFree = false;
		destroy = []() {
		};

	}
	size_t size;
	void* data;
	bool isFree;
	std::function<void()> destroy;
};


class CustomAllocator
{
private:
	void* memory;
	size_t totalMemory;
	std::vector<TrackedData> allTrackedData;

	template<typename T, typename... Args>
	T* allocateViaSplit(int index, size_t dataSize, Args&&... args) {
		TrackedData& trackedData = allTrackedData[index];
		// overwrite existing data
		T* data = new (trackedData.data) T(std::forward<Args>(args)...);
		size_t leftoverSize = trackedData.size - dataSize;
		trackedData.isFree = false;
		trackedData.size = dataSize;
		// add destructor to tracked data
		trackedData.destroy = [data]() {
			data->~T();
			};

		// add additional slot for leftover memory if any
		if (leftoverSize > 0) {
			TrackedData leftoverData;
			leftoverData.data = (char*) data + dataSize;
			leftoverData.size = leftoverSize;
			leftoverData.isFree = true;

			// return pointer to freed memory slot used
			allTrackedData.insert(allTrackedData.begin() + index + 1, leftoverData);
		}
		
		std::cout << "Successfully allocated space for data.\n";
		return data;
	}
public:
	// create custom memory allocator
	CustomAllocator(size_t size);

	// destruct custom allocator and free memory
	~CustomAllocator();

	// display contents of memory
	void displayMemory() const;

	// get location of start of allotted memory
	const void* getMemory() const;

	// get maximum size of continuous memory
	size_t getMaximumSpace() const;

	// allocate space for data
	template<typename T, typename... Args>
	T* allocateMemory(Args&&... args) {
		size_t dataSize = sizeof(T);
		bool enoughMemory = (dataSize <= getMaximumSpace());

		// insufficient continuous space for new data
		if (!enoughMemory)  {
			std::cout << "Unable to allocate space for new data.\n";
			return nullptr;
		}

		TrackedData newData;
		T* data = nullptr;

		// sufficient continuous space for new data
		
		// check if new data can be accomodated without combining tracked data slots
		for (int i = 0; i < allTrackedData.size(); i++) {
			TrackedData& trackedData = allTrackedData[i];

			// new data fits perfectly into free tracked data slot
			if (trackedData.isFree && trackedData.size == dataSize) {
				data = new (trackedData.data) T(std::forward<Args>(args)...);
				trackedData.isFree = false;
				trackedData.destroy = [data]() {
					data->~T();
					};
				std::cout << "Successfully allocated space for data.\n";
				return data;
			}

			// new data is smaller than free tracked data slot, need to split
			if (trackedData.isFree && trackedData.size > dataSize) {
				data = allocateViaSplit<T>(i, dataSize, std::forward<Args>(args)...);
				return data;
			}
		}

		// check if new data can be accomodated by combining memory slots
		int startIdx = 0;
		int endIdx = 0;
		size_t totalSize = 0;

		for (size_t i = 0; i < allTrackedData.size(); i++) {
			TrackedData& trackedData = allTrackedData[i];

			if (!trackedData.isFree) {
				totalSize = 0;
				startIdx = -1;
				endIdx = -1;
			}
			else {
				if (startIdx == -1 && endIdx == -1) {
					startIdx = i;
				}

				endIdx = i;
				totalSize += trackedData.size;
			}

			if (totalSize >= dataSize) {
				// combine slots
				allTrackedData[startIdx].size = totalSize;

				// remove extra memory slots if needed
				if (startIdx != endIdx) {
					allTrackedData.erase(allTrackedData.begin() + startIdx + 1, allTrackedData.begin() + endIdx + 1);
				}

				// allocate memory by splitting combined slot
				data = allocateViaSplit<T>(startIdx, dataSize, std::forward<Args>(args)...);
				return data;
			}
		}

		std::cout << "Unable to allocate space for new data using unused or freed memory.\n";
	}

	template<typename T>
	void freeMemory(T* data) {
		for (int i = 0; i < allTrackedData.size(); i++) {
			if (allTrackedData[i].data == data && !allTrackedData[i].isFree) {
				// call destructor from tracked data
				allTrackedData[i].destroy();
				// mark tracked data as free
				allTrackedData[i].isFree = true;

				allTrackedData[i].destroy = {};
			
				std::cout << "Memory slot of size " << allTrackedData[i].size << " bytes freed.\n";
				data = nullptr;
				return;
			}
		}
		// given data is not stored in custom allocator
		std::cout << "Given data not stored in custom memory allocator.  Please delete manually.\n";
	}


};


