# Floyd's Cycle Detection: Understanding the A-B-C Relationship

## 1. Problem Overview

Floyd's Cycle Detection Algorithm (also known as the Tortoise and Hare Algorithm) is used to detect a loop in a linked list.

It uses two pointers:

- **Slow Pointer:** Moves one node at a time.
- **Fast Pointer:** Moves two nodes at a time.

If a cycle exists, both pointers will eventually meet inside the cycle.

Once they meet, we can find the starting node of the cycle using a mathematical relationship between three distances: **A, B, and C**.

---

## 2. Understanding A, B, and C

Consider the following linked list:

```text
1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

```

Here, node `5` points back to node `2`, creating a cycle.

We divide the linked list into three distances:

- **A:** Distance from the head to the cycle entry point.
- **B:** Distance from the cycle entry point to the collision point.
- **C:** Distance from the collision point back to the cycle entry point.

### Visual Representation

```text
                 A
       <------------------->
HEAD --------------------> ENTRY
  1       2       3       4       5
          ^                       |
          |                       |
          |                       |
          |_______________________|

          ENTRY -> COLLISION = B
          COLLISION -> ENTRY = C
```

For our example, assume the slow and fast pointers collide at node `5`.

| Distance | Value | Explanation                     |
| -------- | ----: | ------------------------------- |
| A        |     1 | Head (1) to cycle entry (2)     |
| B        |     3 | Entry (2) to collision (5)      |
| C        |     1 | Collision (5) back to entry (2) |
| B + C    |     4 | Total cycle length              |

**Important:** These distances represent the number of edges travelled, not the number of nodes.

---

## 3. Why Do We Reset One Pointer to Head?

At the collision point:

- Slow pointer has travelled `A + B` edges.
- Fast pointer has travelled `2(A + B)` edges.

Since the fast pointer moves twice as fast as the slow pointer, the extra distance travelled by the fast pointer must be a whole number of cycle lengths.

Let `k` represent the number of complete cycle lengths covered by this extra distance.

Therefore:

```text
2(A + B) = (A + B) + k(B + C)
```

Simplifying:

```text
A + B = k(B + C)
```

Rearranging:

```text
A = k(B + C) - B
```

Since:

```text
-B = (B + C) - (B + C) - B
```

We get:

```text
A = (k - 1)(B + C) + C
```

Therefore:

```text
A = C + (k - 1) * (B + C)
```

### What does this equation tell us?

It tells us that:

**Distance A = Distance C + some complete cycle rotations.**

This is the key mathematical observation behind Floyd's cycle-entry detection.

---

## 4. How Does This Help Us Find the Cycle Entry?

After both pointers collide:

1. Keep one pointer at the collision point.
2. Reset the other pointer to the head.
3. Move both pointers one node at a time.
4. They will meet at the cycle entry point.

Why?

- The pointer starting from the head travels distance `A`.
- The pointer starting from the collision point travels distance `C`, plus possibly some complete cycle rotations.
- Because of the mathematical relationship, both pointers meet at the cycle entry.

### Dry Run

For the linked list:

```text
1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|
```

Assume the collision occurs at node `5`.

| Step    | Pointer from Head | Pointer from Collision |
| ------- | ----------------- | ---------------------- |
| Initial | 1                 | 5                      |
| Move 1  | 2                 | 2                      |

Both pointers meet at node `2`.

Therefore, **node 2 is the starting point of the cycle.**

---

## 5. Code Implementation

### Step 1: Detect the Collision Point

```cpp
Node *flyodAlgo(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slowPointer = head;
    Node *fastPointer = head;

    while (fastPointer != NULL && fastPointer->next != NULL)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;

        if (slowPointer == fastPointer)
            return slowPointer;
    }

    return NULL;
}
```

### Step 2: Find the Cycle Entry and Remove the Loop

```cpp
void detectIntersectionAndRemoveLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *slowPointer = head;
    Node *floydIntersection = flyodAlgo(head);

    //? No cycle exists, so there is nothing to remove.
    if (floydIntersection == NULL)
        return;

    //? Special case: The cycle starts at the head.
    if (slowPointer == floydIntersection)
    {
        //? Find the last node inside the cycle.
        while (floydIntersection->next != slowPointer)
        {
            floydIntersection = floydIntersection->next;
        }

        //? Disconnect the last node from the head.
        floydIntersection->next = NULL;
        return;
    }

    //? Find the cycle entry by moving both pointers one step at a time.
    while (slowPointer->next != floydIntersection->next)
    {
        slowPointer = slowPointer->next;
        floydIntersection = floydIntersection->next;
    }

    //? Both pointers are now at the node immediately before the cycle entry.
    //? Disconnect it to remove the loop.
    floydIntersection->next = NULL;
}
```

---

## 6. Complexity Analysis

| Operation        | Time Complexity | Space Complexity |
| ---------------- | --------------- | ---------------- |
| Detect cycle     | O(N)            | O(1)             |
| Find cycle entry | O(N)            | O(1)             |
| Remove cycle     | O(N)            | O(1)             |

- **Overall Time Complexity:** O(N)
- **Overall Auxiliary Space Complexity:** O(1)

The algorithm uses only two pointers, so no additional data structure is required.

---

## 7. Key Takeaways

1. Floyd's algorithm detects a cycle using slow and fast pointers.
2. Both pointers eventually collide if a cycle exists.
3. After collision, reset one pointer to the head.
4. Move both pointers one step at a time to find the cycle entry.
5. The A-B-C relationship mathematically explains why both pointers meet at the cycle entry.
6. To remove the cycle, find the node immediately before the cycle entry and set its `next` pointer to `NULL`.

**Remember the most important relationship:**

```text
A = C + (k - 1) * (B + C)
```

This is the mathematical foundation of Floyd's cycle-entry detection algorithm.
