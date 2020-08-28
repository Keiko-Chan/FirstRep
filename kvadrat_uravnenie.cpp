//---------------------------------------------------------------------------------
// The program solves the quadratic equation.
// It receives as input the coefficients of the quadratic equation  ( a, b, c )
// and displays the roots ( x1, x2 ) of the equation and their number ( nroots ).


#include<stdio.h>
#include<math.h>

int Solve_of_qua_equ( double a, double b, double c, double* x1, double* x2)
   {
   double Discr = 0;                       //discriminant of quadratic equation
   double Nroots = 0;                      //number of roots of quadratic equation

    if( a==0 )
      {
      if( b==0 )
        {
        if(c==0)  return -1;               //a = 0 && b = 0 && c = 0


        else      return 0;                //a = 0 && b = 0 && c != 0
        }

      else                                 //a = 0 && b != 0
        {
        *x1 = *x2 = -c/b;

        return 1;
        }
      }

    else                                   //a != 0
      {
      Discr = b*b - 4*a*c;

      if( Discr > 0 )
        {
        *x1 = ( -b + sqrt( Discr ) ) / 2;
        *x2 = ( -b - sqrt( Discr ) ) / 2;

        return 2;
        }

      if( Discr == 0 )
        {
        *x2 = *x1 = ( -b + sqrt( Discr ) ) / 2;

        return 1;
        }

      if( Discr < 0 ) return 0;
      }
    }

int main()

  {
  printf( " Solution of a quadratic equation \n " );
  printf( " Enter a, b, c \n " );

  double a = 0, b = 0, c = 0;              //odds of quadratic equation
  double x1 = 0, x2 = 0;                   //roots of quadratic equation
  int nroots = 0;                          //number of roots of quadratic equation

  scanf( "%lg%lg%lg", &a, &b, &c );

  nroots = Solve_of_qua_equ( a, b, c, &x1, &x2);

  switch( nroots )
    {
    case 0:

      printf( " The equation has no solutions " );
      break;

    case 1:

      printf( " The equation has one solution \n x1 = %lg ", x1 );
      break;

    case 2:

      printf( " The equation has two solutions \n x1 = %lg x2 = %lg ", x1, x2 );
      break;

    case -1:

      printf( " The equation has infinite number of roots " );
      break;

    default:

      printf( " Someone error " );

    return 0;
    }
  return 0;
  }
