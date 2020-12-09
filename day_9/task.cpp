//code of advent 9
#include <iostream>
#include <fstream>
#include <vector>

int main (int argc, char * argv[]){
    std::fstream input;

      std::fstream inputFile("./inputFile.txt", std::ios_base::in);
    int a;
    std::vector<int> inputData;
    while(inputFile >> a){
        inputData.push_back(a);
    }
    int pre =25;
    bool foundWeakness = false;
    bool foundNumbers =false;
    for(; pre<inputData.size();pre++){
        foundNumbers =false;
        for(int searchstart = pre-25; searchstart<pre-1;searchstart ++){
            for(int search =searchstart+1; search< pre; search++){
                if(inputData[search]+ inputData[searchstart]==inputData[pre]){
                    foundNumbers =true;
                    break;
                }
            }
            if(foundNumbers){
                break;
            }
        }
        if(!foundNumbers){
            foundWeakness =true;
            break;
        }
    }
    if(foundWeakness){
        std::cout << "Weaknessfound at "<< pre << "with number " <<inputData[pre] << std::endl;

    }
    else
    {
        std::cout << "no weaknessfound" << std::endl;
    }
    //PART2
    int inputA = inputData[pre];
    
    for(int counter =0;counter<inputData.size();counter++)
    {
        int sum = 0;
        int high=0;
        int low = INT32_MAX;
        for(int counterB =counter; sum < inputA and counterB< inputData.size();counterB ++){
            high<inputData[counterB]?high =inputData[counterB]:true;
            low>inputData[counterB]?low = inputData[counterB]:true;
            sum += inputData[counterB];
        }
        if (sum == inputA){
            std::cout << "We found the sum at " << counter << " highest: " << high << " lowest: " << low << " the solution is: " << low+high <<std::endl;
            break;
        }
    }
}
