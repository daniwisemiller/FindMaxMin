//******************************************************************* 
//                                                                    
//  Program:    Find Max and Min                                           
//                                                                     
//  Author:      Danielle Wisemiller
//  Email:       dw640914@ohio.edu
//                                                                    
//  Lab Section: Section 100 Chelberg
//                                                                    
//  Description: uses findmaxmin function to assess the max, second max, min and second
//					min of the n inputtted list of students. variables are chosen by last
//					name, then first name, then SSN. 
//                                                                    
//  Date:        11/09/17
//                                                                    
//*******************************************************************



#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "FindMaxMin.h"
#include "student.h"
using namespace std;

//******************************************************************
//                                                                  
//  Function:   findmaxmin
//                                                                  
//  Purpose:    finds the max, max2, min, and min2 of the generated
//				students by last name with tie breakers of first name and SSN 
//                                                                  
//  Parameters: vector<Student> &students, size_t &max, size_t &max2, size_t &min, size_t &min2, size_t &num_compares
//
//                                                                  
// Member/Global Variables: 
//
// Pre Conditions: max,min,max2,min2 =0, num_compares =0, students = output of generate
//
// Post Conditions: has indexes of min, max, min2, and max2
//
// Calls:      main
//                                                                  
//******************************************************************
void FindMaxMin(vector<Student> &students, size_t &max, size_t &max2, size_t &min, size_t &min2, size_t &num_compares)
{
	//initialize all variables used in compare loop
	int compare, compare2;
	min = students.size();
	min = students.size()-1;
	Student s, temp;
	string maxLastName, minLastName, max2LastName, min2LastName;
	//loop from 0 to n checking for max, max2, min, min2
	for(size_t i = 0; i < students.size(); ++i)
	{
		//compare strings of max2 to current element
		compare = strcmp(students[max2].last_name.c_str(), students[i].last_name.c_str());
		//if strings are equal then check for first name
		if(compare == 0)
		{
			//check max and max2
			compare = strcmp(students[max2].first_name.c_str(), students[i].first_name.c_str());
			if(compare<0)
			{
				compare2 = strcmp(students[max].first_name.c_str(), students[i].first_name.c_str());
				if(compare2 < 0)
				{
					max2 = max;
					max = i;
					num_compares+=3;
				}
				else
				{
					max2 = i;
					num_compares+=2;
				}
			}	
			//check min and min2
			compare = strcmp(students[min2].first_name.c_str(), students[i].first_name.c_str());
			if(compare>0)
			{
				compare2 = strcmp(students[min].first_name.c_str(), students[i].first_name.c_str());
				if(compare2 > 0)
				{
					min2 = min;
					min = i;
					num_compares+=3;
				}
				else
				{
					min2 = i;
					num_compares+=2;
				}
			}	
		}
		//check which is max and which is max2
		else if(compare < 0)
		{
			compare2 = strcmp(students[max].last_name.c_str(),students[i].last_name.c_str());
			//found max -- switch max and max2
			if(compare2 < 0)
			{
				max2 = max;
				max = i;
				num_compares+=2;
			}
			//still only max2
			else
			{
				max2 = i;
				num_compares+=1;
			}
			//testing print statements for maxs
			// cout<<"MAX "<<temp.last_name<<endl;
// 			cout<<"MAX2 "<<s.last_name<<endl;
		}
		//check if min
		else if(compare > 0)
		{
 			
			compare2 = strcmp(students[min2].last_name.c_str(),students[i].last_name.c_str());
			//check if min or min2
			if(compare2 > 0)
			{
				compare2 = strcmp(students[min].last_name.c_str(), students[i].last_name.c_str());
				//only min2
				if(compare2 < 0)
				{
					min2 = i;
					num_compares+=3;				
				} 
				//found min -- switch min and min2
				else 
				{
					min2 = min;
					min = i;
					num_compares+=2;
				}
			}
			//testing print statements for mins
			// cout<<"MIN "<<temp.last_name<<endl;
// 			cout<<"MIN2 "<<s.last_name<<endl;
		}
	}
	//testing print statements for all variables outside loop
	// cout<<endl;
// 	cout<<"MAX: "<<students[max].last_name<<endl;
// 	cout<<"MAX 2: "<<students[max2].last_name<<endl;
// 	cout<<"MIN: "<<students[min].last_name<<endl;
// 	cout<<"MIN 2: "<<students[min2].last_name<<endl;
}