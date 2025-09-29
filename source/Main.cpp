/*
 * File: main.cpp
 * Project: GPA Calculator
 * Purpose: Present a user-friendly interface and handle higher-order logic of calling Student class member functions
 * Author: Samuel Aboud
 * Date: 4/19/2025
 */

#include "Student.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        cout << "Error: Too many command-line arguments provided." << endl;
        return 1;
    }

	Student student;

    bool flag = false;
    do
    {
        cout << endl << "This GPA calculator is written by Samuel Aboud, and I hope you're enjoying it." << endl;
        cout << "Please input your menu option (enter Q to quit)." << endl << endl;
        cout << "A -- (Re)Calculate your GPA." << endl;
        cout << "B -- Change a grade." << endl;
        cout << "C -- Find all courses that match a grade." << endl;
        cout << "D -- Find a grade for a given course." << endl;
        cout << "E -- Find the number of credits for a given course." << endl;
        cout << "F -- List all courses." << endl;
        cout << "G -- Add a course." << endl;
        cout << "H -- Remove a course." << endl;
        cout << "I -- Load data from a configuration file." << endl << endl;
        cout << "Enter your choice: ";
		
        char grade, input;
        string name, course_name;
        
        cin >> input;
        switch (toupper(input)) 
        {
            case 'Q':  // Option Q
            {   
                cout << "Would you like to save your information for next time? (enter y/n): ";	
	            char choice;
                
                cin >> choice;
                if(choice == 'y' || choice == 'Y')
	            {                    
	                cout << "Enter your name: ";

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	                getline(cin, name);
	                name += ".config";
                    student.export_file(name);
                    
                    cout << "Configuration file saved as: " << "'" << name << "'." << endl;
                    cout << "Thank you for using Sam's GPA calculator!" << endl;

                    flag = true;  
	            }                 
                else if (choice == 'n' || choice == 'N')
                {
                    cout << "Thank you for using Sam's GPA calculator!" << endl;
                    flag = true;  
                }
                else
                {
                    cout << "Invalid input. Please enter y/n." << endl;
                }
            }
            	break;
            case 'A':  // Option A: Calculate your GPA
            {
                cout << fixed << setprecision(2);
                student.calculate_GPA();
                cout << "Your GPA is: " << student.get_GPA() << endl;
            }
            	break;
            case 'B':  // Option B: Change a grade
            {
                cout << "For which course would you like to change your grade?" << endl;
                cout << "Enter the name of the course for which you would like to change your grade: ";
                                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, course_name);
                
                cout << "What would you like your new grade to be?" << endl;
                cout << "Enter a grade: ";

                cin >> grade; 
                student.change_grade(course_name, grade);
            }
            	break;
            case 'C':  // Option C: Find all courses that match a grade
            {
                cout << "What grade would you like all courses to match?" << endl;
                cout << "Enter a grade: ";

                cin >> grade;
                student.find_courses(grade);
            }
                break;
            case 'D':  // Option D: Find a grade for a given course
            {                
                cout << "For what course would you like to know your grade?" << endl;
                cout << "Enter the name of the course: ";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');    
                getline(cin, course_name);

                student.find_grade(course_name);
            }
                break;
            case 'E':  // Option E: Find the number of credits for a given course
            {                
                cout << "For what course would you like to know the number of credits?" << endl;
                cout << "Enter the name of the course: ";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');    
                getline(cin, course_name);

                student.find_credits(course_name);
            }
                break;
            case 'F':  // Option F: Print student info
			{
				student.print_courses();
			}                
                break;
            case 'G':  // Option F: Add a course
            {
                cout << "Which course would you like to add?" << endl;
                cout << "Enter the name of the course to be added: ";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');    
                getline(cin, course_name);

                cout << endl << "Enter number of credit hours for " << course_name << ": ";
                int credits;
                cin >> credits;

                if (cin.fail())
                {
                    cout << "Error: attempting to pass an invalid integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    cout << "Enter grade for " << course_name << ": ";
                    cin >> grade;

                    student.add_course(course_name, credits, grade);
                }                
            }
                break;            
            case 'H':  // Option G: Remove a course
            {
                cout << "Which course would you like to remove?" << endl;
                cout << "Enter the name of the course to be deleted: ";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');    
                getline(cin, course_name);

                student.remove_course(course_name);
            }
                break;
            case 'I':  // Option H: Load student data
            {
                if (argc == 1)
                {
                    cout << "Warning: No configuration file provided. Please re-load the program with an additional command-line argument." << endl;
                }
                else
                {
                    student.import_file(argv[1]);
                }

				cin.ignore(numeric_limits<streamsize>::max(), '\n');                
            }
				break;
			default:
			{
				cout << "Invalid option, please try again." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}                
            	break;
        }                        
    } while (!flag);

    return 0;
}