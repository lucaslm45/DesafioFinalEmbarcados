#include "cmsis_os2.h"                          // CMSIS RTOS header file
#include "EventRecorder.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*----------------------------------------------------------------------------
 *      Message Queue creation & usage
 *---------------------------------------------------------------------------*/
 
#define qntd_msgs_fila 16                     // number of Message Queue Objects
 
typedef struct {                                // object data type
  int valor;
  char Idx[15];
} objs_fila;
 
osMessageQueueId_t fila_mensagens;                // message queue id
 
osThreadId_t tid_Thread_Temperatura;              // thread id 1
osThreadId_t tid_Thread_Luminosidade;              // thread id 2
osThreadId_t tid_Thread_Consome;              // thread id 3
 
void Thread_Temperatura (void *argument);         // thread function 1
void Thread_Luminosidade (void *argument);         // thread function 2
void Thread_Consome (void *argument);         // thread function 3
 
int main (void) {
	EventRecorderInitialize(EventRecordAll, 1);
	osKernelInitialize();
	
 
  fila_mensagens = osMessageQueueNew(qntd_msgs_fila, sizeof(objs_fila), NULL);
  if (fila_mensagens == NULL) {
    ; // Message Queue object not created, handle failure
  }
 
	tid_Thread_Temperatura = osThreadNew(Thread_Temperatura, NULL, NULL);
  if (tid_Thread_Temperatura == NULL) {
    return(-1);
  }
	
  tid_Thread_Luminosidade = osThreadNew(Thread_Luminosidade, NULL, NULL);
  if (tid_Thread_Luminosidade == NULL) {
    return(-1);
  }
  tid_Thread_Consome = osThreadNew(Thread_Consome, NULL, NULL);
  if (tid_Thread_Consome == NULL) {
    return(-1);
  }
	
	if(osKernelGetState() == osKernelReady)
		osKernelStart();
 
  return(0);
}
 
void Thread_Temperatura (void *argument) {
  objs_fila msg;
 
  while (1) {
    ; // Insert thread code here...
    msg.valor =  1 + ( rand() % 59 );//15 + (rand() % 60);
    strcpy(msg.Idx, "Temperatura");
		
    osMessageQueuePut(fila_mensagens, &msg, NULL, osWaitForever);
		osDelay(1000);
  }
}

void Thread_Luminosidade (void *argument) {
  objs_fila msg;
 
  while (1) {
    msg.valor = 1 + ( rand() % 99 );
    strcpy(msg.Idx, "Luminosidade");
    osMessageQueuePut(fila_mensagens, &msg, NULL, osWaitForever);
		osDelay(3000);
  }
}
 
void Thread_Consome (void *argument) {
  objs_fila msg;
  osStatus_t status;
 
  while (1) {
    status = osMessageQueueGet(fila_mensagens, &msg, NULL, osWaitForever);   // wait for message
    if (status == osOK) {
			printf("%s: %d\n", msg.Idx, msg.valor);
    }
		osThreadYield();                                            // suspend thread
  }
}