/* File: Student.h
 * Project: GPA Calculator
 * Purpose: To calculate a student's GPA and perform basic what-if score operations
 * Author: Samuel Aboud
 * Date: 4/19/2025
 */

#include "Helper.h"
#include <map>
#include <string>

#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student
{
public:

    Student();  // default constructor
    
    void import_file(const string &filename);  // read student info from a onfiguration file and store info in private data member
    
    void add_course(const string &course_name, int credits, char grade);  // insert into the map the pair of course info <credits, grade>

    void change_grade(const string &course_name, char grade);  // change the grade 

    void calculate_GPA();  // calculate and update the GPA private data member  

    void export_file(const string &filename);  // create a configuration file for the student

    void remove_course(const string &course_name);  // remove a course from the private data member

    void find_grade(const string &course_name) const;  // access the grade that matches a given a course number

    void find_credits(const string &course_name) const;  // access the number of credits that matches a given a course number

    void find_courses(char grade) const;  // access the courses that match a given grade

    double get_GPA() const;  // retrieve the GPA private data member

    void print_courses() const;  // list all courses

private:

    map<string, pair<int, char>> Grades;  // this is a map with the KEY being a unique course name and the VALUE being a pair of the credits and grade for the course

    double GPA;  // this is the gpa of the student
};

#endif // STUDENT_H