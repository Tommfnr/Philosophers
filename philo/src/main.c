/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:54 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/05 17:28:19 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


void *print_message(void *arg) {
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
}