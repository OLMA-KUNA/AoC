//code of advent 5-1
#include <iostream>
#include <fstream>
#include <vector>


int main (int argc, char * argv[]){
    std::fstream input;
    input.open("./inputFile.txt", std::ios::in);
    std::string a;
    int highestSeatNumber =0;
    bool seatTaken[1024] = {0};
    while(getline(input,a))
    {
        int actualnumber =0;
        for(int count=0; count<a.length();count++)
        {
            actualnumber *= 2;
            if(a[count] == 'B' or a[count]== 'R'){
                actualnumber++;
            }
        }
        seatTaken[actualnumber]=true;
    }
    bool firstplacefound = false;
    for(int counter =0;counter < 1024;counter++){
        if(not(seatTaken[counter]) and firstplacefound)
        {
             std::cout <<seatTaken[counter]<< "a free place at "<< counter <<std::endl;
             return 0;
        }
        else if(seatTaken[counter])
        {
            firstplacefound =true;
        }
    }
}