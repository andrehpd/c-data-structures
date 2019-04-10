/*
 * @brief
 * @par
 * COPYRIGHT NOTICE: (c) 2018 NEPEN
 * All rights reserved.
 */
#ifndef CQUEUE_H
#define CQUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Public define ------------------------------------------------------------*/
/* Public macro -------------------------------------------------------------*/
/* Public typedef -----------------------------------------------------------*/
typedef struct {
  uint8_t *data;
  uint16_t front;
  uint16_t end;
  uint16_t size;
} queue_t;
/* Public variables ---------------------------------------------------------*/
/* Public function prototypes -----------------------------------------------*/
/* Exported functions -------------------------------------------------------*/
void CQUEUE_Init(queue_t *q, uint8_t *queueBuffer, uint32_t queueSize);
uint16_t CQUEUE_IsEmpty(queue_t *q);
uint8_t *CQUEUE_Add(queue_t *q, uint8_t *data, uint8_t size);
uint8_t *CQUEUE_Remove(queue_t *q, uint16_t *length);


#ifdef __cplusplus
}
#endif

#endif

