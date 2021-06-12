CC=g++ --static -O3 --std=c++2a -lm -lboost_system

PGNAME=IEEEQuizGenerator
OBJS=main.o Fraction.o

$(PGNAME): $(OBJS)
	$(CC) -o $@ $^ 
.cpp.o:
	$(CC) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(PGNAME) $(OBJS)
