#Program is compiled on Linux OS.

	#To compile the program
		g++ program.cpp -o program
        
        #To run the program
        	./program
#####################################################################################
Program1:Given a word-sequence and line-width.
 	Greedy approach is used. Program is taking single line length based on the given input. 
 	Based on it creats the number of lines.
 	Since the input string are putting word by word in list<string>. Each line are creating based on the line length.
 	One while loop is running.
 	Time Complexity is O(N^2).N is the number of words.
 	
 	
 	
 	
Program2: Input matrix of the Village connectivity is taken as input.
	  If avillage is directly connected to a village, distance between these two is given in the matrix.
	  else considered as INFINITY. For INFINITY macro is defined with value 65635.
	  For self village distance is zero(0);
	  we can give any village as input. It will print distance with each other villages.
	  
	  In this program, 2-D array is used and two for loops are used. Therefore time complexity is O(N^2).
	  N is the number of villages.
####################################################################################################

Program: RectangleAllPathNumber.cpp
In a given rectangle, find out number of path from (0,0) to buttom right corner. Move is allowed only in RIGHT and DOWN direction.
Two solution are given
1. Using Permutation nCr
2. Recursive solution

