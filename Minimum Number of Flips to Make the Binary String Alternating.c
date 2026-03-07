#include <string.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minFlips(char * s) {
    int n = strlen(s);
    int diff1 = 0; // Comparisons against '0101...'
    int diff2 = 0; // Comparisons against '1010...'
    
    // Initial window of size n
    for (int i = 0; i < n; i++) {
        // Target 1: 0, 1, 0, 1...
        if (s[i] - '0' != i % 2) diff1++;
        // Target 2: 1, 0, 1, 0...
        if (s[i] - '0' == i % 2) diff2++;
    }
    
    int min_ops = MIN(diff1, diff2);
    
    // If n is even, type-1 operations don't change the flip count.
    // If n is odd, sliding the window can change the required flips.
    if (n % 2 != 0) {
        for (int i = 0; i < n; i++) {
            
            // Remove the contribution of the character leaving the front
            if (s[i] - '0' != i % 2) diff1--;
            if (s[i] - '0' == i % 2) diff2--;
            
            // Add the contribution of that same character now at the back (index n + i)
            if (s[i] - '0' != (n + i) % 2) diff1++;
            if (s[i] - '0' == (n + i) % 2) diff2++;
            
            min_ops = MIN(min_ops, MIN(diff1, diff2));
        }
    }
    
    return min_ops;
}
