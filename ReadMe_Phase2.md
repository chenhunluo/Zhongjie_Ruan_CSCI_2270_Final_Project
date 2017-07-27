Readme Phase2

Data structure that used: Graph, Hash table, link list, BST

***Project Summary***

First I need to explain how my text file works. 

My txt file contains different states, and all information relates to that state.
Ex:
0(index),Wyoming(name of the state),plain(landscape of that state),61-88(temperature range),585501(population),jerkey(famous local food),Yellowstone National Park(attraction),Grand Teton National park(attraction),Old Faithful(attraction),Rocky Mountains(attraction)

Each vertex includes one state name. Every vertex is also connected by one link list and one BST.
Temperature, population, landscape, local food is stored in a singly link list. Four attractions are stored in a BST.

Another part of the text file contains different connections and weight between states. 
Ex:
  Colorado(vertex state),Wyoming(adjacent),50(weight),Nebraska(adjacent),115(weight),Oklahoma(adjacent),85(weight).

Basically, after the loadfile function is finished. All of the trees, link lists, and graph are built(I called insert tree, add vertex in side loadfile function).

Instead of creating a vector to store all vertex, I implement a Hashtable template class and use this class template to create vertices to store all vertex.
 
In hashtable class, the array is composed of the node. Each node contains a string key(name of the state) and a T value(in this case is vertex). I also implement a checking for collision, which is solved by creating a link list.

My program has five basic functionalities.
•    Getting information about which state you should go based on your landscape preference. In this option, the user just needs to input landscape type (Ex: canyon, river, urban, etc.) and I will give user opinions about states that have that landscape and also tell user additional information about that state (stored in link list).
•    Showing user four famous attractions. The user just needs to input state name they want to go, and I will list four most famous attractions of that state (stored in BST).
•    Calculate the shortest distance from user’s home to the state he/she want to go. Dijkstra function calculates the exact number of the distance. 
•    Print out the path from start location to the end location. The result is got from the Printshortestdistance function.  Printshortestdistance called Dijkstra first to get the end node, then call the reverse function to reverse the link list connect by parent and then output the path of correct order.
•    Print out the path that contains the least amount of state by using BFS. The path from Dijkstra can give you the path that has the shortest distance, but you may have to pass some unnecessary states. BFS gives you a straightforward path. (Some paths got from Dijkstra and BFS may same). 

***How to Run***

![how to run program](/howto.png)

***System Requirements***

The program is tested on both mac system and windows system. Follow the picture instruction and run it on terminal should work on both system.



