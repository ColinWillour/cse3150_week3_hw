# cse3150_week3_hw

README.md: short explanation of how you used pointers, const, references,
casting, exceptions, and control flow

Pointers:
The program uses many pointers to work with array parameters and manipulate data inside of arrays. An example is when updating a GPA, the function recieves a "double*" and directly changes the value rather than making a copy. 

Const:
A lot of functions use const to prevent future changes or accidents. When printing a student the name and GPA are both const refrences or pointers which make sure the function can only read the data and not change it.

References:
References are used when the program needs to change the variables without using pointers. Once again goes to the idea of not creating a copy but actually changing the value. The current count of students is passed by reference so that adding a student updates the counter rather than making a copy, and this works across the program.

Casting:
When printing GPA's the program uses static_cast to change the gpa double into a rounded gpa which is an integer. Casting is helpful when converting a value to a different type.

Exceptions:
The program uses exception handling to catch invalid operations, the code throws an exception when the caller tries to update the GPA withoug any students added. This throws an exception saying that no students exist to modify the GPA. The exception prevents crashes and allows the program to print a clear message that states the exact reason it doens't work.

Control Flow:
The main control flow for this program is a while loop and a switch statement that are used to implement the menu. Each option in the menu triggers a different switch statement and also allows for an exit option. It's very easy to follow and read.
