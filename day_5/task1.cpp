//code of advent 5-1
#include <iostream>
#include <fstream>
#include <vector>


int main (int argc, char * argv[]){
    std::fstream input;
    input.open("./inputFile.txt", std::ios::in);
    std::string a;
    int highestSeatNumber =0;
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
        (actualnumber>highestSeatNumber)?highestSeatNumber = actualnumber:true;
    }
    std::cout << "Highest Seat ID = " << highestSeatNumber << std::endl;
}