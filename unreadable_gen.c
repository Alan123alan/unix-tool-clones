#include <stdio.h>


int main(){
  FILE *fptr;
  fptr = fopen("unreadable.txt", "w");
  for(int i = 0; i < 16385; i++){
    fputc('a', fptr);
  }
  fputc('x', fptr);
  fclose(fptr);
}
