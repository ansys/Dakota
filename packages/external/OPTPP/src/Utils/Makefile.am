#                      -*- Automake -*-
# Process this file with automake to produce a Makefile.in.

# Set convenience library name and include source files in this
# directory.

noinst_LTLIBRARIES = libutils.la
libutils_la_SOURCES = BoolVector.C		file_cutils.c	  \
		      ioformat.C		mcholesky.C	  \
		      OptppExceptions.C		OptppFatalError.C \
		      print.C			timers.c

# Provide location of additional include files.

TEUCHOS_INCL	= @TEUCHOS_CPPFLAGS@
INCLUDES = $(TEUCHOS_INCL) -I$(top_srcdir)/include

# Additional files to be included in the distribution.

EXTRA_DIST = COPYRIGHT GNU_LGPL

# Files to remove by 'make distclean'

DISTCLEANFILES = *.log *.out *.ti *~

# Autotools-generated files to remove by 'make maintainer-clean'.

MAINTAINERCLEANFILES = Makefile.in

# Compiler cache directories (created on some platforms) to be removed.

clean-local:
	-rm -rf ii_files SunWS_cache so_locations
