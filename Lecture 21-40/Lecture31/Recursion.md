# Recursion

Recursion is a programming technique in which a function calls itself, either directly or indirectly.

Another way to understand recursion is as a problem-solving approach where a large and complex problem is broken down into smaller instances of the same problem. These smaller problems are solved recursively until a simple condition is reached.

## Components of Recursion

A recursive function generally consists of three main components:

1. **Base Case**
   - The condition that stops further recursive calls.
   - Prevents infinite recursion.

2. **Recursive Call**
   - The function calls itself with a smaller or simpler input.

3. **Processing**
   - The work performed either before or after the recursive call.

## Types of Recursion

### 1. Tail Recursion

In tail recursion, the recursive call is the last operation performed by the function.

**Order of components:**

1. Base Case
2. Processing
3. Recursive Call

### 2. Head Recursion

In head recursion, the recursive call is made before any processing is performed.

**Order of components:**

1. Base Case
2. Recursive Call
3. Processing
