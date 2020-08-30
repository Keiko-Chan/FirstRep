//---------------------------------------------------------------------------------
// The program solves the quadratic equation.
// It receives as input the coefficients of the quadratic equation  ( a, b, c )
// and displays the roots ( x1, x2 ) of the equation and their number ( nroots ).

#include <assert.h>
#include <stdio.h>
#include <math.h>

const float bias = 1e-5;

void test_solve(  );

void test_is_zero();

int is_zero( double Value );

int solve_of_qua_equ( double a, double b, double c, double* x1, double* x2);

//----------------------------------------------------------------------------------

int main()
  {
  test_is_zero();
  test_solve();

  printf( "Solution of a quadratic equation \n" );
  printf( "Enter a, b, c \n" );

  double a = 0;
  double b = 0;                            //odds of quadratic equation
  double c = 0;

  double x1 = 0;
  double x2 = 0;                           //roots of quadratic equation

  int nroots = -2;                         //number of roots of quadratic equation

  scanf( "%lg%lg%lg", &a, &b, &c );

  assert( isfinite( a ) );
  assert( isfinite( b ) );
  assert( isfinite( c ) );

  nroots = solve_of_qua_equ( a, b, c, &x1, &x2);

  switch( nroots )
    {
    case 0:
      printf( "The equation has no solutions" );
      break;

    case 1:
      printf( "The equation has one solution \n x1 = %lg", x1 );
      break;

    case 2:
      printf( "The equation has two solutions \n x1 = %lg x2 = %lg", x1, x2 );
      break;

    case -1:
      printf("The equation has infinite number of roots" );
      break;

    default:
      printf( "Someone error" );
      }
  return 0;
  }

//---------------------------------------------------------------------------------------------------

int solve_of_qua_equ( double a, double b, double c, double* x1, double* x2)
   {
   double Discr = 0;                       //discriminant of quadratic equation
   double Nroots = 0;                      //number of roots of quadratic equation

   assert( *x1 != NULL );
   assert( *x2 != NULL );

   if( is_zero( a ) )
      {
      if( is_zero( b ) )
        {
        if( is_zero( c ) )  return -1;      //a = 0 && b = 0 && c = 0

        else               return 0;       //a = 0 && b = 0 && c != 0
        }

      else                                 //a = 0 && b != 0
        {
        *x1 = *x2 = -c/b;
        return 1;
        }
      }

    else                                   //a != 0
      {
      Discr = b * b - 4 * a * c;

      if( Discr < 0 ) return 0;

      else
        {
      *x2 = ( -b - sqrt( Discr ) ) / 2;
      *x1 = ( -b + sqrt( Discr ) ) / 2;

      if( Discr > 0 )  return 2;

      if( Discr == 0 ) return 1;
         }

       }
    }

//--------------------------------------------------------------------------------------------

int is_zero( double Value )
  {
  return( fabs( Value ) < bias ) ;
  }

//-----------------------------------------------------------------------------------------

void test_is_zero()
  {
  if( is_zero( 0 ) == 1 )   printf( "Test one Yes \n" );
  else                     printf( "Test one No: result = %d, should be 1\n", is_zero( 0 ) );

  if( is_zero( 1 ) == 0 )   printf( "Test two Yes \n" );
  else                     printf( "Test two No: result = %d, should be 0 \n", is_zero( 1 ) );

  if( is_zero( bias ) == 0) printf( "Test third Yes \n" );
  else                     printf( "Test third No: result = %d, should be 0 \n", is_zero( bias ) );
  }

//------------------------------------------------------------------------------------------------

void test_solve(  )
  {
  double x1 = 0;
  double x2 = 0;

  if( solve_of_qua_equ( 0, 0, 0, &x1, &x2 ) == -1 ) printf( "Test one Yes \n" );
  else                                              printf( "Test one No: error infinite number of roots, result = %d \n",solve_of_qua_equ( 0, 0, 0, &x1, &x2 ) );

  if( solve_of_qua_equ( 0, 0, 1, &x1, &x2 ) == 0 )  printf( "Test two yes \n " );
  else                                              printf( "Test two No: no roots, but result = %d \n",solve_of_qua_equ( 0, 0, 1, &x1, &x2 ) );

  if( solve_of_qua_equ( 2, 7, 9, &x1, &x2 ) == 2 )  printf( "Test third yes \n " );
  else                                              printf( "Test third No: exist two roots, but result = %d \n",solve_of_qua_equ( 2, 7, 9, &x1, &x2 ) );

  if( solve_of_qua_equ( 6, 2, 1, &x1, &x2 ) == 0 )  printf( "Test four yes \n " );
  else                                              printf( "Test four No: no roots, but result = %d \n",solve_of_qua_equ( 6, 2, 1, &x1, &x2 ) );

  if( solve_of_qua_equ( 1, 4, 4, &x1, &x2 ) == 1 )  printf( "Test five yes \n " );
  else                                              printf( "Test five No: exist one root, but result = %d \n",solve_of_qua_equ( 1, 4, 4, &x1, &x2 ) );

  if( solve_of_qua_equ( 0, 4, 4, &x1, &x2 ) == 1 )  printf( "Test six yes \n " );
  else                                              printf( "Test six No: exist one root, but result = %d \n",solve_of_qua_equ( 0, 4, 4, &x1, &x2 ) );

  }

