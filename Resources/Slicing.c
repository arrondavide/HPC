#include <stdio.h>
#include <stdlib.h>

//code to slice any problem

//compCount = 100
//threadCount = 3;

//thread1 = 34
//thread2 = 33
//thread3 = 33

//thread1 = 0 - 33
//thread2 = 34 - 66
//thread3 = 67 - 99

void main(int argc, char ** argv){

    long long compCount = atoll(argv[1]);
    int threadCount = atoi(argv[2]);
    
    int sliceList[threadCount];
    int remainder = compCount % threadCount;
    
    //fill standard slices (without remainder)
    for (int i = 0; i < threadCount; i++){
        sliceList[i] = compCount / threadCount;
    }
    
    //take remainder and add extra computation
    for (int j = 0; j < remainder; j++){
        sliceList[j] = sliceList[j] + 1;
    }
    
    int startList[threadCount];
    int endList[threadCount];
    
    for (int k = 0; k < threadCount; k++){
        if(k == 0){
            startList[k] = 0;
            endList[k] = startList[k] + sliceList[k] - 1;
        }else{
            startList[k] = endList[k-1] + 1;
            endList[k] = startList[k] + sliceList[k] - 1;
        }
    }
    
    for (int g = 0; g < threadCount; g++){
        printf("start = %d  end = %d\n", startList[g], endList[g]);
    }
    
    
    
    
}
