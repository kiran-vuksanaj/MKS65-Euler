#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long collatzStep(long n);
int collatzLength(int n);
int euler14();

short isPrime(int n);
int euler7();

int main(){
  printf("euler problem 14: %d\n",euler14());
  printf("euler problem 7: %d\n",euler7());
}

long collatzStep(long n){
  if(n%2==0) return n/2;
  else return (3*n)+1;
}

int collatzLength(int n){
  // NOT VALID FOR 1
  long stepped = n;
  int c = 1;
  while(stepped != 1){
    // printf("\n%d ",stepped);
    stepped = collatzStep(stepped);
    // printf("%d\n",stepped)
    c++;
  }
  return c;
}

int euler14(){
  int maxStarter = 2;
  int maxLength = 2;
  int len = 2; // temp
  int c = 2;
  while(c<1000000){
    len = collatzLength(c);
    if(len > maxLength){
      maxLength = len;
      maxStarter = c;
    }
    c++;
  }
  return maxStarter;
}
short isPrime(int n){
  int i;
  for(i=2;i<=(n/i);i++){ //only check lower half of factors
    if(n%i == 0){
      return 0;
    }
  }
  return 1;
}
int euler7(){
  int i;
  int primeCounter = 0;
  int out;
  for(i=2;primeCounter<10001;i++){
    if(isPrime(i)){
      primeCounter++;
      out = i;
      // printf("%d is prime #%d\n",i,primeCounter);
    }
  }
  return out;
}
