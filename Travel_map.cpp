#include "Travel_map.hpp"
#include <iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<deque>
using namespace std;
//Also declear the size of the hash table
Travel_map::Travel_map(string filename) :vertices(1000)
{
    //Initialize root
    root=nullptr;
    //Load file, create link list, create BST, create edge.
    loadfile(filename);
    
}

Travel_map::~Travel_map()
{
    cout<<"Thank you for using our trip match system."<<endl;
    cout<<"Hope to see you again."<<endl;
}


void Travel_map::loadfile(string filename)
{
    ifstream Datafile(filename);
    if(!Datafile)
        cout<<"Open file failed"<<endl;
    string nothing,city,land,temp,pop,food,wholeline,attraction;
    string current;
    string first;
    for(int i=0;i<=16;i++)
    {
        getline(Datafile,wholeline);
        istringstream ss(wholeline);
        getline(ss,nothing,','); //Just the index for each state, not used
        getline(ss,city,',');//State name
        getline(ss,land,',');//Landscape type
        getline(ss,temp,',');//Temperature range
        getline(ss,pop,',');//Population
        getline(ss,food,',');//Famout local food
        insertvertex_and_create_link_list(city,land,temp,pop,food);
        //After food, there are four attractions separated by ','.
        while(getline(ss,attraction,','))
        {
            inserttree(attraction);
        }
        //Connect vertex with each tree
        vertices.get(city).tree=root;
        //reset root for creating a new tree
        root=nullptr;
        loopthrough.push_back(city);
    }
    //Insert edges and weight
    while(getline(Datafile,wholeline))
    {
        istringstream ss (wholeline);
        getline(ss,temp,',');
        first=temp;
        while(getline(ss,temp,','))
        {
            current=temp;
            getline(ss,temp,',');
            adjvertex hi;
            hi.weight=stoi(temp);
            hi.v=&vertices.get(current);
            vertices.get(first).adjacent.push_back(hi);
        }
        
    }
}

void Travel_map::insertvertex_and_create_link_list(string cityname,string land, string temp, string pop, string food)
{
    vertex hello;
    hello.city=cityname;
    hello.solved=false;
    hello.visted=false;
    //building connetion
    Info* landscape = new Info(land,nullptr);
    hello.next=landscape;
    Info* tempp = new Info(temp,nullptr);
    landscape->next=tempp;
    Info* popp = new Info(pop,nullptr);
    tempp->next=popp;
    Info* foo = new Info(food,nullptr);
    popp->next=foo;
    //insert vertex into hash table
    vertices.set(cityname,hello);
}


//Search vertex from vector and return the result
vertex* Travel_map::searchvertex(string cityname)
{
    if(vertices.checkexist(cityname))
    {
        return &vertices.get(cityname);
    }
    else
        
        return nullptr;
}

//Find closest path
vertex* Travel_map::Dijkstra(string start, string end)
{
    int dist = 0;
    vertex* parent = nullptr;
    vertex* startvertex = searchvertex(start);
    vertex* endvertex = searchvertex(end);
    startvertex->solved=true;
    startvertex->distance=0;
    //Set the parent of start node for traverse
    startvertex->parent=nullptr;
    vector<vertex*> solved;
    solved.push_back(startvertex);
    while(!endvertex->solved)
    {
        int shortest=INT_MAX;
        vertex* solvedVertex=new vertex;
        for(int i=0; i<solved.size();i++)
        {
            vertex* s = solved[i];
            for(int y=0;y<s->adjacent.size();y++)
            {
                if(!s->adjacent[y].v->solved)
                {
                    dist=s->distance+s->adjacent[y].weight;
                    if(dist<shortest)
                    {
                        solvedVertex = s->adjacent[y].v;
                        shortest=dist;
                        parent=s;
                    }
                }
            }
        }
        solvedVertex->distance=shortest;
        solvedVertex->parent=parent;
        solvedVertex->solved=true;
        solved.push_back(solvedVertex);
    }
    //reset solved to false
    for(int i=0; i<loopthrough.size();i++)
    {
        vertices.get(loopthrough[i]).solved=false;
    }
    cout<<"Your shortest distance total is "<<dist<<" miles"<<endl;
    return endvertex;
}

