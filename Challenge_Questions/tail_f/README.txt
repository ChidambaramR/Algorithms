Objective:
===========
	Simulate the behavior of tail -f command.

Logic:
======
	The idea is simple. We have to use a file monitoring system call provided by the OS. We need to watch that descriptor
	and when an event has occured, we go ahead and print the last n lines of the file.
