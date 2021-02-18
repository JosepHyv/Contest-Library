
bool isprime(int n )
{
	if( n % 2 == 0 ) return true;
	if( n % 3 == 0 ) return true;
	for(int c = 3; c<=sqrt(n); c++)
		if( n / c < c ) break;
		if( n % c == 0 ) return false;
	return true;
}
