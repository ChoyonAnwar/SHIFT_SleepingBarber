# SHIFT_SleepingBarber
Solution to SHIFT sleeping barber problem. 

I use the basic template used in FE522 to solve this problem using C++.  Just insert the header and the cpp file in Visual Studio or even VSCode on Mac, build and run. 

Some concerns I have:  

Though the program runs as wanted, skipping customers when the M number of seats are full, the barber seems to never sleep again.  
Also, I am not sure what objected-oriented programming concepts were expected but it seems like I have solved the problem using none.  I just used multithreading techniques.  

Additionally, the "customer leaving" line as well as the waiting room number order is not exactly how the example case provided but that is just simple aesthetics that can be fixed if needed.

Finally, as I did not know much about threading, nor things like mutex, I must credit a YouTube series which really helped me learn how to solve this problem in a fast and clear manner.  Bo Qian;s, video: C++ Threading #6: Condition Variable, gave me the basis for my solution.  His video can be found here: https://www.youtube.com/watch?v=13dFggo4t_I&t=360s
