//code of advent: day 9
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <

int freeSpaces(std::vector<std::string> * room, int x, int y){
    int startY = ((y > 0)?y-1:0);
    int endY = ((y < room->size()-1)?y+1: room->size()-1);

    int seat =0;

    for(int yy= startY;yy <= endY;yy++){

        int startX = ((x > 0)?x-1:0) ;
        int endX = ((x < room->at(y).length()-1)?x+1:room->at(y).length()-1);

        for(int xx= startX; xx <= endX;xx++){
            if (room->at(yy).at(xx) == '#' and !(yy == y and xx == x))
            {
                seat++;
            }
        }
    }
    return seat;
}

int main (int argc, char * argv[]){
    std::fstream input;
    input.open("./inputFile.txt", std::ios::in);
    std::vector<std::string> inputData;
    
    std::string a;
    while(getline(input,a)){
        inputData.push_back(a);
    }

    bool is_settled = false;
    int counter =0;
    while(!is_settled and counter <200){
        counter++;
      
        std::vector<std::string> inputDataTwo;
        is_settled = true;
        for(int yy= 0;yy < inputData.size();yy++)
        {
            inputDataTwo.push_back("");
            for(int xx= 0;xx < inputData[yy].length();xx++)
            {
                if (inputData[yy][xx] == '.')
                {
                    inputDataTwo[yy].append(1,'.');
                }
                else if (freeSpaces(&inputData, xx,yy)>=4 and inputData[yy][xx] != 'L' )
                { 
                    inputDataTwo[yy].append(1,'L');
                    is_settled = false;
                }
                else if(freeSpaces(&inputData, xx,yy)==0 and inputData[yy][xx] != '#' )
                {
                    inputDataTwo[yy].append(1,'#');
                    is_settled = false;
                } 
                else
                {
                    inputDataTwo[yy].append(1,inputData[yy][xx]);
                } 
            } 
             std::cout << inputData[yy]<< std::endl;
        }
        inputData.clear();
        inputData = inputDataTwo;
        
        std::cout << counter<< std::endl;
    }

    int counterTwo = 0;
      for(int yy= 0;yy < inputData.size();yy++){
             std::cout << inputData[yy] << std::endl;
         }
           for(int yy= 0;yy < inputData.size();yy++)
        {
            for(int xx= 0;xx < inputData[yy].length();xx++)
            {
                if(inputData[yy][xx] == '#')
                {
                    counterTwo++;
                }
            }
        }

     std::cout << counterTwo << std::endl;
}
