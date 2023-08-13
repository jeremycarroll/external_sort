CXX	?= g++

CFLAGS	= -std=c++11 -c -Wall -pthread
INCL	= -I.. -I./logging -I/usr/local/include
LDFLAGS	= \
	-pthread \
	-L/usr/local/lib \
	-lboost_program_options \
	-lboost_timer \
	-lboost_system

EXE	= external_sort
SRC	= external_sort_main.cc logging/logging.cc
SORT1   = 0
SORT2   = 1

OBJ	= $(SRC:.cc=.o)

.PHONY: all clean

all:	CFLAGS += -O3
all:	$(EXE)

debug:	CFLAGS += -g -DDEBUG -DBOOSTLOG -DBOOST_LOG_DYN_LINK
debug:	LDFLAGS += -lboost_log 	-lboost_log_setup -lboost_thread
debug:	$(EXE)

ipDatetime: SORT1 = -DPRIMARY=1
ipDatetime: SORT2 = -DSECONDARY=0
ipDatetime: clean $(EXE)
	mv $(EXE) ipDatetime

userId: SORT1 = -DPRIMARY=2
userId: SORT2 = -DSECONDARY=0
userId: clean $(EXE)
	mv $(EXE) userId

datetimeIp: SORT1 = -DPRIMARY=0
datetimeIp: SORT2 = -DSECONDARY=1
datetimeIp: clean $(EXE)
	mv $(EXE) datetimeIp

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

.cc.o:
	$(CXX) $(CFLAGS) $(SORT1) $(SORT2) $(INCL) $< -o $@

clean:
	rm -f $(EXE) $(OBJ)
