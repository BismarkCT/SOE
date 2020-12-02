#include "server_funcs.h"

int print_client_message(int client_socket)
{
	int mensagem, end_server_ok;
	read(client_socket, &mensagem, sizeof(int));
	fprintf(stderr,"%d\n", mensagem);
	end_server_ok = 0;
	if(mensagem == 10)
		end_server_ok = 1;
	return end_server_ok;
}

void end_server(int signum)
{
	fprintf(stderr,"Fechando servidor local\n");
	unlink(socket_name);
	close(socket_id);
	exit(0);
}
