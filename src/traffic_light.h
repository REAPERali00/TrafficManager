#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <stdio.h>

#define SHM_NAME "/traffic_light"
#define SHM_SIZE sizeof(LIGHT_STATE)

typedef enum {
  GREEN,
  YELLOW,
  RED,
} LIGHT_STATE;

static const int wait_time[] = {
    10,
    5,
    10,
};

typedef struct Traffic_light {
  int state;
  int duration;
} Traffic_light;

void change_state(Traffic_light *light);
char *print_state(Traffic_light *light);
void queue_traffic();

#endif // !TRAFFIC_LIGHT_H
