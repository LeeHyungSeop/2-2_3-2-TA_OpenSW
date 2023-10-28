.PHONY : all clear
all : bin/myapp

OBJS = obj/main.o obj/foo.o obj/goo.o

bin/myapp : $(OBJS)
	gcc -o bin/myapp $(OBJS)

obj/main.o : src/main.c
	gcc -c src/main.c -o obj/main.o -I./include
obj/foo.o : src/foo.c
	gcc -c src/foo.c -o obj/foo.o -I./include
obj/goo.o : src/goo.c
	gcc -c src/goo.c -o obj/goo.o -I./include

clear : 
	rm -rf obj/*.o bin/myapp