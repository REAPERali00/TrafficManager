#include "traffic_light.h"
#include <stdio.h>

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

void queue_traffic(Traffic_light *light) {}

void run() {
  Traffic_light light = {GREEN, 10};
  change_state(&light);
  printf("%s", print_state(&light));
  change_state(&light);
  printf("%s", print_state(&light));
  change_state(&light);
  printf("%s", print_state(&light));
}
