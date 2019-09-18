CXXFLAGS += -std=c++11 -DBOOST_LOG_DYN_LINK
CXXFLAGS += -O3
CXXFLAGS += -g
CXXFLAGS += -fPIC

TARGET = libBoostLog.so
TARGETA = libBoostLog.a

all: static dynamic

dynamic: $(TARGET)

$(TARGET):  log.o
	$(CXX) $(CXXFLAGS) -shared -o $@ $^

static: $(TARGETA)

$(TARGETA):log.o
	ar crvs $@ $^

clean:
	rm -rf *.o ${TARGET} ${TARGETA}