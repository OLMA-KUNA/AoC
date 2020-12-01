//code of advent 1-1
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char * argv[]){
    std::fstream inputFile("./inputFile.txt", std::ios_base::in);
    int a;
    std::vector<int> inputData;
    while(inputFile >> a){
        inputData.push_back(a);
    }

    for(int ii =0; ii<inputData.size()-2;ii++){
        for(int jj = ii+1; jj <inputData.size()-1;jj++){
            for(int kk = jj+1; kk <inputData.size();kk++){
            
                if(inputData[ii]+ inputData[jj] +inputData[kk] == 2020){
                    printf("Result: %d, %d und %d ergibt %d\n",inputData[ii], inputData[jj],inputData[kk], inputData[kk]*inputData[ii]*inputData[jj]);
                    return(inputData[ii]*inputData[jj]);
                }
            }
        }
    }
    printf("NO numbers found\n");
    return 0;
}
