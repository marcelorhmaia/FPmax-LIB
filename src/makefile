flags = -Wall -O3

all:: fim_all fim_closed fim_maximal
fim_all: fpgrowth.o data.o fp_tree.o buffer.o fsout.o fp_node.o
	g++ $(flags) fpgrowth.o data.o fp_tree.o buffer.o fsout.o fp_node.o -o fim_all

fim_closed: fpclosed.o data.o fp_tree.o buffer.o fsout.o fp_node.o
	g++ $(flags) fpclosed.o data.o fp_tree.o buffer.o fsout.o fp_node.o -o fim_closed

fim_maximal: fpmax.o data.o fp_tree.o buffer.o fsout.o fp_node.o
	g++ $(flags) fpmax.o data.o fp_tree.o buffer.o fsout.o fp_node.o -o fim_maximal

fpgrowth.o: fpmax.cpp data.h fp_tree.h common.h fsout.h
	g++ $(flags) -DFI -c fpmax.cpp -o fpgrowth.o

fpclosed.o: fpmax.cpp data.h fp_tree.h common.h fsout.h
	g++ $(flags) -DCFI -c fpmax.cpp -o fpclosed.o

fpmax.o: fpmax.cpp data.h fp_tree.h common.h fsout.h
	g++ $(flags) -DMFI -c fpmax.cpp

data.o: data.cpp data.h
	g++ $(flags) -c data.cpp

fp_tree.o: fp_tree.cpp data.h fp_tree.h common.h fsout.h
	g++ $(flags) -c fp_tree.cpp

buffer.o: buffer.cpp data.h buffer.h
	g++ $(flags) -c buffer.cpp

fsout.o: fsout.cpp fsout.h common.h
	g++ $(flags) -c fsout.cpp

fp_node.o: fp_node.cpp fp_node.h fsout.h common.h
	g++ $(flags) -c fp_node.cpp

clean:
	rm -f *.o fim_all fim_closed fim_maximal 
