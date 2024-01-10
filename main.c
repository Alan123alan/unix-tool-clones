#include<stdio.h>
#include<string.h>
// #include<ctype.h>
#include<wctype.h>
#include<wchar.h>
#include<unistd.h>

#define MAX_LENGTH 2048

size_t utf8len(const char *s);

int main(int argc, char *argv[]){
  if(strcmp(argv[1], "-c") == 0){
    FILE *fptr;
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
    wchar_t line_buffer[MAX_LENGTH];
    size_t word_count = 0;
    while(fgetws(line_buffer, MAX_LENGTH, fptr)){
      // wchar_t *args[] = {"wc",line_buffer,NULL};
      // execv("/usr/bin/wc",args);
      for(int i = 0; line_buffer[i] != '\0'; i++){
        if(!iswspace(line_buffer[i]) && iswspace(line_buffer[i+1])){
            word_count += 1;
        }
      }
    }
    printf("%zu\n", word_count);
  }
  if(strcmp(argv[1], "-m") == 0){
    FILE *fptr;
    fptr = fopen(argv[2],"r"); 
    if(fptr == NULL){
      printf("Error opening file '%s' to read.\n", argv[2]);
      return -1;
    }
    char line_buffer[MAX_LENGTH];
    size_t char_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, fptr)){
      char_count += utf8len(line_buffer);
      // char_count += wcslen(line_buffer);
    }
	  printf("byte count: %zu\n", char_count);
  }
}

size_t utf8len(const char *s)
{
  size_t len = 0;
  while(*s)
    len += (*(s++)&0xC0)!=0x80;
  return len;
}
