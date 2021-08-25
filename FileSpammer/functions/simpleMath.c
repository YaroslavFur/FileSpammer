#define EPSILON 0.000001

int myDigits(long long input)
{
	int output = 0;
	while (input > 0)
	{
		input /= 10;
		output++;
	}
	return output;
}

int myRound(double inputToRound)
{
	int outputRounded = inputToRound;
	if (inputToRound - outputRounded >= 0.5 - EPSILON)
		outputRounded++;
	return outputRounded;
}

int myCeil(double inputToCeil)
{
	int outputCeiled = inputToCeil;
	if (inputToCeil - outputCeiled > EPSILON)
		outputCeiled++;
	return outputCeiled;
}