.PHONY : all clear
all : bin/myapp

OBJS = obj/main.o obj/foo.o obj/goo.o

bin/myapp : $(OBJS)
	gcc -o bin/myapp $(OBJS)


obj/%.o : src/%.c | obj
	gcc -c $< -o $@ -I./include

clear : 
	rm -rf obj/*.o bin/myapp