#include <stdio.h>
#include<assert.h>

void alphabet_strings( FILE* file, int num );

void trade_string( char* string1, char* string2 );

bool is_punctuation_mark( char symbol);

int main()
  {
  FILE* file;
  char name[80] = "";
  int num = 0;

  printf("Enter the file name: ");
  scanf("%s", &name);

  printf("Enter the number of strings: ");
  scanf("%d", &num);

  file = fopen( name, "r" );

  char String[num][100];

  alphabet_strings( file, num);

  return 0;
  }


//------------------------------------------------------------------------------------------------------------------------

void trade_string( char* string1, char* string2 )
  {
  char help = ' ';
  int i = 0;
  int x = 0;
  int y = 0;
  while( x != 1 || y != 1 )
    {
    if( string1[i+1] == '\0' ) x = 1;
    if( string2[i+1] == '\0' ) y = 1;

    help = string1[i];
    string1[i] = string2[i];
    string2[i] = help;
    i++;

    }
  string1[i] = '\0';
  string2[i] = '\0';
  }

  //----------------------------------------------------------------------------------------------------------------------

void alphabet_strings( FILE* file, int num)
  {
    char String[num][100];
    int i = 0;
    int a = 0;
    int b = 0;
    FILE *file_write;

    file_write = fopen("new_file.txt", "w");

    while( fgets( String[i], 100, file ) != NULL ) i++;

    for( b = 0; b < i; b++ )
      {
      for( a = 0; a < i; a++ )
        {
        int x = 0;
        int k = 0;

        while( ( is_punctuation_mark( String[a][x] ) ) ) x = x + 1;
        while( ( is_punctuation_mark( String[a+1][k] ) ) ) k = k + 1;

        if( String[a][x] == '\0' ) break;
        if( String[a+1][k] == '\0' ) trade_string( String[a], String[a+1] );

        int cod1 = String[a][x];
        int cod2 = String[a+1][k];

        if( cod1 > 90 ) cod1 = cod1 - 32;
        if( cod2 > 90 ) cod2 = cod2 - 32;

        if( cod1 > cod2 ) trade_string( String[a], String[a+1]);

          while( cod1 == cod2 )
            {
            x++;
            k++;

            while( (is_punctuation_mark( String[a][x] ) ) ) x = x + 1;
            while( (is_punctuation_mark( String[a+1][k] ) ) ) k = k + 1;

            if( String[a][x] == '\0' ) break;
            if( String[a+1][k] == '\0' ) trade_string( String[a], String[a+1] );

            cod1 = (int)String[a][x];
            cod2 = (int)String[a+1][k];

            if( cod1 > cod2 )  trade_string( String[a], String[a+1] );
            }
          }
      }
    for( a = 0; a <= i; a++ ) fputs( String[a], stdout );

    for( a = 0; a <= i; a++)
      {
      b = 0;
      char symbol = ' ';

      do
        {
        symbol = String[a][b];
        putc( symbol, file_write );

        b++;
        }
      while( symbol != '\0' );
      }
  }

//----------------------------------------------------------------------------------------------------------------------------------------

bool is_punctuation_mark( char symbol )
  {
  if ( symbol == '.' || symbol == ',' || symbol == '-' || symbol == ':' || symbol == ' ' || symbol == '!' || symbol == '?' || symbol == '`' || symbol == '"') return true;
  else                                                                                                                                                        return false;
  }

