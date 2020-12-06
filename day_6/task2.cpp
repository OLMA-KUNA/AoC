//code of advent 6-2
#include <iostream>
#include <fstream>

int main (int argc, char * argv[]){
    std::fstream input;
    input.open("./inputFile.txt", std::ios::in);
    std::string lineString;
    std::string questionsInGroup;
    int combinedNumberOfQuestions =0; 
    std::string leftInGroup; //helper var for cache questionsInGroup
    bool newGroup =true;  //start a new group
    while(getline(input,lineString))
    {
        if(!lineString.empty())
        {
            if(newGroup)
            {
                questionsInGroup=lineString;
                newGroup = false;
            }
            else
            {
                for(int count=0; count < questionsInGroup.length();count++)
                {                    
                    if(lineString.find(questionsInGroup[count]) != -1)
                    {
                        leftInGroup += questionsInGroup[count];
                    }                    
                }
                questionsInGroup = leftInGroup;
                leftInGroup.clear();
            } 
        }  
        else
        {
            combinedNumberOfQuestions += questionsInGroup.length();
            questionsInGroup.clear();
            newGroup = true;
        }
    }
     combinedNumberOfQuestions += questionsInGroup.length();
             std::cout << questionsInGroup << std::endl;
             questionsInGroup.clear();
    std::cout << "Number of questions everyone answered in a group true = " << combinedNumberOfQuestions << std::endl;
}