from random import randint

f_input = open('my_input.txt', 'w')
f_output = open('my_output.txt', 'w')

for _ in range(99999):
	a = randint(1, 999999999999999)

	f_input.write('{}\n'.format(a))
	f_output.write(str(a) + '\n')

f_input.close()
f_output.close()