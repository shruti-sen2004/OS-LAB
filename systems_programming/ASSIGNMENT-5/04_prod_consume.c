//METHOD -1

// C program for the above approach
#include <stdio.h>
#include <stdlib.h>

// Initialize a mutex to 1
int mutex = 1;

// Number of full slots as 0
int full = 0;

// Number of empty slots as size
// of buffer
int empty = 10, x = 0;

// Function to produce an item and
// add it to the buffer
void producer() {
  // Decrease mutex value by 1
  mutex--;

  // Increase the number of full
  // slots by 1
  full++;

  // Decrease the number of empty
  // slots by 1
  empty--;

  // Item produced
  x++;
  printf("\nProducer produces item %d", x);

  // Increase mutex value by 1
  mutex++;
}

// Function to consume an item and
// remove it from buffer
void consumer() {
  // Decrease mutex value by 1
  mutex--;

  // Decrease the number of full
  // slots by 1
  full--;

  // Increase the number of empty
  // slots by 1
  empty++;
  printf("\nConsumer consumes item %d", x);
  x--;

  // Increase mutex value by 1
  mutex++;
}

// main Code
int main() {
  int n, i;
  printf("\n1. Press 1 for Producer"
         "\n2. Press 2 for Consumer"
         "\n3. Press 3 for Exit");

// 'critical' specifies that code is
// executed by only one thread at a
// time
#pragma omp critical

  for (i = 1; i > 0; i++) {

    printf("\nEnter your choice: ");
    scanf("%d", &n);

    // Switch Cases
    switch (n) {
    case 1:

      // If mutex is 1 and empty
      // is non-zero, then it is
      // possible to produce
      if ((mutex == 1) && (empty != 0)) {
        producer();
      }

      // Otherwise, print buffer
      // is full
      else {
        printf("Buffer is full!");
      }
      break;

    case 2:

      // If mutex is 1 and full
      // is non-zero, then it is
      // possible to consume
      if ((mutex == 1) && (full != 0)) {
        consumer();
      }

      // Otherwise, print Buffer
      // is empty
      else {
        printf("Buffer is empty!");
      }
      break;

    // Exit Condition
    case 3:
      exit(0);
      break;
    }
  }
}


//MEHOD -2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer
int in = 0;    // Index for producer to insert
int out = 0;   // Index for consumer to remove

// Function for the producer
void producer() {
  if (count < BUFFER_SIZE) { // Check if buffer is not full
    int item = rand() % 100; // Produce an item
    buffer[in] = item;       // Insert item in the buffer
    in = (in + 1) % BUFFER_SIZE;
    count++;
    printf("Producer produced: %d\n", item);
  } else {
    printf("Buffer is full! Producer is waiting...\n");
  }
}

// Function for the consumer
void consumer() {
  if (count > 0) {          // Check if buffer is not empty
    int item = buffer[out]; // Remove item from buffer
    out = (out + 1) % BUFFER_SIZE;
    count--;
    printf("Consumer consumed: %d\n", item);
  } else {
    printf("Buffer is empty! Consumer is waiting...\n");
  }
}

// Main function
int main() {
  int choice;

  while (1) {
    printf("\n1. Produce\n2. Consume\n3. Exit\nChoose an option: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      producer();
      break;
    case 2:
      consumer();
      break;
    case 3:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }

    // Simulate time delay
    sleep(1);
  }

  return 0;
}