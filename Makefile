##
## Makefile for Makefile in /home/rius_b/rendu/Piscine_C_J11/lib/my
##
## Made by brendan rius
## Login   <rius_b@epitech.net>
##
## Started on  Mon Oct 20 08:51:07 2014 brendan rius
## Last update Sun May 24 00:09:16 2015 Brendan Rius
##

CP	= cp
CFLAGS	+= -Wextra -Wall
CFLAGS	+= -pedantic
CFLAGS	+= -std=c99
CFLAGS	+= -Wno-unused-result
CFLAGS	+= -I ./inc/

NAME	= libmy

SRC_DIR	= src

SRCS_BTREES	= $(SRC_DIR)/btrees/destroy.c \
		$(SRC_DIR)/btrees/get.c \
		$(SRC_DIR)/btrees/get_tree.c \
		$(SRC_DIR)/btrees/init.c \
		$(SRC_DIR)/btrees/new.c \
		$(SRC_DIR)/btrees/set.c \
		$(SRC_DIR)/btrees/set_tree.c \
		$(SRC_DIR)/btrees/root.c \
		$(SRC_DIR)/btrees/iterator_dfr.c \
		$(SRC_DIR)/btrees/iterator_dfl.c

SRCS_VECTOR	= $(SRC_DIR)/vector/destroy.c \
		$(SRC_DIR)/vector/empty.c \
		$(SRC_DIR)/vector/filter.c \
		$(SRC_DIR)/vector/foreach.c \
		$(SRC_DIR)/vector/from.c \
		$(SRC_DIR)/vector/init.c \
		$(SRC_DIR)/vector/map.c \
		$(SRC_DIR)/vector/new.c \
		$(SRC_DIR)/vector/pop.c \
		$(SRC_DIR)/vector/push.c \
		$(SRC_DIR)/vector/last.c \
		$(SRC_DIR)/vector/iterator.c \
		$(SRC_DIR)/vector/serialize.c

SRCS_DICT	= $(SRC_DIR)/dictionnary/dictionnary.c \
		$(SRC_DIR)/dictionnary/dictionnary_utils.c \
		$(SRC_DIR)/dictionnary/dictionnary_get_entries.c \
		$(SRC_DIR)/dictionnary/dictionnary_length.c

SRCS_HTABLE	= $(SRC_DIR)/hashtable/hashtable.c \
		$(SRC_DIR)/hashtable/ht_hash.c \
		$(SRC_DIR)/hashtable/ht_new.c \
		$(SRC_DIR)/hashtable/ht_dict_set.c \
		$(SRC_DIR)/hashtable/ht_dict_get.c \
		$(SRC_DIR)/hashtable/ht_dict_remove.c \
		$(SRC_DIR)/hashtable/ht_dict_destroy.c \
		$(SRC_DIR)/hashtable/ht_dict_get_entries.c \
		$(SRC_DIR)/hashtable/ht_dict_length.c \
		$(SRC_DIR)/hashtable/ht_hash_string.c

SRCS_LLIST	= $(SRC_DIR)/llist/llist_add.c \
		$(SRC_DIR)/llist/llist_destroy.c \
		$(SRC_DIR)/llist/llist_new.c \
		$(SRC_DIR)/llist/llist_remove.c \
		$(SRC_DIR)/llist/llist_replace.c \
		$(SRC_DIR)/llist/llist_search.c \
		$(SRC_DIR)/llist/llist_toarray.c \
		$(SRC_DIR)/llist/llist_nget.c \
		$(SRC_DIR)/llist/llist_napply.c \
		$(SRC_DIR)/llist/llist_nremove.c \
		$(SRC_DIR)/llist/llist_apply.c \
		$(SRC_DIR)/llist/llist_patch.c \
		$(SRC_DIR)/llist/llist_dict.c \
		$(SRC_DIR)/llist/llist_dict_get_entries.c \
		$(SRC_DIR)/llist/llist_dict_length.c \
		$(SRC_DIR)/llist/llist_iterator_ltr.c \
		$(SRC_DIR)/llist/llist_iterator_rtl.c

SRCS_STRING	= $(SRC_DIR)/string/new.c \
		$(SRC_DIR)/string/init.c \
		$(SRC_DIR)/string/destroy.c \
		$(SRC_DIR)/string/cat.c \
		$(SRC_DIR)/string/contains.c \
		$(SRC_DIR)/string/replace.c \
		$(SRC_DIR)/string/push.c \
		$(SRC_DIR)/string/split.c \
		$(SRC_DIR)/string/delete.c

SRCS	+= $(SRCS_LLIST)
SRCS	+= $(SRCS_DICT)
SRCS	+= $(SRCS_HTABLE)
SRCS	+= $(SRCS_VECTOR)
SRCS	+= $(SRCS_BTREES)
SRCS	+= $(SRCS_STRING)
SRCS	+= $(SRC_DIR)/get_next_line.c

OBJS	= $(SRCS:.c=.o)

all: link
	$(MAKE) ranlib
	$(MAKE) copylib

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

link: $(OBJS)
	ar rc $(NAME).a $(OBJS)

ranlib:
	ranlib $(NAME).a

copylib:
	$(CP) $(NAME).a ../$(NAME).a

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME).a

re: fclean
	$(MAKE) -j all
