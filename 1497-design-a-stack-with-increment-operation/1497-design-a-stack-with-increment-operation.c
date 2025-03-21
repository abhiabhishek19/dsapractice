


typedef struct {
    int *stack;               // Array to hold stack elements
    int *pendingIncrements;   // Array to hold pending increments
    int maxSize;             // Maximum size of the stack
    int currentSize;         // Current size of the stack
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack* obj = (CustomStack*)malloc(sizeof(CustomStack));
    obj->maxSize = maxSize;
    obj->currentSize = 0;
    obj->stack = (int*)malloc(maxSize * sizeof(int));
    obj->pendingIncrements = (int*)malloc(maxSize * sizeof(int));
    
    // Initialize pending increments to 0
    for (int i = 0; i < maxSize; i++) {
        obj->pendingIncrements[i] = 0;
    }
    
    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->currentSize == obj->maxSize) {
        return; // Stack is full
    }
    obj->stack[obj->currentSize] = x;
    obj->pendingIncrements[obj->currentSize] = 0; // Initialize pending increment for this position
    obj->currentSize++;
}

int customStackPop(CustomStack* obj) {
    if (obj->currentSize == 0) {
        return -1; // Stack is empty
    }
    
    int i = obj->currentSize - 1; // Index of the top element
    if (i > 0) {
        obj->pendingIncrements[i - 1] += obj->pendingIncrements[i]; // Transfer pending increment to the previous element
    }
    
    int val = obj->stack[i] + obj->pendingIncrements[i]; // Calculate the value to return
    obj->currentSize--; // Decrease the size of the stack
    return val; // Return the popped value
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    if (obj->currentSize == 0) {
        return; // Stack is empty
    }
    
    int i = (k - 1 < obj->currentSize) ? (k - 1) : (obj->currentSize - 1); // Determine the index to increment
    obj->pendingIncrements[i] += val; // Increment the pending increment for the k-th element
}

void customStackFree(CustomStack* obj) {
    free(obj->stack); // Free the stack array
    free(obj->pendingIncrements); // Free the pending increments array
    free(obj); // Free the CustomStack structure
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/