num = input("Enter a single-digit positive number: ")

# Check if input is a digit and single-digit positive number
if not (num.isdigit() and 1 <= int(num) <= 9):
    print("Invalid input")
else:
    n = int(num)
    square = n * n
    # Check if last digit(s) of square matches the number
    if str(square).endswith(num):
        print(f"{n} is an automorphic number")
    else:
        print(f"{n} is not an automorphic number")
