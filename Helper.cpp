/*
 * File: Helper.cpp
 * Course: CS216-005
 * Project: GPA Calculator
 * Purpose: Provide the implementation of the Helper class
 */

#include "Helper.h"
#include <iostream>

using namespace std;

bool Helper::validate_grade(char grade)
{
	const string VALID_GRADES = "abcdfABCDF";
	bool result = false;

	if (!isalpha(grade)) 
	{
		cout << "Error: Attempting to pass grade as a non-alphabetic character." << endl;		
	} 
	else if (VALID_GRADES.find(grade) == string::npos) 
	{
		cout << "Error: Attempting to pass an invalid grade." << endl;
	}
	else
	{
		result = true;
	}
	
	return result;
}

bool Helper::validate_pair(pair<int, char> pair)
{
	bool result = false;
	if (pair.first < 1 || pair.first > 8)
	{
		cout << "Error: Attempting to pass credits as an out-of-bounds integer." << endl;
	}
	else
	{
		result = Helper::validate_grade(pair.second);
	}

	return result;	
}

void Helper::removeExtraSpace(string& course_name)
{     
    int start = 0;
    int end = course_name.length() - 1;    
    while (start <= end && course_name[start] == ' ')
    {
        if (course_name[start] == ' ')
        {
            start ++;
        }        
    }

    while (end >= start && course_name[end] == ' ')
    {
        if (course_name[end] == ' ')      
        {
            end --;
        }          
    }  
    
    string trimmed = course_name.substr(start, end - start + 1);  
    for (int i = 0; i <= trimmed.length() - 1; i++)  // Remove any extra whitespaces in the middle of the trimmed string
    {
        if (trimmed[i] == ' ' && trimmed[i + 1] == ' ')
        {
            trimmed.erase(i + 1, 1);
            i--;  // Erase shifts everything after space to the left, decrement iterator to check for multiple spaces
        }
    }

    course_name = trimmed;
} 

string Helper::wordFormat(string& course_name)
{
    Helper::removeExtraSpace(course_name);

    for (char& ch : course_name) // Change every character to upper case in course_name
    {
        ch = toupper(ch);
    }

    return course_name;
}

int Helper::compareByPrefix(const string& course_name, const string& key, int r)
{
    string prefix = course_name.substr(0, r);
    string key_prefix = key.substr(0, r);

    return prefix == key_prefix;
}

vector<string> Helper::prefixMatch(string course_name, const map<string, pair<int, char>>& Grades)
{
    vector<string> matches;

    Helper::wordFormat(course_name);
    int r = course_name.length();

    for (auto itr = Grades.begin(); itr != Grades.end(); ++itr)
    {
        string key = itr->first; 
		Helper::wordFormat(key);
        
        if (compareByPrefix(course_name, key, r))  // Use compareByPrefix to check for a match
        {
            matches.push_back(itr->first);  // add the original course_name to the matches vector		
        }
    }

    return matches;
}