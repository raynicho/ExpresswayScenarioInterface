# ExpresswayScenarioInterface

Driving scenarios for the NADS MiniSim take months to produce and take up a major portion of driving research studies. This software was created in order to help the Driver Interface Group at the University of Michigan Transportation Research Institute build and test expressway scenarios in a quick and correct manner. The program consists of three major portions:

- reading the scenario files
- editing the scenario file quickly and correctly
- a graphical interface useful to the researcher

##Authors and Contributors

Raymond Pressly (raynicho@umich.edu)

##Files

*triggers.h:* contains classes used for all triggers present in MiniSim/ISAT

*actions.h:* contains classes for various actions that triggers can cause in MiniSim/ISAT

*vehicles.h:* contains classes for creating and writing vehicles in MiniSim/ISAT

*expresswayClass.h:* maintains all triggers, vehicles, and other scneario objects in one location

*main.h, main.cpp:* various functions used throughout the scenario interface

*staticObject.h:* class that handles reading and writing functionality of static scenario objects 

*virtualObject.h:* class that handles reading and writing functionality of virtual scenario objects 

##To Do
- develop writing functionality of the program
- test reading and writing functionality of the program
- develop objects for handling different virtual objects
- develop process for iterating across trials (sections of expressway) and placing scenario interactions
- develop graphical interface to make placing scenario interactions easier
