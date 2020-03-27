CC ?= gcc
CFLAGS=-g -I.
LIBS=

APP_NAME=app
SRC_EXT=c
SRC_PATH=.

SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' -printf '%T@\t%p\n' \
		  						| sort -k 1nr | cut -f2-)

OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=%.o)

# Function used to check variables. Use on the command line:
# # make print-VARNAME
# # Useful for debugging and adding features
print-%: ; @echo $*=$($*)


run:$(APP_NAME)
	./$(APP_NAME)

$(APP_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(APP_NAME) $(OBJECTS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(APP_NAME) $(OBJECTS)
