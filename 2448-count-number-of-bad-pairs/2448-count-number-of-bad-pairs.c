typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    HashEntry* table;
    int size;
} HashMap;

#define HASH_SIZE 100000

// Hash function
int hash(int key) {
    return ((key % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;
}

// Initialize hash map
void initHashMap(HashMap* map) {
    map->size = HASH_SIZE;
    map->table = (HashEntry*)calloc(HASH_SIZE, sizeof(HashEntry));
    for (int i = 0; i < HASH_SIZE; i++) {
        map->table[i].key = __INT_MAX__;  // Mark as empty
    }
}

// Get value from hash map
int get(HashMap* map, int key) {
    int idx = hash(key);
    while (map->table[idx].key != __INT_MAX__) {
        if (map->table[idx].key == key) return map->table[idx].value;
        idx = (idx + 1) % HASH_SIZE;
    }
    return 0;  // Default count is 0
}

// Insert/update hash map
void put(HashMap* map, int key, int value) {
    int idx = hash(key);
    while (map->table[idx].key != __INT_MAX__ && map->table[idx].key != key) {
        idx = (idx + 1) % HASH_SIZE;
    }
    map->table[idx].key = key;
    map->table[idx].value = value;
}

// Count bad pairs function
long long countBadPairs(int* nums, int numsSize) {
    HashMap hashMap;
    initHashMap(&hashMap);
    
    long long totalPairs = (long long)numsSize * (numsSize - 1) / 2;  // Total pairs
    long long goodPairs = 0;

    for (int i = 0; i < numsSize; i++) {
        int key = i - nums[i];
        int count = get(&hashMap, key);
        goodPairs += count; // Count how many good pairs exist
        put(&hashMap, key, count + 1);
    }

    free(hashMap.table);
    return totalPairs - goodPairs;
}