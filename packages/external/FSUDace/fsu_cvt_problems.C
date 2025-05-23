#ifdef HAVE_CONFIG
#include "fsudace_config.h"
#endif
# ifdef HAVE_STD
#   include <cstdlib>
#   include <cmath>
#   include <cstring>
#   include <ctime>
# else
#   include <stdlib.h>
#   include <math.h>
#   include <string.h>
#   include <time.h>
# endif

# include <iostream>
# include <iomanip>
# include <fstream>

using namespace std;

#include "fsu.H"

int main ( void );
void cvt_test01 ( void );
void cvt_test02 ( void );
void cvt_test03 ( void );
void cvt_test04 ( void );
void cvt_test05 ( void );
void cvt_test06 ( void );
void cvt_test07 ( void );
void cvt_test08 ( void );
void cvt_test09 ( void );
void cvt_test10 ( void );
void cvt_test12 ( void );

//*******************************************************************************

int main ( void )

//*******************************************************************************
//
//  Purpose:
//
//    FSU_CVT_PROBLEMS calls a set of problems for FSU_CVT.
//
//  Modified:
//
//    07 December 2004
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );

  cout << "\n";
  cout << "FSU_CVT_PROBLEMS\n";
  cout << "  Call a simple set of test problems for\n";
  cout << "  the C++ FSU_CVT routines.\n";

  cvt_test01 ( ); 
  cvt_test02 ( );
  cvt_test03 ( );
  cvt_test04 ( );
  cvt_test05 ( );
  cvt_test06 ( );
  cvt_test07 ( );
  cvt_test08 ( );
  cvt_test09 ( );
  cvt_test10 ( );

  cvt_test12 ( );

  cout << "\n";
  cout << "FSU_CVT_PROBLEMS\n";
  cout << "  Normal end of execution.\n";

  cout << "\n";
  timestamp ( );

  return 0;
}
//*******************************************************************************

void cvt_test01 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST01 tests FSU_CVT with uniform initialization and uniform sampling.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define NDIM 2

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST01\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "\n";

  batch = 1000;
  init = 0;
  strcpy ( init_string, "uniform" );
  it_max = 40;
  sample = 0;
  sample_num = 10000;
  strcpy ( sample_string, "uniform" );
  seed_init = 123456789;
  seed = seed_init;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;

# undef NDIM
# undef N
}
//*******************************************************************************

void cvt_test02 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST02 repeats test 1, but uses twice as many iterations.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define NDIM 2

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST02\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "  Repeat test 1, but with twice the number of iterations.\n";
  cout << "\n";

  batch = 1000;
  init = 0;
  strcpy ( init_string, "uniform" );
  it_max = 80;
  sample = 0;
  sample_num = 10000;
  strcpy ( sample_string, "uniform" );
  seed_init = 123456789;
  seed = seed_init;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max,
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;

# undef NDIM
# undef N
}
//*******************************************************************************

void cvt_test03 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST03 repeats test 1 but uses 100 times as many sample points.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define NDIM 2

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST03\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "  Repeat test 1, but with 100 times the sample points.\n";
  cout << "\n";

  batch = 1000;
  init = 0;
  strcpy ( init_string, "uniform" );
  it_max = 40;
  sample = 0;
  sample_num = 1000000;
  strcpy ( sample_string, "uniform" );
  seed_init = 123456789;
  seed = seed_init;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;

# undef NDIM
# undef N
}
//*******************************************************************************

void cvt_test04 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST04 repeats test 1 with uniform initialization and Halton sampling.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define NDIM 2

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST04\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "  Repeat test 1, but with Halton sampling.\n";
  cout << "\n";

  batch = 1000;
  init = 0;
  strcpy ( init_string, "uniform" );
  it_max = 40;
  sample = 1;
  sample_num = 10000;
  strcpy ( sample_string, "halton" );
  seed_init = 123456789;
  seed = seed_init;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;

# undef NDIM
# undef N
}
//*******************************************************************************

void cvt_test05 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST05 repeats test 1 with uniform initialization and grid sampling.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define NDIM 2

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST05\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "  Repeat test 1, but with grid sampling.\n";
  cout << "\n";

  batch = 1000;
  init = 0;
  strcpy ( init_string, "uniform" );
  it_max = 40;
  sample = 2;
  sample_num = 10000;
  strcpy ( sample_string, "grid" );
  seed_init = 123456789;
  seed = seed_init;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;

# undef NDIM
# undef N
}
//*******************************************************************************

