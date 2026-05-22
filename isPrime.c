#include <stdio.h>
#include <math.h>

int isPrime(int x) {
    int ret = 1;
    int i;
    if( x==1 || (x%2==0 && x!=2) ) {
        ret = 0; //不是素数
    }
    for(i=3; i<sqrt(x); i+=2) {
        if(x%i == 0) {
            ret = 0; //不是素数
            break;
        }
    }
    return ret; //是素数
}

int main(){
    const int maxNumber = 25;
    int isPrime[maxNumber];
    int i;
    int x;

    //初始化数组
    for(i=0; i<maxNumber; i++) {
        isPrime[i] = 1; //默认所有数都是素数
    }
    //标记非素数
    for(x=2; x<maxNumber; x++) {
        if(isPrime[x]) {
            for(i=2; i*x<maxNumber; i++) {
                isPrime[i*x] = 0; //标记i*x不是素数
            }
        }
    }
    //输出素数
    for(i=2; i<maxNumber; i++) {
        if(isPrime[i] == 1) {
            printf("%d\t ", i);
        }      
    }
    printf("\n");
    return 0;   
}