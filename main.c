#include<stdio.h>

int main(int argc, char *argv[]){
  for(int i=0; i < argc; i++){
    printf("argument count: %d.\nargument values: %s.\n", argc, argv[i]);
  }
}
