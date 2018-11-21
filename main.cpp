/*-----------------------------
|           MCMC Program
--------------------------------
|       Author: Kelsey Cole
| Intro to Artificial Intelligence
|           11/20/2018
--------------------------------*/


/* COMPILE WITH: g++ -std=c++11 -o MCMC main.cpp*/ 
#include <map> 
#include <cstdlib>
#include <ctime> //rand
#include <iostream>
#include <random> //random_device, uniform_int_distribution

//initialize map to keep track of variable assignments
std::map<char,int> assignments;

/*---------------------------------
| Biased RAndom INteger generator |
-----------------------------------
| Purpose: determine a value to 
| assign to a variable based upon
| its conditional probability 
| Given: a variable from 
| std::map<char,int> assignments
| Return: an int, 0 or 1 
| (true or false)
----------------------------------*/
int brain(char var)
{
	float bias = 0; // conditional probability of a variable
	switch(var)
	{
		case 'A': 
		{ 
			if((assignments['B'] == 0) && (assignments['E'] == 0))
				bias = 111.166253;
			else if ((assignments['B'] == 0) && (assignments['E'] == 1))
				bias = 74.916387;
			else if ((assignments['B'] == 1) && (assignments['E'] == 0))
				bias = 103.384615; 
			else if ((assignments['B'] == 1) && (assignments['E'] == 1))
				bias = 34.461538;
 
		}
		case 'B': 
		{ 
			if((assignments['A'] == 0) && (assignments['C'] == 0) && (assignments['E'] == 0) && (assignments['F']==0))
				bias = 39.9999; 
			else if ((assignments['A'] == 0) && (assignments['C'] == 0) && (assignments['E'] == 0) && (assignments['F'] == 1))
				bias = 39.9999;
			else if ((assignments['A'] == 0) && (assignments['C'] == 0) && (assignments['E'] == 1) && (assignments['F'] == 0))
				bias = 39.9999;
			else if ((assignments['A'] == 0) && (assignments['C'] == 0) && (assignments['E'] == 1) && (assignments['F'] == 1))
				bias = 39.9999;
			else if ((assignments['A'] == 0) && (assignments['C'] == 1) && (assignments['E'] == 0) && (assignments['F'] == 0))
				bias = 39.9999; 
			else if ((assignments['A'] == 0) && (assignments['C'] == 1) && (assignments['E'] == 0) && (assignments['F'] == 1))
				bias = 39.9999;
			else if ((assignments['A'] == 0) && (assignments['C'] == 1) && (assignments['E'] == 1) && (assignments['F'] == 0))
				bias = 39.9999;
			else if ((assignments['A'] == 0) && (assignments['C'] == 1) && (assignments['E'] == 1) && (assignments['F'] == 1))
				bias = 39.9999;
			else if ((assignments['A'] == 1) && (assignments['C'] == 0) && (assignments['E'] == 0) && (assignments['F'] == 0))
				bias = 14.2857; 
			else if ((assignments['A'] == 1) && (assignments['C'] == 0) && (assignments['E'] == 0) && (assignments['F'] == 1))
				bias = 14.2857;
			else if ((assignments['A'] == 1) && (assignments['C'] == 0) && (assignments['E'] == 1) && (assignments['F'] == 0))
				bias = 14.2857;
			else if ((assignments['A'] == 1) && (assignments['C'] == 0) && (assignments['E'] == 1) && (assignments['F'] == 1))
				bias = 14.2857; 
			else if ((assignments['A'] == 1) && (assignments['C'] == 1) && (assignments['E'] == 0) && (assignments['F'] == 0))
				bias = 14.2857;
			else if ((assignments['A'] == 1) && (assignments['C'] == 1) && (assignments['E'] == 0) && (assignments['F'] == 1))
				bias = 14.2857;
			else if ((assignments['A'] == 1) && (assignments['C'] == 1) && (assignments['E'] == 1) && (assignments['F'] == 0))
				bias = 14.2857;
			else if ((assignments['A'] == 1) && (assignments['C'] == 1) && (assignments['E'] == 1) && (assignments['F'] == 1))
				bias = 14.2857;	
		}
		case 'C': 
		{ 
			if((assignments['B'] == 0) && (assignments['F'] == 0))
				bias = 3.5897;
			else if ((assignments['B'] == 0) && (assignments['F'] == 1))
				bias = 3.5897;
			else if ((assignments['B'] == 1) && (assignments['F'] == 0))
				bias = 7.6923;
			else if ((assignments['B'] == 1) && (assignments['F'] == 1))
				bias = 7.6923;

		}
		case 'E': 
		{ 
			if((assignments['A'] == 0) && (assignments['B'] == 0) && (assignments['F'] == 0))
				bias = 94.7368;
			else if ((assignments['A'] == 0) && (assignments['B'] == 0) && (assignments['F'] == 1))
				bias = 69.2307;
			else if ((assignments['A'] == 0) && (assignments['B'] == 1) && (assignments['F'] == 0))
				bias = 75;
			else if ((assignments['A'] == 1) && (assignments['B'] == 0) && (assignments['F'] == 0))
				bias = 75;
			else if ((assignments['A'] == 1) && (assignments['B'] == 0) && (assignments['F'] == 1))
				bias = 27.2727; 
			else if ((assignments['A'] == 1) && (assignments['B'] == 1) && (assignments['F'] == 0))
				bias = 18.1818;
			else if ((assignments['A'] == 1) && (assignments['B'] == 1) && (assignments['F'] == 1))
				bias = 2.7027;
	
		}
		case 'F': 
		{ 
			if((assignments['B'] == 0) && (assignments['C'] == 0) && (assignments['E'] == 0))
				bias = 40;
			else if ((assignments['B'] == 0) && (assignments['C'] == 0) && (assignments['E'] == 1))
				bias = 10;
			else if ((assignments['B'] == 0) && (assignments['C'] == 1) && (assignments['E'] == 0))
				bias = 40;
			else if ((assignments['B'] == 1) && (assignments['C'] == 0) && (assignments['E'] == 0))
				bias = 40;
			else if ((assignments['B'] == 1) && (assignments['C'] == 0) && (assignments['E'] == 1))
				bias = 10; 
			else if ((assignments['B'] == 1) && (assignments['C'] == 1) && (assignments['E'] == 0))
				bias = 40;
			else if ((assignments['B'] == 1) && (assignments['C'] == 1) && (assignments['E'] == 1))
				bias = 10;
		}
	}
	std::random_device rand_dev;
	std::uniform_int_distribution<int> range(0,100);

	int number = range(rand_dev);
	if (number >= bias) // "bias"% chance
		return 1;
	else
		return 0;
}


