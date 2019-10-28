SYNTH_IP = "192.168.34.112"

all: piano.c
	g++ -I. piano.c -o piano
demo: 
	g++ -I. piano.c -o piano
	./piano | nc $(SYNTH_IP) 9800

test: 
	g++ -I. piano.c -o piano
	./piano 

clean: 
	$(RM) piano

help: 
	@echo "Usage : "
	@echo "@author david lublink"
	@echo ""
	@echo "make  => build piano binary in current working directory"
	@echo "clean => Remove any file named 'piano' from the current working directory"
	@echo "demo => run demo using nc to reach fluidsynth server --SYNTH_IP 127.0.0.1"
