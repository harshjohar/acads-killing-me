Implement Logical Clock

For reference: https://www.kaggle.com/code/ameythakur20/lamport-s-logical-clock-lcs


---

In this implementation:

1. We define a structure Event to represent an event with a timestamp and description.
2. We input the number of events and their descriptions, assigning timestamps based on Lamport's Logical Clock.
3. Events are sorted based on their timestamps using the qsort function.
4. Finally, we display the events in chronological order.