# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Utilities.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 00:46:19 by mbouthai          #+#    #+#              #
#    Updated: 2023/02/13 01:26:50 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD	:=\033[1m

RESET	:=\033[0m

RED	:=\033[91m

GREEN	:=\033[92m

CYAN	:=\033[96m

define	colorize = 
	@echo "\n$(1)$(2)$(RESET)\n"
endef
