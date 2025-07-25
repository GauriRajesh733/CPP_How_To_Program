#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "ClientData.h"

using namespace std;

enum class Choice {PRINT=1, UPDATE, NEW, DELETE, END};

Choice enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const ClientData&);
int getAccount(const char* const);


int main()
{
	/*
	// ofstream constructor opens file
	// NOTE: can use ios:app instead of ios::out to append data
	ofstream outClientFile("clients.txt", ios::out);

	// exit program if unable to create file
	// RECALL: ! overloaded operator used to check if file succesfully created 
	// ! returns true if FAILBIT or BADBIT set for stream (ex. here could
	// be due to opening nonexistent file for reading, opening file in dir you
	// don't have access to, no disk space to write to opened file)


	// RECALL: overloaded operator bool converts stream to TRUE or FALSE so it 
	// can be tested (ex. end of file indicator sets failbit for cin)
	// RECALL: failbit indicates recoverable error (RECALL: incorrect input format for ex.)
	// RECALL: badbit indicates more severe error
	if (!outClientFile) {
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Enter the account, name, and balance.\nEnter end-of-file to end input.\n? ";

	int account;
	string name;
	double balance;

	// read account, name, and balance from cin, then place in file
	while (cin >> account >> name >> balance) {
		outClientFile << account << ' ' << name << ' ' << balance << endl;
		cout << "? ";
	}

	// open file
	ofstream outClientFile2;
	outClientFile2.open("clients.txt", ios::app);

	outClientFile2 << "Appending text after opening file";

	// explicitly calling destructors
	outClientFile2.close();

	// NOTE: to read data from sequential file and make sure contents 
	// are not edited, use ios::in

	ifstream inClientFile("clients.txt", ios::in);

	if (!inClientFile) {
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	cout << left << setw(10) << "Account" << setw(13) << "Name" << "Balance\n" << fixed << showpoint;


	while (inClientFile >> account >> name >> balance) {
		cout << left << setw(10) << account << setw(13) << name
			<< setw(7) << setprecision(2) << right << balance << endl;
	}

	// file-position pointers

	// 5th byte of file object (assumes ios::beg)
	inClientFile.seekg(5);
	cout << inClientFile.rdbuf(); // read remaining content into string stream

	// position 5 bytes in fileObject from current position
	inClientFile.seekg(5, ios::cur);
	cout << inClientFile.rdbuf(); // read remaining content into string stream

	// position n bytes back from end of fileObject
	inClientFile.seekg(5, ios::end);
	cout << inClientFile.rdbuf();

	// position at end of fileObject
	inClientFile.seekg(0, ios::end);
	cout << inClientFile.rdbuf();

	// NOTE: seekg (seek get) vs seekp (seek put) to position file position pointer


	inClientFile.close();

	// NOTE: can use quote() to read quoted text from stream and treat as one unit

	// NOTE: when updating sequential files in place cannot use formatted input/output mode
	// NOTE: one technique could be making change, copying text after updated text in a new file, 
	// copying over text, and then deleting old file (but this is only acceptable if many records need to be
	// updated in 1 pass of the file)

	// NOTE: sequential files are NOT APPROPRIATE for INSTANT-ACCESS APPLICATIONS!
	// -> instant access is made possible with RANDOM-ACCESS FILES 
	// -> imposing structure on file (ex. same fixed length) can help determine location
	// of any record immediately relative to beginning of file
	// THINK: railroad car with same-size cars (some empty some not)
	// THEREFORE, data can be inserted into random access file without corrupting other data


	// creating random-access file: function read inputs bytes at location in file
	// specified by get file position pointer

	// ex. writing int to file (for 4 byte int could be 1 to 11 bytes)
	// first arg to write is group of bytes (RECALL: const char* is pointer to byte since char is 1 byte)
	// second arg specifies number of bytes to output
	// NOTE: reinterpret_cast used to convert pointers to const char* as expected by function
	int num = 5;
	outClientFile.write(reinterpret_cast<const char*>(&num), sizeof(num));

	outClientFile.close();

	*/
	// ex. credit processing program

	// NOTE: size of client data object is PLATFORM DEPENDENT!
	// NOTE: how to keep track of objects of DIFFERENT TYPES in SAME FILE??
	// -> object serialization: serialized object is represented in PLATFORM INDEPENDENT
	//    manner as sequence of bytes w object's data, info on type, and types of data in object
	// -> objects can be deserialized to recreate object in memory 
	// NOTE: there are third party open source cpp libraries that support this (ex. Boost C++)


	// open file for reading and writing
	fstream inOutCredit{ "credit.txt", ios::in | ios::out | ios::binary };


	inOutCredit.seekp(0, ios::end);

	// if file is empty add blank data
	if (inOutCredit.tellp() == 0) {
		ClientData blankClient;

		for (int i = 0; i < 100; i++) {
			inOutCredit.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
		}

		inOutCredit.flush();
		inOutCredit.seekg(0);
	}
	

	// exit if file cannot be opened
	if (!inOutCredit) {
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	Choice choice;

	while ((choice = enterChoice()) != Choice::END) {
		switch (choice) {
		case Choice::PRINT:
			createTextFile(inOutCredit);
			break;
		case Choice::UPDATE:
			updateRecord(inOutCredit);
			break;
		case Choice::NEW:
			newRecord(inOutCredit);
			break;
		case Choice::DELETE:
			deleteRecord(inOutCredit);
		default:
			cerr << "Invalid choice." << endl;
			break;

		}

		inOutCredit.clear(); // reset end-of-file indicator
	}
}

// display menu choices to user
Choice enterChoice() {
	cout << "\nEnter your choice\n"
		<< "1 - store a formatted text file of accounts\n"
		<< " called \"print.txt\" for printing\n"
		<< "2 - update an account\n"
		<< "3 - add a new account\n"
		<< "4 - delete an account\n"
		<< "5 - end program\n? ";

	int menuChoice;
	cin >> menuChoice; // input menu selection from user
	return static_cast<Choice>(menuChoice);
}

void createTextFile(fstream& readFromFile) {
	ofstream outPrintFile("print.txt", ios::out);

	if (!outPrintFile) {
		cerr << "File could not be created." << endl;
		exit(EXIT_FAILURE);
	}

	outPrintFile << left << setw(10) << "Account" << setw(16)
		<< "Last Name" << setw(11) << "First Name" << right
		<< setw(10) << "Balance" << endl;

	// set file-position reader to beginning of readFromFile
	readFromFile.seekg(0); 

	/// read first record
	ClientData client;
	readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

	// copy all records from record file into text file
	while (!readFromFile.eof()) {
		if (client.getAccountNumber() != 0) {
			outputLine(outPrintFile, client);
		}

		readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
	}
}

void updateRecord(fstream& updateFile) {
	int accountNumber{ getAccount("Enter account to update") };

	updateFile.seekg((accountNumber - 1) * sizeof(ClientData));

	ClientData client;
	updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

	if (client.getAccountNumber() != 0) {
		outputLine(cout, client); // NOTE: used outputLine function for writing to console and file since ostream& passed in func

		cout << "\nEnter charge (+) or payment (-): ";
		double transaction;
		cin >> transaction;

		double oldBalance = client.getBalance();
		client.setBalance(oldBalance + transaction);
		outputLine(cout, client);

		// move file position ponter to correct record in file
		updateFile.seekp((accountNumber - 1) * sizeof(ClientData));

		// overwrite client data with updated record
		updateFile.write(reinterpret_cast<const char*> (&client), sizeof(ClientData));
	}
	else {
		cerr << "Account #" << accountNumber << " has no information." << endl;
	}
}

// create and insert record
void newRecord(fstream& insertInFile) {
	int accountNumber{ getAccount("Enter new account number") };

	insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));
	ClientData client;
	insertInFile.read(reinterpret_cast
		<char*> (&client), sizeof(ClientData));

	// create record if it does not exist
	if (client.getAccountNumber() == 0) {
		string lastname;
		string firstname;
		double balance;

		cout << "Enter lastname, firstname, balance\n? ";
		cin >> setw(15) >> lastname;
		cin >> setw(10) >> firstname;
		cin >> balance;
		cout << firstname;
		cout << lastname;
		cout << balance;

		client.setFirstName(firstname);
		client.setLastName(lastname);
		client.setBalance(balance);
		client.setAccountNumber(accountNumber);

		insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));
		insertInFile.write(reinterpret_cast<char*>(&client), sizeof(ClientData));
	}
	else {
		cerr << "Account #" << accountNumber << " already contains information." << endl;
	}
}

void deleteRecord(fstream& deleteFromFile) {
	int accountNumber{ getAccount("Enter account to delete") };

	deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));

	ClientData client;
	deleteFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));


	if (client.getAccountNumber() != 0) {
		ClientData blankClient;
		deleteFromFile.seekp((accountNumber - 1) * sizeof(ClientData));

		// replace with blank record
		deleteFromFile.write(reinterpret_cast<char*>(&blankClient), sizeof(ClientData));
	
		cout << "Account #" << accountNumber << " was deleted.\n";
	}
	else {
		cerr << "Account #" << accountNumber << " is empty.\n";
	}	
}

void outputLine(ostream& output, const ClientData& record) {
	output << left << setw(10) << record.getAccountNumber()
		 << setw(16) << record.getLastName()
		 << setw(11) << record.getFirstName()
		 << setw(10) << setprecision(2) << right << fixed
		 << showpoint << record.getBalance() << endl;
}

// obtain account-number value from user
int getAccount(const char* const prompt) {
	int accountNumber;

	// obtain account-number value
	do {
		cout << prompt << " (1 - 100): ";
		cin >> accountNumber;

	} while (accountNumber < 1 || accountNumber > 100);

	return accountNumber;
}
	



