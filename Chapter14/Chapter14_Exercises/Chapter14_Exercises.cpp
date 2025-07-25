// Chapter14_Exercises.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Person.h"

using namespace std;

void displayContents(fstream&);

void updatePersonAge(fstream&, int);

void deletePerson(fstream&, int);


int main()
{
    // create nameage.dat file with 100 records that store blank Person objects
    fstream peopleFile{ "nameage.txt", ios::in | ios::out | ios::binary };

    if (!peopleFile) {
        cout << "nameage.txt file not found." << endl;
        exit(EXIT_FAILURE);
    }

    peopleFile.seekp(0, ios::end);

    if (peopleFile.tellp() == 0) {
        Person person;

        // initialize 50 people
        for (int i = 0; i < 50; i++) {
            peopleFile.write(reinterpret_cast<char*>(&person), sizeof(Person));
        }

        peopleFile.flush();
        peopleFile.seekg(0);
    }

    // input 10 last names, first names, and ages and write them to the file
    for (int i = 0; i < 10; i++) {
        Person person;

        string lastname;
        string firstname;
        int age;

        cout << "Enter last name, first name, and age like 'lastName firstName age'\n? ";
        
        cin >> setw(15) >> lastname;
        cin >> setw(10) >> firstname;
        cin >> age;

        person.setLastName(lastname);
        person.setFirstName(firstname);
        person.setAge(age);
        person.setId(i);

        peopleFile.seekp(i * sizeof(Person));
        peopleFile.write(reinterpret_cast<char*>(&person), sizeof(Person));
    }

    displayContents(peopleFile);

    // update a record that already contains information, if none, print "No info"

    // update person 4
    updatePersonAge(peopleFile, 4);
    //displayContents(peopleFile);

    // cannot update person 20
    updatePersonAge(peopleFile, 20);

    // delete a record with information by reinitializing that record

    // can delete person 5
    deletePerson(peopleFile, 5);
    displayContents(peopleFile);

    // cannot delete person 30
    deletePerson(peopleFile, 30);

}

void displayContents(fstream& file) {
    file.clear();

    file.seekg(0);

    cout << left << setw(4) << "Id" << setw(15) << "Last Name" << setw(10) << "First Name" << right << setw(5) << " Age" << endl;

    while (!file.eof()) {
        Person person;
        file.read(reinterpret_cast<char*>(&person), sizeof(Person));

        cout << left << setw(4) << person.getId() << setw(15) << person.getLastName() << setw(10) << person.getFirstName() 
            << right << person.getAge() << endl;

    }

}

void updatePersonAge(fstream& file, int id) {
    file.clear();

    Person toUpdate;
    file.seekg(id * sizeof(Person));

    file.read(reinterpret_cast<char*>(&toUpdate), sizeof(Person));

    if (toUpdate.getId() == -1) {
        cout << "Person has not initialized, cannot update age." << endl;
        return;
    }

    int newAge;
    cout << "Update age\n? ";
    cin >> newAge;
    toUpdate.setAge(newAge);

    file.seekp(id * sizeof(Person));
    file.write(reinterpret_cast<char*>(&toUpdate), sizeof(Person));
    cout << "Age of person with id #" << id << " was updated to " << newAge << endl;

}

void deletePerson(fstream& file, int id) {
    file.clear();
    Person toUpdate;
    file.seekg(id * sizeof(Person));

    file.read(reinterpret_cast<char*>(&toUpdate), sizeof(Person));

    if (toUpdate.getId() == -1) {
        cout << "Person has not initialized, cannot delete person." << endl;
        return;
    }

    Person blankPerson;

    file.seekp(id * sizeof(Person));
    file.write(reinterpret_cast<char*>(&blankPerson), sizeof(Person));
    cout << "Person with id #" << id << " was deleted." << endl;
}



