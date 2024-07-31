// Huffman Encoding
#include "compressor.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

// Tree Node
typedef struct MinHeapNode {
  unsigned char data;
  unsigned freq;
  struct MinHeapNode *left, *right;
} MinHeapNode;

// Collection of Trees
typedef struct MinHeap {
  unsigned size;
  unsigned capacity;
  MinHeapNode **array;
} MinHeap;

// Allocate a new node
MinHeapNode *new_node(char data, unsigned freq) {
  MinHeapNode *tmp = (MinHeapNode *)malloc(sizeof(MinHeapNode));
  tmp->left = tmp->right = NULL;
  tmp->data = data;
  tmp->freq = freq;

  return tmp;
}

// Create a new min heap
MinHeap *create_min_heap(unsigned capacity) {
  MinHeap *min_heap = (MinHeap *)malloc(sizeof(MinHeap));

  min_heap->size = 0;
  min_heap->capacity = capacity;
  min_heap->array =
      (MinHeapNode **)malloc(min_heap->capacity * sizeof(MinHeapNode *));

  return min_heap;
}

// Swap two min heap nodes
void swap_min_heap_node(MinHeapNode **a, MinHeapNode **b) {
  MinHeapNode *t = *a;

  *a = *b;
  *b = t;
}

// The standard min heapify function
void min_heapify(MinHeap *min_heap, int idx) {
  int smallest = idx;
  unsigned left = 2 * idx + 1;
  unsigned right = 2 * idx + 2;

  if (left < min_heap->size &&
      min_heap->array[left]->freq < min_heap->array[smallest]->freq)
    smallest = left;

  if (right < min_heap->size &&
      min_heap->array[right]->freq < min_heap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swap_min_heap_node(&min_heap->array[smallest], &min_heap->array[idx]);
    min_heapify(min_heap, smallest);
  }
}

// Check if size heap is 1
int is_size_one(MinHeap *min_heap) {
  // Brr
  return (min_heap->size == 1);
}

// Extract min value node from the heap
MinHeapNode *extract_min(MinHeap *min_heap) {
  MinHeapNode *tmp = min_heap->array[0];
  min_heap->array[0] = min_heap->array[min_heap->size - 1];

  min_heap->size--;
  min_heapify(min_heap, 0);

  return tmp;
}

// Insert new node to min heap
void insert_min(MinHeap *min_heap, MinHeapNode *min_heap_node) {
  int i = min_heap->size;
  min_heap->size++;

  while (i && min_heap_node->freq < min_heap->array[(i - 1) / 2]->freq) {
    min_heap->array[i] = min_heap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }

  min_heap->array[i] = min_heap_node;
}

// Standart function to build min heap
void build_min_heap(MinHeap *min_heap) {
  int n = min_heap->size - 1;
  for (int i = (n - 1) / 2; i >= 0; i--)
    min_heapify(min_heap, i);
}

// Function to print an array of size n
void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d", arr[i]);

  printf("\n");
}

// Function to check if this node is leaf
int is_leaf(MinHeapNode *root) {
  // Brr 2
  return !(root->left) && !(root->right);
}

// Create min heap of capacity size
MinHeap *create_and_build_min_heap(char data[], int freq[], int size) {
  MinHeap *min_heap = create_min_heap(size);

  for (int i = 0; i < size; i++)
    min_heap->array[i] = new_node(data[i], freq[i]);

  min_heap->size = size;
  build_min_heap(min_heap);

  return min_heap;
}

// The main functions that builds the Huffman Tree
MinHeapNode *build_huffman_tree(char data[], int freq[], int size) {
  MinHeapNode *left, *right, *top;

  MinHeap *min_heap = create_and_build_min_heap(data, freq, size);

  while (!is_size_one(min_heap)) {
    left = extract_min(min_heap);
    right = extract_min(min_heap);

    top = new_node('$', left->freq + right->freq);

    top->left = left;
    top->right = right;

    insert_min(min_heap, top);
  }

  return extract_min(min_heap);
}

// Prints huffman codes from the root of the tree
void print_codes(MinHeapNode *root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    print_codes(root->left, arr, top + 1);
  }

  if (root->right) {
    arr[top] = 1;
    print_codes(root->right, arr, top + 1);
  }

  if (is_leaf(root)) {
    printf("%c", root->data);
    print_arr(arr, top);
  }
}

// Main function for the encoding
void HuffmanCodes(char data[], int freq[], int size) {
  MinHeapNode *root = build_huffman_tree(data, freq, size);

  int arr[MAX_TREE_HT], top = 0;

  print_codes(root, arr, top);
}
