def get_collatz_length(number):
	length = 0
	while number != 1:
		if number % 2 == 0:
			number = number / 2
		else:
			number = (3 * number) + 1
		length += 1
	return length

def longest_collatz_length(start, end):
	longest_length = 0
	longest_length_number = start
	for i in range(start, end):
		lengthOfI = get_collatz_length(i)
		if lengthOfI >= longest_length:
			longest_length = lengthOfI
			longest_length_number = i
	return (longest_length, longest_length_number)

if __name__ == "__main__":
	import sys
	if len(sys.argv[1:]) == 2:
		(collatz_length, collatz_number) = longest_collatz_length(int(sys.argv[1], 10), int(sys.argv[2], 10))
		print('number: ' + str(collatz_number) + '\nlength: ' + str(collatz_length))
	else:
		print('illegal arguments')
