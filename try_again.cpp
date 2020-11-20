#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>

struct str
{
  int l;
  char *pointer;
};

int count_of_strings( char *massive);

int compare(const void * x1, const void * x2);

char* filework(char* name, long* lsize, size_t* number);

struct str* pointer_massive(int num, int lsize, char* all_strings);

void write_in_file(struct str* x, int num_strings);

int main()
{
  size_t number = 0;
  char name[80];
  int num_strings = 0;
  int i = 0;
  long lsize;

  printf("Enter the file name: ");
  int k = scanf("%s", name);
  assert(k != NULL);

  char *all_strings;

  all_strings = filework(name, &lsize, &number);
  assert(all_strings != NULL);

  num_strings = count_of_strings( all_strings );
  assert(num_strings != NULL);

  //char* *x = poiner_massive(num_strings, lsize, all_strings);

  struct str* x;

  x = pointer_massive(num_strings, lsize, all_strings);

  qsort(x, num_strings, sizeof(struct str *), compare);

  write_in_file(x, num_strings);

  free(x);

  free(all_strings);

  return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

void write_in_file(struct str* x, int num_strings)
{

  FILE* file_write = fopen("newfile1.txt", "w");

  assert (file_write);

  //printf ("%p\n", file_write);

  for(int k = 0; k < num_strings; k++)
  {
    int i = 0;

    while(*(x[k].pointer + i) != '\n')
    {
      putchar(*(x[k].pointer + i));

      fputc(x[k].pointer[i], file_write);

      i++;
    }
      fputc ('\n', file_write);
      printf("\n");
  }

  fclose (file_write);
}

//---------------------------------------------------------------------------------------------------------------------------

struct str* pointer_massive(int num, int lsize, char* all_strings)
{
  int j = 1, i = 0, k = 0;
  struct str *x;

  x = (struct str*)calloc(num, sizeof(struct str));

  x[0].pointer = all_strings;

  while( i < lsize )
  {
    k++;
    if( all_strings[i] == '\n' && i != lsize - 1 )
    {
      x[j].pointer = all_strings + i + 1;
      x[j].l = k;
      j++;
      k = 0;
    }
    i++;
  }

  return x;

}

//---------------------------------------------------------------------------------------------------------------------------

char* filework(char* name, long* lsize, size_t* number )
{
  FILE* file;

  file = fopen( name, "r" );
  fseek(file, 0, SEEK_END);
  *lsize = ftell(file);
  rewind (file);

  char *all_strings = (char*)calloc(*lsize,sizeof(char));
  *number = fread(all_strings, 1, *lsize, file);

  fclose (file);

  return all_strings;
}

//-------------------------------------------------------------------------------------------------------------------------------------

int compare(const void * x1, const void * x2)
{
  char *y1, *y2;

  struct str z1, z2;

  z1 = *((struct str*)x1);
  z2 = *((struct str*)x2);

  y1 = z1.pointer;
  y2 = z2.pointer;

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

//---------------------------------------------------------------------------------

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
