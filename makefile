list: node.c
	gcc node.c
clean:
	rm *~
run: list
	./list
