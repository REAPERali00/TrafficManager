#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <stdio.h>

enum LIGHT_STATE {
  GREEN,
  YELLOW,
  RED,
};

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
void queue_traffic(Traffic_light *light);

void run();

#endif // !TRAFFIC_LIGHT_H
