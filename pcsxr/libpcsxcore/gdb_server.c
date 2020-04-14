#include "gdb_server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

static int fd;

int gdb_server_init(void)
{
    fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd != -1)
    {
        enum
        {
            SERVER_PORT = 3333
        };

        struct sockaddr_in addr = {0};

        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(SERVER_PORT);

        if (!bind(fd, (const struct sockaddr *)&addr, sizeof addr))
        {
            if (!listen(fd, 1))
            {
                printf("Listening to GDB connections on port %d\n", SERVER_PORT);
                return 0;
            }
        }
    }

    return errno;
}

void gdb_server_update(void)
{
    if (fd)
    {
        const int client = accept(fd, NULL, NULL);

        printf("Incoming connection from GDB server\n");
    }
}
