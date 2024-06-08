CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/Users/$$USER/Desktop/fract-ol/fractol/MLX42/include -fsanitize=address
LDFLAGS = -L/Users/$$USER/Desktop/fract-ol/fractol/MLX42/build -lmlx42 -ldl -lglfw -pthread

SRCS = ft_atof.c init_fractol.c  julia.c libft.c main.c  mandelbrot.c\
        mov_utils.c movement.c
       
OBJS = $(SRCS:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
