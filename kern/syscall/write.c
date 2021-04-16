#include <types.h>
#include <syscall.h>
#include <lib.h>

int sys_write(int32_t *retval, int fd, void *buf, size_t nbyte) {
  KASSERT(fd == 1); // support stdout only
  for (size_t i = nbyte; i > 0; i--, buf++)
    putch(*(char *)buf);
  *retval = nbyte;
  return 0;
}