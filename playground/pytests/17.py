elevens = ['', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
units = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
tens = ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
hundreds = [str(i) + 'hundred' for i in units]
hundreds[0] = ''

def split_digits(number):
	if number >= 1 and number <= 9: 						# [1, 9]
		return [0, 0] + [int(i, 10) for i in list(str(number))]
	elif number >= 10 and number <= 99: 					# [10, 99]
		return [0] + [int(i, 10) for i in list(str(number))]
	elif number >= 100 and number <= 999: 					# [100, 999]
		return [int(i, 10) for i in list(str(number))]
	else:													# 1000
		return [0, 0, 0]

def length_of_name(number):
	if number >= 1 and number <= 999:
		number_name = ''
		length = 0
		position_list = split_digits(number)
		length += len(list(hundreds[position_list[0]]))
		number_name += hundreds[position_list[0]]
		if position_list[1] != 0 or position_list[2] != 0:
			if position_list[0] != 0:
				length += len(list('and'))
				number_name += 'and'
		else:
			length += 0
		if position_list[1] == 1:
			if position_list[2] == 0:
				length += len(list('ten'))
				number_name += 'ten'
			else:
				length += len(list(elevens[position_list[2]]))
				number_name += elevens[position_list[2]]
		else:
			length += len(list(tens[position_list[1]]))
			number_name += tens[position_list[1]]
			length += len(list(units[position_list[2]]))
			number_name += units[position_list[2]]
		return (length, number_name)
	else:
		return (len(list('onethousand')), 'onethousand')

numbers = [i for i in range(1, 1001)]
names = [length_of_name(i)[1] for i in numbers]
lengths = [length_of_name(i)[0] for i in numbers]
length_name_pairs = [length_of_name(i) for i in numbers]
print(sum(lengths))
