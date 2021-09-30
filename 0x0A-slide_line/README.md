# holbertonschool-interview

## 0x0A-slide_line

The goal of this task is to reproduce the 2048 game(NSFW !!) mechanics on a single horizontal line.

Given an array of integers, we want to be able to slide & merge it to the left or to the right. Identical numbers, if they are contiguous or separated by zeros, should be merged 

## Compile:

	$ gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c


## Usage:

	$ ./0-slide_line L 2 2 0 0
	Line: 2, 2, 0, 0
	Slide to the left
	Line: 4, 0, 0, 0

	$ ./0-slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
	Line: 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4
	Slide to the left
	Line: 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

	$ ./0-slide_line R 2 2 2 2 2
	Line: 2, 2, 2, 2, 2
	Slide to the right
	Line: 0, 0, 2, 4, 4	
	
	$ ./0-slide_line R 2 4 8 16
	Line: 2, 4, 8, 16
	Slide to the right
	Line: 2, 4, 8, 16
