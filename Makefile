CC	   	 		=	gcc
OPTS   	 		=	-Wall -Wextra -pedantic
FIN	   	 		=	g.c
FOUT			=	g

all:
	$(CC) $(OPTS) $(FIN) -o $(FOUT)

clean:
	rm -v $(FOUT)

