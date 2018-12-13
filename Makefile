main: main.o buildTree.o writeTree.o
	gcc -lm -o main main.o buildTree.o writeTree.o

main.o: main.c treestructure.h buildTree.h writeTree.h
	gcc -lm -c main.c

buildTree.o: buildTree.c treestructure.h
	gcc -lm -c buildTree.c

writeTree.o: writeTree.c treestructure.h
	gcc -lm -c writeTree.c

clean:
	-rm -f main.o buildTree.o writeTree.o
