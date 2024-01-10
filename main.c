#include<stdio.h>
#include<string.h>
// #include<ctype.h>
#include<wctype.h>
#include<wchar.h>
// #include<unistd.h>

#define MAX_LENGTH 2048

size_t utf8len(const char *s);
size_t get_byte_count(char *filename);
size_t get_line_count(char *filename);
size_t get_word_count(char *filename);
size_t get_char_count(char *filename);

int main(int argc, char *argv[]){
  if(argc > 1){
    if(strcmp(argv[1], "-c") == 0){
      printf("%zu %s\n", get_byte_count(argv[2]), argv[2]);
    }else if(strcmp(argv[1], "-l") == 0){
    printf("%zu %s\n", get_line_count(argv[2]), argv[2]);
    }else if(strcmp(argv[1], "-w") == 0){
    printf("%zu %s\n", get_word_count(argv[2]), argv[2]);
    }else if(strcmp(argv[1], "-m") == 0){
      printf("%zu %s\n", get_char_count(argv[2]), argv[2]);
    }else{
      printf("%zu %zu %zu %s\n", get_line_count(argv[1]), get_word_count(argv[1]), get_byte_count(argv[1]), argv[1]);
    }
  }else{
    char line_buffer[MAX_LENGTH];
    size_t char_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, stdin)){
      char_count += strlen(line_buffer);
    }
    printf("%zu\n", char_count);
  }
}

size_t get_byte_count(char *filename){
    FILE *fptr;
    fptr = fopen(filename, "r"); 
    if(fptr == NULL){
      printf("Error opening file '%s' to read.\n", filename);
      return 1;
    }
    char line_buffer[MAX_LENGTH];
    size_t char_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, fptr)){
      char_count += strlen(line_buffer);
    }
    return char_count;
}

size_t get_line_count(char *filename){
    FILE *fptr;
    fptr = fopen(filename, "r");
    if(fptr == NULL){
      printf("Error opening file '%s' to read.\n", filename);
      return 1;
    }
    char line_buffer[MAX_LENGTH];
    size_t line_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, fptr)){
      line_count += 1;
    }
    return line_count;
}

size_t get_word_count(char *filename){
    FILE *fptr;
    fptr = fopen(filename, "r");
    if(fptr == NULL){
      printf("Error opening file '%s' to read.\n", filename);
      return 1;
    }
    wchar_t line_buffer[MAX_LENGTH];
    size_t word_count = 0;
    while(fgetws(line_buffer, MAX_LENGTH, fptr)){
      for(int i = 0; line_buffer[i] != '\0'; i++){
        if(!iswspace(line_buffer[i]) && iswspace(line_buffer[i+1])){
            word_count += 1;
        }
      }
    }
    fclose(fptr);
    return word_count;
}

size_t get_char_count(char *filename){
    FILE *fptr;
    fptr = fopen(filename, "r"); 
    if(fptr == NULL){
      printf("Error opening file '%s' to read.\n", filename);
      return 1;
    }
    char line_buffer[MAX_LENGTH];
    size_t char_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, fptr)){
      char_count += utf8len(line_buffer);
    }
    fclose(fptr);
    return char_count;
}

size_t utf8len(const char *s)
{
  size_t len = 0;
  while(*s)
    len += (*(s++)&0xC0)!=0x80;
  return len;
}
