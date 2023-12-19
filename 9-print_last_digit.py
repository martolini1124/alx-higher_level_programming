#!/usr/bin/python3

def print_last_digit(number):
    # Check if the number is negative
    if number < 0:
        # Calculate the last digit for negative numbers
        last_num = (-number % 10)
    elif number >= 0:
        # Calculate the last digit for non-negative numbers
        last_num = number % 10

    # Print the last digit without a new line
    print("{:d}".format(last_num), end="")

    # Return the last digit
    return last_num
