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
  if(strcmp(argv[1], "-w") == 0){
    FILE *fptr;
    fptr = fopen(argv[2], "r");
    if(fptr == NULL){
      printf("Error opening file '%s' to read.\n", argv[3]);
      return -1;
    }
    char line_buffer[MAX_LENGTH];
    size_t word_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, fptr)){
      size_t index = 0;
      // char current_char = line_buffer[index];
      size_t space_count = 0;
      while(line_buffer[index] != '\0'){
        if(line_buffer[index] == ' '){
          space_count += 1;
        }
        index++;
      }
      word_count += space_count + 1;
      // char *token = strtok(line_buffer, " ");
      // word_count += 1;
      // while(token != NULL){
      //   token = strtok(NULL, " ");
      //   word_count += 1;
      // }
    }
    printf("word count: %zu\n", word_count);
  }
}
