#!/bin/bash

num_of_games=3
bot_1_pts=0
bot_2_pts=0
bot_3_pts=0

# bots 1 and 2, easy mode
for i in {1..5}
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

# bots 1 and 2, hard mode
for i in {1..5}
do
	../build/main < hard12 > out.out &
	ID=$!
	kill $ID
	if grep "Player A wins" out.out; then
		(( bot_1_pts += 3 ))
	else
		(( bot_2_pts += 3 ))
	fi
done

# bots 1 and 3, easy mode
for i in {1..5}
do
	../build/main < easy13 > out.out &
	ID=$!
	kill $ID
	if grep "Player A wins" out.out; then
		(( bot_1_pts++ ))
	else
		(( bot_3_pts++ ))
	fi
done

# bots 1 and 3, hard mode
for i in {1..5}
do
	../build/main < hard13 > out.out &
	ID=$!
	kill $ID
	if grep "Player A wins" out.out; then
		(( bot_1_pts += 3 ))
	else
		(( bot_3_pts += 3 ))
	fi
done

# bots 2 and 3, easy mode
for i in {1..5}
do
	../build/main < easy23 > out.out &
	ID=$!
	kill $ID
	if grep "Player A wins" out.out; then
		(( bot_2_pts++ ))
	else
		(( bot_3_pts++ ))
	fi
done

# bots 2 and 3, hard mode
for i in {1..5}
do
	../build/main < hard23 > out.out &
	ID=$!
	kill $ID
	if grep "Player A wins" out.out; then
		(( bot_2_pts += 3 ))
	else
		(( bot_3_pts += 3 ))
	fi
done

echo $bot_1_pts
echo $bot_2_pts
echo $bot_3_pts
