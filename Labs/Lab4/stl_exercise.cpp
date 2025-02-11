//--------------------------------------------------------------------
// STL List Exercise
// file: main.cpp
//
// Reads a list of student names, sorts the list according to a key, and
// prints the sorted list.
//
//	Modified by: Alex Clarke -- November 5, 2014
//  Modified by: Catherine Song -- October 30, 2015 
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct DataType
{
    string lastname;	// Student's Last Name
    string firstname;	// Student's First Name

    string getKey() const
    {
        return lastname;
    }   // Returns the key field
};

// Overload the << operator to output DataType
ostream& operator<<(ostream& os, const DataType& data) {
    os << data.firstname << " " << data.lastname;
    return os;
}

// Overload the < operator to compare DataType's keys (last names)
bool operator < (const DataType& lhs, const DataType& rhs) {
    return lhs.getKey() < rhs.getKey();
}

int main()
{
    ifstream studentFile("input.txt");  // Student file
    list<DataType> students;            // Students
    DataType currStudent;              // One Student (has firstname,lastname)

    // Read each line from input.txt and store into the list
    while (studentFile >> currStudent.firstname >> currStudent.lastname) {
        students.push_back(currStudent);
    }

    // Print the unsorted list
    cout << "Unsorted list:" << endl;
    for (list<DataType>::iterator it = students.begin(); it != students.end(); ++it) {
        cout << *it << endl;
    }

    // Sort the list
    students.sort();

    cout << endl;
    // Print the sorted list
    cout << "Sorted list:" << endl;
    for (list<DataType>::iterator it = students.begin(); it != students.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}