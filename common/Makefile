SRC = $(wildcard *.cpp)
OBJ_DIR = ./.objs
OBJS = $(addprefix ${OBJ_DIR}/,$(subst .cpp,.o,$(SRC)))
CXX = g++
CXXFLAG = -g -c -std=c++11

all: $(OBJS)

$(OBJ_DIR)/%.o:%.cpp
	@if [ ! -e $(dir $@) ]; then \
	    mkdir -p $(dir $@); \
	fi
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)
