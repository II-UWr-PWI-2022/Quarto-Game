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
	grep out.out "wins" > res.out
done
