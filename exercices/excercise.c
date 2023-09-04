/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excercise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:02:15 by ihama             #+#    #+#             */
/*   Updated: 2023/09/03 16:42:04 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void*   routine(void *arg)
{

	int	i = 0;
	int j = (int) arg;
	while (i < 1000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	pthread_t th[4];
	int i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 5)
	{
		if (pthread_create(th + i, NULL, &routine, &i) != 0)
		{
			perror("failed to create thread");
			return (1);
		}
		printf("thread %d has started execution\n", i);
		sleep(1);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			return (2);
		}
		printf("thread %d has finished execution\n", i);
		i++;
		sleep(1);
	}
	pthread_mutex_destroy(&mutex);
	printf("number of mails: %d\n", mails);
	return (0);
}
