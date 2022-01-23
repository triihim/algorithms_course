# Increasing Array

## Description
There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.

You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.

What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?

## Input

The first input line contains an integer n: the number of customers.

Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.

## Output

Print first an integer k: the minimum number of rooms required.

After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,…,k. You can print any valid solution.

## Limits
Time limit: 1.00 s  
Memory limit: 512 MB

## Constraints
- 1 <= n <= 2*10^5
- 1 <= a < b <= 10^9

## Example

Input:  
3  
1 2  
2 4   
4 4  

Output:  
2  
1 2 1  
