highest = 0;
seats = Array.new(1024)

File.open("input.txt", "r") do |file_handle|
  file_handle.each_line do |ticket|

	row = ticket.slice(0, 7)
	row.gsub!("F", "0")
	row.gsub!("B", "1")
	row = row.to_i(2);
	
	column = ticket.slice(7, 10)
	column.gsub!("L", "0")
	column.gsub!("R", "1")
	column = column.to_i(2);
	
	value = (row * 8) + column
	seats[value] = 1
	
	if value > highest then
		highest = value
  end
end

#Part 1.
puts highest

counter = 0
seat = 1;
while seat < 1022
	if(seats[seat] == nil)
		if(seats[seat-1] == 1 && seats[seat+1] == 1)
			#Part 2.
			puts seat
			break
		end
	end
	seat = seat+1 
end

		
end