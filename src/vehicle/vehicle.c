
#include "../traffic_light.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

void run_vehicle() {
  int shm_fd;
  LIGHT_STATE *shm_state;

  shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
  if (shm_fd == -1) {
    perror("shm_open");
    exit(1);
  }

  shm_state = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
  if (shm_state == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  while (1) {
    LIGHT_STATE current_state = *shm_state;
    if (current_state == GREEN) {
      printf("Vehicle is moving\n");
    } else {
      printf("Vehicle is stopped\n");
    }
    sleep(1);
  }

  munmap(shm_state, SHM_SIZE);
  close(shm_fd);
}

int main() {
  run_vehicle();
  return 0;
}
