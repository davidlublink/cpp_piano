SYNTH_IP = "192.168.34.112"

all: piano.c
	g++ -I. piano.c -o piano
demo: 
	g++ -I. piano.c -o piano
	./piano | fluidsynth -a alsa -o audio.alsa.device=hw:0 /usr/share/sounds/sf2/FluidR3_GM.sf2 -c=2 -z=64

test: 
	g++ -g -I. piano.c -o piano
	./piano 

debug: 
	g++ -g -I. piano.c -o piano
	gdb ./piano 

clean: 
	$(RM) piano

help: 
	@echo "Usage : "
	@echo "@author david lublink"
	@echo ""
	@echo "make  => build piano binary in current working directory"
	@echo "clean => Remove any file named 'piano' from the current working directory"
	@echo "demo => run demo using nc to reach fluidsynth server --SYNTH_IP 127.0.0.1"