void cvt_test06 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST06 repeats test 1 with uniform initialization and C++ RANDOM sampling.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define NDIM 2

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST06\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "  Repeat test 1, but with C++ RANDOM sampling.\n";
  cout << "\n";

  batch = 1000;
  init = 0;
  strcpy ( init_string, "uniform" );
  it_max = 40;
  sample = -1;
  sample_num = 10000;
  strcpy ( sample_string, "random" );
  seed_init = 123456789;
  seed = seed_init;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;

# undef NDIM
# undef N
}
//*******************************************************************************

void cvt_test07 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST07 tests FSU_CVT with a different seed.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define NDIM 2

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST07\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "  Repeat test 1 with a different seed.\n";
  cout << "\n";

  batch = 1000;
  init = 0;
  strcpy ( init_string, "uniform" );
  it_max = 40;
  sample = 0;
  sample_num = 10000;
  strcpy ( sample_string, "uniform" );
  seed_init = 987654321;
  seed = seed_init;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;

# undef NDIM
# undef N
}
//*******************************************************************************

void cvt_test08 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST08 repeats test 1 with a different batch size.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define NDIM 2

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST08\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "  Repeat test 1 with a different batch size.\n";
  cout << "\n";

  batch = 5;
  init = 0;
  strcpy ( init_string, "uniform" );
  it_max = 40;
  sample = 0;
  sample_num = 10000;
  strcpy ( sample_string, "uniform" );
  seed_init = 123456789;
  seed = seed_init;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;

# undef NDIM
# undef N
}
//*******************************************************************************

void cvt_test09 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST09 generates 100 points in 3D.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 100
# define NDIM 3

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST09\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "  Compute 100 points in 3D.\n";
  cout << "\n";

  batch = 1000;
  init = 0;
  strcpy ( init_string, "uniform" );
  it_max = 40;
  sample = 0;
  sample_num = 10000;
  strcpy ( sample_string, "uniform" );
  seed_init = 123456789;
  seed = seed_init;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print_some ( NDIM, N, r, 1, 1, NDIM, 10, 
    "  First 10 Generators (rows):" );

  return;
# undef N
# undef NDIM
}
//*******************************************************************************

void cvt_test10 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST10 tests FSU_CVT.
//
//  Discussion:
//
//    In this test, we initialize the generators to grid points; this is 
//    an unstable CVT solution.  The data would "prefer" to be in a
//    different form.  However, even if we take 2000 steps of CVT iteration,
//    the data is still only slowly progressing towards that other 
//    configuration.
//
//  Modified:
//
//    04 October 2004
//
//  Author:
//
//    John Burkardt
//
{
# define N 16
# define NDIM 2

  int batch;
  int i;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  int j;
  int ngrid;
  double r[NDIM*N];
  int rank;
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;
  int tuple[NDIM];

  cout << "\n";
  cout << "CVT_TEST10\n";
  cout << "  FSU_CVT computes a Centroidal Voronoi Tessellation.\n";
  cout << "\n";
  cout << "  In this test, we initialize the generators to\n";
  cout << "  grid points; this is an unstable CVT solution.\n";
  cout << "\n";

  batch = 1000;
  init = 3;
  strcpy ( init_string, "user initialization" );
  it_max = 40;
  sample = 0;
  sample_num = 1000;
  strcpy ( sample_string, "uniform" );
  seed_init = 123456789;
  seed = seed_init;
//
//  Initialize the tuple generator.
//
  rank = -1;
  ngrid = 4;
  tuple_next_fast ( ngrid, NDIM, rank, tuple );
//
//  Pick points on a grid.
//
  for ( j = 0; j < N; j++ )
  {
    rank = j;
    tuple_next_fast ( ngrid, NDIM, rank, tuple );
    for ( i = 0; i < NDIM; i++ )
    {
      r[i+j*NDIM] = ( double ) ( 2 * tuple[i] - 1 ) 
                  / ( double ) ( 2 * ngrid );
    }
  }
  dmat_transpose_print ( NDIM, N, r, "  Initial generators (rows):" );

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max,
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =  "  << NDIM          << "\n";
  cout << "  Number of points N =      "  << N             << "\n";
  cout << "  Initial SEED_INIT =       "  << seed_init     << "\n";
  cout << "  Current SEED =            "  << seed          << "\n";
  cout << "  INIT =                   \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =   "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =       "  << it_num        << "\n";
  cout << "  SAMPLE =                 \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =   "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =     "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) = "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;
# undef N
# undef NDIM
}
//*******************************************************************************

void cvt_test12 ( void )

