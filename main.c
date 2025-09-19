/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:56:30 by timatias          #+#    #+#             */
/*   Updated: 2025/09/19 00:54:18 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>

#define print(ms) std::cout << ms << std::end;

int main(int ac, char **av)
{
	int i = 0;
	if (ac < 2)
	{
		std::cout << "Numero de argumentos invalidos" << std::endl;
		return (1);
	}
	while (av[1][i])
	{
		if (av[1][i] >= 65 && av[1][i] <= 90)
			av[1][i] += 32;
		i++;
	}
	std::cout << av << std::endl;
    return 0;
}
