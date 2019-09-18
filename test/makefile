BOOSTLIB = /usr/local/boost_1_68_0_lib
BOOSTLOGLIB = ../

DLIBS=-Wl,-rpath,$(BOOSTLIB):$(BOOSTLOGLIB)

POS=-L$(BOOSTLIB) -L$(BOOSTLOGLIB)

LIBS= -lBoostLog -lboost_system -lboost_log_setup -lboost_log -lboost_thread -lboost_date_time -lboost_serialization \
-lboost_regex -lboost_chrono -lpthread

CXXFLAGS += -std=c++11 -DBOOST_LOG_DYN_LINK -DTHREADED
CXXFLAGS += -O3
CXXFLAGS += -g
CXXFLAGS += -I../

BIN=test

all: $(BIN)

clean:
	rm -rf *.o $(BIN)

test: test.o
	$(CXX) -o $@ test.o $(POS) $(LIBS) $(DLIBS) -pthread
	@g++ -v