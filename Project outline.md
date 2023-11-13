# Description 

We utilized reg51.h header file in
C language to design and program a
security door lock system using
8051 microcontroller secured with 
a 4-digit changeable passcode. 

The  program would ask the user
to type 'E' or 'R', to decide weather
he need to unlock the door or to 
reset it, the second step is to enter
the the passcode. The character
if typed was 'E' in the first step
would unlock the door, for the 
correct passcode else would restrain 
the user from in the attempt, 
while for 'R', it would overwrite 
the earlier passcode. 

# Overview
Using the reg51.h header file for 
8051 microcontroller for the design.

Initializing the passcode to be 1234, 
setting timer 1 of 8051 to mode 2,
8-bit-reload, with a baud rate of 9600
and enabling serial buffer to receive data.
We start the timer 1.
This would prompt the user to choose to 
enter or reset the passcode, by typing
letter `r` or `e`.

In any case the user would be prompted
to enter the passcode, while, the next
stage differs from here. If the initial
character was `e`, indicating to enter 
the passcode, it would transmit 
the passcode to array `EnteredPassCode`
, call `ComparePassCode` function 
to compare the array and send `A` or `D` 
for authorization or decline.

While for `R` in earlier prompt 
would call `resetPasscode` which would 
overwrite `authorizedPasscode` 
the passcode with the new one.

# Uses
These certain kind of security door 
lock systems are in use today, with
increasing crime, these type of technologies
are prevalent in every sectors 
comprising public institutions, 
production plants, administrative buildings,
hospitals, commercial offices and 
private residences.
