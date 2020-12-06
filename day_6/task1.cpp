//code of advent 6-1
#include <iostream>
#include <fstream>

int main (int argc, char * argv[]){
    std::fstream input;
    input.open("./inputFile.txt", std::ios::in);
    std::string lineString;
    std::string questionsInGroup;
    int combinedNumberOfQuestions =0;
    while(getline(input,lineString))
    {
        if(!lineString.empty()){
            for(int count=0; count < lineString.length();count++)
                {   
                    if((questionsInGroup.find(lineString[count])) == -1)
                    {
                        questionsInGroup += lineString[count];
                    }
                }
            }
        else
        {
            combinedNumberOfQuestions += questionsInGroup.length();
            //std::cout << questionsInGroup << std::endl;
            questionsInGroup.clear();
        }
        
    }
     combinedNumberOfQuestions += questionsInGroup.length();
             std::cout << questionsInGroup << std::endl;
             questionsInGroup.clear();
    std::cout << "Number of questions answered true in a group in all groups: " << combinedNumberOfQuestions << std::endl;
}