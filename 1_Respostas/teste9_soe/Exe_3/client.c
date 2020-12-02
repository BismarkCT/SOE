#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main ()
{
	char buffer[100];
	char msg1[]="CLIENTE: Pai, qual é a verdadeira essência da sabedoria?";
	char msg2[]="CLIENTE: Mas até uma criança de três anos sabe disso!";
	int socket_id;
	struct sockaddr name;

		socket_id = socket(PF_LOCAL, SOCK_STREAM,0);
		name.sa_family = AF_LOCAL;
		strcpy(name.sa_data, "/tmp/socket3");
		
		connect(socket_id, &name, sizeof(name));
		send(socket_id, msg1, 100, 0);
		printf("%s\n", msg1);
		sleep(1);

		recv(socket_id, buffer, 100, 0);
		printf("%s\n", buffer);
		sleep(1);
		
		send(socket_id, msg2, 100, 0);
		printf("%s\n", msg2);
		sleep(1);

		recv(socket_id, buffer, 100, 0);
		printf("%s\n", buffer);
		close(socket_id);
		
	return 0;
}