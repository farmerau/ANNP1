ann:	ann.o driver.o nodes.o
	g++ -o ann ann.o driver.o nodes.o

ann.o:	ann.h ann.cc
	g++ -c -g ann.cc

nodes.o:	nodes.h nodes.cc
	g++ -c -g nodes.cc

driver.o: driver.cc
	g++ -c -g driver.cc

clean:
	rm -f *~ ann *.o
