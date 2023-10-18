#include <stdio.h>
#include <stdlib.h>

struct Event {
    int timestamp;
    char* description;
};

int compareEvents(const void* a, const void* b) {
    return ((struct Event*)a)->timestamp - ((struct Event*)b)->timestamp;
}

int main() {
    int numEvents;
    printf("Enter the number of events: ");
    scanf("%d", &numEvents);

    struct Event events[numEvents];

    for (int i = 0; i < numEvents; i++) {
        events[i].timestamp = i; // Assign Lamport's Logical Clock timestamp
        events[i].description = (char*)malloc(100 * sizeof(char));
        printf("Enter the description for event %d: ", i + 1);
        scanf(" %[^\n]", events[i].description);
    }

    qsort(events, numEvents, sizeof(struct Event), compareEvents);

    printf("\nEvents in chronological order:\n");
    for (int i = 0; i < numEvents; i++) {
        printf("Timestamp: %d, Description: %s\n", events[i].timestamp, events[i].description);
        free(events[i].description);
    }

    return 0;
}
