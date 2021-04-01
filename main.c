/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:17:33 by pfile             #+#    #+#             */
/*   Updated: 2020/10/18 22:58:54 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_read_started;
int		g_sigquit;
int		g_sigint;

char	**init_env(char **old, char *str)
{
	int		size;
	int		i;
	char	**env;

	size = 0;
	while (old[size])
		size++;
	if (str)
		size++;
	if (!(env = ft_calloc(size + 1, sizeof(char *))))
		error_standart(NULL);
	i = 0;
	while (old[i])
	{
		if (!(env[i] = ft_strdup(old[i])))
			error_standart(NULL);
		i++;
	}
	if (str)
		if (!(env[i++] = ft_strdup(str)))
			error_standart(NULL);
	env[i] = NULL;
	return (env);
}

int		main(int ac, char **av, char **envp)
{
	t_data	data;

	signal(SIGQUIT, (void *)ft_sigquit);
	signal(SIGINT, (void *)ft_sigint);
	data.error_code = 0;
	if (!(data.envp = init_env(envp, NULL)))
		error_standart(NULL);
	if (!(data.env_var = init_env(envp, NULL)))
		error_standart(NULL);
	get_standart(&data);
	return (0);
}
