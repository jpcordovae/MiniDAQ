CC=g++
CXXFLAGS=-W -Wall -g -std=c++0x -Iinclude -Isrc -Wno-unused-parameter
OBJECTS=src/common.cpp src/database.cpp src/tcp_service.hpp main.cpp
LDFLAGS+=-lboost_date_time -lboost_system -L/usr/lib64/mysql -lmysqlcppconn -lboost_thread

VPATH = ./src

TARGETS: tcp_service tcp_client

all: $(TARGETS)

tcp_client: examples/client_50ms.cpp src/common.cpp src/tcp_client.hpp
	$(CC) $? $(CXXFLAGS) $(LDFLAGS) -o $@ -gdwarf-2 -g3

tcp_service: examples/main_service_1.cpp src/common.cpp src/database.cpp src/tcp_service.hpp src/config.cpp src/frontend.cpp
	$(CC) $? $(CXXFLAGS) $(LDFLAGS) -lncurses -o $@ -gdwarf-2 -g3
