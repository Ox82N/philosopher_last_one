NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -rf

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(wildcard $(INC_DIR)/*.h)
SRCS = $(wildcard $(SRC_DIR)/*.c)
vpath %.c $(SRC_DIR)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))


#                                   COLOR                                      

CL_BOLD	 = \e[1m
CL_DIM	= \e[2m
CL_UDLINE = \e[4m
RED =  \e[31m


NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

LF = \e[1K\r$(NO_COLOR)
CRLF= \n$(LF)

all : $(NAME)
	@echo "\033[95m██████╗░██╗░░██╗██╗██╗░░░░░░█████╗░░██████╗░█████╗░██████╗░██╗░░██╗███████╗██████╗░░██████╗"
	@echo "██╔══██╗██║░░██║██║██║░░░░░██╔══██╗██╔════╝██╔══██╗██╔══██╗██║░░██║██╔════╝██╔══██╗██╔════╝"
	@echo "██████╔╝███████║██║██║░░░░░██║░░██║╚█████╗░██║░░██║██████╔╝███████║█████╗░░██████╔╝╚█████╗░"
	@echo "██╔═══╝░██╔══██║██║██║░░░░░██║░░██║░╚═══██╗██║░░██║██╔═══╝░██╔══██║██╔══╝░░██╔══██╗░╚═══██╗"
	@echo "██║░░░░░██║░░██║██║███████╗╚█████╔╝██████╔╝╚█████╔╝██║░░░░░██║░░██║███████╗██║░░██║██████╔╝"
	@echo "╚═╝░░░░░╚═╝░░╚═╝╚═╝╚══════╝░╚════╝░╚═════╝░░╚════╝░╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝╚═════╝░  \033[0m \033[92mBy : Obenjair\033[0m"

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@printf "$(LF) $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'s Object files...\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "$(LF) $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)\n"

re : fclean all

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(LIBFT_FILE) | $(OBJ_DIR)
	@$(CC)  -I $(INC_DIR) -c $< -o $@
	@printf "$(LF) $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
	@printf "$(LF) $(FG_TEXT)Successfully Created $@'s Object files $(FG_TEXT)! ✅"
	@printf "$(CRLF) $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@$(FG_TEXT)! ✅\n"
	@$(CC)  -I $(INC_DIR) $(CLIBFLAGS) $(LIBFT_FLAGS) $(OBJS) -o $@
	@printf "$(LF) $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)! ✅\n$(NO_COLOR)"


.PHONY: all clean fclean re bonus