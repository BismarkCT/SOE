#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main ()
{
	int mensagem = 1;
	int socket_id;
	struct sockaddr name;

	mensagem = 1;
	while(mensagem <= 10)
	{
		socket_id = socket(PF_LOCAL, SOCK_STREAM,0);
		name.sa_family = AF_LOCAL;
		strcpy(name.sa_data, "/tmp/socket2");
		
		connect(socket_id, &name, sizeof(name));
		write(socket_id, &mensagem, sizeof(int));
		close(socket_id);
		
		mensagem++;
		sleep(1);
	}
	return 0;
}