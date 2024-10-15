demo: main.o event.o concert.o conference.o
	g++ main.o event.o concert.o conference.o -o homework2

main.o: main.cpp event.h concert.h conference.h
	g++ -c main.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

concert.o: concert.cpp concert.h
	g++ -c concert.cpp

conference.o: conference.cpp conference.h
	g++ -c conference.cpp

run: homework2
	./homework2

clean: 
	rm -f main.o event.o concert.o conference.o homework2