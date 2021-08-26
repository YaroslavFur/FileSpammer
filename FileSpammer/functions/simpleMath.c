#define EPSILON 0.000001

// gets quantity of digits in number
int digitsMy(long long input)
{
	int output = 0;
	while (input > 0)
	{
		input /= 10;
		output++;
	}
	return output;
}

// rounds double to closer int (4.49 => 4, 4.5 => 5)
int roundMy(double inputToRound)
{
	int outputRounded = inputToRound;
	if (inputToRound - outputRounded >= 0.5 - EPSILON)
		outputRounded++;
	return outputRounded;
}

// rounds double to higher int (4.2 => 5, 4.9 => 5, 5 => 5)
int ceilMy(double inputToCeil)
{
	int outputCeiled = inputToCeil;
	if (inputToCeil - outputCeiled > EPSILON)
		outputCeiled++;
	return outputCeiled;
}