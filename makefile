BOOSTLIB = /usr/local/boost_1_68_0_lib

DLIBS=-Wl,-rpath,$(BOOSTLIB)

POS=-L$(BOOSTLIB)

LIBS= -lboost_system -lboost_log_setup -lboost_log -lboost_thread -lboost_date_time -lboost_serialization \
-lboost_regex -lboost_chrono -lpthread

CXXFLAGS += -std=c++11 -DBOOST_LOG_DYN_LINK -DBOOST_ERROR_CODE_HEADER_ONLY -DTHREADED
CXXFLAGS += -O3
CXXFLAGS += -g

BIN=test

all: $(BIN)

clean:
	rm -rf *.o $(BIN)

test: log.o test.o
	$(CXX) -o $@ log.o test.o $(POS) $(LIBS) $(DLIBS) -pthread
	@g++ -v