//code of advent: day 12 task 2
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
    void rotate(int rotation)
    {
        int helpPos;
        rotation = (rotation +4)%4;
        if(rotation >= 2){
            xPos = -xPos;
            yPos = -yPos;
        }
        if(rotation%2)
        {
                helpPos =yPos;
                yPos = -xPos;
                xPos = helpPos;
        }
    }
};

class ship
{
public:
   ship()
   {
       speed.xPos =10;
       speed.yPos =1;
   }
    void command(wayPoint action)
    {
        char dir = action.command; 
        int way= action.way;
        switch(dir){
            case('N'):
             case('S'):
             case('W'):
             case('E'):
        
                changeSpeed(dir, way);
                break;
            
             case('F'):
                move(way);
                break;
            
            case('R'):
                speed.rotate((way/90)%4);
                break; 

            case('L'):
                speed.rotate(-((way/90)%4));
                break; 

            default:
                std::cout << "command: direction is wrong: "<< dir << std::endl;
        }
    }
    position getPos(){
        return pos;
    }
private:
    void move(int times)
    {
        pos.xPos += speed.xPos*times;
        pos.yPos += speed.yPos*times;
    }

    void changeSpeed(char dir, int way){
        switch(dir)
        {
            case('N'):
                speed.yPos += way;
                break;
            
             case('S'):
                speed.yPos -= way;
                break;
            
             case('W'):
                speed.xPos -= way;
                break;
           
             case('E'):
                speed.xPos += way;
                break;
            
            default:
                std::cout << "speed: direction is wrong: "<< dir << std::endl;
            
        }
    }
    int heading;        
    std::string oswn = "ESWN";
    position pos;
    position speed;

};


int main (int argc, char * argv[]){
    std::fstream input;

    input.open("./inputFile.txt", std::ios::in);
    
    std::vector<wayPoint> inputData;
    
    std::string a;
    ship ourShip;
    while(getline(input,a)){
        wayPoint action = wayPoint(a[0], std::stoi( a.substr(1)));
        inputData.push_back(action);
        ourShip.command(action);
    }
  
    std::cout << "x :" <<ourShip.getPos().xPos <<" y :" <<ourShip.getPos().yPos <<" result :" <<abs(ourShip.getPos().yPos)+ abs(ourShip.getPos().xPos) << std::endl ;
    return 0;
}
