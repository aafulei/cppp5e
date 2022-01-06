CODE :=  $(wildcard *.cpp)
CODE :=  $(filter-out 01-07.cpp, $(CODE))
CODE :=  $(filter-out 01-15.cpp, $(CODE))
TARGET := $(patsubst %.cpp, %, $(CODE))
INCLUDE := -I ../include/

all: $(TARGET)

%: %.cpp
	g++ $< -o ../binary/$@ $(INCLUDE)
