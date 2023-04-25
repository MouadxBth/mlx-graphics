# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Files.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 23:45:12 by mbouthai          #+#    #+#              #
#    Updated: 2023/04/25 17:53:00 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Headers/Includes

HEADERS_DIR	:= inc

#HEADERS	=
#HEADERS	:= $(addprefix $(HEADERS_DIR)/,$(HEADERS))

# Sources

SRCS_DIR	:= src

COLOR_DIR	:= color
COLOR_SRCS	= color_utils.c color.c
COLOR_SRCS	:= $(addprefix $(COLOR_DIR)/,$(COLOR_SRCS))

WINDOW_DIR	:= window
WINDOW_SRCS	= image_utils.c image.c window.c
WINDOW_SRCS	:= $(addprefix $(WINDOW_DIR)/,$(WINDOW_SRCS))

RENDERER_DIR	:= renderer
RENDERER_SRCS	= renderer_utils.c renderer.c
RENDERER_SRCS	:= $(addprefix $(RENDERER_DIR)/,$(RENDERER_SRCS))


SOURCES	= main.c \
	$(COLOR_SRCS) \
	$(WINDOW_SRCS) \
	$(RENDERER_SRCS) \

SOURCES	:= $(addprefix $(SRCS_DIR)/,$(SOURCES))

# Objects/Output files

OBJS_DIR	= obj
#OBJECTS	:= $(patsubst %,%.o,$(addprefix $(OBJS_DIR)/,$(notdir $(SOURCES))))
OBJECTS	:= $(patsubst $(SRCS_DIR)/%,$(OBJS_DIR)/%.o,$(SOURCES))

# Dependencies

DEPS_DIR	= dep
DEPENDENCIES	:= $(patsubst %,%.d,$(addprefix $(DEPS_DIR)/,$(notdir $(SOURCES))))

DIRS	= $(COLOR_DIR) \
	$(WINDOW_DIR) \
	$(RENDERER_DIR) \

DIRS	:= $(addprefix $(OBJS_DIR)/,$(DIRS))
