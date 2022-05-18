#include<stdio.h>

int getBit(int num, int pos){
    int temp = 1 << (pos);
    num = num & temp;

    return  num >> pos;
}

int setBit(int num, int pos){
    int temp = 1<<(pos);
    return num = num | temp;
}

int clearBit(int num, int pos){
    int temp = 1<<pos;
    temp = ~ temp;
    return num = num&temp;
}

int toggleBit(int num, int pos){
     int temp = 1<<pos;
    return num = num^temp;
}

int clearRange(int num, int start, int end){
    for(start;start<=end; start++)
    {
        num=clearBit(num,start);
    }
    return num;
    
}

int setRange(int num, int start, int end){
    for(start;start<=end; start++)
    {
        num=setBit(num,start);
    }
    return num;
}

int getSetCnt(int num){
    int flag=0;
    for(int i=0;i<=10; i++)
    {
        if(getBit(num,i)==1)
        {
            flag=flag+1;
        }
        
    }
    return flag;
}

int getSetCnt_2(int num)
{
    int count=0;
        while(num)
    {
        if(num&1)count++;
        num=num>>1;
    }
    return count;
}

void printBin(int num){
    int setBitFound = -1;
    int bitNum = sizeof(num) * 8 - 1 - 1;

    for(int i = bitNum; i>=0; i--){
        int curr_bit = getBit(num, i);
        if(setBitFound == -1 && curr_bit == 0) continue;
        if(setBitFound == -1 && curr_bit == 1) setBitFound = 1;
        printf("%d", curr_bit);
    }
}

int main(){
    int num  = 7; 

    // 1010
    // 4321
    ;
    // printBin(num);
   
    printf("%d", getSetCnt(num));
        // printf("%d", getBit(num, 1));

    return 0;
}