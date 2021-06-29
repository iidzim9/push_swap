/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:14:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/29 13:27:19 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	print_err(char *str)
{	
	write(2, "Error\n", 6);
	free(str);
	exit (1);
}

int	get_next_inst(t_all *x)
{
	char	*buff;
	char	*str;
	char	*temp;
	int		new;

	new = 1;
	while (get_next_line(&buff) > 0)
	{
		if (new)
			str = ft_strdup("");
		if (buff[0] != '\0')
		{
			new = 0;
			temp = str;
			str = ft_strjoin(str, &buff[0]);
			free (temp);
			if (valid_instruction(str))
				exec_op(str, x, 0);
		}
		else
			print_err(str);
		new = 1;
		free(str);
		free(buff);
	}
	if (buff[0])
	{
		if (valid_instruction(buff))
			exec_op(buff, x, 0);
		else
			print_err(buff);
	}
	free(buff);
	return (0);
}

// int	helper(t_all *x, char *str, char *buff, int i)
// {
// 	char	*temp;

// 	if (i == 0)
// 	{
// 		if (str[0])
// 		{
// 			if (valid_instruction(str))
// 				exec_op(str, x, 0);
// 			else
// 				print_err(str);
// 		}
// 		free(str);
// 	}
// 	if (i == 1)
// 	{
// 		temp = str;
// 		str = ft_strjoin(str, buff);
// 		free (temp);
// 		if (valid_instruction(str))
// 			exec_op(str, x, 0);
// 	}
// 	return (i);
// }

// int	get_next_inst(t_all *x)
// {
// 	char	*buff;
// 	char	*str;
// 	int		new;

// 	new = 1;
// 	while (get_next_line(&buff) > 0)
// 	{
// 		if (new)
// 			str = ft_strdup("");
// 		if (buff[0] != '\0')
// 		{
// 			new = 0;
// 			helper(x, str, &buff[0], 1);
// 		}
// 		else
// 			print_err(str);
// 		new = 1;
// 		free(str);
// 		free(buff);
// 	}
// 	return (helper(x, buff, NULL, 0));
// }

int	main(int argc, char **argv)
{
	t_all	x;

	if (argc >= 2)
	{
		if (!valid_nbr(argc, argv, &x))
			get_next_inst(&x);
		if (sorted(&x))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_freelst(x.a);
		ft_freelst(x.b);
	}
	else if (argc == 1)
		return (0);
	else
		write(2, "Error\n", 6);
	system("leaks checker");
	return (0);
}
