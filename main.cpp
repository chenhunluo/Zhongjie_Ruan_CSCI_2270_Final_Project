#include <iostream>
#include "Travel_map.hpp"
using namespace std;

int main()
{
    Travel_map test("Project.txt");
    cout<<"Welcome to travel suggestion system!"<<endl;
    cout<<endl;
    cout<<"We will give suggestions about which city you should go based on you natural landscape preference."<<endl;
    cout<<endl;
    cout<<"You will also get the information about your destination like, current temperature, local population, and famous local food."<<endl;
    cout<<endl;
    cout<<"Our company is still in infancy, some cities may not included in out system."<<endl;
    cout<<"States that are in our system now are: "<<endl;
    cout<<"<Wyoming> <Colorado> <South Dakota> <Nebraska> <Oklahoma> <Texas> <Minnesota> <Iowa> <Missouri>"<<endl;
    cout<<"<Kentucky> <Tennessee> <California> <Ohio> <Pennsylvania> <New York> <Michigan> <Indiana>"<<endl;
    cout<<"If your state or the state you want to go are not listed above, please wait for next update"<<endl;
    cout<<endl;
    cout << "======Travel Partner======" << endl;
    cout << "1. Find your perfection destination" << endl;
    cout<<  "2. Get attraciton information"<<endl;
    cout << "3. Calculate the fastest route" << endl;
    cout << "4. Print out fastest route" << endl;
    cout << "5. Find the route contains least state" << endl;
    cout << "6. Quit" << endl;
    string choice;
    cout<<endl;
    cout<<"Please enter the number: "<<endl;
    getline(cin,choice);
    while(choice!="6")
    {
        if(choice=="1")
        {
            string landscape;
            cout<<"Great, you have choices of river, canyon, diverse, desert, forest, lake, cornfield ."<<endl;
            cout<<" plain, beach, farm, urban "<<endl;
            cout<<"Please enter your ideal landscape: "<<endl;
            getline(cin,landscape);
            cout<<"***********************************************"<<endl;
            test.searchlandscape(landscape);
            cout<<"***********************************************"<<endl;
            cout<<endl;
            cout<<"Found your favourite place?"<<endl;
            cout<<"Enter other numbers to get for information"<<endl;
            cout<<"Enter 1 again to search other landscapes"<<endl;
            cout << "======Travel Partner======" << endl;
            cout << "1. Find your perfection destination" << endl;
            cout<<  "2. Get attraciton information"<<endl;
            cout << "3. Calculate the fastest route" << endl;
            cout << "4. Print out fastest route" << endl;
            cout << "5. Find the route contains least state" << endl;
            cout << "6. Quit" << endl;
            getline(cin,choice);
            
            
        }
        if(choice=="2")
        {
            cout<<"Please enter your dstination to get the information about attractions";
            string input;
            cout<<"State name: "<<endl;
            getline(cin,input);
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            test.printattraction_public(input);
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<endl;
            cout << "======Travel Partner======" << endl;
            cout << "1. Find your perfection destination" << endl;
            cout<<  "2. Get attraciton information"<<endl;
            cout << "3. Calculate the fastest route" << endl;
            cout << "4. Print out fastest route" << endl;
            cout << "5. Find the route contains least state" << endl;
            cout << "6. Quit" << endl;
            getline(cin,choice);
            
        }
        if(choice=="3")
        {
            cout<<"Great,we will search the best route that hs shortest distance from your home to the destination"<<endl;
            string currentlocatoin;
            string destination;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            cout<<"Remember! Please enter the valid city listed before."<<endl;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            cout<<"Please enter your home address: "<<endl;
            getline(cin,currentlocatoin);
            cout<<"Please enter your destinaton: "<<endl;
            getline(cin,destination);
            cout<<"---------------------------------------------"<<endl;
            test.Dijkstra(currentlocatoin, destination);
            cout<<"---------------------------------------------"<<endl;
            cout<<endl;
            cout << "======Travel Partner======" << endl;
            cout << "1. Find your perfection destination" << endl;
            cout<<  "2. Get attraciton information"<<endl;
            cout << "3. Calculate the fastest route" << endl;
            cout << "4. Print out fastest route" << endl;
            cout << "5. Find the route contains least state" << endl;
            cout << "6. Quit" << endl;
            getline(cin,choice);
            
            
        }
        if(choice=="4")
        {
            string currentlocatoin;
            string destination;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            cout<<"Remember! Please enter the valid city listed before."<<endl;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            cout<<"Please enter your home address: "<<endl;
            getline(cin,currentlocatoin);
            cout<<"Please enter your destinaton: "<<endl;
            getline(cin,destination);
            cout<<"-------------------------------------------------------------"<<endl;
            test.printoutshortestdistance(currentlocatoin, destination);
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<endl;
            cout << "======Travel Partner======" << endl;
            cout << "1. Find your perfection destination" << endl;
            cout<<  "2. Get attraciton information"<<endl;
            cout << "3. Calculate the fastest route" << endl;
            cout << "4. Print out fastest route" << endl;
            cout << "5. Find the route contains least state" << endl;
            cout << "6. Quit" << endl;
            getline(cin,choice);
        }
        if(choice=="5")
        {
            string currentlocatoin;
            string destination;
            cout<<"This function will provide you the route that contains least halfway states."<<endl;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            cout<<"Remember! Please enter the valid city listed before."<<endl;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            cout<<"Please enter your home address: "<<endl;
            getline(cin,currentlocatoin);
            cout<<"Please enter your destinaton: "<<endl;
            getline(cin,destination);
            cout<<"-------------------------------------------------------------"<<endl;
            test.printoutBFS(currentlocatoin, destination);
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<endl;
            cout << "======Travel Partner======" << endl;
            cout << "1. Find your perfection destination" << endl;
            cout<<  "2. Get attraciton information"<<endl;
            cout << "3. Calculate the fastest route" << endl;
            cout << "4. Print out fastest route" << endl;
            cout << "5. Find the route contains least state" << endl;
            cout << "6. Quit" << endl;
            getline(cin,choice);
        }
    }
    
    
    
    
}
