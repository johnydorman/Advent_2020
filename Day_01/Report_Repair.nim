import strutils

let f = open("input.txt")

var numbers: seq[int]
for line in lines f:
    numbers.add(parseInt(line))


var index : int = 0

for i in 0 ..< numbers.len:
    for j in index ..< numbers.len:
            var addition = numbers[i] + numbers[j]
            if addition == 2020:
                echo numbers[i], " x ", numbers[j] 
                echo numbers[i] * numbers[j] 
            elif addition <= 2020:
                for k in j ..< numbers.len:
                    if addition + numbers[k] == 2020:
                        echo numbers[i], " x ", numbers[j], " x ", numbers[k]
                        echo numbers[i] * numbers[j] * numbers[k]
    inc(index)