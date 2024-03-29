# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ngerrets <ngerrets@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/15 14:47:03 by ngerrets      #+#    #+#                  #
#    Updated: 2021/09/23 10:40:23 by ngerrets      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# For now this is the default Makefile I use for C projects
# Manually edit:

FPS_MULTIPLIER := 1

NAME := fract-ol
COMPILE_FLAGS ?= -Wall -Wextra
LINKING_FLAGS ?= -Llib/get_next_line -lgnl
LIBRARIES ?=
SOURCE_DIRECTORY ?= src
HEADER_DIRECTORY ?= include
OBJECTS_DIRECTORY ?= objects
BINARIES_DIRECTORY ?= .

# Don't manually edit:
SOURCES :=
include sources.mk

HEADERS	:= $(shell find $(HEADER_DIRECTORY) -type f -name *.h)
INCLUDES := $(patsubst %,-I%,$(dir $(HEADERS)))
OBJECTS := $(patsubst %,$(OBJECTS_DIRECTORY)/%,$(SOURCES:.c=.o))
NAME := $(BINARIES_DIRECTORY)/$(NAME)

# OS specific rules
ifeq ($(shell uname),Darwin)
	MLXLIB := lib/mlx_mac
	LINKING_FLAGS += -Llib/mlx_mac -lmlx \
		-framework OpenGL -framework AppKit
	LIB := lib/mlx_mac/libmlx.dylib
else
	MLXLIB := lib/mlx_linux
	LINKING_FLAGS += -Llib/mlx_linux -lmlx -lXext -lX11 -lm
	LIB := lib/mlx_linux/*.a
endif

# Default make-rule. Compile and link files.
all: $(NAME)

# Link files
$(NAME): $(BINARIES_DIRECTORY) $(HEADERS) $(OBJECTS)
	@echo "\nBuilding dependencies..."
	@$(MAKE) dependencies
	@echo "\nLinking files..."
	@$(CC) $(OBJECTS) -o $(NAME) $(LINKING_FLAGS)
	@echo "Done!"

dependencies:
	@$(MAKE) -C lib/get_next_line
	@$(MAKE) -C $(MLXLIB)
	@cp $(LIB) .

# Create binaries directory
$(BINARIES_DIRECTORY):
	@mkdir -p $(BINARIES_DIRECTORY)

# Compile files
$(OBJECTS_DIRECTORY)/%.o: %.c $(HEADERS)
	@echo "Compiling: $<"
	@mkdir -p $(@D)
	@$(CC) -DFPS_MULTIPLIER=$(FPS_MULTIPLIER) $(COMPILE_FLAGS) $(INCLUDES) -c -o $@ $<

# Clean objects
clean: cleandeps
	@echo "Cleaning objects..."
	@rm -Rf $(OBJECTS_DIRECTORY)
	@echo "Objects cleaned."

cleandeps:
	@echo "Cleaning dependencies..."
	@$(MAKE) -C lib/get_next_line clean
	@$(MAKE) -C $(MLXLIB) clean

# Clean objects and binaries
fclean: clean
	@rm -f $(NAME)
	@rm -f *.a
	@rm -f *.dylib
	@echo "Binaries cleaned."

# Clean, recompile and relink project
re: fclean all

# Compile, link and run project
run: all
	@echo "Running..."
	@./$(NAME)

# Prints header and source files
print:
	@echo "---HEADERS: $(HEADERS)" | xargs -n1
	@echo "---SOURCES: $(SOURCES)" | xargs -n1

# In case of bonus
bonus: all

.PHONY: all dependencies clean cleandeps fclean re run print bonus