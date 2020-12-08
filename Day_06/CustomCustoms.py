file = open('input.txt', 'r').read()

#Part 1
score = 0
for group in file.split('\n\n'):
	answers = set()
	for person in group.split('\n'):
		answers.update(set(person))
	score += len(answers)
	
print(score)


#Part 2
score = 0
for group in file.split('\n\n'):
	answers = set()
	p = 1
	for person in group.split('\n'):
		if p == 1:
			p = 0
			answers = set(person)
		else:
			answers = answers.intersection(set(person))
	score += len(answers)
	
print(score)