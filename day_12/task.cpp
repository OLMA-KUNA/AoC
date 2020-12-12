//code of advent: day 12 task 1
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class wayPoint
{
    public:
    char command;
    int way;
    wayPoint(char commandIn, int wayIn){
        command = commandIn;
        way = wayIn;
    }
};

class position
{
    public:
    position(){};
    char dir = 'E';
    int64_t xPos =0;
    int64_t yPos =0;
};

class ship
{
public:
   
    void command(wayPoint action)
    {
        char dir = action.command; 
        int way= action.way;
        switch(dir){
            case('N'):
             case('S'):
             case('W'):
             case('E'):
             
                move(dir, way);
                break;
            
             case('F'):
                move(pos.dir, way);
                break;
            
            case('R'):
                heading = oswn.find(pos.dir);
                heading = (heading+ way/90)%4;
                pos.dir = oswn[heading];
                break; 
            case('L'):
                heading = oswn.find(pos.dir)+8;
                heading = (heading- way/90)%4;
                pos.dir = oswn[heading];
                break; 
            default:
                std::cout << "command: direction is wrong: "<< dir << std::endl;
            
        }
    }
    position getPos(){
        return pos;
    }
private:
    void move(char dir, int way){
        switch(dir)
        {
            case('N'):
                pos.yPos += way;
                break;
            
             case('S'):
                pos.yPos -= way;
                break;
            
             case('W'):
                pos.xPos -= way;
                break;
           
             case('E'):
                pos.xPos += way;
                break;
            
            default:
                std::cout << "move: direction is wrong: "<< dir << std::endl;
            
        }
        std::cout << "x :" <<pos.xPos <<" y :" <<pos.yPos << std::endl ;
    
    }
        int heading;
        std::string oswn = "ESWN";
        position pos;

};


int main (int argc, char * argv[]){
    std::fstream input;

    input.open("./inputFile.txt", std::ios::in);
    
    std::vector<wayPoint> inputData;
    
    std::string a;
    ship ourShip;
    while(getline(input,a)){
       //  std::cout << a.substr(1) << std::endl;
        wayPoint action = wayPoint(a[0], std::stoi( a.substr(1)));
        inputData.push_back(action);
        ourShip.command(action);
    }
  
   

    std::cout << "x :" <<ourShip.getPos().xPos <<" y :" <<ourShip.getPos().yPos <<" result :" <<abs(ourShip.getPos().yPos)+ abs(ourShip.getPos().xPos) << std::endl ;
    return 0;
}
