Most of the design decisions are explained in brief comments above the individual functions in each file that I wrote.

Listed below are the errors and warnings that we worked to resolved while working on the lab. 

We had issues with arithmetic overflow errors, which were initially constant throughout the lab. We were able to resolve these after we realized the [] operator requires unsigned
integers, so we went ahead and assigned the indices we calculated to be of this type. We had issues with signed and unsigned matches, which we were able to resolve by ensuring that we cast certain variables and made sure that the indices of our loops matched our variables. We had issues with exceptions that resulted due to out of bounds errors, which we were able to resolve by using the debugger to step through our code.

Overall, we managed to avoid any major errors while working on this lab by making sure to rebuild my solution after writing each function, which led us to catching small errors as they popped up.

Test Cases

1. Lab4.exe 
- This ran correctly, displaying the usage message. Initially, this command timed out but I managed to account for the case by checking for it at the beginning of our function.
2. Lab4.exe random
- This ran correctly, displaying the usage message due to the wrong name for the game.
3. Lab4.exe random random.
- This ran correctly, displaying the usage message due to the incorrect number of arguments.
4. Lab4.exe TicTacToe
- This ran correctly, displaying the TicTacToe board. Listed below are some of the subcases I tested.
	- Normal inputs worked and resulted in draw or loss/win for both players. Board is reprinted after each turn with updated moves and move list.
	- Tested input to make sure that a square could only filled once, argument had to be passed in correctly in form of 'x,y'. Coordinates off the board caused a prompt from the user to input valid points.
	- Quit game worked properly, displays proper message and ends program
	- A variety of test cases were ran, all worked properly confirming proper implementation of the program. Some examples included a horizontal win, vertical win, diagonal wins, and drawn games. Both players were able to achieve victory.

5. Lab4.exe Gomoku
- This ran correctly, displaying the Gomoku board. Listed below are some of the subcases I tested.
	- Normal inputs worked and resulted in draw or loss/win for both players. Board is reprinted after each turn with updated moves and move list.
	- Double digits didn't mess up the board, as adequate spacing was achieved. 
	- Tested input to make sure that a square could only filled once, argument had to be passed in correctly in form of 'x,y'. Coordinates off the board caused a prompt from the user to input valid points.
	- Quit game worked properly, displays proper message and ends program
	- A variety of test cases were ran, all worked properly confirming proper implementation of the program.
		- Horizontal victory with win condition of 5, vertical victory, diagonal victory (in both ways). Draw was not tested in 19 by 19 board, but was tested in extra credit.
		- Both players were able to achieve victory.

All the initial checks with extra arguments passed, usage message was prompted in all of these scenarios.

1. Lab4.exe Gomoku 3 3

Output: Correctly prints out 3 by 3 board with win condition of 3. Wins are possible by either player.
3

2

1

0   1   2   3

It is player B's turn.
Please input a valid coordinate of the type 'x,y' to make a move or input 'quit' to end the game

1. Lab4.exe Gomoku 5 5

Output: Correctly prints out 5 by 5 board with win condition of 5. Draw was also tested here successfully, game is declared a tie if there are no paths to victory.

5

4

3

2

1

0   1   2   3   4   5

It is player B's turn.
Please input a valid coordinate of the type 'x,y' to make a move or input 'quit' to end the game

Draw Example

5   B       W       B

4   W   W   B   W   W

3   B   W   B       B

2   W   W       B   W

1   B   B   W       B

0   1   2   3   4   5

W's moves: 2, 2; 4, 4; 5, 4; 5, 2; 1, 2; 1, 4; 2, 4; 3, 5; 2, 3; 3, 1;
The match was a tie!
20 moves were played.