puts "WHATS UR NAME???>?>"
name = gets.chomp
puts "#{name}, MILORD! THE ENEMY HAS ARRIVED. WHAT WILL YOU DO?"
alive = true
defeated = 0

while (alive)
    c = gets.chomp
    case c
        when /s/
            puts "YOU SHOOT AN ARROW BUT MISSED!"
        when /r/
            puts "YOU RUN INTO A WINDOW"
            alive = false
        when /a/
            puts "YOU SWING YOUR SWORD"
            defeated += 1
            puts "ENEMY #{defeated} DOWN"
        else
            puts "WTF ARE YOU DOING"
    end
end

puts "YOU DIE"
puts "BUT YOU HAVE KILLED #{defeated} ENEMIES THIS GLORIOUS DAY"
