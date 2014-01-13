


PROJ := robot_cat
OBJS := robot_cat.o
CFLAGS += -g

all:$(PROJ)

$(PROJ):$(OBJS)
	cc $^ -o $@

..o:.c

clean:
	rm $(OBJS) $(PROJ)
