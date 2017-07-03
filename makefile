#Add flags for compiler warnings and use the latest C++ version
CCFLAGS = -Wall -std=c++11

#Link object(s) and output an executable file
SearchVector.exe: SearchVector.o
	g++ $(CCFLAGS) -o SearchVector.exe SearchVector.o

#Create object file
SearchVector.exe.o: SearchVector.cc
	g++ $(CCFLAGS) -c SearchVector.cc

#Remove object files and the executable
clean:
	-rm *.o SearchVector.exe
