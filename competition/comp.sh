#!/bin/bash

num_of_games=1
bot_A_pts=0
bot_B_pts=0
bot_C_pts=0

# simulate competition between bots A and B
for i in {1..$num_of_games}
do
	../build/main < easy_AB > out.out &
	ID=$!
	kill $ID
	if grep "Player A wins" out.out; then
		(( bot_A_pts++ ))
	else
		(( bot_B_pts++ ))
	fi
done

echo $bot_A_pts
