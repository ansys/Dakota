INCLUDE = -I..\\MOMHLib++\\Common -I..\\MOMHLib++\\HGA -I..\\MOMHLib++\\MO -I..\\MOMHLib++\\MOMSLS -I..\\MOMHLib++\\ParetoGA -I..\\MOMHLib++\\SA

GCCPAR = 
CC = gcc $(GCCPAR) $(INCLUDE) 

EXENAME = mokp.exe

CPP    = \
	main.cpp \
	..\\MOMHLib++\\Common\\trandomgenerator.cpp \
	..\\MOMHLib++\\ParetoGA\\tindexedpoint.cpp \
	..\\MOMHLib++\\MO\\global.cpp \
	..\\MOMHLib++\\MO\\momhconstrainedsolution.cpp \
	..\\MOMHLib++\\MO\\solution.cpp \
	..\\MOMHLib++\\MO\\solutionsset.cpp \
	..\\MOMHLib++\\MO\\nondominatedset.cpp \
	..\\MOMHLib++\\MO\\tbnode.cpp \
	..\\MOMHLib++\\MO\\tbtree.cpp \
	..\\MOMHLib++\\MO\\tlistset.cpp \
	..\\MOMHLib++\\MO\\tmotools.cpp \
	..\\MOMHLib++\\MO\\tquadnode.cpp \
	..\\MOMHLib++\\MO\\weights.cpp \
	mokpproblem.cpp \
	mokpsolution.cpp

OBJTEST :=  $(patsubst %.cpp,%.o,$(CPPTEST))

CompileAndBuild : $(OBJTEST) 
	g++ -o $(EXENAME) $(INCLUDE) $(CPP)

$(OBJTEST): %.o: %.cpp 
	$(CC) -c $(CFLAGS) $< -o $@ 

	
