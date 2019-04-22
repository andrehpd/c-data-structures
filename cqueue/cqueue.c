/*
 * @brief
 * @par
 * COPYRIGHT NOTICE: (c) 2018 NEPEN
 * All rights reserved.
 */
/* Includes ------------------------------------------------------------------*/
#include "cqueue.h"
#include "string.h"
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Function Implementation -------------------------------------------------- */

void cqueue_init(Queue *q, uint8_t *queueBuffer, uint32_t queueSize) {
  q->end = 0x00;
  q->front = 0x00;
  q->data = queueBuffer;
  q->size = queueSize;
}

uint16_t cqueue_is_empty(Queue *q) {
  if (q->front == q->end)
    return 1;
  else
    return 0;
}

uint8_t *cqueue_add(Queue *q, uint8_t *data, uint8_t size) {
  uint16_t i = 0;

  for (i = 0; i < size; i++) {
    q->data[q->front] = data[i];
    q->front++;
    if (q->front == q->size) {
      q->front = 0;
    }
    if (q->front == q->end - 1) {
      break;
    }
  }
  return (uint8_t *)&q->data[q->end];
}

uint8_t *cqueue_remove(Queue *q, uint16_t *length) {
  uint8_t *ptr = NULL;
  if (q->end > q->front) {
    *length = q->size - q->end;
    ptr = (uint8_t *)&q->data[q->end];
    q->end = 0;
  } else if (q->end < q->front) {
    *length = q->front - q->end;
    ptr = (uint8_t *)&q->data[q->end];
    q->end = q->front;
  } else {
    *length = 0;
  }
  return ptr;
}
