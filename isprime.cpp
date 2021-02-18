
bool isprime(int n )
{
	if( n <= 1 ) return false;

	if( n % 2 == 0 ) return ( n == 2);

	for(int c = 3; c<=sqrt(n); c+=2)
	{
		if( n/c < c ) break;
		if( n % c == 0 ) return false;
	}
	return true;

}
