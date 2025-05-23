//
// Test program for Quasi-Newton optimization objects
//
// 1. Quasi-Newton with trust regions on an NLF1
// 2. Quasi-Newton with More-Thuente linesearch on an NLF1
// 3. Quasi-Newton with backtrack linesearch on an NLF1
//

#include <fstream>

#include "OptQNewton.h"
#include "NLF.h"
#include "tstfcn.h"

using Teuchos::SerialDenseVector;

using namespace OPTPP;

using std::cerr;
using std::endl;

#define true  1
#define false 0

void update_model(int, int, SerialDenseVector<int,double>) {}

int main ()
{
  int n = 2;
  
  static char *status_file = {"tstfdnlf1.out"};

//----------------------------------------------------------------------------
// 1. Quasi-Newton with trust regions
//----------------------------------------------------------------------------

  //  Create a Nonlinear problem object

  FDNLF1 nlp(n,rosen0,init_rosen);
  
  //  Build a Quasi-Newton object and optimize 

  OptQNewton objfcn(&nlp,update_model);   
  if (!objfcn.setOutputFile(status_file, 0))
    cerr << "main: output file open failed" << endl;
  objfcn.optimize();
  objfcn.printStatus("Solution from quasi-newton");

#ifdef REG_TEST
  SerialDenseVector<int,double> x_sol = nlp.getXc();
  double f_sol = nlp.getF();
  ostream* optout = objfcn.getOutputFile();
  if ((1.0 - x_sol(0) <= 1.e-2) && (1.0 - x_sol(1) <= 1.e-2) && (f_sol
								 <=
								 1.e-2))
    *optout << "FDNewton 1 PASSED" << endl;
  else
    *optout << "FDNewton 1 FAILED" << endl;
#endif

  objfcn.cleanup();	 
    
//----------------------------------------------------------------------------
// 2. Quasi-Newton with More and Thuente's line search
//----------------------------------------------------------------------------

  FDNLF1 nlp2(n,rosen0,init_rosen);
  
  OptQNewton objfcn2(&nlp2,update_model);   
  objfcn2.setSearchStrategy(LineSearch);
  objfcn2.setOutputFile(status_file, 1);
  objfcn2.optimize();
  objfcn2.printStatus("Solution from quasi-newton: More and Thuente linesearch");

#ifdef REG_TEST
  x_sol = nlp2.getXc();
  f_sol = nlp2.getF();
  optout = objfcn2.getOutputFile();
  if ((1.0 - x_sol(0) <= 1.e-2) && (1.0 - x_sol(1) <= 1.e-2) && (f_sol
								 <=
								 1.e-2))
    *optout << "FDNewton 2 PASSED" << endl;
  else
    *optout << "FDNewton 2 FAILED" << endl;
#endif

  objfcn2.cleanup();	 
    
//----------------------------------------------------------------------------
// 3. Quasi-Newton with backtrack line search
//----------------------------------------------------------------------------

  FDNLF1 nlp3(n,rosen0,init_rosen);
  nlp3.setIsExpensive(true);
  
  OptQNewton objfcn3(&nlp3,update_model);   
  objfcn3.setOutputFile(status_file, 1);
  objfcn3.setSearchStrategy(LineSearch);
  objfcn3.optimize();
  objfcn3.printStatus("Solution from quasi-newton");

#ifdef REG_TEST
  x_sol = nlp3.getXc();
  f_sol = nlp3.getF();
  optout = objfcn3.getOutputFile();
  if ((1.0 - x_sol(0) <= 1.e-2) && (1.0 - x_sol(1) <= 1.e-2) && (f_sol
								 <=
								 1.e-2))
    *optout << "FDNewton 3 PASSED" << endl;
  else
    *optout << "FDNewton 3 FAILED" << endl;
#endif    

  objfcn3.cleanup();	 
}
