class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)
        print(f"Pushed {item} onto stack.")

    def pop(self):
        if not self.items:
            print("Stack is empty. Cannot pop.")
            return None
        return self.items.pop()

    def display(self):
        print("Stack:", self.items)

def main():
    stack = Stack()
    while True:
        print("\n1. Push\n2. Pop\n3. Display\n4. Exit")
        choice = input("Enter your choice: ")
        
        if choice == '1':
            val = input("Enter value to push: ")
            stack.push(val)
        elif choice == '2':
            popped = stack.pop()
            if popped is not None:
                print(f"Popped {popped} from stack.")
        elif choice == '3':
            stack.display()
        elif choice == '4':
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()
