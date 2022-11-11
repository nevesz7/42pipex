NAME			= pipex

HEADERS_DIR 	= ./includes/
SOURCES_DIR		= ./sources/

HEADERS_LIST	= pipex.h
SOURCES_LIST	= pipex.c \
				read.c \
				free.c \
				split.c \
				check.c

HEADERS			= ${addprefix ${HEADERS_DIR}, ${HEADERS_LIST}}
SOURCES			= ${addprefix ${SOURCES_DIR}, ${SOURCES_LIST}}
INCLUDES		= -I ${HEADERS_DIR} -I ${LIBFT_HEADERS}

OBJECTS_DIR		= ./objects/
OBJECTS_LIST	= ${patsubst %.c, %.o, ${SOURCES_LIST}}
OBJECTS			= ${addprefix ${OBJECTS_DIR}, ${OBJECTS_LIST}}

LIBFT			= ${LIBFT_DIR}libft.a
LIBFT_DIR		= ./libft/
LIBFT_HEADERS	= ${LIBFT_DIR}includes/

CC				= cc
CFLAGS			= -Wall -Werror -Wextra 

RM 				= rm -f

all:			${NAME}
				@echo Everything went well!

libft:			${LIBFT}

${NAME}:		${LIBFT} ${OBJECTS_DIR} ${OBJECTS}
			${CC} ${CFLAGS} ${OBJECTS} ${LIBFT} ${INCLUDES} -o ${NAME}

${OBJECTS_DIR}:
			mkdir -p ${OBJECTS_DIR}
			@echo objects folder has been created!
${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c ${HEADERS}
			${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@

${LIBFT}:
			make -sC ${LIBFT_DIR}
			@echo libft has been compiled!

clean:
			make -sC ${LIBFT_DIR} clean
			rm -rf ${OBJECTS_DIR}
			rm -rf ${OBJECTS_DIRB}

fclean:		clean
			${RM} ${LIBFT}
			${RM} ${NAME}

re:			fclean all

HEADERS_DIRB	= ./includesb/
SOURCES_DIRB	= ./sourcesb/

HEADERS_LISTB	= pipex_bonus.h

SOURCES_LISTB	= pipex_bonus.c \
				fd_bonus.c \
				read_bonus.c \
				free_bonus.c \
				split_bonus.c \
				check_bonus.c \

HEADERSB		= ${addprefix ${HEADERS_DIRB}, ${HEADERS_LISTB}}
SOURCESB 		= ${addprefix ${SOURCES_DIRB}, ${SOURCES_LISTB}}

INCLUDESB		= -I ${HEADERS_DIRB} -I ${LIBFT_HEADERS}

OBJECTS_DIRB	= ./bonus/
OBJECTS_LISTB	= ${patsubst %.c, %.o, ${SOURCES_LISTB}}
OBJECTSB		= ${addprefix ${OBJECTS_DIRB}, ${OBJECTS_LISTB}}

${OBJECTS_DIRB}:
			mkdir -p ${OBJECTS_DIRB}
			@echo bonus folder has been created!
${OBJECTS_DIRB}%.o : ${SOURCES_DIRB}%.c ${HEADERSB}
			${CC} ${CFLAGS} -c ${INCLUDESB} $< -o $@

bonus:			${LIBFT} ${OBJECTS_DIRB} ${OBJECTSB}
			${CC} ${CFLAGS} ${OBJECTSB} ${LIBFT} ${INCLUDESB} -o ${NAME}

rebonus:	fclean bonus

.PHONY:		all, clean, fclean, re