Objective:
==========
	Write a function which prints Foo when i is divisible by 3, prints Bar when divisible by 5 and prints FooBar when 
	divisible by both 3 and 5. 
	
Logic:
======
	It is a very simple problem but can be optimized greatly. Each mod operation is costly. So we need to try and reduce the
	mod operations involved.
	One method is that, we can store i%3 and i%5 in a variable and use this result for i%3 and i%5 instead of doing the
	mod oepration again.
	Other method is to completely avoid the mod being used. Let the counter run. Let us have two variables i3 and i5.
	If the counter equals i3 and i5 print FooBar, else if the counter equals i3, print Foo, else if the counter equals i5
	print Bar. When the counter equals i3 and i5, increment i3 by 3 and increment i5 by 5. Similarly if the counter
	equals only i3, increment i3 by 3 and if the counter equals only i5, increment by 5.
