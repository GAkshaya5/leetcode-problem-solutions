class MyQueue:

    def __init__(self):
        # s1 for pushing (input), s2 for popping (output)
        self.s1 = []
        self.s2 = []

    def push(self, x: int) -> None:
        # Standard stack push is always O(1)
        self.s1.append(x)

    def pop(self) -> int:
        # Transfer elements to s2 only if it's empty
        self.peek()
        return self.s2.pop()

    def peek(self) -> int:
        # If output stack is empty, move everything from s1 to s2
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        return self.s2[-1]

    def empty(self) -> bool:
        # Queue is empty only if both stacks are empty
        return not self.s1 and not self.s2
