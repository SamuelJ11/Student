TERMINAL-BASED GPA CALCULATOR

This is a comprehensive terminal-based GPA calculator that provides more functionality than a standard online GPA calculator.

The program supports user-provided configuration files to load saved course information. It allows prefix-matching to add, remove, or modify multiple courses at once using a matched prefix.

In addition to basic GPA calculations and course management, the program enables changing a grade for a course, finding all courses matching a given grade or number of credits, looking up the grade for any specific course, quickly recalculating GPA after course changes to explore "what-if" scenarios, and saving changes for future use.

The program handles invalid input gracefully, allowing the user to retry with valid entries. If no configuration file is provided, the program prompts the user to create one.

DESIGN

The GPA calculator is implemented with two main classes. The Student class encapsulates the core GPA calculation logic and implements all essential functions for managing courses and GPA. The Helper class provides static functions for input validation and prefix-matching, keeping utility logic separate from the core GPA functionality for a cleaner design.

Enjoy using this GPA calculator. Suggestions or feedback for improvement are always welcome.

— Sam
