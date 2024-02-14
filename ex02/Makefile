CC = c++
CFLAGS = -Wall -Wextra -Werror -ggdb -std=c++98
RM = rm -f

NAME = tests
LOGFILE = new.log

SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

INCS = Account.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LOGFILE)

test:
	@./$(NAME) > $(LOGFILE)
	@paste 19920104_091532.log $(LOGFILE) | \
	awk '{print $$2 "\t" $$4 ($$2 == $$4 ? "\tOK": "\tERROR")} ' | column -t

re: fclean all
