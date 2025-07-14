// Chapter7_Machine_Language_Processing_Ex.cpp: This example creates a simple computer
// called the Simpletron.  The Simpletron has a special register that handles instructions
// in terms of words, which are signed four digit decimal numbers.
// The Simpletron has a 100-word memory and words are referenced by their location numbers 00, 01,
// , ... 99.  Before running a SML program, instructions must be loaded into memory
// starting at location 00.  The sign of an SML instruction is always positive
// but the sign of a data word can be positive or negative.
// Each location in the register may contian an instruction, data value,
// or area of memory (defined or undefined).  The first two digits of each instruction
// are the operation code that specifies the operation to be performed and last two digits are the
// operand or address of memory location with word to which operation applies.


// ex. 1007 -> 10 means read first number from keyboard and place at location 07
// ex. 2007 -> 20 or load instruction copies number at 07 into accumulator
// ex. 3007 -> add number to number in accumulator


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int MEMORY_SIZE = 100;
    int accum = 0; // accum register
    int instrCountr = 0; // instruction counter
    int instrRegistr; // current instruction
    int memory[MEMORY_SIZE]; // instructions and data stored here
    
    cout << "*** Enter your program instructions ***" << endl;
    cout << "*** Enter -99999 to stop ***" << endl;

    // load program
    while (true) {
        cout << setfill('0') << setw(2) << instrCountr;
        cout << " ? ";
        cin >> instrRegistr;

        if (instrRegistr == -99999) {
            memory[instrCountr] = 4300;
            break;
        }
        if (instrRegistr < -9999 || instrRegistr > 9999) {
            cout << "Invalid instruction, must be signed 4 digit number." << endl;
            continue;
        }
        if (instrCountr >= 100) {
            cout << "Memory full, halting instructions." << endl;
            break;
        }

        memory[instrCountr++] = instrRegistr;
    }

    cout << "*** Program loading ended. ***" << endl;
    cout << "*** Program running started. ***" << endl;


    // run program
    instrCountr = 0;

    while (true) {
        // halt or end of memory
        if (memory[instrCountr] >= 4300 || instrCountr >= 100) {
            cout << "*** Program execution ended ***" << endl;
            cout << "Accumulator: " << accum << endl;
            cout << "Instruction Counter: " << instrCountr;
            break;
        }
        // branch to location in memory if accum is 0
        else if (memory[instrCountr] >= 4200) {
            if (accum == 0) {
                instrCountr = memory[instrCountr] - 4200;
            }
        }
        // branch to location in memory if accumulator is negative
        else if (memory[instrCountr] >= 4100) {
            if (accum < 0) {
                instrCountr = memory[instrCountr] - 4100;
            }
        }
        // branch to location in memory
        else if (memory[instrCountr] >= 4000) {
            instrCountr = memory[instrCountr] - 4000;
        }
        // multiply
        else if (memory[instrCountr] >= 3300 && memory[instrCountr] <= 3399) {
            accum = accum * memory[memory[instrCountr++] - 3300];
        }
        // divide
        else if (memory[instrCountr] >= 3200 && memory[instrCountr] <= 3299) {
            int divisor = memory[memory[instrCountr++] - 3200];
            if (divisor == 0) {
                cout << "Cannot divide by 0." << endl;
                continue;
            }
            accum = accum / divisor;
        }
        // subtract
        else if (memory[instrCountr] >= 3100 && memory[instrCountr] <= 3199) {
            accum = accum - memory[memory[instrCountr++] - 3100];
        }
        // add
        else if (memory[instrCountr] >= 3000 && memory[instrCountr] <= 3099) {
            accum = accum + memory[memory[instrCountr++] - 3000];
        }
        // store
        else if (memory[instrCountr] >= 2100 && memory[instrCountr] <= 2199) {
            memory[memory[instrCountr++] - 2100] = accum;
        }
        // load
        else if (memory[instrCountr] >= 2000 && memory[instrCountr] <= 2099) {
            accum = memory[memory[instrCountr++] - 2000];
        }
        // write
        else if (memory[instrCountr] >= 1100 && memory[instrCountr] <= 1199) {
            cout << memory[memory[instrCountr++] - 1100] << endl;
        }
        // read
        else if (memory[instrCountr] >= 1000 && memory[instrCountr] <= 1099) {
            int val;
            cout << "? ";
            cin >> val;
            cout << endl;
            if (val < -9999 || val > 9999) {
                cout << "Value being read into memory must be a signed 4 digit number.";
                continue;
            }
            memory[memory[instrCountr++] - 1000] = val;  
        }
        else {
            cout << "Invalid instruction.";
            continue;
        }
    }

}