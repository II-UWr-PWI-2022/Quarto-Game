#!/bin/bash

num_of_games=1
bot_1_pts=0
bot_2_pts=0
bot_3_pts=0

# bots 1 and 2, easy mode
for i in {1..$num_of_games}
do
	../build/main < easy12 > out.out &
	ID=$!
	kill $ID
	if grep "Player A wins" out.out; then
		(( bot_1_pts++ ))
	else
		(( bot_2_pts++ ))
	fi
done

echo $bot_A_pts
