//code of advent 3-1

#include <iostream>
#include <fstream>
#include <vector>


int main (int argc, char * argv[]){
    std::fstream input;
    input.open("./inputFile.txt", std::ios::in);
    std::string a;
    std::vector<std::string> inputData;
    while(getline(input,a)){
        inputData.push_back(a);
    }
    int treecounter = 0, linecount =0;
    for(int ii =0, jj =0; ii<int(inputData.size()); jj=(jj+3)%(int(inputData[ii].length())), ii++)
    {

        if(inputData[ii][jj]=='#'){
            treecounter++;
            inputData[ii][jj] ='X';
        }else{
            inputData[ii][jj] ='o';
        }
        std::cout <<inputData[ii] << std::endl;
        linecount++;
    }


    std::cout <<"there were "<< treecounter << " trees I hit and I came "<< linecount << " down" <<std::endl;


}