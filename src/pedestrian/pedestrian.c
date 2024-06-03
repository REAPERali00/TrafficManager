
#include "../traffic_light.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_NAME "/traffic_light_shm"
#define SHM_SIZE sizeof(LIGHT_STATE)

void run_pedestrian() {
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
    if (current_state == RED) {
      printf("Pedestrian is crossing\n");
    } else {
      printf("Pedestrian is waiting\n");
    }
    sleep(1);
  }

  munmap(shm_state, SHM_SIZE);
  close(shm_fd);
}

int main() {
  run_pedestrian();
  return 0;
}
