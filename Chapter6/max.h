#pragma once

// NOTE: function templates
// function for different types but same behavior
template <typename T>
T max(T value1, T value2) {
	// val 1 > val 2
	if (value1 > value2) {
		return value1;
	}
	// val 2 > val 1 or val 2 = val 1
	return value2;
}