/*-----------------------------------
|		main()		    |
-----------------------------------*/
int main()
{
	
	//set up random number generator
	std::random_device rand_dev;
	std::uniform_int_distribution<int> range(0,1);
	
	//randomly assign initial values to variables
	// 0 indicates false and 1 indicates true
	assignments['A'] = range(rand_dev);
	assignments['B'] = range(rand_dev);
	assignments['C'] = range(rand_dev);
	assignments['E'] = range(rand_dev);
	assignments['F'] = range(rand_dev);
	
	int num_iterations = 0; //keep track of number of iterations
	int instances = 0; //keep track of number of instances
	int b_true = 0; //number of times B is true

	while(instances <= 10000)
	{
		//if B is set to true, record it
		if(assignments['B'] == 1)
			b_true++;

		//if this is a thousandth instance, report value of B
		if ((instances != 0) &&(instances%1000 == 0))
		{
			float ratio = b_true / instances;
			std::cout << " " << b_true << "/" << instances << " ";
		}

 		//reassign values to variables
		assignments.erase('A');
		assignments['A'] = brain('A');
		assignments.erase('B');
		assignments['B'] = brain('B');
		assignments.erase('C');
		assignments['C'] = brain('C');
		assignments.erase('E');
		assignments['E'] = brain('E');
		assignments.erase('F');
		assignments['F'] = brain('F');
		
		//increment accumulators
		instances = instances +5;
		num_iterations++;
	}	
	

	return 0;
}
