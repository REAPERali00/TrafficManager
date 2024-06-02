# Traffic Manager

- Task: Design a traffic management system using real time embedded system to manage pedestrian, turning traffic, and through traffic at an intersection.

- Code snippets:

```c

Teachers Note:

This code uses queue variable types to send information from one task to another.
The info is copied onto a QueueHandle_t variable type. One task sends data onto the queue, the other task receives the data off the queue. If the queue is full, the task calling xQueueSend() goes into suspended mode.
If the queue is empty, the task calling xTaskReceive() goes into suspension mode.


Code Given:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

// global queue variable
QueueHandle_t queue;

void listenForHTTP(void params){

    int count = 0; // added

    while(true){
        count++;
        printf("received http message\n");
        long ret = xQueueSend(queue, &count, 1000 / portTICK_PERIOD_MS);
        if (ret)
        {
            printf("message sent to queue.\n");
        }
        else
        {
            printf("failed to add message,\n");
        }
        printf("processed http message\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void task1(voidparams){

    while(true)
    {
        int intRx;
        if (xQueueReceive(queue, &intRx, 5000 / portTICK_PERIOD_MS))
        {
            printf("Doing something with http %d\n", intRx);
        }
    }

}


void app_main(void)
{
    queue = xQueueCreate(3, sizeof(int));
    xTaskCreate(&listenForHTTP, "get http", 2048, NULL, 1, NULL);
    xTaskCreate(&task1, "do something with HTTP", 2048, NULL, 2, NULL);
}

```
