file = File.open("input.txt")

$file_data = file.readlines.map(&:chomp)
$col_len = $file_data[0].size

class Slope
	def Sim(x_inc, y_inc)
		x = 0b00000
		y = 0
		trees = 0

		until y == $file_data.length()

			if($file_data[y][x] == '#')
				trees += 1
			end

		  	y += y_inc
		  	x += x_inc

			if x >= $col_len
				x -= $col_len
			end
		end

		return trees
	end
end

slope_1 = Slope.new.Sim(1,1)
slope_2 = Slope.new.Sim(3,1)
slope_3 = Slope.new.Sim(5,1)
slope_4 = Slope.new.Sim(7,1)
slope_5 = Slope.new.Sim(1,2)


puts "Part 1: #{slope_3}"

puts "Part 2: #{slope_1 * slope_2 * slope_3 * slope_4 * slope_5}"
