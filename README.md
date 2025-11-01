# Student
This is a simple yet comprehensive terminal-based GPA calculator that goes above and beyond any GPA calculator you will find online!

Various functionalities include:

  • Supports user-provided configuration files to load saved course info
  • Prefix-matching enabled to add/remove/modify multiple courses at once using a matched prefix
  • In addition to the basic GPA calculations and adding/removing courses, users have the ability to:
      (1) change a grade for a course
      (2) find all courses matching a given grade / number of credits
      (3) find a grade for any given course
      (4) quickly recalculate GPA after course changes were made to view a "what-if" score scenario
      (5) save changes made for next time to a configuration file.  If no configuration file provided, the program gives the user
          the option to make one
      (6) rest assured that any errenous input will be graciously handled, allowing the user to retry with valid input

Design:

This GPA calculator was designed with the implementation of 2 classes: the Student class and the Helper class
The Student class simply defines and implements the various member functions of the Student class that make up the core logic of the 
GPA calculator
The Helper class is a class of static member functions that only serve input validation and prefix-matching purposes, abstracting away 
any logic that is not directly revelant to the core logic of the GPA calculator

I hope you enjoy this program, and if you have any suggestions on how to make this project more robust, feel free to leave a message!

-Sam
