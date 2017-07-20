#include <stdlib.h>
#include <stdio.h>
#include <err.h>

#include "1-10.h"

unsigned long mult3And5(){
  unsigned long res = 0;
  for(size_t i = 0;i < 1000;i++){
    if(i % 3 == 0 || i % 5 == 0)
      res += i;
  }
  return res;
}

unsigned long fibo(){
  unsigned long res = 0;
  size_t a = 1;
  size_t b = 1;
  while(a <= 4000000){
    a += b;
    b = a - b;
    if(a % 2 == 0)
      res += a;
  }
  return res;
}

unsigned long primeFact(){
  unsigned long prime = 600851475143;
  unsigned long res = 0;
  for(unsigned long i = 2; i <= prime/2; i++){
    if(prime % i == 0)
      res = i;
  }
  return res;
}
