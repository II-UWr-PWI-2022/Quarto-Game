#!/bin/bash

bot_1_pts=0
bot_2_pts=0
bot_3_pts=0
num_of_tests=20

# clear the script log
echo "" > scriptres.txt

# bots 1 and 2, easy mode
echo "bots 1 and 2, easy mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < easy12 > out.out
	if grep "Player A wins" out.out; then
		(( bot_1_pts++ ))
		echo "bot 1 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_2_pts++ ))
		echo "bot 2 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "no one won" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 1 and 2, hard mode
echo "bots 1 and 2, hard mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < hard12 > out.out
	if grep "Player A wins" out.out; then
		(( bot_1_pts += 3 ))
		echo "bot 1 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_2_pts += 3 ))
		echo "bot 2 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "no one won" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 2 and 1, easy mode
echo "bots 2 and 1, easy mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < easy21 > out.out
	if grep "Player A wins" out.out; then
		(( bot_2_pts++ ))
		echo "bot 2 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_1_pts++ ))
		echo "bot 1 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "no one won" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 2 and 1, hard mode
echo "bots 2 and 1, hard mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < hard21 > out.out
	if grep "Player A wins" out.out; then
		(( bot_2_pts += 3 ))
		echo "bot 2 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_1_pts += 3 ))
		echo "bot 1 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "no one won" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 1 and 3, easy mode
echo "bots 1 and 3, easy mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < easy13 > out.out
	if grep "Player A wins" out.out; then
		(( bot_1_pts++ ))
		echo "bot 1 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_3_pts++ ))
		echo "bot 3 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "draw" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 1 and 3, hard mode
echo "bots 1 and 3, hard mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < hard13 > out.out
	if grep "Player A wins" out.out; then
		(( bot_1_pts += 3 ))
		echo "bot 1 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_3_pts += 3 ))
		echo "bot 3 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "draw" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 3 and 1, easy mode
echo "bots 3 and 1, easy mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < easy31 > out.out
	if grep "Player A wins" out.out; then
		(( bot_3_pts++ ))
		echo "bot 3 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_1_pts++ ))
		echo "bot 1 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "draw" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 3 and 1, hard mode
echo "bots 3 and 1, hard mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < hard31 > out.out
	if grep "Player A wins" out.out; then
		(( bot_3_pts += 3 ))
		echo "bot 3 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_1_pts += 3 ))
		echo "bot 1 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "draw" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 2 and 3, easy mode
echo "bots 2 and 3, easy mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < easy23 > out.out
	if grep "Player A wins" out.out; then
		(( bot_2_pts++ ))
		echo "bot 2 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_3_pts++ ))
		echo "bot 3 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "draw" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 2 and 3, hard mode
echo "bots 2 and 3, hard mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < hard23 > out.out
	if grep "Player A wins" out.out; then
		(( bot_2_pts += 3 ))
		echo "bot 2 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_3_pts += 3 ))
		echo "bot 3 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "draw" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 3 and 2, easy mode
echo "bots 3 and 2, easy mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < easy32 > out.out
	if grep "Player A wins" out.out; then
		(( bot_3_pts++ ))
		echo "bot 3 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_2_pts++ ))
		echo "bot 2 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "draw" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

# bots 3 and 2, hard mode
echo "bots 3 and 2, hard mode" >> scriptres.txt
for (( i=1; i<=$num_of_tests; i++ ))
do
	../build/main < hard32 > out.out
	if grep "Player A wins" out.out; then
		(( bot_3_pts += 3 ))
		echo "bot 3 won" >> scriptres.txt
	elif grep "Player B wins" out.out; then
		(( bot_2_pts += 3 ))
		echo "bot 2 won" >> scriptres.txt
	elif grep "Draw" out.out; then
		echo "draw" >> scriptres.txt
	else
		echo "error" >> scriptres.txt
	fi
done

echo "score of bot 1:" $bot_1_pts > report.txt
echo "score of bot 2:" $bot_2_pts >> report.txt
echo "score of bot 3:" $bot_3_pts >> report.txt
