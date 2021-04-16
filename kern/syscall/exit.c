#include <types.h>
#include <syscall.h>
#include <lib.h>
#include <current.h>
#include <proc.h>
#include <addrspace.h>

int sys_exit(int status) {
  curthread->t_proc->exitcode = status;
  as_destroy(curthread->t_proc->p_addrspace);
  thread_exit();

  // should never reach this point
  KASSERT(0);
  return 0;
}