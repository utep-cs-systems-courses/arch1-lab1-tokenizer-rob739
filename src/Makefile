
#object files 
OBJS = history.o tokenizer.o uimain.o

#default rule
CFLAGS=-g -O3 # -g for debug, -O3 for optimization

tokenizer: $(OBJS)

	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokenizer

run: tokenizer
	./tokenizer
