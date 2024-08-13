#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

int main(void) {
  sigset_t set;
  int ret, sig_num;

  sigemptyset(&set);
  sigaddset(&set, SIGUSR1);
  ret = sigprocmask(SIG_BLOCK, &set, NULL);

  if (ret < 0) {
    perror("Can't set signal handler!\n");
    exit(EXIT_FAILURE);
  }

  while(1) {
    sigwait(&set, &sig_num);
    printf("Sig number %d\n", sig_num);
  }
  
  exit(EXIT_SUCCESS);
}
