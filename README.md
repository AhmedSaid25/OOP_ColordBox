# OOP_ColordBox
Declare and implement a class ColoredBox which stores a box of characters (Dynamic 2D array).
The class has private member variables that are attributes of the box like the box itself(which is a dynamic 2D array of characters), a character that forms the box, dimensions of the box (length and width) and color of the box (integer). The class also has a static member variable that stores the biggest area among the boxes objects of the class.
This is an example of a box with the character ‘*’ as its building block, length =5, width = 7, color = 4 (equivalent to Red)
1- A constructor or constructors that takes length and width of the box (mandatory), the character that constructs the box (optional and if not provided the character is ‘#’), the color of the box (optional and if not provided the color is white).
2- Getters and setters for the building block character and color of the box.
3- A display function that prints the box
4- A function displayTransposed that displays the box transposed
5- A function displayWider that displays the box on a wider scale,
6- A function that takes a color as a parameter and displays the box as a chess board where a character is displayed with the original color of the object, and the next character is displayed with the parameter color. For example let’s say we have a box object (boxObj) with dimensions 4 and 7, the character ‘&’, and the color 14 (yellow). We call the member function: boxObj.displayChess(4).
7- A function getArea that returns the calculated area of the box (if for ex. Length = 10 and width = 3, then area = 30)
8- A static member function getMaxArea that returns the value of the static member variable.
9- A destructor that frees dynamic memory
