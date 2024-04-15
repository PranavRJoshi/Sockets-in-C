CC=gcc
INDICRS=-I.
OPT=-O0
CFLAGS=-Wall -Wextra -g $(INDICRS) $(OPT)

CFILES=tcp_server.c tcp_client.c
OBJECTS=$(CFILES:.c=.o)
EXEC=$(CFILES:.c=)
DSYM=$(CFILES:.c=.dSYM)

# The process goes something like this:
# 1. using `make` only invokes the make all command
# 2. It looks for the prerequisite, $(EXEC) in this case, which has not been built yet, 
# 3. The value of EXEC will be http_server and http_client (defined above in simplified way)
# 4. The regular expression to generate executables is given below, % is a wildcard that represents any value
# 5. The compilation produces dSYM directories for the given C files, which stores the debug symbols for the file. More about this on the thread: https://stackoverflow.com/questions/3656391/whats-the-dsym-and-how-to-use-it-ios-sdk
all: $(EXEC)

# $(EXEC): $(OBJECTS)
# 	$(CC) $(CFLAGS) -o -v $@ $^

# $(OBJECTS): $(CFILES)
# 	$(CC) -c -o $@ $^

# %:%.o
# 	$(CC) -o $@ $^

# $< and $@ are magic symbols in makefile, basically the LHS is the taget and the RHS is the prerequisite, and $< represents the variable used in the LHS whereas $@ represents the variable used in the RHS.
%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXEC) $(OBJECTS) $(DSYM)
