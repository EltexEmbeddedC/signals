#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

void sig_handler(int sig_num);

int main(void) {
  struct sigaction handler;
  int ret;

  handler.sa_handler = sig_handler;
  ret = sigaction(SIGUSR1, &handler, NULL);

  if (ret < 0) {
    perror("Can't set signal handler!\n");
    exit(EXIT_FAILURE);
  }

  while(1) {
    sleep(1);
  }

  exit(EXIT_SUCCESS);
}

void sig_handler(int sig_num) {
  printf("Signal SIGUSR1 - %d\n", sig_num);
}
