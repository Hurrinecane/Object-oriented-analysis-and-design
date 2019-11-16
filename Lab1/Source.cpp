class Polynom
{
public:
	void add(Polynom&);
	void mul(Polynom&);
private:
	double x, pd;
		int n;
};

void Polynom ::add(Polynom& t)
{
	//extend(t.n);
	//for (int i = 0; i <= n_; i++) pd_[i] += t.pd_[i];
	//normolize();

}

void Polynom::mul(Polynom& t)
{
	Polynom R(n_ + t.n);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= t.n; j++)
		{
			R.pd_[i + j] += pd_[i] * t.pd_[j];
		}
	int c;
	double* p;
	R.n_ = c;
	c = n;
	n_ = R.n;
	p = pd_;
	pd_ = R.pd_;
	R.pd_=pd_;
}

int main()
{

}