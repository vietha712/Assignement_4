# Utilities
PROJ := MatVecClass

#Paths
OUTPUT_PATH := _build
INC_PATH := E:\mstAdvancedProgrammingClass\A4
SRC_PATH := src

# Includes
INC := -I$(INC_PATH)
INCLUDES := $(INC_PATH)

# Compiler
CC := g++
CC_OPT := -g -Wall

# Search paths
vpath %.c $(SRC_PATH)

#OBJECT FILES
OBJ_FILES := $(OUTPUT_PATH)/dmatrix.o $(OUTPUT_PATH)/dvector.o

# Commands

#OUTPUT_PATH/%.o: %.c
#	$(CC) -c $(CC_OPT) $(INCLUDES) $< -o $@

build: $(PROJ).cpp $(OBJ_FILES) build-dir
	@echo "Compiling $(PROJ).cpp"
	@$(CC) $(CC_OPT) -I$(INC_PATH) $(OBJ_FILES) $(PROJ).cpp -o $(OUTPUT_PATH)/$(PROJ).exe 

$(OUTPUT_PATH)/dvector.o: dvector.cpp
	@$(CC) -c $(CC_OPT) -I$(INC_PATH) $< -o $(OUTPUT_PATH)/dvector.o

$(OUTPUT_PATH)/dmatrix.o: dmatrix.cpp
	@$(CC) -c $(CC_OPT) -I$(INC_PATH) $< -o $(OUTPUT_PATH)/dmatrix.o

build-dir:
	@mkdir -p $(OUTPUT_PATH)

clean:
	@echo "Cleaning up"
	@rm -rf  $(OUTPUT_PATH)

run:
	@echo "Executing program"
	@echo "Outcome can be found below"
	@echo ""
	@$(OUTPUT_PATH)/*.exe