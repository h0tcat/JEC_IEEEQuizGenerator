CC=g++ --static -O3 --std=c++2a
PGNAME=IEEEQuizGenerator
OBJS=main.o Eratosthenes.o

$(PGNAME): $(OBJS)
	$(CC) -o $@ $^ 
.cpp.o:
	$(CC) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(PGNAME) $(OBJS)
