##
## EPITECH PROJECT, 2022
## make
## File description:
## Makefile for C++ project
##

SRC = 	src/Main.cpp \
		src/Parser/Parser.cpp \
		\
		src/Simulation/Simulation.cpp \
		\
		src/Components/AComponent.cpp \
		src/Components/Gate.cpp \
		src/Components/ComponentFactory.cpp \
		\
		src/Components/Pin/APin.cpp \
		src/Components/Pin/PinMap.cpp \
		src/Components/Pin/InputPin.cpp \
		src/Components/Pin/OutputPin.cpp \
		\
		src/Components/IO/Input.cpp \
		src/Components/IO/Output.cpp \
		src/Components/IO/Clock.cpp \
		src/Components/IO/True.cpp \
		src/Components/IO/False.cpp \
    	\
    	src/Components/Chipsets/AChipset.cpp \
    	src/Components/Chipsets/And.cpp \
    	src/Components/Chipsets/Not.cpp \
    	src/Components/Chipsets/Or.cpp \
    	src/Components/Chipsets/Xor.cpp \
    	src/Components/Chipsets/C4081.cpp \
    	src/Components/Chipsets/C4001.cpp \
    	src/Components/Chipsets/C4011.cpp \
    	src/Components/Chipsets/C4030.cpp \
    	src/Components/Chipsets/C4069.cpp \
    	src/Components/Chipsets/C4071.cpp \
		\
		src/Shell/Shell.cpp \
		\
		src/Circuit/Circuit.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDE_FLAGS = -I src

CXXFLAGS = -Wall -Wextra -Werror -g $(INCLUDE_FLAGS)

NAME = nanotekspice

GCC = g++

all: $(NAME)

.cpp.o:
	@echo "$(notdir $(CURDIR)): C++ '$<'"
	@$(GCC) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@$(GCC) -o $(NAME) $(OBJ) $(LIB_FLAGS)

.PHONY: all clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all