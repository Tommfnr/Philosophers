/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:54 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 11:25:43 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/* void *print_message(void *arg) {
    char *message = (char *)arg;
    printf("Message du thread : %s\n", message);
    return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thread;
    char *message = "Bonjour depuis le thread !";

	pthread_create(&thread, NULL, print_message, message);
    pthread_join(thread, NULL); // Attendre la fin du thread
	

	printf(GREEN"Working\n"RESET);
	printf("argc: %d, name: %s", argc, argv[0]);
	return (0);
} */




// void init_data(t_data data, int argc, char **argv)
// {
// 	data.argc = argc;
// 	data.argv = argv;
// }

int main(int argc, char **argv)
{
	t_data data;
	
	data.argc = argc;
	data.argv = argv;
	parsing(data);
	return (0);
}