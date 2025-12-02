/*
 * File: Student.cpp
 * Project: GPA Calculator
 * Purpose: Provide the implementation of the Student class
 * Date: 4/19/2025
 */

#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

Student::Student()
{
	GPA = 0.0;
}

void Student::import_file(const string &filename)
{
    ifstream in_file;
	string folder = "config_files/";
    in_file.open(folder + filename);

    if (!in_file.good())
    {
        cout << "Warning: Cannot open file named " << filename << "!" << endl;
    }
	else
	{		
		string line, course_name;
		int credits;
		char grade;    
		while (getline(in_file, line))  // Read the entire line
		{
			if (!line.empty())
			{
				istringstream iss(line);

				if (line.find(":") == string::npos) // If there's no colon in the line
				{
					cout << "Error: Missing colon delimiter." << endl;
				}
				else if (!getline(iss, course_name, ':') || course_name.empty())
				{
					cout << "Error: Invalid or missing course name." << endl;
				}
				else if (!(iss >> credits)) 
				{
					cout << "Error: Credits is not a valid integer." << endl;
					iss.clear(); 
					iss.ignore(numeric_limits<std::streamsize>::max(), '\n'); 
				}		
				else
				{
					iss >> grade;			
					grade = toupper(grade); 
					auto course_info = make_pair(credits, grade);

					if (Helper::validate_pair(course_info))
					{
						Grades[course_name] = course_info;
						cout << course_name << " imported successfully." << endl;
					}
				}
			}
		}	
	}
}

void Student::export_file(const string &filename)
{
	ofstream out_file;
	string folder = "config_files/";
	out_file.open(folder + filename);

	if (!out_file.good())
	{
		cout << "Warning: Cannot open file named " << filename << "!" << endl;
	}
	else
	{
		for (auto itr = Grades.begin(); itr != Grades.end(); ++itr)
		{
			out_file << itr->first << ":";
			out_file << itr->second.first << " ";
			out_file << itr->second.second << endl;
		}

		out_file.close();
	}	
}

void Student::add_course(const string &course_name, int credits, char grade)
{
	if (Helper::checkCourseName(course_name))
	{
		char grade_upper = toupper(grade);
		auto course_info = make_pair(credits, grade_upper);

		if (Helper::validate_pair(course_info))
		{
			Grades[course_name] = course_info;
			cout << course_name << " has been added successfully." << endl;
		}	
	} 
}

void Student::remove_course(const string &course_name)
{
	if (Helper::checkIfEmpty(Grades) && Helper::checkCourseName(course_name))	
	{
		vector<string> matches = Helper::prefixMatch(course_name, Grades); 
		if (matches.empty()) 
		{
			cout << "No courses found matching the given course name!" << endl;
		}
		else 
		{
			for (const string& matched_course : matches) 
			{			
				auto itr = Grades.find(matched_course);				
				Grades.erase(matched_course);
				cout << matched_course << " has been removed successfully." << endl;
			}
		}
	}
}

void Student::change_grade(const string &course_name, char grade)
{
	if (Helper::checkIfEmpty(Grades) && Helper::checkCourseName(course_name) && Helper::validate_grade(grade))
	{	
		vector<string> matches = Helper::prefixMatch(course_name, Grades); 
		if (matches.empty()) 
		{
			cout << "No courses found matching the given course name!" << endl;
		}
		else
		{
			for (const string& matched_course : matches) // For each matched course, change the grade
			{
				auto itr = Grades.find(matched_course);					
				itr->second.second = toupper(grade);  							
			}
		}  
	}					
}

void Student::find_courses(char grade) const
{
	if (Helper::checkIfEmpty(Grades) && Helper::validate_grade(grade))
	{		
		vector<string> matchingCourses; 

		for (auto itr = Grades.begin(); itr != Grades.end(); ++itr)
		{
			if (itr->second.second == toupper(grade))
			{
				matchingCourses.push_back(itr->first);
			}
		}

		if (!matchingCourses.empty())
		{
			cout << "The courses in which you received a(n) " << "'" << (char)toupper(grade) << "'" << " are: " << endl;

			for (const string& course : matchingCourses)
			{
				cout << course << endl;
			}
		}
		else
		{
			cout << "No courses found with the grade " << "'" << (char)toupper(grade) << "'" << "." << endl;
		}				
	}	
}

void Student::find_grade(const string &course_name) const
{
	if (Helper::checkIfEmpty(Grades) && Helper::checkCourseName(course_name))
	{
		vector<string> matches = Helper::prefixMatch(course_name, Grades); 
		if (matches.empty()) 
		{
			cout << "No courses found matching the given course name!" << endl;
		}
		else 
		{
			for (const string& matched_course : matches) // For each matched course, display the grade
			{			
				auto itr = Grades.find(matched_course);
				if (itr != Grades.end()) 
				{
					cout << "Your grade in " << matched_course << " is: " << itr->second.second << endl;
				}
			}
		}
	}    
}

void Student::find_credits(const string &course_name) const
{
	if (Helper::checkIfEmpty(Grades) && Helper::checkCourseName(course_name))
	{
		vector<string> matches = Helper::prefixMatch(course_name, Grades); 
		if (matches.empty()) 
		{
			cout << "No courses found matching the given course name!" << endl;
		}
		else 
		{
			for (const string& matched_course : matches) // For each matched course, display the number of credits
			{			
				auto itr = Grades.find(matched_course);
				if (itr != Grades.end()) 
				{
					cout << "The number of credits for " << matched_course << " is: " << itr->second.first << endl;
				}
			}
		}
	}    
}

void Student::calculate_GPA()
{
	int total_credits = 0;
	int course_quality_points = 0;

	for (auto itr = Grades.begin(); itr != Grades.end(); ++itr)
	{
		int quality_points = 0;
		char grade = itr->second.second;

		switch (grade)
		{
			case 'A':
				quality_points = 4;
				break;
			case 'B':
				quality_points = 3;
				break;
			case 'C':
				quality_points = 2;
				break;
			case 'D':
				quality_points = 1;
				break;
			case 'F':
				quality_points = 0;
				break;
		}

		course_quality_points += (itr->second.first * quality_points);
		total_credits += itr->second.first;
	}

	if (total_credits != 0)
	{
		GPA = static_cast<double>(course_quality_points) / total_credits;		
	}
	else
	{
		GPA = 0.0;
	}
}

double Student::get_GPA() const
{
	return GPA;
}

void Student::print_courses() const
{
	if (Helper::checkIfEmpty(Grades))
	{
		cout << "Your previously completed courses are:" << endl;
		for (auto itr = Grades.begin(); itr != Grades.end(); ++itr)
		{			
			cout << itr->first << endl;		
		}
	}	
}