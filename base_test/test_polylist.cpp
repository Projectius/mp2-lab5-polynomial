#include <gtest.h>
#include"polyList.h"

TEST(polyList, can_create_monom)
{
  ASSERT_NO_THROW(Monom m(42,1,2,3));
}

TEST(polyList, throws_create_invalid_monom)
{
	ASSERT_ANY_THROW(Monom m(42, MAX_P, 2, 3));
}

TEST(polyList, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom p;);
}

TEST(polyList, can_fill_polynom)
{
	try {
		Monom m(42, 1, 2, 3);
		Monom n(55, 0, 0, 0);
		Monom b(-33, 4, 0, 3);
		Polynom p;
		cout << p<<endl;
		p.insert(m);
		p.insert(n);
		p.insert(b);
		cout << p;
	}
	catch (char* e) { cout << e; }
	ASSERT_NO_THROW();
}

TEST(polyList, can_create_copy_polynom)
{
	Monom m(42, 1, 2, 3);
	Monom n(55, 0, 0, 0);
	Monom b(-33, 4, 0, 3);
	Polynom p;
	p.insert(m);
	p.insert(n);
	p.insert(b);
	Polynom p2(p);
	ostringstream o1, o2;
	o1 << p;
	o2 << p2;
	ASSERT_EQ(o1.str(), o2.str());
}

TEST(polyList, throw_insert_exsisting)
{
	Monom m(42, 1, 2, 3);
	Monom n(55, 0, 3, 1);
	Monom v(2, 1, 2, 3);
	Polynom p;
	p.insert(m);
	p.insert(n);
	ASSERT_ANY_THROW(p.insert(v));

}

TEST(polyList, t)
{

	Polynom p;
	p.insert(Monom(44, 0, 0, 0));
	cout << p;

	ASSERT_NO_THROW();
}

TEST(polyList, can_add_polynoms)
{
	Monom m(42, 1, 2, 3);
	Monom n(55, 0, 3, 1);
	Monom v(2, 4, 0, 3);
	Polynom p;
	p.insert(m);
	p.insert(n);
	p.insert(v);

	Monom m2(-2, 1, 2, 3);
	Monom n2(1, 1, 0, 0);
	Monom v2(3, 4, 0, 3);
	Polynom p2;
	p2.insert(m2);
	p2.insert(n2);
	p2.insert(v2);
	Polynom p3(p + p2);
	ASSERT_NO_THROW();
	cout << p3 << endl;

	ostringstream o1;
	o1 << p3;

	ASSERT_EQ("40x1y2z3 + 5x4z3 + 55y3z1 + 1x1 ", o1.str());

}

TEST(polyList, can_sub_polynoms)
{
	Monom m(42, 1, 2, 3);
	Monom n(55, 0, 3, 1);
	Monom v(2, 4, 0, 3);
	Polynom p;
	p.insert(m);
	p.insert(n);
	p.insert(v);

	Monom m2(-2, 1, 2, 3);
	Monom n2(1, 1, 0, 0);
	Monom v2(3, 4, 0, 3);
	Polynom p2;
	p2.insert(m2);
	p2.insert(n2);
	p2.insert(v2);
	Polynom p3(p - p2);
	ASSERT_NO_THROW();
	cout << p3 << endl;

	ostringstream o1;
	o1 << p3;

	ASSERT_EQ("44x1y2z3 -1x4z3 + 55y3z1 -1x1 ", o1.str());

}

TEST(polyList, can_mul_polynom)
{
	Monom m(42, 1, 2, 3);
	Monom n(55, 0, 3, 1);
	Monom v(2, 4, 0, 3);
	Polynom p;
	p.insert(m);
	p.insert(n);
	p.insert(v);

	Polynom p3(p*2);
	ASSERT_NO_THROW();
	cout << p3 << endl;

	ostringstream o1;
	o1 << p3;

	ASSERT_EQ("84x1y2z3 + 4x4z3 + 110y3z1 ", o1.str());

}