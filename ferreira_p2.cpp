#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void keep_tertiary(int &x){
    if(x > 2){
        x = 0;
    }else if(x < 0){
        x = 2;
    }
}

void gateSetter(string inputConfig, int &x1, bool &x2, bool &x3, bool &x4){
    if(inputConfig[0] == 'L'){
        x1 = 0;

    }else if(inputConfig[0] == 'C'){
        x1 = 1;

    }else if(inputConfig[0] == 'R'){
        x1 = 2;

    }

    if(inputConfig[1] == 'L'){
        x2 = false;
    }else if(inputConfig[1] == 'R'){
        x2 = true;
    }

    if(inputConfig[2] == 'L'){
        x3 = false;
    }else if(inputConfig[2] == 'R'){
        x3 = true;
    }

    if(inputConfig[3] == 'L'){
        x4 = false;
    }else if(inputConfig[3] == 'R'){
        x4 = true;
    }
}

void machineStates(int x1, bool x2, bool x3, bool x4){
    if(x1 == 0){
        cout << "L";
    }else if(x1 == 1){
        cout << "C";
    }else if(x1 == 2){
        cout << "R";
    }
    
    if(!x2){
        cout << "L";
    }else{
        cout << "R";
    }

    if(!x3){
        cout << "L";
    }else{
        cout << "R";
    }

    if(!x4){
        cout << "L";
    }else{
        cout << "R";
    }
}

int main(int argc, char * argv[]){
    string inputConfigs = argv[1];
    string inputString = argv[2];
    int x1;
    bool x2, x3, x4;
    gateSetter(inputConfigs,x1,x2,x3,x4);

    char lastState;



    //All START FACING LEFT
    //ON 1 X1 GOES LEFT CENTER RIGHT AND OPPOSITE FOR 0

    
    for(int i = 0; i < inputString.size(); i++){
        machineStates(x1, x2, x3, x4);
        if(i != inputString.size()){
            cout << "->";
        }
        if(x1 == 0){
            
            //PROCESS INPUT
            //GATES BC
            if(!x2){
                //W
                lastState = 'B';
            }else if(x2){
                lastState = 'C';
                
            }
            x2 = !x2;

        }else if(x1 == 1){
            
            //PROCESS INPUT
            //GATES CD
            if(!x3){
                lastState = 'C';

            }else if(x3){
                //W
                lastState = 'D';

            }
            x3 = !x3;


        }else if(x1 == 2){
            //PROCESS INPUT
            //GATES DE
            if(!x4){
                
                //W
                lastState = 'D';
            }else if(x4){
                
                lastState = 'E';
            }
            x4 = !x4;

        }
        if(inputString[i] == '1'){
            x1++;
        }else if(inputString[i] == '0'){
            x1--;
        }
        // cout << input[i];
        // cout << x1;
        keep_tertiary(x1);
        
        

    }
    machineStates(x1,x2,x3,x4);
    
    cout << " " << lastState << endl;

    return 0;
}