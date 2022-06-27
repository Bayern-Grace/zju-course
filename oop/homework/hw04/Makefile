all: pdshow pdadd pdremove pdlist
.PHONY : all
pdshow: pdshow.cpp diary.o
	g++ pdshow.cpp diary.o -o pdshow
pdlist: pdlist.cpp diary.o
	g++ pdlist.cpp diary.o -o pdlist
pdremove: pdremove.cpp diary.o
	g++ pdremove.cpp diary.o -o pdremove
pdadd: pdadd.cpp diary.o
	g++ pdadd.cpp diary.o -o pdadd
diary.o: diary.cpp diary.h
	g++ -c diary.cpp -o diary.o