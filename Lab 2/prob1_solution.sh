#!/bin/bash
set -u

# This program use bisection search
# algorithm to find a secret key from prob1
# Created by Chawin Metah

# initial set up
# range of the secret key
low=0
high=2147483647

temp=0

while ((1))
do
	# guess_number is equal to the
	# middle number in the range
	guess_number=$(((low + high)/2))

	# execute prob1 with the argument
	# and retrive a return value 
	./prob1 $guess_number
	stat=$?
	
	# guess_number is equal to the secret key
	if (($stat == 0)); then
		echo "Found: $guess_number"
		break

	# guess_number is smaller than the secret key
	elif (($stat == 2)); then
		low=$guess_number

	# guess_number is larger than the secret key
	elif (($stat == 1)); then
		high=$guess_number
	fi
	
	# NOT found case
	# when previous guess_number is equal to
	# the current guess_number
	if (($temp == $guess_number)); then
		echo "NOT found"
		break
	fi
	temp=$guess_number
done

echo " "