//*******************************************************************************
//
//  Purpose:
//
//    CVT_TEST12 tests FSU_CVT with 'RANDOM' initialization.
//
{
# define N 10
# define NDIM 2

  int batch;
  int init;
  char init_string[80];
  int it_max;
  int it_num;
  double r[NDIM*N];
  int sample;
  int sample_num;
  char sample_string[80];
  int seed;
  int seed_init;

  cout << "\n";
  cout << "CVT_TEST12\n";
  cout << "  The \"random\" initialization option calls the\n";
  cout << "  system random number generator.  There is some\n";
  cout << "  question about whether this works correctly.\n";
  cout << "\n";
  cout << "  The test is as follows:\n";
  cout << "\n";
  cout << "  CVT call #1:\n";
  cout << "\n";
  cout << "    NDIM      =      2\n";
  cout << "    N         =     10\n";
  cout << "    INIT      =     -1\n";
  cout << "    IT_MAX    =      0\n";
  cout << "    SEED      = 100000\n";
  cout << "\n";
  cout << "    Print output values of SEED and R #1.\n";
  cout << "\n";
  cout << "  CVT call #2: (jump SEED)\n";
  cout << "\n";
  cout << "    NDIM      =      2\n";
  cout << "    N         =     10\n";
  cout << "    INIT      =     -1\n";
  cout << "    IT_MAX    =      0\n";
  cout << "    SEED      = 200000.\n";
  cout << "\n";
  cout << "    Print output values of SEED and R #2.\n";
  cout << "\n";
  cout << "  CVT call #3: (restore SEED)\n";
  cout << "\n";
  cout << "    NDIM      =      2\n";
  cout << "    N         =     10\n";
  cout << "    INIT      =     -1\n";
  cout << "    IT_MAX    =      0\n";
  cout << "    SEED_INIT = 100000\n";
  cout << "\n";
  cout << "    Print output values of SEED and R #3.\n";
  cout << "\n";
  cout << "  We expect that:\n";
  cout << "  * the values of R #1 and R #2 differ;\n";
  cout << "  AND\n";
  cout << "  * the values of R #1 and R #3 agree.\n";
//
//  Run #1.
//
  batch = 1000;
  init = -1;
  strcpy ( init_string, "random" );
  it_max = 0;
  sample = 0;
  sample_num = 10000;
  strcpy ( sample_string, "uniform" );
  seed = 100000;

  seed_init = seed;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =   "  << NDIM          << "\n";
  cout << "  Number of points N =       "  << N             << "\n";
  cout << "  Initial SEED =             "  << seed_init     << "\n";
  cout << "  Current SEED =             "  << seed          << "\n";
  cout << "  INIT =                    \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =    "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =        "  << it_num        << "\n";
  cout << "  SAMPLE =                  \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =    "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =      "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) =  "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );
//
//  Run #2.
//
  batch = 1000;
  init = -1;
  strcpy ( init_string, "random" );
  it_max = 0;
  sample = 0;
  sample_num = 10000;
  strcpy ( sample_string, "uniform" );
  seed = 200000;

  seed_init = seed;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max, 
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =   "  << NDIM          << "\n";
  cout << "  Number of points N =       "  << N             << "\n";
  cout << "  Initial SEED =             "  << seed_init     << "\n";
  cout << "  Current SEED =             "  << seed          << "\n";
  cout << "  INIT =                    \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =    "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =        "  << it_num        << "\n";
  cout << "  SAMPLE =                  \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =    "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =      "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) =  "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );
//
//  Run #3.
//
  batch = 1000;
  init = -1;
  strcpy ( init_string, "random" );
  it_max = 0;
  sample = 0;
  sample_num = 10000;
  strcpy ( sample_string, "uniform" );
  seed = 100000;

  seed_init = seed;

  fsu_cvt ( NDIM, N, batch, init, sample, sample_num, it_max,
    &seed, r, &it_num );

  cout << "\n";
  cout << "  Spatial dimension NDIM =   "  << NDIM          << "\n";
  cout << "  Number of points N =       "  << N             << "\n";
  cout << "  Initial SEED =             "  << seed_init     << "\n";
  cout << "  Current SEED =             "  << seed          << "\n";
  cout << "  INIT =                    \"" << init_string   << "\".\n";
  cout << "  Max iterations IT_MAX =    "  << it_max        << "\n";
  cout << "  Iterations IT_NUM =        "  << it_num        << "\n";
  cout << "  SAMPLE =                  \"" << sample_string << "\".\n";
  cout << "  Samples SAMPLE_NUM    =    "  << sample_num    << "\n";
  cout << "  Sampling BATCH size =      "  << batch         << "\n";
  cout << "  EPSILON (unit roundoff) =  "  << d_epsilon ( ) << "\n";
  
  dmat_transpose_print ( NDIM, N, r, "  Generators (rows):" );

  return;

# undef NDIM
# undef N
}
