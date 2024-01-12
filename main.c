#include<stdio.h>
#include<string.h>
// #include<ctype.h>
#include<wctype.h>
#include<wchar.h>
// #include<unistd.h>

#define MAX_LENGTH 2048

size_t utf8len(const char *s);
size_t get_line_count(FILE *stream);
size_t get_word_count(FILE *stream);
size_t get_char_count(FILE *stream);
size_t get_byte_count(FILE *stream);

int main(int argc, char *argv[]){
  //setting up variables to keep track of options set **DONE**
  //-m and -c options overwrite each other **DONE**
  //if file is not found or file pointer null fgets to stdin as stream **DONE**
  //fix issue by using only one file pointer
  char *line_count_option = "\0";
  char *word_count_option = "\0";
  char *char_or_byte_count_option = "\0";
  char *filename = "\0";

  for(int i = 0; i < argc; i++){
    printf("%d : %s\n", i, argv[i]);
    if(strcmp(argv[i], "-l") == 0){
      line_count_option = "-l";
    }else if(strcmp(argv[i], "-c") == 0){
      char_or_byte_count_option = "-c";
    }else if(strcmp(argv[i], "-m") == 0){
      char_or_byte_count_option = "-m";
    }else if(strcmp(argv[i], "-w") == 0){
      word_count_option = "-w";
    }
  }

  printf("line count option %s, word count option %s, char or byte count option %s\n", line_count_option, word_count_option, char_or_byte_count_option);

  filename = argv[argc-1];

  FILE *fptr;
  fptr = fopen(filename, "r"); 
  if(fptr == NULL){
    if(strcmp(line_count_option, "-l") == 0){
      printf("\t%zu", get_line_count(stdin));
    }
    if(strcmp(char_or_byte_count_option, "-c") == 0){
      printf("\t%zu", get_char_count(stdin));
    }
    if(strcmp(char_or_byte_count_option, "-m") == 0){
      printf("\t%zu", get_byte_count(stdin));
    }
    if(strcmp(word_count_option, "-w") == 0){
      printf("\t%zu", get_word_count(stdin));
    }
    printf("\n");
  }else{
    if(strcmp(line_count_option, "-l") == 0){
      printf("\t%zu", get_line_count(fptr));
    }
    if(strcmp(word_count_option, "-w") == 0){
      printf("\t%zu", get_word_count(fptr));
    }
    if(strcmp(char_or_byte_count_option, "-c") == 0){
      printf("\t%zu", get_char_count(fptr));
    }
    if(strcmp(char_or_byte_count_option, "-m") == 0){
      printf("\t%zu", get_byte_count(fptr));
    }
    printf("\t%s\n", filename);
  }
}

size_t get_byte_count(FILE *stream){
    char line_buffer[MAX_LENGTH];
    size_t char_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, stream)){
      char_count += strlen(line_buffer);
    }
    return char_count;
}

size_t get_line_count(FILE *stream){
    char line_buffer[MAX_LENGTH];
    size_t line_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, stream)){
      line_count += 1;
    }
    return line_count;
}

size_t get_word_count(FILE *stream){
    wchar_t line_buffer[MAX_LENGTH];
    size_t word_count = 0;
    while(fgetws(line_buffer, MAX_LENGTH, stream)){
      for(int i = 0; line_buffer[i] != '\0'; i++){
        if(!iswspace(line_buffer[i]) && iswspace(line_buffer[i+1])){
            word_count += 1;
        }
      }
    }
    return word_count;
}

size_t get_char_count(FILE *stream){
    char line_buffer[MAX_LENGTH];
    size_t char_count = 0;
    while(fgets(line_buffer, MAX_LENGTH, stream)){
      char_count += utf8len(line_buffer);
    }
    return char_count;
}

size_t utf8len(const char *s)
{
  size_t len = 0;
  while(*s)
    len += (*(s++)&0xC0)!=0x80;
  return len;
}
