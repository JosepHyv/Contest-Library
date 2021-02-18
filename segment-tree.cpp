const int MAXN = 1e6+2;
typedef long long int ll;
ll st[4*MAXN];
ll lz[4*MAXN];

ll combine( ll a, ll b )
{
	/// return operations in nodes
	return (a+b); // example
}

ll buid( int nd, int i, int f)
{
	if( i == f)
	{ 
		cin>>st[c]; 			
		return st[nn];
	}
	int mm = (i+f)/2;
	return st[nn] = combine(build(2*nd, i, mm) , build(2*nd+1,mm+1,f));
}

ll query(int nn, int i, int f, int li, int ld)
{
	if( i > ld || f < li )
		return 0;
	if( i >= li && f <= ld)
		return st[nn];
	int mm = ( i+f) / 2;
	return combine(query(2*nn, i, mm, li, ld) + querr(2*nn+1, mm+1, f, li, ld));	
}

void update(int nn, int i, int f, int pos, int val)
{
	if( i == f)
		st[nn] += val;
	else
	{
		int mm = ( i+f) / 2;
		if( i <= pos && pos <= mm)
			pupd(2*nn, i, mm, pos, val);
		else
			pupd(2*nn+1, mm+1, f, pos, val);
		st[nn] = st[2*nn] + st[2*nn+1]; 
	}
}

///lazy propagation
void UpdateRange(int nn, int i, int f, int li, int ld, int val)
{
	if( lz[nn])
	{
		st[nn] += (f - i + 1 ) * lz[nn];
		if( i != f)
		{
			lz[2*nn] += lz[nn];
			lz[2*nn+1] += lz[nn];
		}
		lz[nn] = 0;
	}
	if( i > ld || f < li)
		return;
	if( i >= li && f <= ld)
	{
		st[nn]  += ( f - i + 1) * val;
		if( i != f)
		{
			lz[2*nn] += val;
			lz[2*nn+1] += val;
		}
		return;
	}
	int mm = ( i+f) / 2;
	lzup(2*nn, i, mm, li, ld, val);
	lzup(2*nn+1, mm+1, f, li, ld, val);
	st[nn] = st[2*nn] + st[2*nn+1];
	return;
}

