INCLUDE_DIRECTORIES(${FFTW_BINARY_DIR})

ADD_LIBRARY(bench2
  after-ccopy-from.c after-ccopy-to.c after-hccopy-from.c after-hccopy-to.c
  after-rcopy-from.c after-rcopy-to.c aligned-main.c allocate.c aset.c     
  bench-cost-postprocess.c bench-exit.c bench-main.c can-do.c caset.c 
  dotens2.c info.c main.c mflops.c mp.c ovtpvt.c pow2.c problem.c   
  report.c speed.c tensor.c timer.c useropt.c util.c verify-dft.c   
  verify-lib.c verify-r2r.c verify-rdft2.c verify.c zero.c bench-user.h 
  bench.h verify.h my-getopt.c my-getopt.h
)

