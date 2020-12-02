#include "server_funcs.h"

int main ()
{
	struct sockaddr socket_struct;
	
    signal(SIGINT, end_server);
	
    socket_id = socket(PF_LOCAL, SOCK_STREAM, 0);
	socket_struct.sa_family = AF_LOCAL;
	strcpy(socket_struct.sa_data, "/tmp/socket3");
	
    bind(socket_id, &socket_struct, sizeof(socket_struct));
	listen(socket_id, 10);
	while(1)
	{
		struct sockaddr cliente;
		int socket_id_cliente, end_server_ok;
		socklen_t cliente_len;

		socket_id_cliente = accept(socket_id, &cliente, &cliente_len);
		end_server_ok = print_client_message(socket_id_cliente);
		close(socket_id_cliente);
		
        if(end_server_ok)
			end_server(0);
	}
	return 0;
}