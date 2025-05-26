#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stdio.h"

#define FRAME_CAPTURE_INTERVAL_MS 100
#define PROCESSING_DELAY_MS 100

// Structure for recognition result
typedef struct
{
    int frameNumber;
    unsigned short int status[20]; // e.g., for face detect = 1, no face = 0
    TickType_t timestamp;
} RecognitionResult;

// Queues
QueueHandle_t xFrameQueue;
QueueHandle_t xResultQueue;

// FrameCaptureTask: High Priority
void FrameCaptureTask(void *para)
{
    int frameNumber = 0;
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(FRAME_CAPTURE_INTERVAL_MS)); // Wait 100ms

        frameNumber++; // Simulate a new frame
        printf("Captured Frame: %d\n", frameNumber);

        // Send frame number to FaceRecognitionTask
        xQueueSend(xFrameQueue, &frameNumber, portMAX_DELAY);
    }
}

// FaceRecognitionTask: Medium Priority
void FaceRecognitionTask(void *para)
{
    int receivedFrame;
    RecognitionResult result;

    while (1)
    {
        // Wait for frame number from capture queue
        if (xQueueReceive(xFrameQueue, &receivedFrame, portMAX_DELAY) == pdTRUE)
        {
            // Simulate processing time
            vTaskDelay(pdMS_TO_TICKS(PROCESSING_DELAY_MS));

            result.frameNumber = receivedFrame;
            result.timestamp = xTaskGetTickCount();

            // Logic for detecting the face
            // result.status = 1;
            // result.status = 0;

            // Send result to LoggerTask
            xQueueSend(xResultQueue, &result, portMAX_DELAY);
        }
    }
}

// LoggerTask: Low Priority
void LoggerTask(void *para)
{
    RecognitionResult receivedResult;

    while (1)
    {
        // Wait for processed result
        if (xQueueReceive(xResultQueue, &receivedResult, portMAX_DELAY) == pdTRUE)
        {
            printf("Log -> Frame: %d | Status: %d | Time: %lu ticks\n",
                   receivedResult.frameNumber,
                   receivedResult.status,
                   receivedResult.timestamp);
        }
    }
}

int main()
{
    // Create queues
    xFrameQueue = xQueueCreate(10, sizeof(int));                // Holds frame numbers
    xResultQueue = xQueueCreate(10, sizeof(RecognitionResult)); // Holds processed results

    if (xFrameQueue == NULL || xResultQueue == NULL)
    {
        printf("Failed to create queues.\n");
        while (1); // Halt
    }

    // Create tasks
    xTaskCreate(FrameCaptureTask, "FrameCapture", 128, NULL, 3, NULL);
    xTaskCreate(FaceRecognitionTask, "FaceRecognition", 128, NULL, 2, NULL);
    xTaskCreate(LoggerTask, "Logger", 128, NULL, 1, NULL);

    // Start scheduler
    vTaskStartScheduler();

    // Should never reach here
    for (;;);
    return 0;
}