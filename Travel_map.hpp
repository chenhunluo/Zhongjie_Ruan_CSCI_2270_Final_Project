#include <iostream>
#include<vector>
#include"Hashtable.cpp"

using namespace std;

struct adjvertex;
struct Info;
struct Tree;
//Each state is a vertex inside the graph
struct vertex
{
    string city;
    //Connect with Info link list
    Info* next;
    //Connect with Tree BST
    Tree* tree;
    vector <adjvertex> adjacent;
    //used for Dijkstra
    bool solved;
    int distance;
    vertex* parent;
    //used for breath first search
    bool visted;
};

struct adjvertex
{
    vertex* v;
    int weight;
};
//Info stores landscape, population, temperature, local food information of each state
struct Info
{
    string information;
    Info* next;
    //Constructor
    Info (string name, Info* node)
    {
        information=name;
        next=node;
    }
    
};

//Tree struct used for BST, Tree contains 4 attractions information
struct Tree
{
    string attraction;
    Tree* parent;
    Tree* leftchild;
    Tree* rightchild;
};



class Travel_map
{
private:
    //Used for traverse BST
    void printattractionprivate(Tree* root);
    //vertices stored in hashtable
    Hashtable <vertex> vertices;
    //Root of BST
    Tree* root;
    //Used for connect each tree with each vertex
    int counter;
    //vector store all state names
    vector <string> loopthrough;
    
public:
    Travel_map(string filename);
    ~Travel_map();
    //Open file, parsing file, sotre information into graph, link list, BST are all happend in this function
    void loadfile(string filename);
    void insertvertex_and_create_link_list(string cityname,string land, string temp, string pop, string food);
    //Find shortest path
    vertex* Dijkstra(string start, string end);
    //search and return vertex pointer
    vertex* searchvertex(string cityname);
    //After getting the destination from Dijkstra, print the path(because there's a parent connection)
    void printoutshortestdistance(string start, string end);
    //Reverse the link list, because return value for BFS & Dijkstra are destination
    vertex* ReverseLinkedList(vertex *node);
    //search Info->information right next to vetices[]
    void searchlandscape(string landscape);
    //Breath first search
    vertex* BFS(string startcity,string endcity);
    //Print out the path from breath first search
    void printoutBFS(string start, string end);
    //Fill the BST
    void inserttree(string attraction);
    //call printattractionprivate in public
    void printattraction_public(string cityname);
};



