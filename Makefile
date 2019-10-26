all: piano.c
	g++ -I. piano.c -o piano

clean: 
	$(RM) piano
