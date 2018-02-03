#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <math.h>

#include "1-10.h"
#include "list.c"


unsigned long pow2(unsigned long n){
  return n*n;
}

unsigned long int_sqrt(unsigned long n){
  unsigned long res = 0;
  unsigned long i = 1 << 14;

  while(i > n) i >>= 2;
  while(i != 0){
    if(n >= res + i){
      n -= res + i;
      res = (res >> 1) + i;
    }
    else
      res >>= 1;
    i >>= 2;
  }
  return res;
}

unsigned long squareSum(){

  unsigned long sum = 0;
  unsigned long square = 0;

  for(unsigned long i = 0; i <= 100;i++){
    sum += i;
    square += pow2(i);
  }

  return pow2(sum) - square;
}


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

unsigned long _lowerMult(unsigned long res){
    unsigned long i = 1;
    int boo = 0;
    while(boo == 0 && i < 20){
      if(res % i == 0)
        i++;
      else{
        boo = 1;
        res = 0;
      }
    }
    return res;
  }

unsigned long lowerMult(){
    unsigned long cpt = 1;
    unsigned long res = 1;
    unsigned long inter;
    while( cpt < 1000000000){
      inter = _lowerMult(cpt);
      if( inter != 0){
        if(res == 1)  res = inter;
        if(res > inter) res = inter;
      }
      cpt++;
    }
    return res;
}

int isPrime(unsigned long n){
  if(n <= 1)  return 0;
  if(n % 2 == 0 && n > 2) return 0;
  for(unsigned long i = 3;i < n / 2; i+= 2){
    if(n % i == 0)  return 0;
  }
  return 1;
}

unsigned long primeFact(){
  unsigned long prime = 600851475143; 
  unsigned long res = 0;
  for(unsigned long i = 3; i <= 7775147 ; i += 2){
    if(prime % i == 0 && isPrime(i)){
      printf("%ld\n",i);
      res = i;
    }
    printf("%ld, %ld\n",i,res);
  }
  return res;
}

unsigned long prime10001(){
  
  unsigned long i = 0;
  unsigned long cpt = 0;
  while(i < 10001){
    if (isPrime(cpt)) {
      printf("%ld\n",cpt);
      i++;
    }
    cpt++;
  }
  return cpt - 1;
}


int isPalin(unsigned long n){
  unsigned long backup = n;
  unsigned long inter;
  unsigned long reverse = 0;
  while(backup > 0){
    inter = backup%10;
    reverse = reverse*10 + inter;
    backup /= 10;
  }

  if(n == reverse)  return 1;
  else return 0;
}

unsigned long palin(){
  
  unsigned long res = 0;
  for(unsigned long i = 100;i < 999;i++){
    for(unsigned long j = 100;j < 999;j++){
      if(isPalin(i * j) && res < i * j) res = i * j; 
    }
  }
  return res;  
}

unsigned long isSquare(unsigned long n){
  
  for(unsigned long i = 1;i < n;i++){
    if(i*i == n)  {
      return 1;
    }
  }
  return 0;
}

void print_list(struct list *list){

  int line = 1;
  printf("[");
  if(list->next){
    goto pastfst;
    while(list->next){
      line += printf(";");
      if(line > 72){
        printf("\n");
        line = 1;
      }
      pastfst:
      line += printf(" %d", list->next->data);
      list = list->next;
    }
  }
  printf(" ]\n");
}


struct list list_square(){
  struct list res;
  list_init(&res);
  struct list t[30];
  unsigned long i = 1;
  unsigned long j = 0;
  while(i < 1000 && j < 200){ 
    if(isSquare(i)) {
      t[j].data = i;
      t[j].next = NULL;
      list_push_front(&res,&t[j]);
      j++;
    }
    i++;
  }
  print_list(&res);
  return res;
}

unsigned long pythagor(){


  return 0;
}

unsigned long firstSum(){
  unsigned long res = 0;
  for(unsigned long i = 0;i < 2000000;i++){
    if(isPrime(i))  res += i;
    printf("%ld,%ld\n",i,res);
  }
  return res;
}

unsigned long triforce(){
  unsigned long cpt = 0;
  unsigned long j = 1;
  while(cpt < 500){
    
    for(unsigned long i = 500; i < 1000000;i++){
      while(j < i){
        if(i % j == 0)  cpt++;
        printf("%ld,%ld,%ld\n",i,j,cpt);
        j++;
      }
      j = 1;
    }
    if(cpt < 500){
      j = 1;
      cpt = 0;
    }
  }
  return j;
}

unsigned long powerSum(){
  unsigned long n = 2;
  unsigned long cpt = 0;
  while(cpt < 1000){
    printf("%ld\n",n);
    n = n*2;
    cpt++;
  }
  printf("%ld\n",n);
  unsigned long res = 0;
  while(n / 10 > 0){
    res += n % 10;
    n /= 10;
  }
  return res;
}
              
               
                















 
  

