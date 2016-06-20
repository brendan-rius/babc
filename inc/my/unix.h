/*
** unix.h for unix in /home/brendan/rendu/PSU_2014_my_select
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Dec 17 19:59:04 2014 Brendan Rius
** Last update Sat Jan 31 17:22:14 2015 Brendan Rius
*/

#ifndef UNIX_H_
# define UNIX_H_

# include <stdint.h>
# include "env.h"

struct termios;

/*
** Define the most useful color codes the ANSI way.
** Most of terminal emulator should support it
*/
# define ANSI_COLOR_RESET	"\x1b[0;0m"
# define ANSI_COLOR_BLACK	"\x1b[0;30m"
# define ANSI_COLOR_RED		"\x1b[0;31m"
# define ANSI_COLOR_GREEN	"\x1b[0;32m"
# define ANSI_COLOR_YELLOW	"\x1b[0;33m"
# define ANSI_COLOR_BLUE	"\x1b[0;34m"
# define ANSI_COLOR_MAGENTA	"\x1b[0;35m"
# define ANSI_COLOR_CYAN	"\x1b[0;36m"
# define ANSI_COLOR_LGRAY	"\x1b[0;37m"
# define ANSI_COLOR_DGRAY	"\x1b[1;30m"
# define ANSI_COLOR_LRED	"\x1b[1;31m"
# define ANSI_COLOR_LGREEN	"\x1b[1;32m"
# define ANSI_COLOR_LYELLOW	"\x1b[1;33m"
# define ANSI_COLOR_LBLUE	"\x1b[1;34m"
# define ANSI_COLOR_LPURPLE	"\x1b[1;35m"
# define ANSI_COLOR_LCYAN	"\x1b[1;36m"
# define ANSI_COLOR_WHITE	"\x1b[1;37m"

/*
** Define some useful termcaps
*/
# define TC_STANDOUT_ON		"so"
# define TC_STANDOUT_OFF	"se"
# define TC_UNDERLINE_ON	"us"
# define TC_UNDERLINE_OFF	"ue"
# define TC_CLS			"cl"
# define TC_HIDE_CURSOR		"vi"
# define TC_NORMAL_CURSOR	"ve"
# define TC_ENHANCE_CURSOR	"vs"

/*
** Keycodes
*/
typedef int64_t t_key;

# define K_CTRL_MA	1L
# define K_CTRL_MB	2L
# define K_CTRL_MC	3L
# define K_CTRL_MD	4L
# define K_CTRL_ME	5L
# define K_CTRL_MF	6L
# define K_CTRL_MG	7L
# define K_CTRL_MH	8L
# define K_CTRL_MI	9L
# define K_CTRL_MJ	10L
# define K_CTRL_MK	11L
# define K_CTRL_ML	12L
# define K_CTRL_MM	13L
# define K_CTRL_MN	14L
# define K_CTRL_MO	15L
# define K_CTRL_MP	16L
# define K_CTRL_MQ	17L
# define K_CTRL_MR	18L
# define K_CTRL_MS	19L
# define K_CTRL_MT	20L
# define K_CTRL_MU	21L
# define K_CTRL_MV	22L
# define K_CTRL_MW	23L
# define K_CTRL_MX	24L
# define K_CTRL_MY	25L
# define K_CTRL_MZ	26L
# define K_F2		5328667L
# define K_F3		5394203L
# define K_F4		5459739L
# define K_F5		542058306331L
# define K_F6		542091860763L
# define K_F7		542108637979L
# define K_F8		542125415195L
# define K_F9		541974485787L
# define K_F10		541991263003L
# define K_F11		5328667L
# define K_LEFT		4479771L
# define K_UP		4283163L
# define K_RIGHT	4414235L
# define K_DOWN		4348699L
# define K_PGDOWN	2117491483L
# define K_PGUP		2117425947L
# define K_PGEND	4607771L
# define K_PGSTART	4738843L
# define K_TAB		9L
# define K_SPACE	32L
# define K_ENTER	10L
# define K_ESC		27L
# define K_BACKSPACE	127L
# define K_DEL		2117294875L
# define K_MA		97L
# define K_MB		98L
# define K_MC		99L
# define K_MD		100L
# define K_ME		101L
# define K_MF		102L
# define K_MG		103L
# define K_MH		104L
# define K_MI		105L
# define K_MJ		106L
# define K_MK		107L
# define K_ML		108L
# define K_MM		109L
# define K_MN		110L
# define K_MO		111L
# define K_MP		112L
# define K_MQ		113L
# define K_MR		114L
# define K_MS		115L
# define K_MT		116L
# define K_MU		117L
# define K_MV		118L
# define K_MW		119L
# define K_MX		120L
# define K_MY		121L
# define K_MZ		122L
# define K_A		65L
# define K_B		66L
# define K_C		67L
# define K_D		68L
# define K_E		69L
# define K_F		70L
# define K_G		71L
# define K_H		72L
# define K_I		73L
# define K_J		74L
# define K_K		75L
# define K_L		76L
# define K_M		77L
# define K_N		78L
# define K_O		79L
# define K_P		80L
# define K_Q		81L
# define K_R		82L
# define K_S		83L
# define K_T		84L
# define K_U		85L
# define K_V		86L
# define K_W		87L
# define K_X		88L
# define K_Y		89L
# define K_Z		9L

/*
** Search for the environment variable "s".
** If it is found, it returns its value, otherwise, it returns
** NULL
*/
char	*my_real_getenv(char *s);

/*
** Init the terminal with a few useful capabilities and returns it.
** Returns NULL in case of failure.
*/
struct termios	*init_term();

/*
** Restore the termical initialized wodth init_term(). Returns
** -1 on failure, 0 otherwise
*/
int	restore_term(struct termios *term);

bool	key_is_arrow(t_key key);
bool	key_is_textual(t_key key);

#endif /* !UNIX_H_ */
