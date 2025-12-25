TERMINAL-BASED GPA CALCULATOR

FEATURES

This is a comprehensive terminal-based GPA calculator that provides much more functionality than a standard online GPA calculator. The program supports user-provided configuration files to load saved course information. It also includes prefix matching to search for, modify, and remove multiple courses at once using a matched prefix.

The core functionalities of the program include (but are not limited to):

* changing a grade or credits for a course
* adding or removing a course
* finding all courses matching a given grade or number of credits
* looking up the grade or credits for any specific course
* quickly recalculating GPA after course changes to explore "what-if" scenarios
* saving changes for future use

The program handles invalid input gracefully, allowing the user to retry with valid entries. If no configuration file is provided, the program prompts the user to "save their information for next time" (i.e., create a configuration file for future use).

DESIGN

The GPA calculator is implemented with two classes.

The Student class encapsulates the core GPA calculation logic and implements all essential functions for managing courses and GPA. Its primary private data structure is a map that stores the course name as the key and a pair of credits and grade as the value. Much of the input validation in the Student class is handled separately in the Helper class.

The Helper class provides static functions for input validation and prefix matching, keeping utility logic separate from the core GPA functionality and preventing the Student class from becoming too bloated.

USAGE

If using the program for the first time with no configuration file, simply run the program with no additional arguments and add courses as desired. Upon quitting, the program will prompt the user to save changes. Pressing yes (y) will create a configuration file in the config_files folder so the user’s data is saved for next time.

If the user already has a configuration file, simply run the program via:

./Student configurationfilename.config

and press option "I" to load data from a configuration file.

Note that while the program will create a configuration file for you if you manually add classes through the program one by one, there is also an option to provide one separately. In this case, the user must ensure the provided configuration file has the following structure:

ClassName : num_credits letter_grade

For example, a permissible line in a configuration file might be:

CS 115:3 A

Failure to follow this structure will result in an error message informing the user of a configuration file parsing error, although some of these error messages may be vague.

IMPORTANT BEHAVIOR NOTES (FEATURES, NOT BUGS)

There are several key features to be aware of when using this program.

The option to remove a course (H) will remove all courses that match a prefix. For example, if there are two courses, LIN 512 and LAS 201, and the user removes the course with the prefix "L", both courses will be removed, as they both start with L.

Perhaps more perniciously, if there are multiple courses with the same name but varying capitalization or spacing, such as PHY 231, phy 231, and phy     231, then the prefix "phy 231" will remove all three courses. This is because the prefix-matching function is case-insensitive, and any number of spaces greater than one is normalized to a single space.

This feature is very useful for removing multiple courses at once, but users should be aware of this behavior to avoid unintentionally removing more courses than intended.

REVERTING CHANGES

There is also a useful, though not explicit, way of reverting changes made to a configuration file.

If the user has imported a configuration file and later decides that the changes made during the session are undesirable, they can simply import the configuration file again. All changes made to the originally loaded courses will be reverted to their original state.

This avoids the need to quit and restart the program in order to reset a session.

CLOSING REMARKS

My hope is that this program serves as a convenient tool to help college students figure out what grades they need to meet their academic or personal goals. I put a lot of effort into restructuring and refining the code from its original conception, and I can say with fair confidence that it has come a long way toward being an easy and useful tool—not only for calculating one’s GPA, but also for providing confidence and reassurance to those who may be unsure of what level of performance they need to achieve their desired grades.

Enjoy using this GPA calculator. Suggestions or feedback for improvement are always welcome.

— Sam

