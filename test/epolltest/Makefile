OBJ_DIR = ./.objs
TARGET_DIR = ./Bin
COMMON_DIR = ../../common/.objs
TARGET = $(TARGET_DIR)/svr $(TARGET_DIR)/cli
CXX = g++
CXXFLAG = -g -std=c++11 

.PRECIOUS:$(OBJ_DIR)/*.o

all: $(TARGET)

$(TARGET_DIR)/%:$(OBJ_DIR)/%.o
	@if [ ! -e $(dir $@) ]; then \
	    mkdir -p $(dir $@); \
	fi
	$(CXX) $(CXXFLAG) $(COMMON_DIR)/*.o $< -o $@

$(OBJ_DIR)/%.o:%.cpp
	@if [ ! -e $(dir $@) ]; then \
	    mkdir -p $(dir $@); \
	fi
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.SECONDARY:
