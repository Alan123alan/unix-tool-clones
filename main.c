#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 2048

int main(int argc, char *argv[]){
  FILE *fptr;
  if(strcmp(argv[1], "-c") == 0){
    fptr = fopen(argv[2],"r"); 
    if(fptr == NULL){
      printf("Error opening file '%s' to read.\n", argv[2]);
      return -1;
    }
    char line_buffer[MAX_LENGTH];
    size_t char_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, fptr)){
      char_count += strlen(line_buffer);
    }
	  printf("byte count: %zu\n", char_count);
  }
  if(strcmp(argv[1], "-l") == 0){
    FILE *fptr;
    fptr = fopen(argv[2], "r");
    if(fptr == NULL){
      printf("Error opening file '%s' to read.\n", argv[2]);
      return -1;
    }
    char line_buffer[MAX_LENGTH];
    size_t line_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, fptr)){
      line_count += 1;
    }
    printf("line count: %zu\n", line_count);
  }
}
