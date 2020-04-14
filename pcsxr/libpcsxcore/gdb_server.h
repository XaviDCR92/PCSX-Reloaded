#ifndef GDB_SERVER_H
#define GDB_SERVER_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

int gdb_server_init(void);
void gdb_server_update(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GDB_SERVER_H */
