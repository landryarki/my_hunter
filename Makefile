##
## EPITECH PROJECT, 2022
## B-CPE-100-NAN-1-1-cpoolday05-landry.gigant
## File description:
## description
##

SRC		=	src/debug_mode.c		\
			src/destroy_game.c		\
			src/display_text.c		\
			src/gameover.c			\
			src/history.c			\
			src/main.c				\
			src/manage_event.c		\
			src/manage_time.c		\
			src/my_put_nbr.c		\
			src/play_scene.c		\
			src/pseudo.c			\
			src/save_score.c		\
			src/set_game.c			\
			src/set_menu.c			\
			src/set_rect.c			\
			src/set_sprite.c

NAME	=	my_hunter

CFLAGS = -W -Wall -Wextra -Wshadow

CSFMLFLAGS = -lcsfml-window -lcsfml-graphics -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME) $(CFLAGS) $(CSFMLFLAGS)
	touch save.txt

clean:

fclean: clean
	rm -f save.txt
	rm -f $(NAME)

re: fclean all
