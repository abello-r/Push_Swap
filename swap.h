#ifndef SWAP_H
# define SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./srcs/Libft/libft.h"
# include "./srcs/gnl/get_next_line_bonus.h"

# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define AZUL "\033[34m"
# define INV "\e[7m"
# define RESET "\033[0m"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

typedef struct s_global
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*head_a;
	t_stack		*head_b;
	int			len;
	int			i;
	int			aux;
}				t_global;

void		check_args(char **argv);
void		aux_check_args(char **argv, int i, int aux);
void		adn_control(t_global *g, char **argv);
int			adn_size(char **adn);
void		free_adn(char **adn);
int			fill_stack_a(t_global *g, int *numbers);
int			find_repeat_num(t_global *g);

// Utils

int			ft_error(int ret, char *error);
int			ft_draw_lst(t_stack *lst);
void		copy_stacks(t_global *g);
void		check_neg_sign(int argc, char **argv);
void		init_struct(t_global *g);

// Functions lst

t_stack		*ft_lstnew_stack(int content);
void		ft_lstadd_back_stack(t_stack **lst, t_stack *new);
int			ft_lstsize_stack(t_stack *lst);
void		ft_lstadd_front_stack(t_stack **head, t_stack *new);

// RULES

int			sa_rule(t_global *g);
int			sb_rule(t_global *g);
int			ss_rule(t_global *g);
int			pa_rule(t_global *g);
int			pb_rule(t_global *g);
int			ra_rule(t_global *g);
int			rb_rule(t_global *g);
int			rr_rule(t_global *g);
int			rra_rule(t_global *g);
int			rrb_rule(t_global *g);
int			rrr_rule(t_global *g);

// Read term 

void		read_term(t_global *g);
void		ok_and_ko(t_global *g);

// Push Swap

void		identify_quantity(t_global *g);
void		two_num(t_global *g);
void		three_num(t_global *g);
void		three_num_support(t_global *g, t_stack *t);

// Draw and execute rules in Push Swap

void		draw_sa_rule(t_global *g);
void		draw_sb_rule(t_global *g);
void		draw_ss_rule(t_global *g);
void		draw_ra_rule(t_global *g);
void		draw_rb_rule(t_global *g);
void		draw_pb_rule(t_global *g);
void		draw_pa_rule(t_global *g);
void		draw_rr_rule(t_global *g);
void		draw_rra_rule(t_global *g);
void		draw_rrb_rule(t_global *g);
void		draw_rrr_rule(t_global *g);
#endif
