//******************************************************************* 
//                                                                    
//  Program:    Main File                                           
//                                                                     
//  Author:      Danielle Wisemiller
//  Email:       dw640914@ohio.edu
//                                                                    
//  Lab Section: Section 100 Chelberg
//                                                                    
//  Description: utilizes the generate functions in order to create a test
//				set of students with names and SSN and GPA, calls the functions
//				from the main while keeping track of compares and time 
//                                                                    
//  Date:        11/09/17
//                                                                    
//*******************************************************************

//includes and .h files
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sys/time.h>
#include "FindMaxMin.h"
#include "student.h"

using namespace std;

//******************************************************************
//                                                                  
//  Function:   timeval2sec
//                                                                  
//  Purpose:    Computes the number of seconds from a timeval of microseconds  
//                                                                  
//  Parameters: const timeval& T
//                                                                  
// Member/Global Variables: 
//
// Pre Conditions: none
//
// Post Conditions: returns seconds
//
// Calls:       timeofday
//                                                                  
//******************************************************************
double timeval2sec(const timeval& T) 
{
	// Constant for time unit conversion
	const double USEC_TO_SEC = 1000000.0;

	return ((double) T.tv_sec + (double) (T.tv_usec / USEC_TO_SEC));
}

//******************************************************************
//                                                                  
//  Function:   timeofday
//                                                                  
//  Purpose:    Computes the time of day in seconds.                                  
//                                                                  
//  Parameters: none
//                                                                  
// Member/Global Variables: timeval T
//
// Pre Conditions: none
//
// Post Conditions: returns the cost in dollars of shipping a
//                  package that weighs weight pounds a distance
//                  of distance miles.
//
// Calls:       main
//                                                                  
//******************************************************************
double timeofday() 
{
	timeval T;
	gettimeofday(&T, NULL);
	return (timeval2sec(T));
}

//******************************************************************
//                                                                  
//  Function:   genRandomNum
//                                                                  
//  Purpose:    generates a random number as a string for SSN                        
//                                                                  
//  Parameters: length of SSN
//                                                                  
// Member/Global Variables: string r, char num[]
//
// Pre Conditions: length = 10
//
// Post Conditions: returns a string of randomized numbers with length 10
//
// Calls:      generateStudents
//                                                                  
//******************************************************************
string genRandomNum(int length)
{
	string r;
	//array of numbers to chose from
	static const char num[] =
	"0123456789";
	//loop to add random nums to
	for (int i = 0; i < length; ++i) 
	{
		r.push_back(num[rand() % (sizeof(num) - 1)]);
	}
	//return random string of nums
	return r;
}
//******************************************************************
//                                                                  
//  Function:   genRandom
//                                                                  
//  Purpose:    generates a random string for first and last names 
//                                                                  
//  Parameters: length of string
//                                                                  
// Member/Global Variables: string name, char letters[]
//
// Pre Conditions: length = 5 for first name, length = 10 for last name
//
// Post Conditions: returns a string of randomized characters
//
// Calls:      none
//                                                                  
//******************************************************************
string genRandom(int length)
{
	string name;
	static const char letters[] =
	"abcdefghijklmnopqrstuvwxyz";
	int stringLength = sizeof(letters) - 1;
	
	for(int i = 0; i < length; ++i) 
	{
		name.push_back(letters[rand() % stringLength]);
	}
	name[0] = toupper(name[0]);
	return name;
}

//******************************************************************
//                                                                  
//  Function:   generateStudents
//                                                                  
//  Purpose:    generates n students with names, SSN and GPA 
//                                                                  
//  Parameters: size_t num
//                                                                  
// Member/Global Variables: svector<Student> testing, Student temp_student
//
// Pre Conditions: num = length of input desired -- set to 1000 in main
//
// Post Conditions: returns n length students
//
// Calls:      main
//                                                                  
//******************************************************************
vector<Student> generateStudents(size_t num)
{
	vector <Student> testing;
	Student temp_student = {};

	for (size_t i = 0; i < num; ++i) 
	{
		// get a random social security number:
		temp_student.SSN = genRandomNum(10);// and assign it

		// get a random first name:
		string first_name;
		first_name = genRandom(5);
		temp_student.first_name = first_name;

		// get a random last name:
		string last_name;
		last_name = genRandom(10);
		temp_student.last_name = last_name;

		temp_student.major = "Computer Science";
		temp_student.gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/4.0));

		testing.push_back(temp_student);
	}
	return(testing);
}



//******************************************************************
//                                                                  
//  Function:   main
//                                                                  
//  Purpose:    calls functions 
//                                                                  
//  Parameters: none
//                                                                  
// Member/Global Variables: mins, maxs, vector<Student> Students, num_compares
//						NUM_STUDENTS
//
// Pre Conditions: length = 5 for first name, length = 10 for last name
//
// Post Conditions: returns a string of randomized characters
//
// Calls:      generateStudents
//                                                                  
//******************************************************************
int main ()
{
	srand(time(NULL));		//randomize time
	vector<Student> Students;	//vector of students
	size_t min, min2, max, max2; //declare mins and maxes
	size_t num_compares=0;		//initialize to 0
	const size_t NUM_STUDENTS=4;	//size of input
	double start=timeofday();		//start timing

	Students = generateStudents(NUM_STUDENTS);
	// for(int i=0; i<Students.size(); i++)
// 		cout<<"SSN: "<<Students[i].SSN<< " First: "<<Students[i].first_name<<" Last: "<<Students[i].last_name
// 		 <<" Major: "<<Students[i].major<<" GPA: "<<Students[i].gpa<<endl;
	cout<<endl<<endl;
	FindMaxMin(Students, max, max2, min, min2, num_compares);

	cout << "FindMaxMin took " << timeofday() - start << " seconds" 
			 << " on input of size " << NUM_STUDENTS << endl;

	cout << "FindMaxMin took " << num_compares << " comparisons" 
			 << " on input of size " << NUM_STUDENTS << endl;

	return(EXIT_SUCCESS);
}
