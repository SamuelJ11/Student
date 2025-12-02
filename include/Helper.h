/* File: Helper.h
 * Project: GPA Calculator
 * Purpose: Serve as a helper class to the Student class to perform input validation and prefix-matching
 * Author: Samuel Aboud
 * Date: 4/19/2025
 */

#include <map>
#include <vector>
#include <string>

#ifndef HELPER_H
#define HELPER_H

using namespace std;

class Helper
{
public:

    static bool checkIfEmpty(const map<string, pair<int, char>>& Grades); // check if either course name or Grades map is emtpy

    static bool checkCourseName(const string& course_name); // check that coursename is not NULL

    static bool validate_pair(pair<int, char> pair); // validate pair of <credits, grade>

    static bool validate_grade(char valid_chars);  // validate grade info   

    static vector<string> prefixMatch(string course_name, const map<string, pair<int, char>> &Grades);  // returns a vector of prefix-matched course names

private:

    static string wordFormat(string &course_name);  // capitalize all characters in course_name for prefix matching

    static void removeExtraSpace(string &course_name);  // removes the extra blank spaces(including tab) from course_name

    static int compareByPrefix(const string &course_name, const string& key, int r);  // compares the two courses in lexicographic order using only the first r characters of each prefix
};

#endif // HELPER_H