//print out the result path from Dijkstra
void Travel_map::printoutshortestdistance(string start, string end)
{
    vertex* current = Dijkstra(start, end);
    vertex* reversed = ReverseLinkedList(current);
    while(reversed!=nullptr)
    {
        if(reversed->parent==nullptr)
        {
            cout<<reversed->city;
        }
        else
            cout<<reversed->city<<" -> ";
        reversed=reversed->parent;
    }
    cout<<endl;
    
}
//Based on input and give a suggestion about which city to go and show user other informations
//Traversing link list
void Travel_map::searchlandscape(string landscape)
{int k=1;
    for(int i=0; i<loopthrough.size();i++)
    {
        if(vertices.get(loopthrough[i]).next->information==landscape)
        {
            cout<<"Match "<<k<<endl;
            cout<<"The landscape of "<<loopthrough[i]<<" is "<<vertices.get(loopthrough[i]).next->information<<"."<<endl;
            cout<<"The temperature range of "<<loopthrough[i]<<" is "<<vertices.get(loopthrough[i]).next->next->information<<" F "<<endl;
            cout<<"The population of "<<loopthrough[i]<<" is "<<vertices.get(loopthrough[i]).next->next->next->information<<endl;
            cout<<"The food of "<<loopthrough[i]<<" is "<<vertices.get(loopthrough[i]).next->next->next->next->information<<endl;
            k++;
            cout<<endl;
        }
    }
}
//Parent in this case means next
//Reverse link list cause BFS and Dijkstra return end node;
vertex* Travel_map::ReverseLinkedList(vertex *node)
{
    
    vertex *newhead=nullptr;
    bool first = true;
    while(node->parent)
    {
        vertex* temp = node;
        while(temp->parent->parent)
        {
            temp=temp->parent;
        }
        temp->parent->parent=temp;
        if(first)
        {
            newhead=temp->parent;
            first = false;
        }
        temp->parent=nullptr;
    }
    return newhead;
}

//Breath first search
vertex* Travel_map::BFS(string startcity, string endcity)
{
    vertex* start = searchvertex(startcity);
    start->visted=true;
    start->distance=0;
    start->parent=nullptr;
    deque<vertex*> myqueue;
    myqueue.push_back(start);
    while(!myqueue.empty())
    {
        vertex* n = myqueue.front();
        myqueue.pop_front();
        for(int i=0;i<n->adjacent.size();i++)//might be problem
        {
            if(!n->adjacent[i].v->visted)
            {
                n->adjacent[i].v->distance=n->distance+1;
                n->adjacent[i].v->parent=n;
                if(n->adjacent[i].v->city==endcity)
                {
                    return n->adjacent[i].v;
                }
                else
                {
                    n->adjacent[i].v->visted=true;
                    myqueue.push_back(n->adjacent[i].v);
                }
            }
        }
    }
    
    return nullptr;
}

//cout the path result got from BFS
void Travel_map::printoutBFS(string start, string end)
{
    vertex* happy = BFS(start, end);
    vertex*apppp = ReverseLinkedList(happy);
    while(apppp!=nullptr)
    {
        if(apppp->parent==nullptr)
        {
            cout<<apppp->city<<endl;
        }
        else
            cout<<apppp->city<<" -> ";
        apppp=apppp->parent;
    }
    //After BFS, Re set visted value to false;
    for(int i=0; i<loopthrough.size();i++)
    {
        vertices.get(loopthrough[i]).visted=false;
    }}

//Insert BST
void Travel_map::inserttree(string attraction)
{
    Tree* temp = root;
    //temporary node to store the parent for building connection
    Tree* parent=nullptr;
    //create new node and store all datas
    Tree* newnode = new Tree;
    newnode->attraction = attraction;
    newnode->parent=nullptr;
    newnode->leftchild=nullptr;
    newnode->rightchild=nullptr;
    //find the parent of the newnode
    while(temp != nullptr)
    {
        parent = temp;
        if(newnode->attraction < temp->attraction)
        {
            temp=temp->leftchild;
        }
        else
            temp=temp->rightchild;
    }
    // if root is nullptr
    if(parent==nullptr)
    {
        root=newnode;
    }
    else if(newnode->attraction < parent->attraction)
    {
        //Don't forget to make it doubly linklist
        parent->leftchild=newnode;
        newnode->parent=parent;
    }
    else
    {
        parent->rightchild=newnode;
        newnode->parent=parent;
    }
}

//Traverse and print out tree
void Travel_map::printattractionprivate(Tree* temp)
{
    if(temp->leftchild !=nullptr)
    {
        printattractionprivate(temp->leftchild);
    }
    
    cout<<"Attraction: "<<temp->attraction<<endl;
    
    if(temp->rightchild !=nullptr)
    {
        printattractionprivate(temp->rightchild);
    }
    
}
//Call function above in main
void Travel_map::printattraction_public(string cityname)
{
    printattractionprivate(vertices.get(cityname).tree);
    
}


