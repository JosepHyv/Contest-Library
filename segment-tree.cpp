ll st[4*MAXN];
ll lz[4*MAXN];

ll bld( int nn, int i, int f)
{
	if( i == f)
	{
		cin>>st[nn];
		return st[nn];
	}
	int mm = (i+f) /2;
	return st[nn] = bld(2*nn, i, mm) + bld( 2*nn+1, mm+1, f);
}

ll qr(int nn, int i, int f, int li, int ld)
{
	if( i > ld || f < li )
		return 0;
	if( i >= li && f <= ld)
		return st[nn];
	int mm = ( i+f) / 2;
	return qr(2*nn, i, mm, li, ld) + qr(2*nn+1, mm+1, f, li, ld);	
}

void pupd(int nn, int i, int f, int pos, int val)
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

void lzup(int nn, int i, int f, int li, int ld, int val)
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

