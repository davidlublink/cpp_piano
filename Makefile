all: piano.c
	g++ -I. piano.c -o piano
test: 
	g++ -I. piano.c -o piano
	./piano

clean: 
	$(RM) piano
