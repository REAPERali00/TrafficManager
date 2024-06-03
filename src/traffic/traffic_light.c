#include "../traffic_light.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

void change_state(Traffic_light *light) {
  switch (light->state) {
  case RED:
    light->state = GREEN;
    break;
  case GREEN:
    light->state = YELLOW;
    break;
  case YELLOW:
    light->state = RED;
    break;
  }
  light->duration = wait_time[light->state];
}

char *print_state(Traffic_light *light) {
  static char buffer[100];
  sprintf(buffer, "Light is %s\n",
          light->state == RED ? "RED"
                              : (light->state == YELLOW ? "YELLOW" : "GREEN"));
  return buffer;
}

void queue_traffic() {
  int shm_fd;
  LIGHT_STATE *shm_state;
  if (shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666) == -1) {
    perror("shm_open");
    exit(EXIT_FAILURE);
  }
  if (ftruncate(shm_fd, SHM_SIZE) == -1) {
    perror("shm_open");
    exit(EXIT_FAILURE);
  }

  shm_state = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  if (shm_state == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  Traffic_light light = {GREEN, wait_time[GREEN]};

  while (1) {
    printf("%s", print_state(&light));
    *shm_state = light.state;
    sleep(light.duration);
    change_state(&light);
  }

  munmap(shm_state, SHM_SIZE);
  close(shm_fd);
  shm_unlink(SHM_NAME);
}

int main() {
  queue_traffic();
  return 0;
}
