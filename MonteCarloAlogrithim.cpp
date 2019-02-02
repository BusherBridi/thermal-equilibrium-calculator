#include <iostream>
#include <stdlib.h>
#include <array>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>
#include <numeric>


using namespace std;

int main () {
    const int GRID_WIDTH = 10;                  //Defines grid size, can be changed as needed 
    const int GRID_HEIGHT = 10;
    int grid[GRID_HEIGHT][GRID_WIDTH] = {       //makes grid, this will be the model of the body that we want to find temperatues for
    {150, 150, 150, 120, 100, 50, 45, 45, 45, 45},
    {150, 0, 0, 0, 0, 0, 0, 0, 0, 45},           //grid coords start from top left and increase as you move down and right
    {150, 0, 0, 0, 0, 0, 0, 0, 0, 40},
    {150, 0, 0, 0, 0, 0, 0, 0, 0, 40},           //Change edge values as needed
    {150, 0, 0, 0, 0, 0, 0, 0, 0, 35},
    {120, 0, 0, 0, 0, 0, 0, 0, 0, 50},
    {100, 0, 0, 0, 0, 0, 0, 0, 0, 50},
    {50, 0, 0, 0, 0, 0, 0, 0, 0, 45},
    {45, 0, 0, 0, 0, 0, 0, 0, 0, 35},
    {35, 35, 35, 35, 35, 35, 35,35,35,35}
};
srand(time(NULL));                              //seeds the random number generator
int xInit;
int yInit;
cout<<"Enter Y position of point to be calcuated:"; 
cin>> xInit;
cout <<"Enter x position of point to be calculated:"; 
cin>> yInit;
int x=xInit;                                    // starting 'x' position 
int y=yInit;                                    // starting 'y' position
vector<int> values;                             // vector that will store values of boundry points once reached
int iterations;                                 // number of iterations
cout <<"Enter number of iterations: ";
cin>>iterations;

auto numberOfValues = values.size();            // how many numbers in the vector (how many times has the program reached the boundry points)
while(numberOfValues != iterations) {
int randomPath = rand()%4;                      // get four random numbers to define to move left, right, up, or down


       switch (randomPath)
   {
       case 0:
       x++;
       cout <<"right"<<endl;
       break;
       case 1:
       x--;
       cout <<"left"<<endl;
       break;
       case 2:
       y++;
       cout <<"up"<<endl;
       break;
       case 3:
       y--;
       cout <<"down"<<endl;
       break;
       }
    cout<<x<<","<<y<<endl;
    
if(x ==0 || x == GRID_WIDTH -1 || y == 0 || y == GRID_WIDTH -1){    //when boundry coordinate is reached, put that value in the vector
 values.push_back(grid[y][x]);
 numberOfValues++;                          //increase the number of values in the vector by 1
  cout<<"boundry value reached!:"<<grid[y][x]<<endl;
 x = xInit;                                 // reset x position
 y = yInit;                                 //reset y position

}
  

}
cout<<"Walks finished, data collected:"<<numberOfValues<<endl;  
cout<<"Press any button to continue..."<<endl;
int placeHolder;
cin>>placeHolder;
double temperatureAtInitialPoint;                               
int sumOfValues = accumulate(values.begin(), values.end(), 0);  //performs average calculation
temperatureAtInitialPoint = sumOfValues/numberOfValues;
cout <<"Temperature approx at point "<<"("<<yInit<<","<<xInit<<")"<<" = "<<temperatureAtInitialPoint<<endl; //prints result

return 0;
}