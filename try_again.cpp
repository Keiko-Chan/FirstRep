#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
#include<assert.h>

int count_of_strings( char *massive);

int compare(const void * x1, const void * x2);

main()
  {
  FILE* file;
  size_t number = 0;
  char name[80];
  int num_strings = 0;
  int i = 0;

  printf("Enter the file name: ");
  scanf("%s", name);

  file = fopen( name, "r" );
  fseek(file, 0, SEEK_END);
  long lsize = ftell(file);
  rewind (file);

  char *all_strings = (char*)calloc(lsize,sizeof(char));
  number = fread(all_strings, 1, lsize, file);

  num_strings = count_of_strings( all_strings );

  char* *x;
  int j = 1;

  x = (char**)calloc(num_strings,sizeof(char*));

  x[0] = all_strings;

  while( i < lsize )
    {
    if( all_strings[i] == '\n' && i != lsize - 1 )
      {
      x[j] = all_strings + i + 1;
       j++;
      }
    i++;
    }

  qsort(x, num_strings, sizeof(char*), compare);

  fclose (file);

  FILE* file_write = fopen("newfile1.txt", "w");

  printf ("%p\n", file_write);

  for(int o = 0; o < num_strings; o++)
    {
    i = 0;

    while(*(x[o] + i) != '\n')
      {
      putchar(*(x[o] + i));

      int check = fputc((int) (*(x[o] + i)), file_write);

      i++;
      }
      fputc ((int) '\n', file_write);
      printf("\n");
    }

    fclose (file_write);
  }

//-------------------------------------------------------------------------------------------------------------------------------------

int compare(const void * x1, const void * x2)
  {
  char *y1, *y2;

  y1 = *((char**)x1);
  y2 = *((char**)x2);

  while( *y1 != '\n' && *y2 != '\n' )
    {
    if(*y1 < 'A' || *y1 > 'z' || (*y1 > 'Z' && *y1 < 'a'))
      {
      y1 = y1 + 1;
      continue;
      }
    if(*y2 < 'A' || *y2 > 'z' || (*y2 > 'Z' && *y2 < 'a'))
      {
      y2 = y2 + 1;
      continue;
      }
    if(*y1 == *y2)
      {
      y1 = y1 + 1;
      y2 = y2 + 1;
      continue;
      }

    if((*y1 < 'z' && *y1 > 'a') && (*y2 < 'Z' && *y2 > 'A'))
      return (-*y2 - 32 + *y1);

    if((*y1 < 'Z' && *y1 > 'A') && (*y2 < 'z' && *y2 > 'a'))
      return (*y1 + 32 - *y2);

    return (*y1 - *y2);
    }
    if( *y1 == '\n' && *y2 == '\n')
      return 0;

    if( *y1 != '\n' && *y2 == '\n')
      return 1;

    if( *y1 == '\n' && *y2 != '\n')
      return -1;

    return 0;
  }

int count_of_strings( char *massive)
  {
  int i = 0;
  int counter = 0;

  while(massive[i] != '\0')
    {
    if( massive[i] == '\n' ) counter++;
    i++;
    }

  if( massive[i-1] != '\n' ) counter++;

  return counter;
  }
