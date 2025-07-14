#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DoubleSubscriptedArray
{
public:
	DoubleSubscriptedArray(int r, int c) {
		rows = r;
		cols = c;
		grid = new T*[r];
		for (int i = 0; i < r; i++) {
			grid[i] = new T[c];
		}

	}

	T operator()(int row, int col) {
		return grid[row][col];
	}

	void add(int r, int c, T obj) {
		if (r < 0 || r >(rows - 1) || c < 0 || c >(cols - 1)) {
			throw invalid_argument("Invalid row and/or column.");
		}
		
		grid[r][c] = obj;
	}

	void display() {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				cout << grid[r][c] << " ";
			}
			cout << endl;
		}
	}
private:
	T** grid;
	int rows;
	int cols;
};
