# Mineswept
A simple 5X5 grid game.
Inspired by Microsoft's Minsweeper's game, Mineswept is created using C++ as its language.
Mineswept is made from scratch and can be understood by beginners very easily. The purpose behind this project
was to implement all the basic functions and stream them into a project that was fun yet mind wrecking.

Randomizing the positions of the bombs is the back bone of the program, wherein randomize() functions were used wherever possible.
The 5X5 grid was made using basic coordinating functions, especially 2 dimension arrays that would uniformly place
the numbers in a quadrilateral manner.

The user is first asked to enter its username and then he/she is let to play the game.
The user enters the number that they would want to pop, the player has no idea where the bombs are hidden.
The more number of places are popped, the more he/she scores  points of 5.
As soon as there is point where the player pops the wrong position, the bomb explodes, declaring it to be "Game Over".
The user with the highest number of points is listed on top of the leaderboard. 