NAME			= libft.a

HEADERS_DIR		= ./includes/
SOURCES_DIR		= ./sources/

HEADERS_LIST	= libft.h 
SOURCES_LIST	=	ft_atoi.c \
			ft_calloc.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strcat.c \
			ft_strlcat.c \
			ft_strcpy.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strjoin_free.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_free_array.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstsize.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstlast.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_printf_numbers.c \
			ft_printf.c 

HEADERS			= ${addprefix ${HEADERS_DIR}, ${HEADERS_LIST}}
SOURCES			= ${addprefix ${SOURCES_DIR}, ${SOURCES_LIST}}
INCLUDES		= -I ${HEADERS_DIR}

OBJECTS_DIR		= ./objects/
OBJECTS_LIST	= ${patsubst %.c, %.o, ${SOURCES_LIST}}
OBJECTS			= ${addprefix ${OBJECTS_DIR}, ${OBJECTS_LIST}}


AR 				= ar rcs
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -c

all:			${NAME}

${NAME}:		${OBJECTS_DIR} ${OBJECTS}
				${AR} ${NAME} ${OBJECTS}

${OBJECTS_DIR}:
				mkdir -p ${OBJECTS_DIR}

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c ${HEADERS}
				${CC} ${CFLAGS} ${INCLUDES} $< -o $@

clean:
				rm -rf ${OBJECTS_DIR}

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all, clean, fclean, re
