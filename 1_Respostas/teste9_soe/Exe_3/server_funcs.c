#include "server_funcs.h"

char msg1[100] = "SERVIDOR: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.";
char msg2[100] = "SERVIDOR: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...";

int print_client_message(int client_socket)
{
	int end_server_ok;
	char *text;
	recv(client_socket, text, 100, 0);
	sleep(1);
	send(client_socket, msg1, 100,0);
	sleep(1);
	recv(client_socket, text, 100, 0);
	sleep(1);
	send(client_socket, msg2, 100,0);

	return end_server_ok=1;
}


void end_server(int signum)
{
	fprintf(stderr,"Fechando servidor local\n");
	unlink(socket_name);
	close(socket_id);
	exit(0);
}
