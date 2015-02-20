# Who Are We
Team 3705 (the Arrowbots) operates out of Fletcher's Meadow Secondary School in Brampton, Ontario and this is our code for the Recycle Rush game which is for the 2015 FRC Greater Toronto Central at Ryerson University.

# What Does It Do
The code in this repository controls a robot that is designed to stack up to three totes.

# Sensors used
*2 Limit Switches

# Actuators used
*3 CIM Motors
*1 Relay
*3 Talon Motor Controllers
*2 Single Solenoids

# Interesting quirks
	topCounter(&topSwitch),
	bottomCounter(&bottomSwitch),
This code sets up two digital counters that will count presses of a limit switch at the top of the robot and a limit switch at the bottom of the robot. What is interesting about this code is the fact that the argument passed to the constructors of the two digital counters is a pointer. A pointer is the address in the computer's memory that contains a variable. The & operator takes the memory address of a variable. For example, if I write "int x=1" and I then write "&x", I would be taking the memory address of a integer variable with a value of 1. Of course, the reason that the digital counter requires the limit switch objects to be passed as variables is because the signature for the digital counter constructor is Counter(DigitalSoure *source) and the operator * refers to a pointer.

# Glossary
Class: A section of code outlining multiple methods and variables that can be accessed through it
Object: An instance of a class

#License
The license used is the MIT license and it is defined in the license.txt file.

#About the Author
My name is Javed Nissar and I am the only programmer for Team 3705 for the 2015 FRC season.