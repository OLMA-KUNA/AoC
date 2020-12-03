//code of advent 3-1

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


int main (int argc, char * argv[]){
    std::fstream input;
    input.open("./inputFile.txt", std::ios::in);
    std::string a;
    std::vector<std::string> inputData;
    while(getline(input,a)){
        inputData.push_back(a);
    }

    class coordinates{
        public:
        int x;
        int y;
        coordinates(int xx,int yy){
            x = xx;
            y = yy;
        }
    };

    std::vector<coordinates>slops;
    slops.push_back(coordinates(1,1));
    slops.push_back(coordinates(3,1));
    slops.push_back(coordinates(5,1));
    slops.push_back(coordinates(7,1));
    slops.push_back(coordinates(1,2));

    int64_t multiplied =1;
    for(int count =0;count <slops.size(); count++)
    {
        int treecounter = 0, linecount =0;
        for(int ii =0, jj =0; ii<int(inputData.size()); jj=(jj+slops[count].x)%(int(inputData[ii].length())), ii=ii+slops[count].y)
        {

            if(inputData[ii][jj]=='#'){
                treecounter++;
            }
            linecount++;
        }
        std::cout <<"there were "<< treecounter << " trees I hit and I came "<< linecount << " down" <<std::endl;
        multiplied = multiplied * treecounter; 
    }
  std::cout<< "multiplier: "<< multiplied << std::endl;
}