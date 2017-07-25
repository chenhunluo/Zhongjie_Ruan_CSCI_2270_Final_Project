# Zhongjie_Ruan_CSCI_2270_Final_Project

I am going to design an application that helps user to find the best travel destination based on their landscape preference, and help the user to calculate the shortest path based on distance and based on least states they will pass to arrive the destination country. 

Three data structures that I will use are the graph, queue, and link list. I will use the graph to map the whole application; different states are independent vertex inside the map; adjacent states are connected with vertex by a weighted edge. The weight in my program represents the distance between two countries. Each vertex is associated with a singly link list, which includes the landscape information, temperature information, population information, and local food information. I will implement a queue to use it for breath first search.

I will first give the user some options of landscapes and ask them which type of landscape they are looking for and give them some suggestions about which state should they go; the information of that state will also be listed by traversing the link list. After user deciding which state they want to go, I will ask their local address and their preference of the trip. If the user wants to pass as fewer states as possible, I will use depth first search to find the route that fits their choice. If the user wants to go to the destination with the shortest distance, I will use Dijkstra to find the route with the shortest distance, which may pass a lot of states. After depth first search and Dijkstra, I will also create a reverse link list function to reverse the link list and print out the path from the start city to end city because the node that returned from DFS and Dijkstra is the end node;

Update:
Instead of implementing queue I used deque library to access queue directly. I also have functions to create trees contain attraction information and connect each tree with the vertex. Basically, there are two data structures are connected with the vertex, link list, and BST.

Update:
Create Hashtable class and use it as a template to store vertices
